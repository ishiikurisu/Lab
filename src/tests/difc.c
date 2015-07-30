#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	unsigned long long c = 0;
	FILE* f1 = NULL;
	FILE* f2 = NULL;

	if (argc < 2) {
		printf("TWO FILES PLEASE\n");
		return 1;
	}

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");
	while (!feof(f1) && !feof(f2))
		if (fgetc(f1) != fgetc(f2))
			c++;
	fclose(f1);
	fclose(f2);

	printf("%d\n", c);
	return 0;
}