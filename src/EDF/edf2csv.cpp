#include <iostream>
#include "edf.hpp"

int main(int argc, char const *argv[]) {
    EDF edf;
    std::string input;

    if (argc == 0) {
        std::cout << "Input: ";
        std::cin >> input;
    }
    else {
        input = argv[1];
    }

    edf.read_file(input.c_str());
    edf.csv();

    return 0;
}
