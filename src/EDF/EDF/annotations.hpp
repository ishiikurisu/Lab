#ifndef ANNOTATION_H
#define ANNOTATION_H 0
#include <iostream>
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
	size_t number_samples;
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
	std::string annotation;

	for (size_t i = 0; i < 2*number_samples; ++i)
		annotation += fgetc(stream);
	
	annotations.push_back(annotation);
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

	std::cout << outlet << std::endl;
	return outlet.c_str();
}

#endif
