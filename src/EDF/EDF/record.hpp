#ifdef EDFP_H
#ifndef RECORD_H
#define RECORD_H 0
#include <vector>
#include <map>

class DATA_RECORD
{
	std::map<std::string, std::string> header;
	std::vector<short> record;
	size_t number_samples;

public:
	void read_record(FILE*, size_t);
	void write_record(FILE*, size_t, size_t);
	std::vector<double> get_translated_record();
	std::vector<short> get_record();
	friend class EDF;
	friend class EDFP;
};

void DATA_RECORD::read_record(FILE* inlet, size_t duration)
{
	short sig;

	for (size_t j = 0; j < duration * number_samples; ++j)
	{
		sig = read_short(inlet);
		record.push_back(sig);
	}
}

void DATA_RECORD::write_record(FILE* outlet, size_t duration, size_t which)
{
	std::vector<short>::iterator it;

	for (it = record.begin(); it != record.end(); ++it)
	{
		short bmo = *it;
		fwrite(&bmo, sizeof(short), 1, outlet);
	}
}

std::vector<double> DATA_RECORD::get_translated_record()
{
	std::vector<double> result;
	std::vector<short>::iterator it = record.begin();
	long digitalmaximum = stol(header["digitalmaximum"]);
	long digitalminimum = stol(header["digitalminimum"]);
	long physicalmaximum = stol(header["physicalmaximum"]);
	long physicalminimum = stol(header["physicalminimum"]);
	double correct = (double)(digitalmaximum - digitalminimum) 
		/ (double)(physicalmaximum - physicalminimum);
	double to_append = -1.0;
	
	while (it != record.end())
	{		
		to_append = (*it) / correct;
		result.push_back(to_append);
		++it;
	}

	return result;
}

std::vector<short> DATA_RECORD::get_record()
{
	return record;
}

#endif
#endif
