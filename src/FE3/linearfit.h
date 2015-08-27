#pragma once
#include <oa.h>

LIST *read_lines(FILE* inlet)
{
    LIST *lines = list_new();
    char *line = read_from_file(inlet);

    while (line != NULL)
    {
        push(lines, line);
        line = read_from_file(inlet);
    }

    rewind(inlet);
    return lines;
}

double **treat_lines(LIST* lines)
{
    LIST *walker = lines->next;
    LIST *pair = NULL;
    double key = 0;
    double value = 0;
    double **table = malloc((list_length(lines) + 1) * sizeof(double*));
    int i = 0;

    printf("---\n");
    while (walker != NULL)
    {
        pair = list_strsplit(walker->value, ',');
        sscanf(list_get(pair, 0), "%lf", &key);
        sscanf(list_get(pair, 1), "%lf", &value);
        printf("%lf, %lf\n", key, value);
        table[i] = malloc(sizeof(double) * 2);
        table[i][0] = key;
        table[i][1] = value;

        list_free(pair);
        inc(walker);
        ++i;
    }

    table[i] = NULL;
    printf("...\n");
    return table;
}

void display_table(double **table)
{
    int i = 0;

    for (i = 0; table[i] != NULL; ++i)
    {
        printf("%ld: %ld\n", table[i][0], table[i][1]);
    }
}
