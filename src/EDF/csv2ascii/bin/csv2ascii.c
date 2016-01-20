#include <stdlib.h>
#include <flags.h>
#include <csv2ascii.h>

int main(int argc, char *argv[])
{
    OPTIONS *options = parse_flags(argc, argv);

    printf("%s to %s\n", options->input_file, 
                         get_output(options->input_file));
    if (options->single)
      csv2single(options->input_file, get_output(options->input_file));
    /*else
      csv2multiple(options->input_file);*/

    free(options);
    return 0;
}
