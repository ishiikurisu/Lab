#ifndef AUXILIAR_H
#define AUXILIAR_H 0

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

std::string read_bytes(FILE* stream, size_t number_bytes)
{
	std::string outlet;
	char just_read;

	for (size_t i = 0; i < number_bytes; ++i)
	{
		fscanf(stream, "%c", &just_read);
		outlet += just_read;
	}

	return outlet;
}

void debug(std::string key, std::string value)
{
	std::cout << key << ": " << value << std::endl;
	return;
}

int read_int(FILE* stream)
{
	int i;
	fread(&i, sizeof(int), 1, stream);
	return i;
}

#endif