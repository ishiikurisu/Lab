#include "edfp/edfp.hpp"

int main(int argc, char const *argv[])
{
	EDFP edfp;

	edfp.read_file(argv[1]);
	edfp.csv();
	printf("\n--- # Annotations\n%s\n...\n", 
		   edfp.get_annotations());

	return 0;
}