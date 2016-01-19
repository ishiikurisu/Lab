#ifndef CSV_TO_ASCII
#define CSV_TO_ASCII
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <buffer.h>

/* 
# Common functions

+ LIST* parse_header(char *line);
+ LIST* parse_line(char *line);
*/

// TODO: write parsing functions

/*
# Main functions

+ void csv2single(const char *input, const char *output);
+ void csv2multiple(const char *input);
*/

/**
 * Translates a `csv` file
 */
void csv2single(const char *input, const char *output) 
{
	BUFFER *inlet = beffer_new(input, "r", 256);
	BUFFER *outlet = buffer_new(output, "w", 256);

	/* let the magic happen */

	buffer_close(inlet);
	buffer_close(outlet);
}

void csv2multiple(const char *input)
{
	return;
}

#endif