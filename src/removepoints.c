#include <stdio.h>
#include <stdlib.h>
#include "joepack.h"

char* command(char *input, char *output)
{
	char *comm = "move ";

	cat(comm, input);
	cat(comm, " ");
	cat(comm, output);

	return comm;
}

int main(int argc, char const *argv[])
{
	char *name = "";
	char *out = "";
	char *curr;
	LIST *bits = NULL;
	int i = 0;

	while (name = read_from_file(stdin))
	{
		bits = list_strsplit(name, '.');
		out = "";

		for (inc(bits); bits->next != NULL; inc(bits))
		{
			curr = bits->value;
			cat(out, curr);
		}

		cat(out, ".");
		cat(out, bits->value);
		out = command(name, out);
		system(out);
	}

	return 0;
}
