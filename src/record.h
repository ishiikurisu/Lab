#ifndef RECORD_H
#define RECORD_H 0

typedef struct
{
	std::map<std::string, std::string> header;
	std::vector<float> records;
	size_t number_samples;
} RECORD;

#endif