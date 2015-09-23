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
    unsigned int total_rt;
    unsigned int successful_reactions;
    unsigned int total_reactions;
    unsigned int total_ssd;
    unsigned int successful_stops;
    unsigned int total_stops;
    float ssrt;
    float rt;
    float ssd;
    float inhib;

    void associate(std::string, int);
    void get_needed_columns();

public:
    SSRT() {};
    ~SSRT() {};
    void show_columns();
    void get_columns(std::string);
    void extract_data(std::string);
    void analyze_data();
    float get_rt();
    float get_ssd();
    float get_ssrt();
    float get_inhibition();
};

/********************
* PRIVATE FUNCTIONS *
********************/

/* check if a column should of not be associated with this app */
void SSRT::associate(std::string column, int number)
{
    if (needed_columns.count(column) > 0)
        columns[column] = number;
}

/* reads the file "variables.txt" and
get the needed columns for the calculations */
void SSRT::get_needed_columns()
{
    /* BE SURE TO KEEP THE "variables.txt" file updated */
    std::fstream fs;
    char name[BUFFER_SIZE];

    fs.open("variables.txt", std::fstream::in);
    while (fs.getline(name, BUFFER_SIZE))
        needed_columns.insert(name);
    fs.close();
}

/*******************
* PUBLIC FUNCTIONS *
*******************/

void SSRT::show_columns()
{
    std::set<std::string>::iterator it;

    for (it = needed_columns.begin(); it != needed_columns.end(); ++it)
        std::cout << *it << ": " << columns[*it] << std::endl;
}

/* reads the line with the column names and associates
the needed columns with their respective number */
void SSRT::get_columns(std::string line)
{
    std::stringstream ss(line);
    char bit[BUFFER_SIZE];

    get_needed_columns();
    for (int column_number = 0; ss.getline(bit, BUFFER_SIZE, '\t'); ++column_number)
        associate(bit, column_number);
}

/* analyzes a line of the data file to extract the needed
information for updates */
void extract_data(std::string line)
{

}

#undef BUFFER_SIZE
#endif /* end of include guard: SSRT_CALC_H */
