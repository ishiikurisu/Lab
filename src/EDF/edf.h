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
	RECORD* records;
	size_t number_signals;
	size_t data_records;
	void read_header(FILE*);
	void read_records(FILE*);

	public:
	EDF(void) {};
	void readfile(const char*);
	void writefile(const char*);
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
			data_records = (size_t) aux_number;
		}
		else if ((*it).compare("numbersignals") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			number_signals = (size_t) aux_number;
			++it;
			break;
		}

		++it;
	}

	records = (RECORD*) malloc(sizeof(RECORD)*number_signals);
	for (size_t r = 0; r < number_signals; ++r)
		records[r] = RECORD();

	while (it != EDF_SPECS.end())
	{
		bytes = EDF_SPEC[*it];
		for (size_t i = 0; i < number_signals; ++i)
		{
			data = read_bytes(inlet, bytes);
			records[i].header[*it] = data;

			if ((*it).compare("samplesrecord") == 0) {
				sscanf(data.c_str(), "%d", &aux_number);
				records[i].number_samples = (size_t) aux_number;
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
void EDF::read_records(FILE* inlet)
{
	RECORD record;
	size_t samples;
	std::string data;
	int sig;

	for (size_t i = 0; i < number_signals; ++i)
	{
		record = records[i];
		samples = record.number_samples;

		for (size_t j = 0; j < samples; ++j)
		{
			sig = read_int(inlet);
			printf("%d\n", sig);
			record.records.push_back(sig);
		}
	}
}

void EDF::readfile(const char* input)
{
	FILE* inlet = fopen(input, "rb");
	
	EDF_SETUP();
	read_header(inlet);
	read_records(inlet);

	fclose(inlet);
}

void EDF::writefile(const char* output)
{
	FILE* outlet = fopen(output, "wb");
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator checkpoint;
	RECORD record;
	size_t i;

	/* write */
	it = EDF_SPECS.begin();
	while ((*it).compare("label") != 0)
	{
		fprintf(outlet, "%s", header[*it].c_str());
		// printf("%s", header[*it].c_str());
		++it;
	}

	while (it != EDF_SPECS.end())
	{
		for (i = 0; i < number_signals; ++i)
		{
			record = records[i];
			fprintf(outlet, "%s", record.header[*it].c_str());
		// printf("- %s: %s\t", (*it).c_str(), record.header[*it].c_str());
		}
		++it;
	}

	for (i = 0; i < number_signals; ++i)
	{
		record = records[i];

		for (size_t j = 0; j < record.number_samples; ++j)
			fwrite(&record.records[j], sizeof(int), 1, outlet);
	}

	fflush(outlet);
	fclose(outlet);
}

#endif
