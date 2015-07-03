#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	FILE* inlet = fopen(argv[1], "r");
	int   read  = '\0';

	while (!feof(inlet))
	{
		fscanf(inlet, "%c", &read);
		printf("%d", read);
	}

	return 0;
}