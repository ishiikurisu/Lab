#include "edf.h"

char* get_input(int argc, char *argv[])
{
	char* input = NULL;

	if (argc == 0) {
		printf("Input: ");
		input =  read_from_file(stdin);
	}
	else {
		input = argv[1];
	}

	printf("%s: ", input);
	return input;
}

int main(int argc, char *argv[])
{
	char *input = get_input(argc, argv);
	EDF *edf = edf_read(input);
	return 0;
}