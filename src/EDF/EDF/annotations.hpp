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
	std::string parse(std::string);

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

std::string ANNOTATION::parse(std::string haystack)
{
	std::string needles;
	std::string needle;
	std::string::iterator c;

	for (c = haystack.begin(); c != haystack.end(); c++)
	{
		needle = std::string();
		if ((*c) == '+' || (*c) == '-') {
			while ( ((*c) != 0) && (c != haystack.end()) )
			{
				needle += *c;
				c++;
			}
			needles += needle + "\n";
		}
	}

	return needles;
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
		outlet = outlet + parse(*it);
	}

	return outlet.c_str();
}

#endif
