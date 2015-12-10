#ifndef ANNOTATION_H
#define ANNOTATION_H 0
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

class ANNOTATION
{
	std::map<std::string, std::string> header;
	std::vector<std::string> annotations;
	size_t size;
	bool is_annotation(FILE*);
	std::string build(std::string, std::string);

public:
	ANNOTATION() { };
	~ANNOTATION() { } ;
	void read_annotation(FILE*);
	const char* get_annotations();
};

/******************
* PRIVATE METHODS *
******************/

bool ANNOTATION::is_annotation(FILE *stream)
{
	char preview = fgetc(stream);
	ungetc(preview, stream);
	return (preview == '+' || preview == '-')? true : false;
}

std::string ANNOTATION::build(std::string timestamp, std::string annotation)
{
	return timestamp + ": " + annotation;
}

/*****************
* PUBLIC METHODS *
*****************/

void ANNOTATION::read_annotation(FILE* stream)
{
	char bit;
	std::string timestamp;
	std::string annotation;

	if (!is_annotation(stream))
		return;

	bit = fgetc(stream);
	while (bit != 20)
	{
		timestamp += bit;
		bit = fgetc(stream);
	}

	bit = fgetc(stream);
	while (bit != 0)
	{
		bit = fgetc(stream);
		while (bit != 20)
			annotation += bit,
			bit = fgetc(stream);
		annotations.push_back(build(timestamp, annotation));
		annotation.clear();
		bit = fgetc(stream);
	}
}

const char* ANNOTATION::get_annotations()
{
	std::string outlet;
	std::vector<std::string>::iterator it;

	for (it = annotations.begin(); it != annotations.end(); ++it)
	{
		outlet = outlet + (*it);
		outlet += "\n";
	}

	return outlet.c_str();
}

#endif
