#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include "edf.h"

int main(int argc, char const *argv[])
{
	std::string input_name;
	std::string output_name = "joe_emo.edf";
	FILE* input_file;
	FILE* output_file;	
	EDF edf;

	/* READ DATA */
	if (argc == 0) {
		printf("Input: ");
		std::cin >> input_name;
	}
	else {
		input_name = argv[1];
	}

	/* PROCESS DATA */
	input_file = fopen(input_name.c_str(), "r");
	edf.readfile(input_file);
	fclose(input_file);

	/* WRITE DATA */
	output_file = fopen(output_name.c_str(), "a");
	edf.writefile(output_file);
	fclose(output_file);
	return 0;
}