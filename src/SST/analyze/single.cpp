#include <iostream>
#include <fstream>
#include "ssrt-calculator.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    char const *input = argv[1];
    fstream inlet;
    string line;
    SSRT ssrt;

    inlet.open(input, std::fstream::in);
    getline(inlet, line); // file path
    getline(inlet, line); // columns
    ssrt.get_columns(line);
    ssrt.show_columns();
    inlet.close();

    return 0;
}
