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

#define ERROR (0.000001)
double _sq(double x) { return x * x; }
double _av(double x, double y) { return (x + y)/2.0; }
double _abs(double x) { return (x > 0)? x : -x; }
double _ge(double g, double x) { return _abs(x - _sq(g)) < ERROR; }
double _imp(double g, double x) {return _av(g, x/g); }
double _ni(double g, double x) { return (_ge(g, x))? g : _ni(_imp(g, x), x); }
double newton_sqrt(double x) { return _ni(1.0, x); }
#undef ERROR