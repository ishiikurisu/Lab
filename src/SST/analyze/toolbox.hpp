#pragma once
#include <string>
#include <sstream>
#include <vector>

std::string tidy_string(std::string input)
{
    std::string output;

    for (unsigned int i = 0; i < input.length(); ++i)
        if (input[i] != 0)
            output += input[i];

    return output;
}

std::vector<std::string> split(std::string inlet, char divider)
{
    std::vector<std::string> outlet;
    std::stringstream ss(inlet);
    std::string item;

    while (std::getline(ss, item, divider))
        outlet.push_back(tidy_string(item));

    return outlet;
}