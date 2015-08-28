#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <oa.h>
#include "linearfit.h"

char *get_name(int argc, char *argv[])
{
    char *input_name = NULL;

    if (argc < 1) {
        printf("Input file: ");
        input_name = read_from_file(stdin);
    }
    else {
        input_name = argv[1];
    }

    return input_name;
}

float **read_table(FILE *inlet)
{
    LIST *lines = read_lines(inlet);
    float **table = treat_lines(lines);
    list_free(lines);
    return table;
}

int main(int argc, char *argv[]) {
    char *input = NULL;
    FILE *inlet = NULL;
    float **table = NULL;

    input = get_name(argc, argv);
    inlet = fopen(input, "r");
    table = read_table(inlet);
    fclose(inlet);

    display_table(table);

    return 0;
}
