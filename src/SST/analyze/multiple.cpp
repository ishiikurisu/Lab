#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include "analyze.hpp"

double mean(std::vector<double> vec)
{
	std::vector<double>::iterator it;
	double sum = 0;

	for (it = vec.begin(); it != vec.end() ; ++it)
		sum += *it;

	return sum / vec.size();
}

double variance(std::vector<double> vec)
{
	std::vector<double>::iterator it;
	double m = mean(vec);
	double sum = 0;

	for (it = vec.begin(); it != vec.end() ; ++it)
		sum += pow(m - (*it), 2);

	return sum / vec.size();
}

double sd(std::vector<double> vec)
{
	return sqrt(variance(vec));
}


int main(int argc, char const *argv[])
{
	std::string inlet;
	std::vector<double> rt;
	std::vector<double> ssd;
	std::vector<double> ssrt;
	std::vector<double> inhib;
	double *raw_data;

	/* READ DATA */
	while (std::getline(std::cin, inlet))
	{
		if (inlet.size() > 1) {
			raw_data = analyze(inlet.c_str());
			rt.push_back(raw_data[0]);
			ssd.push_back(raw_data[1]);
			ssrt.push_back(raw_data[2]);
			inhib.push_back(raw_data[3]);
		}
	}

	/* WRITE PROCESSED DATA */
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "<RT>: " << mean(rt) << "+-" << sd(rt) << std::endl;
	std::cout << "<SSD>: " << mean(ssd) << "+-" << sd(ssd)  << std::endl;
	std::cout << "<SSRT>: " << mean(ssrt) << "+-" << sd(ssrt)  << std::endl;
	std::cout << "<%%I>: " << mean(inhib) << "+-" << sd(inhib)  << std::endl;

	return 0;
}