#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include "emotiv.h"
#include "edfp.h"

const string USAGE = "USAGE: ";

int main(int argc, char const *argv[])
{
	string input_name;
	string output_name;
	FILE* input_file;
	FILE* output_file;	
	EMOTIV* emotiv_data;

	/* READ DATA */
	if (argc == 0) {
		printf("Input: ");
		std::cin >> input_name;
		printf("Output: ");
		std::cin >> output_name;
	}
	else {
		input_name = argv[1];
		output_name = argv[2];
	}

	/* PROCESS DATA */
	input_file = fopen(input_name, "r");
	emotiv_data = emotiv_readfile(input_file);
	fclose(input_file);

	/* WRITE DATA */
	output_file = fopen(output_name, "w");
	emotiv_writefile(emotiv_data);
	fclose(output_file);
	
	return 0;
}