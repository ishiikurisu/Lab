#ifndef SSRT_CALC_H
#define SSRT_CALC_H
#define BUFFER_SIZE 256
#include <sstream>
#include <set>
#include <map>

class SSRT
{
    std::map<std::string, int> columns;
    std::set<std::string> needed_columns;
    unsigned int total_rt = 0;
    unsigned int successful_reactions = 0;
    unsigned int total_ssd = 0;
    unsigned int successful_stops = 0;
    unsigned int total_stops = 0;
    float ssrt = 0.0;
    float rt = 0.0;
    float ssd = 0.0;
    float inhib = 0.0;

    void associate(std::string, int);
    void get_needed_columns();

public:
    void SSRT() {};
    void ~SSRT() {};
    void get_columns(std::string);
    void extract_data(std::string);
    void analyze_data();
    float get_rt();
    float get_ssd();
    float get_ssrt();
    float get_inhibition();
};

void SSRT::get_needed_columns()
{
    
}

void SSRT::get_columns(std::string line)
{
    std::stringstream ss(line);
    char bit[BUFFER_SIZE];

    get_needed_columns();
    for (int column_number = 0; ss.getline(bit, BUFFER_SIZE, '\t'); ++column_number)
    {

    }
}

#undef BUFFER_SIZE
#endif /* end of include guard: SSRT_CALC_H */
