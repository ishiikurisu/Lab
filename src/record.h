#ifndef RECORD_H
#define RECORD_H 0

class RECORD
{
	std::map<std::string, std::string> header;
	std::vector<int> records;
	size_t number_samples;
	friend class EDF;
public:
	void pass() { return; };
};

#endif