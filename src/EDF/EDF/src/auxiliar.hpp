#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

std::string read_to_string(FILE* stream, size_t number_bytes)
{
	std::string outlet;

	for (size_t i = 0; i < number_bytes; ++i)
		outlet += fgetc(stream);

	return outlet;
}

size_t write_from_string(FILE* stream, std::string outlet)
{
	size_t written_chars = outlet.length();
	fwrite(outlet.c_str(), sizeof(char), written_chars, stream);
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

std::vector<std::string> split(std::string str, char delimit)
{
	std::vector<std::string> result;
	std::string::iterator ch = str.begin();

	while (ch != str.end())
	{
		std::string token;

		while (*ch != delimit && ch != str.end()) {
			token += *ch;
			++ch;
		}

		result.push_back(token);

		if (ch != str.end()) {
			token.clear();
			++ch;
		}
	}

	return result;
}

std::string read_line_from_file(FILE* stream)
{
	std::string outlet;
	char just_read;

	if (!feof(stream))
	{
		just_read = fgetc(stream);
		while (just_read != '\n' && !feof(stream))
		{
			outlet += just_read;
			just_read = fgetc(stream);
		}
	}

	return outlet;
}

bool match(const char *s, const char *t)
{
	while (*s && *t)
		if (*s != *t)
			return false;
		else
			++s, ++t;
	return true;
}