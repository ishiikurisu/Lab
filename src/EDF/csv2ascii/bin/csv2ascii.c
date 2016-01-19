#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <buffer.h>
#include <src/flags.h>
#include <src/csv2ascii.h>

int main(int argc, char const *argv[])
{
    OPTIONS *options = parse_flags(argc, argv);



    free(options);
    return 0;
}
