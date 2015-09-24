#pragma once
#include <fstream>
#include <iomanip>
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

    std::getline(inlet, line);
    while (line.length() > 1)
    {
        ssrt.extract_data(line);
        std::getline(inlet, line);
    }
    ssrt.analyze_data();

    std::cout << "RT: " << ssrt.get_rt() << std::endl;
    std::cout << "SSD: " << ssrt.get_ssd() << std::endl;
    std::cout << "SSRT: " << ssrt.get_ssrt() << std::endl;
    std::cout << "\u0025I: " << (ssrt.get_inhibition() * 100) << std::endl;

    inlet.close();
}
