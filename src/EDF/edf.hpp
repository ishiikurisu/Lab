#ifndef EDFP_H
#define EDFP_H 0

#include <cstdio>
#include <map>
#include <vector>

#include "auxiliar.hpp"
#include "edf_spec.hpp"
#include "record.hpp"

class EDF
{
	std::map<std::string, std::string> header;
	std::vector<DATA_RECORD> data_records;
	size_t number_signals;
	size_t number_data_records;
	double duration;
	void read_header(FILE*);
	void read_data_record(FILE*);

public:
	EDF(void) {};
	void read_file(const char*);
	void write_file(const char*);
	void yaml(void);
	void csv(void);
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
		else if ((*it).compare("duration") == 0) {
			sscanf(data.c_str(), "%lf", &duration);
		}
		else if ((*it).compare("numbersignals") == 0) {
			sscanf(data.c_str(), "%d", &aux_number);
			number_signals = (size_t) aux_number;
			++it;
			break;
		}

		++it;
	}

	// allocate memory
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

void EDF::read_file(const char* input)
{
	FILE* inlet = fopen(input, "rb");

	EDF_SETUP();
	read_header(inlet);
	for (size_t k = 0; k < number_data_records; ++k)
		read_data_record(inlet);

	fclose(inlet);
}

/* SAVING EDF DATA TO FILE */
void EDF::write_file(const char* output)
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
		write_bytes(outlet, header[*it]);
		++it;
	}

	// write records' header
	while (it != EDF_SPECS.end())
	{
		for (i = 0; i < number_signals; ++i)
			write_bytes(outlet, data_records[i].header[*it]);
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

void EDF::yaml()
{
   std::vector<std::string>::iterator it;
   std::vector<std::string>::iterator checkpoint;
   DATA_RECORD data_record;
   size_t i;

   // write header's header
   it = EDF_SPECS.begin();
   while ((*it).compare("label"))
   {
	   write_bytes(stdout, *it);
	   write_bytes(stdout, ": ");
	   write_bytes(stdout, header[*it]);
	   write_bytes(stdout, "\n");
	   ++it;
   }

   // write records' header
   while (it != EDF_SPECS.end())
   {
	   write_bytes(stdout, *it);
	   write_bytes(stdout, ":\n");
	   for (i = 0; i < number_signals; ++i)
	   {
		   write_bytes(stdout, "- ");
		   write_bytes(stdout, data_records[i].header[*it]);
		   write_bytes(stdout, "\n");
	   }
	   ++it;
   }

   // write records' records
   printf("Signals:\n");
   for (i = 0; i < number_signals; ++i)
   {
	   printf("  %d: ", i);
	   std::vector<short> record = data_records[i].record;
	   for (std::vector<short>::iterator r = record.begin(); r != record.end(); ++r)
	   {
		   printf("%d\t", *r);
	   }
	   printf("\n");
   }
}

void EDF::csv()
{
	std::vector< std::vector<short> > records;
	std::vector<short> record;
	unsigned long limit = -1;
	size_t i, j;
	short data;

	// write header
	printf("title:%s,", header["recording"].c_str());
	printf("recorded:%s %s,",
		header["startdate"].c_str(), header["starttime"].c_str());
	printf("sampling:128,");
	printf("subject:%s,", header["patient"].c_str());
	printf("labels:");
	for (i = 0; i < number_signals; ++i)
		printf("%s ", data_records[i].header["label"].c_str()); printf(",");
	printf("chan:%d,", number_signals);
	printf("units:emotiv\n");

	// write data records
	for (i = 0; i < number_signals; ++i)
		records.push_back(data_records[i].get_record());
	limit = records.at(0).size();
	for (j = 0; j < limit; ++j)
	{
		for (i = 0; i < number_signals; ++i)
		{
			record = records.at(i);
			data = record.at(j); // translate this fucker
			if (i != 0) printf(", %d", data);
			else printf("%d", data);
		}
		printf("\n");
	}
	records.clear();
}

#endif
