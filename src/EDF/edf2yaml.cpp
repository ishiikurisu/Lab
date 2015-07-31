#include <iostream>
#include "edf.hpp"

int main(int argc, char const *argv[]) {
    EDF edf;
    std::string input;

    /* READ DATA */
	if (argc == 0) {
		std::cout << "Input: ";
		std::cin >> input;
	}
    else {
		input = argv[1];
	}

	/* PROCESS DATA */
	edf.read_file(input.c_str());

	/* WRITE DATA */
	edf.yaml();

    return 0;
}
