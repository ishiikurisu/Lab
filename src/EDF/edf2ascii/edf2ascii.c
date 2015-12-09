#include <stdlib.h>
#include <stdio.h>
#include <oa.h>
#include "edf2ascii.h"

char* ask_for_name(int argc, char *argv[])
{
    return (argc == 1)? read_from_file(stdin) : argv[1];
}

char* get_source_edf(char *old_input)
{
	LIST *parts = list_strsplit(old_input, '.');
	LIST *part = parts->next;
	char *new_input = part->value;

	for (inc(part); part->next != NULL; inc(part))
		cat(new_input, ctos('.')),
		cat(new_input, part->value);

	free(old_input);
	return new_input;
}

int main(int argc, char *argv[])
{
	char *input = ask_for_name(argc, argv);

	input = get_source_edf(input);
	edf2csv(input);
	csv2ascii(input);
	clear_folder(input);

	free(input);
	return 0;
}