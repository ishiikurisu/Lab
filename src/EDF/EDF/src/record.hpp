#ifdef EDFP_H
#ifndef RECORD_H
#define RECORD_H 0
#include <vector>
#include <map>

class DATA_RECORD
{
	short change_endian(short);
	std::map<std::string, std::string> header;
	std::vector<short> record;
	size_t number_samples;

public:
	void read_record(FILE*, size_t);
	void write_record(FILE*, size_t, size_t);
	std::vector<float> get_translated_record();
	std::vector<short> get_record();
	std::string get_from_header(std::string);
#ifdef USING_EDF
	friend class EDF;
#else
#ifdef USING_EDFP
	friend class EDFP;
#endif
#endif
};

short DATA_RECORD::change_endian(short in)
{
	return ((in >> 8) & 0x00ff) | ((in & 0x00ff) << 8);
}

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

std::vector<float> DATA_RECORD::get_translated_record()
{
	std::vector<float> result;
	std::vector<short>::iterator it;
	long digitalmaximum = stol(header["digitalmaximum"]);
	long digitalminimum = stol(header["digitalminimum"]);
	long physicalmaximum = stol(header["physicalmaximum"]);
	long physicalminimum = stol(header["physicalminimum"]);
	float correct = (float)(digitalmaximum - digitalminimum)
		/ (float)(physicalmaximum - physicalminimum);

	for (it = record.begin(); it != record.end(); ++it)
		result.push_back(change_endian(*it) / correct);

	return result;
}

std::vector<short> DATA_RECORD::get_record()
{
	return record;
}

std::string DATA_RECORD::get_from_header(std::string key)
{
	return header[key];
}

#endif
#endif
