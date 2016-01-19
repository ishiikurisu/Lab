#include <stdlib.h>
#include <src/flags.h>
#include <src/csv2ascii.h>

int main(int argc, char *argv[])
{
    OPTIONS *options = parse_flags(argc, argv);

    if (options->single)
    	csv2single(options->input, get_output(options->input));
    else
    	csv2multiple(options->input);

    free(options);
    return 0;
}
