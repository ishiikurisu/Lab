#ifndef RECORD_H
#define RECORD_H 0
#include <vector>
#include <map>

class DATA_RECORD
{
	std::map<std::string, std::string> header;
	std::vector< std::vector<int> > records;
	size_t number_samples;

public:
	void read_record(FILE*, size_t);
	void write_record(FILE*, size_t, size_t);
	friend class EDF;
};

void DATA_RECORD::read_record(FILE* inlet, size_t duration)
{
	std::vector<int> record;
	int sig;

	for (size_t j = 0; j < duration * number_samples; ++j)
	{
		sig = read_int(inlet);		
		record.push_back(sig);
	}

	records.push_back(record);
}

void DATA_RECORD::write_record(FILE* outlet, size_t duration, size_t which)
{
	int bmo = 0;

	for (size_t j = 0; j < number_samples * duration; ++j)
	{
		bmo = records[which].at(j);
		fwrite(&bmo, sizeof(int), 1, outlet);
	}
}

#endif