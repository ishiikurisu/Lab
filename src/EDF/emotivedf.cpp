#include <iostream>
#include "edf.hpp"

int main(int argc, char const *argv[])
{
	std::string input;
	std::string output;
	EDF edf;

	/* READ DATA */
	if (argc == 0) {
		std::cout << "Input: ";
		std::cin >> input;
		std::cout << "Output: ";
		std::cin >> output;
	}
	else if (argc == 1) {
		input = argv[1];
		std::cout << "Output: ";
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