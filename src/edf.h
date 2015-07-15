#ifndef EDFP_H
#define EDFP_H 0

#include <stdio.h>
#include <stdlib.h>
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
	friend class RECORD;

	public:
	EDF(void) {};
	void readfile(FILE*);
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
void debug(std::string key, std::string value)
{
	std::cout << "  " << key << ": " << value << std::endl;
	return;
}

void EDF::read_header(FILE* inlet)
{
	std::vector<std::string>::iterator it;
	std::string data;
	int aux_number;
	size_t bytes;

	it = EDF_SPECS.begin();
	while ((*it).compare("datarecords") != 0)
	{
		bytes = EDF_SPEC[*it];
		data = read_bytes(inlet, bytes);header[*it] = data;
		debug(*it, data);
		++it;
	}

	/* get how many data records */
	bytes = EDF_SPEC[*it];
	data = read_bytes(inlet, bytes);
	header[*it] = data;
	debug(*it, data);
	sscanf(data.c_str(), "%d", &aux_number);
	data_records = (size_t) aux_number;
	++it;
	/* get record duration*/
	bytes = EDF_SPEC[*it];
	data = read_bytes(inlet, bytes);
	header[*it] = data;
	debug(*it, data);
	++it;
	/* get how many signals */
	bytes = EDF_SPEC[*it];
	data = read_bytes(inlet, bytes);
	header[*it] = data;
	debug(*it, data);
	sscanf(data.c_str(), "%d", &aux_number);
	number_signals = (size_t) aux_number;
	++it;

	/* init records */
	records = (RECORD*) malloc(sizeof(RECORD)*number_signals);
	for (size_t r = 0; r < number_signals; ++r)
		records[r] = RECORD();

	while (it != EDF_SPECS.end()) 
	{
		bytes = EDF_SPEC[*it];
		std::cout << "  " << *it << ":\n";
		for (size_t i = 0; i < number_signals; ++i)
		{
			std::cout << "  - " << i << ": ";
			data = read_bytes(inlet, bytes);
			records[i].header[*it] = data;
			std::cout << data << std::endl;
			if ((*it).compare("samples") == 0) {
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
	int samples;
	int data;

	for (size_t i = 0; i < number_signals; ++i)
	{
		record = records[i];
		samples = record.number_samples;
		std::cout << i << ":\n";
		for (int j = 0; j < samples; ++j)
		{
			fscanf(inlet, "%d", &data);
			record.records.push_back(data);
			std::cout << "- " << data << "\n";
		}
	}
}

void EDF::readfile(FILE* inlet)
{
	EDF_SETUP();

	printf("header:\n");
	read_header(inlet);
	printf("reading records...\n");
	read_records(inlet);
}

#endif