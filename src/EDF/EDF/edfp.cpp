#include "iostream"
#include "edfp.hpp"

const char* get_input(int argc, const char **argv)
{
	return (argc > 1)? argv[1] : NULL;
}

int main(int argc, char const *argv[])
{
	EDFP edf;

	edf.read_file(get_input(argc, argv));

	return 0;
}