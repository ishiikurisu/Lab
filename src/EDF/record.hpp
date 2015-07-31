#ifndef RECORD_H
#define RECORD_H 0
#include <vector>
#include <map>

class DATA_RECORD
{
	std::map<std::string, std::string> header;
	std::vector< std::vector<short> > records;
	size_t number_samples;

public:
	void read_record(FILE*, size_t);
	void write_record(FILE*, size_t, size_t);
	std::vector<short> get_record();
	friend class EDF;
};

void DATA_RECORD::read_record(FILE* inlet, size_t duration)
{
	std::vector<short> record;
	short sig;

	for (size_t j = 0; j < duration * number_samples; ++j)
	{
		sig = read_short(inlet);
		record.push_back(sig);
	}

	records.push_back(record);
}

void DATA_RECORD::write_record(FILE* outlet, size_t duration, size_t which)
{
	std::vector<short> current = records[which];
	std::vector<short>::iterator it = current.begin();
	short bmo;

	for (it = current.begin(); it != current.end(); ++it)
	{
		bmo = *it;
		fwrite(&bmo, sizeof(short), 1, outlet);
	}
}

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

#endif
