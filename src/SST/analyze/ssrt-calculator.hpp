#ifndef SSRT_CALC_H
#define SSRT_CALC_H
#define BUFFER_SIZE 256
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stdio.h>
#include "toolbox.hpp"

class SSRT
{
    std::map<std::string, int> columns;
    std::set<std::string> needed_columns;
    std::vector<unsigned int> times;
    std::vector<bool> answers;
    std::vector<std::string> procedures;
    unsigned int total_rt;
    unsigned int successful_reactions;
    unsigned int total_reactions;
    unsigned int total_ssd;
    unsigned int successful_stops;
    unsigned int total_stops;
    double ssrt;
    double rt;
    double ssd;
    double inhib;
	double aus;

    void associate(std::string, int);
    void get_needed_columns();

public:
    SSRT();
    void show_columns();
    void get_columns(std::string);
    void extract_data(std::string);
    void analyze_data();
    double get_rt(bool);
    double get_ssd(bool);
    double get_ssrt();
    double get_inhibition();
	double get_ausences();
    std::vector<unsigned int> get_times();
    std::vector<bool> get_answers();
    std::vector<std::string> get_procedures();
};

/********************
* PRIVATE FUNCTIONS *
********************/

/* check if a column should not be associated with this app */
void SSRT::associate(std::string column, int number)
{
    if (needed_columns.count(column) > 0)
        columns[column] = number;
}

/* reads the file "variables.txt" and
get the needed columns for the calculations */
void SSRT::get_needed_columns()
{
    /* BE SURE TO KEEP THE "variables" FILE UPDATED */
    std::fstream fs;
    char name[BUFFER_SIZE];

    fs.open("variables", std::fstream::in);
    while (fs.getline(name, BUFFER_SIZE))
        needed_columns.insert(name);
    fs.close();
}

/*******************
* PUBLIC FUNCTIONS *
*******************/

SSRT::SSRT()
{
    total_rt = 0;
    successful_reactions = 0;
    total_reactions = 0;
    total_ssd = 0;
    successful_stops = 0;
    total_stops = 0;
    ssrt = 0;
    rt = 0;
    ssd = 0;
    inhib = 0;

    get_needed_columns();
}

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
    std::vector<std::string> bits = split(line, '\t');
    std::vector<std::string>::iterator it;
    int column_number = 0;

    for (it = bits.begin(); it != bits.end(); ++column_number, ++it)
        associate((*it), column_number);
}

/* analyzes a line of the data file to extract the needed
information for updates */
void SSRT::extract_data(std::string line)
{
    std::vector<std::string> bits = split(line, '\t');
    std::string srt = "PressStimulus.RT";
    std::string srtacc = "PressStimulus.ACC";
    std::string sssd = "VisualStimulus.Duration";
    std::string sssdacc = "SoundStimulus.ACC";
    std::string ssdrt = "SoundStimulus.RT";
    std::string procedure = "Procedure[Trial]";
    std::string bit;
    unsigned int ct; // current time
    unsigned int cacc; // current accuracy

    procedure = bits.at(columns[procedure]);
    if (procedure.compare("PressProc") == 0) {
        /* RT */
        bit = bits.at(columns[srt]);
        sscanf(bit.c_str(), "%u", &ct);
        bit = bits.at(columns[srtacc]);
        sscanf(bit.c_str(), "%u", &cacc);

        ++total_reactions;
        successful_reactions += cacc;
        total_rt += ct;

        procedures.push_back(procedure);
        times.push_back(ct);
        answers.push_back((cacc)? true : false);
    }
    else if (procedure.compare("NotPressProc") == 0) {
        /* SSD */
        bit = bits.at(columns[sssd]);
        sscanf(bit.c_str(), "%u", &ct);
        bit = bits.at(columns[sssdacc]);
        sscanf(bit.c_str(), "%u", &cacc);

        ++total_stops;
        successful_stops += cacc;
        total_ssd += (cacc)? ct : 0;

        bit = bits.at(columns[ssdrt]);
        sscanf(bit.c_str(), "%d", &ct);
        procedures.push_back(procedure);
        times.push_back(ct);
        answers.push_back((cacc)? true : false);
    }
}

void SSRT::analyze_data()
{
    rt = (total_rt + 0.0) / total_reactions;
    ssd = (total_ssd + 0.0) / successful_stops;
    inhib = (successful_stops + 0.0) / total_stops;
}

double SSRT::get_rt(bool w = false)
{
    if (w) {
        std::cout << "RT:\n";
        std::cout << "  TOTAL RT: " << total_rt << "\n";
        std::cout << "  REACTIONS: " << successful_reactions << " from " << total_reactions << "\n";
        std::cout << "  MEAN RT: " << rt << std::endl;
    }

    return rt;
}

double SSRT::get_ssd(bool w = false)
{
    if (w) {
        std::cout << "SSD:\n";
        std::cout << "  TOTAL SSD: " << total_ssd << "\n";
        std::cout << "  STOPS: " << successful_stops << " from " << total_stops << "\n";
        std::cout << "  MEAN SSD: " << ssd << std::endl;
    }

    return ssd;
}

double SSRT::get_inhibition()
{
    return inhib;
}

double SSRT::get_ssrt()
{
    return rt - ssd;
}

double SSRT::get_ausences()
{
	return ((double) total_reactions - successful_reactions) / total_reactions;
}

std::vector<unsigned int> SSRT::get_times()
{
    return times;
}

std::vector<bool> SSRT::get_answers()
{
    return answers;
}

std::vector<std::string> SSRT::get_procedures()
{
    return procedures;
}

#undef BUFFER_SIZE
#endif /* end of include guard: SSRT_CALC_H */
