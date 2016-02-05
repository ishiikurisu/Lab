#include <iostream>
#include "edf.hpp"

std::string prompt(char *msg, int argc, char const *argv[])
{
	static int arg = 1;
	std::string query;

	if (argc < arg) {
		std::cout << msg;
		std::cin >> query;
	}
    else {
		query = argv[arg];
	}

	arg++;
	return query;
}

int main(int argc, char const *argv[]) {
    EDF edf;
    std::string input = prompt("Input: ", argc, argv);
    std::string output = prompt("Output: ", argc, argv);

    /* PROCESS DATA */
	edf.read_file(input.c_str());

	/* WRITE DATA */
	edf.yaml(output.c_str());

    return 0;
}
