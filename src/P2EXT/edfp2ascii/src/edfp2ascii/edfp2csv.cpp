#include "edfp/edfp.hpp"

const char* generate_output(const char *input, const char *extension) 
{
	std::string inlet = input;
	std::string outlet;
	int offset = inlet.length() - 1;

	while (inlet.at(offset) != '.')
		offset--;

	for (int i = 0; i < inlet.length() - offset; ++i)
		outlet += inlet.at(i);
	outlet += extension;

	return outlet.c_str();
}

int main(int argc, char const *argv[])
{
	const char *input = argv[1];
	EDFP edfp;

	printf("%s\n", input); fflush(stdout);
	edfp.read_file(input, true);
	edfp.csv(generate_output(input, ".csv"));
	fprintf(fopen(generate_output(input, 
		                          ".txt"), 
	              "w"), 
		    "--- # Annotations\n%s\n...\n", 
		    edfp.get_annotations());

	return 0;
}