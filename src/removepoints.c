#include <stdio.h>
#include <stdlib.h>
#include "joepack/string.h"
#include "joepack/list.h"

char* command(char *input, char *output)
{
	char *comm = "move ";

	cat(comm, input);
	cat(comm, " ");
	cat(comm, output);

	return comm;
}

char* read_from_file(FILE* fp)
{
    char* output = NULL;
    char  to_add = '\0';

    do {
        output = "";
        fscanf(fp, "%c", &to_add);

        while (to_add != '\0' && to_add != '\n')
        {
            output = concat(output, to_array(to_add));
            fscanf(fp, "%c", &to_add);
        }

    } while (strlen(output) == 0 && !feof(fp));

    if (strlen(output) == 0) output = NULL;

    return output;
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