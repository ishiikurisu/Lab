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
	std::vector<short> get_record();
	friend class EDF;
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
	std::vector<short>::iterator it = record.begin();
	short bmo;

	for (it = record.begin(); it != record.end(); ++it)
	{
		bmo = *it;
		fwrite(&bmo, sizeof(short), 1, outlet);
	}
}

/*
std::vector<short> DATA_RECORD::get_record()
{
	std::vector< std::vector<short> >::iterator current = records.begin();
	std::vector<short>::iterator it;
	std::vector<short> result;

	while (current != records.end())
	{
		it = current->begin();
		while (it != current->end())
		{
			result.push_back((*it));
			++it;
		}

		++current;
	}

	return result;
}
*/

std::vector<short> DATA_RECORD::get_record()
{
	return record;
}

#endif
