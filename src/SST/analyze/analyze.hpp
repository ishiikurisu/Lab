#pragma once
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "ssrt-calculator.hpp"

/* returns an array containing 
the RT, SSD, SSRT and %INHIB of a file */
double* analyze(char const *input, bool shall_write = false)
{
    double *outlet = (double*) malloc(4*sizeof(double));
    std::fstream inlet;
    std::string line;
    SSRT ssrt;

    inlet.open(input, std::fstream::in);
    std::getline(inlet, line); // file path
    std::getline(inlet, line); // columns
    ssrt.get_columns(line);

    std::getline(inlet, line);
    while (line.length() > 1)
    {
        ssrt.extract_data(line);
        std::getline(inlet, line);
    }
    ssrt.analyze_data();

    if (shall_write) {
        std::cout << std::fixed << std::setprecision(3);
        std::cout << "RT: " << ssrt.get_rt() << std::endl;
        std::cout << "SSD: " << ssrt.get_ssd() << std::endl;
        std::cout << "SSRT: " << ssrt.get_ssrt() << std::endl;
        std::cout << "%I: " << (ssrt.get_inhibition() * 100) << std::endl;
    }

    inlet.close();
    outlet[0] = ssrt.get_rt();
    outlet[1] = ssrt.get_ssd();
    outlet[2] = ssrt.get_ssrt();
    outlet[3] = ssrt.get_inhibition();

    return outlet;
}
