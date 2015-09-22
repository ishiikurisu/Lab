#include <oa.h>
#include "csv2fullascii.h"

char* ask_for_name(int argc, char *argv[])
{
	static int arg = 0;
	return (argc < arg++)? read_from_file(stdin) : argv[1];
}

int main(int argc, char *argv[])
{
	csv2fullascii(ask_for_name(argc, argv));
	return 0;
}