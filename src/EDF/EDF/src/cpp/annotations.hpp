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
	std::string yaml(std::string);
	std::string parse(std::string);
	std::string format(std::string);

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

std::string ANNOTATION::yaml(std::string inlet)
{
	std::string outlet = "- ";
	std::string::iterator c;

	for (c = inlet.begin(); c != inlet.end(); c++)
		outlet.push_back(((*c) == 20 || (*c) == 21)? ' ' : *c);

	return outlet;
}

std::string ANNOTATION::parse(std::string haystack)
{
	std::string needles;
	std::string needle;
	std::string::iterator c;

	for (c = haystack.begin(); c != haystack.end(); c++)
	{
		needle = std::string();
		if ((*c) == '+' || (*c) == '-') {
			for ( ; ((*c) != 0) && (c != haystack.end()); c++)
				needle += *c;
			needles += needle + "\n";
		}
	}

	return needles;
}

std::string ANNOTATION::format(std::string inlet)
{
	std::vector<std::string> each = split(inlet, '\n');
	std::vector<std::string>::iterator it;
	std::string outlet;

	for (it = each.begin(); it != each.end(); ++it)
		outlet += yaml(*it) + "\n";

	return outlet;
}

/*****************
* PUBLIC METHODS *
*****************/

/**
 * This method reads a whole EDF annotations chunk from the
 * file and append it to a vector that contains every chunk
 */
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
		outlet = outlet + parse(*it);

	return format(outlet).c_str();
}

#endif
