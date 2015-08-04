#ifndef AUXILIAR_H
#define AUXILIAR_H 0

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

std::string read_bytes(FILE* stream, size_t number_bytes)
{
	std::string outlet;

	for (size_t i = 0; i < number_bytes; ++i)
		outlet += fgetc(stream);

	return outlet;
}

size_t write_bytes(FILE* stream, std::string outlet)
{
	const char* to_be_written = outlet.c_str();
	size_t written_chars = outlet.length();

	fwrite(to_be_written, sizeof(char),	outlet.length(), stream);

	return written_chars;
}

void debug(std::string key, std::string value)
{
	std::cout << key << ": " << value << std::endl;
	return;
}

int read_int(FILE* stream)
{
	int i = 0;
	fread(&i, sizeof(int), 1, stream);
	return i;
}

short read_short(FILE* stream)
{
	short i = 0;
	fread(&i, sizeof(short), 1, stream);
	return i;
}

long stol(std::string str)
{
	long result;
	sscanf(str.c_str(), "%ld", &result);
	return result;
}

#endif