#include "iostream"
#include "edfp.hpp"

const char* get_arg(int argc, const char **argv)
{
    static int arg = 0;
	return (argc > ++arg)? argv[arg] : NULL;
}

int main(int argc, char const *argv[])
{
	EDFP edf;

	edf.read_file(get_arg(argc, argv));
    edf.csv(get_arg(argc, argv));

	return 0;
}
