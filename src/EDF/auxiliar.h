#ifndef AUXILIAR_H
#define AUXILIAR_H 0

#include <stdio.h>
#include <stdlib.h>

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

#endif