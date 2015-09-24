#pragma once
#include <fstream>
#include "ssrt-calculator.hpp"

void analyze(char const *input)
{
    std::fstream inlet;
    std::string line;
    SSRT ssrt;

    inlet.open(input, std::fstream::in);
    std::getline(inlet, line); // file path
    std::getline(inlet, line); // columns
    ssrt.get_columns(line);
    for (int l = 0; l < 8; ++l)
        std::getline(inlet, line);

    while (true)
    {
        try {
            std::getline(inlet, line);
            ssrt.extract_data(line);
        }
        catch (...) {
            break;
        }
    }
    ssrt.analyze_data();

    ssrt.get_rt();
    ssrt.get_ssd();
    std::cout << "SSRT: " << ssrt.get_ssrt() << std::endl;
    std::cout << "\u0025I: " << ssrt.get_inhibition() << std::endl;

    inlet.close();
}
