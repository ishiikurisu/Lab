#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include "ssrt-calculator.hpp"

int main(int argc, char **argv)
{
    std::fstream inlet;
    std::string line;
    SSRT ssrt;
    std::vector<unsigned int> times;
    std::vector<bool> answers;
    std::vector<std::string> procs;

    inlet.open(argv[1], std::fstream::in);
    std::getline(inlet, line);
    std::getline(inlet, line);
    ssrt.get_columns(line);
    std::getline(inlet, line);
    while (line.length() > 1)
    {
        ssrt.extract_data(line);
        std::getline(inlet, line);
    }
    inlet.close();

    times = ssrt.get_times();
    answers = ssrt.get_answers();
    procs = ssrt.get_procedures();
    for (int i = 0; i < 128; ++i)
    {
    	printf("%s %d %u\n", procs[i].c_str(), (answers[i])? 1 : 0, times[i]);
    }

    return 0;
}
