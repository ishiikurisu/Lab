#ifdef EDFH_P 
#ifndef ANNOTATION_H
#define ANNOTATION_H 0
#include <vector>
#include <map>
#include 

class ANNOTATION
{
	std::map<std::string, std::string> header;
	std::vector<std::string> annotations;
	size_t size;

public:
	ANNOTATION();
	~ANNOTATION();
	void read_annotation();
};

#endif
#endif