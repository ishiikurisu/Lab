#ifndef EDFP_H
#define EDFP_H 0

#include <cstdio>
#include <map>
#include <vector>

#include "edf_spec.hpp"
#include "auxiliar.hpp"
#include "record.hpp"
#include "annotations.hpp"

class EDFP
{
	std::map<std::string, std::string> header;
	std::vector<DATA_RECORD> data_records;
	std::vector<std::string> labels;
	ANNOTATION annotations;
	size_t number_signals;
	size_t number_data_records;
	float duration;
	void read_header(FILE*);
	void read_data_record(FILE*);

public:
	EDFP(void) {};
	~EDFP(void) {};
	void read_file(const char*);
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
void EDFP::read_header(FILE* inlet)
{
	std::vector<std::string>::iterator it;
	std::string data;
	size_t aux_number;
	size_t bytes;


	for (it = EDFP_SPECS.begin(); (*it).compare("label") != 0; ++it)
	{
		bytes = EDFP_SPEC[*it];
		data = read_to_string(inlet, bytes);
		header[*it] = data;

		if ((*it).compare("reserved") == 0) {
			// analize if it is EDF+ or EDF
		}
		else if ((*it).compare("datarecords") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			number_data_records = (size_t) aux_number;
		}
		else if ((*it).compare("duration") == 0) {
			sscanf(data.c_str(), "%f", &duration);
		}
		else if ((*it).compare("numbersignals") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			number_signals = (size_t) aux_number;
		}
	}

	// allocate memory
	for (size_t r = 0; r < number_signals; ++r)
	{
		/* add EDF+ annotations case */
		data_records.push_back(DATA_RECORD());
	}

	for (; it != EDFP_SPECS.end(); ++it)
	{
		bytes = EDFP_SPEC[*it];
		for (size_t i = 0; i < number_signals; ++i)
		{
			data = read_to_string(inlet, bytes);
			data_records[i].header[*it] = data;

			if ((*it).compare("samplesrecord") == 0) {
				sscanf(data.c_str(), "%d", &aux_number);
				data_records[i].number_samples = (size_t) aux_number;
			}
		}
	}
}

/*
# samples * integer: first signal in data record
# samples * integer: second signal
... ns times
*/
void EDFP::read_data_record(FILE* inlet)
{
	for (size_t i = 0; i < number_signals; ++i)
	{
		/* add EDF+ annotations case */
		data_records[i].read_record(inlet, duration);
	}
}

void EDFP::read_file(const char* input)
{
	FILE* inlet = NULL;

	if (input == NULL)
		inlet = stdin;
	else
		inlet = fopen(input, "rb");

	EDF_SETUP();
	read_header(inlet);
	for (size_t k = 0; k < number_data_records; ++k)
		read_data_record(inlet);

	fclose(inlet);
}

#endif
