#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "edf.h"

int main(int argc, char const *argv[])
{
	std::string input;
	std::string output;
	EDF edf;

	/* READ DATA */
	if (argc == 0) {
		printf("Input: ");
		std::cin >> input;
		printf("Output: ");
		std::cin >> output;
	}
	else if (argc == 1) {
		input = argv[1];
		printf("Output: ");
		std::cin >> output;
	}
	else {
		input = argv[1];
		output = argv[2];
	}

	/* PROCESS DATA */
	edf.read_file(input.c_str());

	/* WRITE DATA */
	edf.write_file(output.c_str());
	return 0;
}