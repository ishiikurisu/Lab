#include <iostream>
#include "edf.hpp"

int main(int argc, char const *argv[]) {
    EDF edf;
    std::string input;
    std::string output;

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

    edf.read_file(input.c_str());
    edf.csv(output.c_str());

    return 0;
}
