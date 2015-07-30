#ifndef EDFP_H
#define EDFP_H 0

#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include "auxiliar.h"

#include "edf_spec.h"
#include "record.h"
class EDF
{
	std::map<std::string, std::string> header;
	std::vector<DATA_RECORD> data_records;
	size_t number_signals;
	size_t number_data_records;
	size_t duration;
	void read_header(FILE*);
	void read_data_record(FILE*);

public:
	EDF(void) {};
	void readfile(const char*);
	void writefile(const char*);
	friend class DATA_RECORD;
};

/* HEADER SPEC
	8: version
	80: local patient identification
	80: local recording identification
	8: startdate of recording (dd.mm.yy)
	8: starttime of recording (hh.mm.ss)
	8: number of bytes in header record
	44: reserved (not present in EDF+)
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
void EDF::read_header(FILE* inlet)
{
	std::vector<std::string>::iterator it;
	std::string data;
	size_t aux_number;
	size_t bytes;

	it = EDF_SPECS.begin();
	while (it != EDF_SPECS.end())
	{
		bytes = EDF_SPEC[*it];
		data = read_bytes(inlet, bytes);
		header[*it] = data;

		if ((*it).compare("datarecords") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			number_data_records = (size_t) aux_number;
		}
		if ((*it).compare("duration") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			duration = (size_t) aux_number;
		}
		else if ((*it).compare("numbersignals") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			number_signals = (size_t) aux_number;
			++it;
			break;
		}

		++it;
	}

	/* allocate memory */
	for (size_t r = 0; r < number_signals; ++r)
		data_records.push_back(DATA_RECORD());

	while (it != EDF_SPECS.end())
	{
		bytes = EDF_SPEC[*it];
		for (size_t i = 0; i < number_signals; ++i)
		{
			data = read_bytes(inlet, bytes);
			data_records[i].header[*it] = data;

			if ((*it).compare("samplesrecord") == 0) {
				sscanf(data.c_str(), "%d", &aux_number);
				data_records[i].number_samples = (size_t) aux_number;
			}
		}
		++it;
	}
}

/*
# samples * integer: first signal in data record
# samples * integer: second signal
... ns times
*/
void EDF::read_data_record(FILE* inlet)
{
	for (size_t i = 0; i < number_signals; ++i)
		data_records[i].read_record(inlet, duration);
}

void EDF::readfile(const char* input)
{
	FILE* inlet = fopen(input, "rb");
	
	EDF_SETUP();
	read_header(inlet);
	for (size_t k = 0; k < number_data_records; ++k)
		read_data_record(inlet);

	fclose(inlet);
}

/* SAVING EDF DATA TO FILE */
void EDF::writefile(const char* output)
{
	FILE* outlet = NULL;
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator checkpoint;
	DATA_RECORD data_record;
	size_t i;

	if (output == NULL)
		outlet = stdout;
	else
		outlet = fopen(output, "wb");

	// write header's header
	it = EDF_SPECS.begin();
	while ((*it).compare("label"))
	{
		fprintf(outlet, "%s", header[*it].c_str());
		++it;
	}

	// write records' header
	while (it != EDF_SPECS.end())
	{
		for (i = 0; i < number_signals; ++i)
			fprintf(outlet, "%s", data_records[i].header[*it].c_str());
		fflush(outlet);
		++it;
	}

	// write records' records
	for (size_t k = 0; k < number_data_records; ++k)
		for (i = 0; i < number_signals; ++i)
			data_records[i].write_record(outlet, duration, k);

	fflush(outlet);
	fclose(outlet);
}

#endif
