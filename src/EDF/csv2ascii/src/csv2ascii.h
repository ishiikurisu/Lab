#ifndef CSV_TO_ASCII
#define CSV_TO_ASCII
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <buffer.h>

/* 
# Common functions

+ LIST* parse_header(char *line);
+ LIST* parse_line(char *line);
*/

char* are_these_labels(char *field)
{
    char *clean = tidy_string(field);
    return (match("labels", clean))? substring(clean, 7, strlen(clean)) : NULL;
}

/**
 * Extract the 'labels' field as a list from the CSV header
 * @param  line   a c_string containing the file's header
 * @return fields a joe_list containing the label for each signal
 */
LIST* parse_header(char *line)
{
    LIST *fields = list_strsplit(line, ',');
    LIST *field = NULL;
    char *labels = NULL;

    for (field = fields->next; field != NULL && labels == NULL; inc(field))
        labels = are_these_labels(field->value);

    list_free(fields);
    return list_strsplit(labels, ' ');
}

/**
 * Separates the values in a CSV line
 * @param  line   a CSV file line in c_str format
 * @return values a joe_string containing each value in 
 */
LIST *parse_line(char *line)
{
    LIST *values = list_strsplit(line, ',');
    LIST *value = NULL;

    for (value = values->next; value != NULL; inc(value))
        value->value = tidy_string(value->value);

    return values;
}

/*
# Main functions

+ void csv2single(const char *input, const char *output);
+ void csv2multiple(const char *input);
*/

/**
 * Translates a `csv` file
 * @param input  csv file name
 * @param output ascii file name
 */
void csv2single(char *input, char *output) 
{
    BUFFER *inlet = buffer_new(input, "r", 256);
    BUFFER *outlet = buffer_new(output, "w", 256);
    LIST *line = parse_header(buffer_readline(inlet));

    for (line = line->next; line != NULL; inc(line))
        printf("%s\n", line->value);

    buffer_close(inlet);
    buffer_close(outlet);
}

void csv2multiple(const char *input)
{
    return;
}

#endif