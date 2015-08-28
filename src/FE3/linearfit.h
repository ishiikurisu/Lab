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

float **treat_lines(LIST* lines)
{
    LIST *walker = lines->next;
    LIST *pair = NULL;
    float key = 0;
    float value = 0;
    float **table = malloc((list_length(lines) + 1) * sizeof(float*));
    int i = 0;

    while (walker != NULL)
    {
        pair = list_strsplit(walker->value, ',');
        sscanf(list_get(pair, 0), "%f", &key);
        sscanf(list_get(pair, 1), "%f", &value);
        table[i] = malloc(sizeof(float) * 2);
        table[i][0] = key;
        table[i][1] = value;

        list_free(pair);
        inc(walker);
        ++i;
    }

    table[i] = NULL;
    return table;
}

void display_table(float **table)
{
    int i = 0;

    for (i = 0; table[i] != NULL; ++i)
    {
        printf("%f: %f\n", table[i][0], table[i][1]);
    }
}
