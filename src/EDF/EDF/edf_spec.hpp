#include <map>
#include <vector>
#include <string>
#include "auxiliar.hpp"

std::map<std::string, size_t> EDF_SPEC;
std::vector<std::string> EDF_SPECS;
std::string EDF_PLUS = "EDF+";

void EDF_SETUP()
{
	FILE* specs = fopen("edf_specs.txt", "r");
	std::vector<std::string> pair;
	std::string key;
	int temp;
	size_t value;
	std::string line;

	line = read_line_from_file(specs);
	while (line.length() > 0)
	{
		pair = split(line, '=');
		key = pair[0];
		line = pair[1];

		sscanf(line.c_str(), "%d", &temp);
		value = (size_t) temp;
		EDF_SPECS.push_back(key);
		EDF_SPEC[key] = value;

		line = read_line_from_file(specs);
	}

	fclose(specs);
}
