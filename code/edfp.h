#ifndef EDFP_H
#define EDFP_H 0

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include "auxiliar.h"

#include "edfp_spec.h"
#include "record.h"
class EDFP
{
	std::map<std::string, std::string> header;
	RECORDS* records;
	size_t number_signals;

	public:
	EDFP(void) {};
	void read_header(FILE*);
	void read_records(FILE*);
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
void EDFP::read_header(FILE* inlet)
{
	std::vector<std::string>::iterator it;
	string data;
	size_t bytes;
	size_t data_records;

	it = EDFP_SPECS.begin();
	while ((*it) != "datarecords")
	{
		bytes = EDFP_SPEC[*it];
		data = read_bytes(inlet, bytes);
		header[*it] = data;
		++it;
	}

	
	number_signals = (*it).to_i;
	++it;
	while (it != EDFP_SPECS.end()) 
	{
		for (int i = 0; i < number_signals; ++i)
		{
			bytes = EDFP_SPEC[*it];
			data = read_bytes(inlet, bytes);
			header[*it] = data;
		}
		++it;
	}
}

/* 
# samples * integer: first signal in data record
# samples * integer: second signal
... ns times
*/
void EDFP::read_records(FILE* inlet)
{
	records = (std::vector<std::string>*) malloc(sizeof(std::vector<std::string>) * number_signals);
	int data;

	for (int i = 0; i < number_signals; ++i)
	{
		records[i] = new std:vector<std::string>;
		fscanf(inlet, "%d", &data);
		records[i] = data;
	}
}

EDFP edfp_readfile(FILE* inlet)
{
	EDFP *edf = malloc(sizeof(EDFP));

	edf->read_header(inlet);
	edf->read_records(inlet);

	return edf;
}

#endif