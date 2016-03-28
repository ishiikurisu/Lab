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

void write_annotations(EDFP edfp, const char *input)
{
	const char *output = generate_output(input, ".txt");
	FILE *outlet = fopen(output, "w");

	if (outlet == NULL) outlet = stdout;
	fprintf(outlet, "--- # Annotations\n%s\n...\n", edfp.get_annotations());

	fclose(outlet);
}

int main(int argc, char const *argv[])
{
	const char *input = argv[1];
	EDFP edfp;

	edfp.read_file(input);
	edfp.csv(generate_output(input, ".csv"));
	write_annotations(edfp, input);

	return 0;
}