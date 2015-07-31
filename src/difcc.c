#include <stdlib.h>
#include <stdio.h>
#include "oa.h"

int main(int argc, char const *argv[])
{
	unsigned long long i = 0;
	LIST* where = new_list();
	FILE* f1 = NULL;
	FILE* f2 = NULL;

	if (argc < 2) {
		printf("TWO FILES PLEASE\n");
		return 1;
	}

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");
	while (!feof(f1) && !feof(f2))
	{
		if (fgetc(f1) != fgetc(f2))
			push(where, itos(i));
		++i;
	}

	fclose(f1);
	fclose(f2);
	printf("%s\n", list_yaml(where));
	list_free(where);

	return 0;
}