#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "edf.h"

int main(int argc, char const *argv[])
{
	std::string input;
	std::string output = "joe_emo.edf";
	EDF edf;

	/* READ DATA */
	if (argc == 0) {
		printf("Input: ");
		std::cin >> input;
	}
	else {
		input = argv[1];
	}

	/* PROCESS DATA */
	edf.readfile(input.c_str());

	/* WRITE DATA */
	edf.writefile(output.c_str());
	return 0;
}