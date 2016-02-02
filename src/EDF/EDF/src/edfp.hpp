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

/**
 * Class to represent the data in an EDF/EDF+ file
 */
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

EDFP::EDFP()
{
	annotations_channel = (size_t) -1;
	isEDFP = false;
}

/**
 * Reads the EDF header to the EDFP object and its annotations' and record's simblings
 * @param inlet a pointer to the file
 * @param debug false by default, it prints header info on screen using the YAML format.
 */
void EDFP::read_header(FILE* inlet, bool debug = false)
{
	std::vector<std::string>::iterator it;
	std::string data;
	size_t aux_number;
	size_t bytes;

	// reading header
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

	// allocating memory
	for (size_t r = 0; r < number_signals; ++r)
	{
		data_records.push_back(DATA_RECORD());
	}

	// reading data records' and annotations' headers
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

/**
 * Reads a data record to the respective annotation or data record it belongs to.
 * @param inlet the pointer to the file the app is reading from.
 * @param debug false by default, it enables debugging on terminal screen.
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

/**
 * Reads an EDF file and store it in an instance of the EDFP class.
 * @param input the name of the file.
 * @param debug false by default, determines if it should or not write stuff on terminal.
 * @author Cris Silva Jr. <cristianoalvesjr@gmail.com>
 */
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

/*
 ------------------------------------------------------------------------
*/

/* Auxiliary functions to EDFP::csv(char*) */
std::string _more_common(std::vector<DATA_RECORD> records, std::string property)
{
	std::vector<DATA_RECORD>::iterator record;
	std::vector<std::string>::iterator sampling;
	std::map<std::string, long> counter;
	std::vector<std::string> samplings;
	long biggest = -1;
	std::string value;

	for (record = records.begin(); record != records.end(); record++)
	{
		value = record->get_from_header(property);
		if (counter.count(value))
			counter[value]++;
		else
			counter[value] = 1,
			samplings.push_back(value);
	}

	for (sampling = samplings.begin(); sampling != samplings.end(); sampling++)
	{
		long current = counter[(*sampling)];
		if (current > biggest)
			biggest = current,
			value = (*sampling);
	}

	return value;
}

std::string _csvfy(std::string inlet)
{
	std::string outlet = chomp(inlet);

	for (size_t i = 0; i < outlet.length(); ++i)
		if (whitespace(outlet[i]))
			outlet[i] = '_';

	return outlet;
}


/**
 * Converts the EDF+ file to a CSV one
 * @param output <p>the name of output file. If there is no output,
 * the program will write it in terminal.</p>
 * @author Cris Silva Jr. <cristianoalvesjr@gmail.com>
 */
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

	// writing header
	fprintf(outlet, "title:%s,", header["recording"].c_str());
	fprintf(outlet, "recorded:%s %s,",
		header["startdate"].c_str(), header["starttime"].c_str());
	fprintf(outlet, "sampling:%ld,", 
		stol(_more_common(data_records, "samplesrecord")));
	fprintf(outlet, "subject:%s,", header["patient"].c_str());
	fprintf(outlet, "labels:");
	for (i = 0; i < number_signals; ++i)
		if (i != annotations_channel)
			fprintf(outlet, "%s ", 
				_csvfy(data_records[i].header["label"]).c_str());
	fprintf(outlet, ",");
	fprintf(outlet, "chan:%d,", number_signals - ((isEDFP)? 1 : 0));
	fprintf(outlet, "units:%s\n",
		_more_common(data_records, "physicaldimension").c_str());

	// writing data records
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
