#include <stdlib.h>
#include <flags.h>
#include <csv2ascii.h>

int main(int argc, char *argv[])
{
    OPTIONS *options = parse_flags(argc, argv);

    if (options->single)
      csv2single(options->input_file);
    /*else
      csv2multiple(options->input_file);*/

    free(options);
    return 0;
}
