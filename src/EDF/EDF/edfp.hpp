#ifndef EDFP_H
#define EDFP_H 0
#define USING_EDFP 0

#include <cstdio>
#include <map>
#include <vector>

#include "edf_spec.hpp"
#include "auxiliar.hpp"
#include "record.hpp"
#include "annotations.hpp"

class EDFP
{
	void read_header(FILE*, bool);
	void read_data_record(FILE*, bool);
	std::map<std::string, std::string> header;
	std::vector<DATA_RECORD> data_records;
	std::vector<std::string> labels;
	ANNOTATION annotations;
	size_t number_signals;
	size_t number_data_records;
	size_t annotations_channel;
	float duration;
	bool isEDFP;

public:
	EDFP(void);
	~EDFP(void) {};
	void read_file(const char*, bool);
	void csv(const char*);
	friend class DATA_RECORD;
};

/* HEADER SPEC
	8: version
	80: local patient identification
	80: local recording identification
	8: startdate of recording (dd.mm.yy)
	8: starttime of recording (hh.mm.ss)
	8: number of bytes in header record
	44: reserved
	8: number of data records
	8: duration of a data record in seconds
	4: ns = number of signals in data record
	ns * 16: ns * label
	ns * 80: ns * transducer type
	ns * 8: physical dimension
	ns * 8: physical minimum
	ns * 8: physical maximum
	ns * 8: digital minimum
	ns * 8: digital maximum
	ns * 80: ns * prefiltering
	ns * 8: ns * # of samples in each data record
	ns * 32: ns * reserved
*/


EDFP::EDFP()
{
	annotations_channel = (size_t) -1;
	isEDFP = false;
}

void EDFP::read_header(FILE* inlet, bool debug = false)
{
	std::vector<std::string>::iterator it;
	std::string data;
	size_t aux_number;
	size_t bytes;

	for (it = EDF_SPECS.begin(); it->compare("label") != 0; ++it)
	{
		bytes = EDF_SPEC[*it];
		data = read_to_string(inlet, bytes);
		header[*it] = data;

		if (debug) printf("%s: %s", it->c_str(), data.c_str());

		if (it->compare("reserved") == 0) {
			// analize if it is EDF+ or EDF
			isEDFP = (match(data.c_str(), EDF_PLUS.c_str()))? true : false;
			if (debug) printf("%s", (isEDFP)? "# EDF+" : "# EDF");
		}
		else if (it->compare("datarecords") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			number_data_records = (size_t) aux_number;
		}
		else if (it->compare("duration") == 0) {
			sscanf(data.c_str(), "%f", &duration);
		}
		else if (it->compare("numbersignals") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			number_signals = (size_t) aux_number;
		}
		if (debug) printf("\n");
	}

	// allocate memory
	for (size_t r = 0; r < number_signals; ++r)
	{
		data_records.push_back(DATA_RECORD());
	}

	for (; it != EDF_SPECS.end(); ++it)
	{
		bytes = EDF_SPEC[*it];
		if (debug) printf("%s:\n", it->c_str());
		for (size_t i = 0; i < number_signals; ++i)
		{
			data = read_to_string(inlet, bytes);
			data_records[i].header[*it] = data;
			if (debug) printf("- %s\n", data.c_str());

			if (it->compare("samplesrecord") == 0) {
				sscanf(data.c_str(), "%d", &aux_number);
				((i == annotations_channel)? \
					annotations.number_samples : data_records[i].number_samples) \
					= (size_t) aux_number;
			}
			else if (it->compare("label") == 0 && isEDFP) {
				if (match(data.c_str(), "EDF Annotations"))
					annotations_channel = i;
			}
		}
	}
}

/*
# samples * integer: first signal in data record
# samples * integer: second signal
... ns times
*/
void EDFP::read_data_record(FILE* inlet, bool debug = false)
{
	for (size_t i = 0; i < number_signals; ++i)
	{
		if (i == annotations_channel)
		 	annotations.read_annotation(inlet);
		else
			data_records[i].read_record(inlet, duration);
	}
}

void EDFP::read_file(const char* input, bool debug = false)
{
	FILE* inlet = (input == NULL)? stdin : fopen(input, "rb");

	EDF_SETUP();
	read_header(inlet, debug);
	for (size_t c = 0; c < number_data_records; c++)
		read_data_record(inlet, debug);

	if (debug)
		printf("Annotations:\n"),
		printf("%s\n", annotations.get_annotations()),
		printf("...\n");

	if (input == NULL) fclose(inlet);
}

void EDFP::csv(const char *output = NULL)
{
	FILE *outlet = stdout;
	std::vector< std::vector<float> > records;
	std::vector<float> record;
	unsigned long limit = -1;
	size_t i, j;
	float data;

	if (output != NULL)
		outlet = fopen(output, "wb");

	// write header
	fprintf(outlet, "title:%s,", header["recording"].c_str());
	fprintf(outlet, "recorded:%s %s,",
		header["startdate"].c_str(), header["starttime"].c_str());
	fprintf(outlet, "sampling:200,"); // TODO: discover sampling
	fprintf(outlet, "subject:%s,", header["patient"].c_str());
	fprintf(outlet, "labels:");
	for (i = 0; i < number_signals; ++i)
		if (i != annotations_channel)
			fprintf(outlet, "%s ", data_records[i].header["label"].c_str());
	fprintf(outlet, ",");
	fprintf(outlet, "chan:%d,", number_signals - ((isEDFP)? 1 : 0));
	fprintf(outlet, "units:uV\n"); // TODO: discover units

	// write data records
	for (i = 0; i < number_signals; ++i)
		if (i != annotations_channel)
			records.push_back(data_records[i].get_translated_record());
	limit = records.at(0).size();
	for (j = 0; j < limit; ++j)
	{
		for (i = 0; i < number_signals; ++i)
		{
			if (i == annotations_channel) continue;
			record = records.at(i);
			data = record.at(j);
			if (i == 0) fprintf(outlet, "%f", data);
			else fprintf(outlet, ", %f", data);
		}
		fprintf(outlet, "\n");
	}
	records.clear();

	if (output != NULL)
		fclose(outlet);
}

#endif
