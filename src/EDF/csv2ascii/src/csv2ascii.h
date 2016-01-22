#ifndef CSV_TO_ASCII
#define CSV_TO_ASCII
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "buffer.h"

/*
# Common functions

+ LIST* parse_header(char *line);
+ LIST* parse_line(char *line);
+ void write_line(BUFFER *outlet, LIST *line)
*/

char* are_these_labels(char *field)
{
    char *clean = tidy_string(field);
    char *temp = NULL;

    if (match("labels", clean))
        temp = substring(clean, 7, strlen(clean)),
        free(clean),
        clean = temp;
    else
        free(clean),
        clean = NULL;

    return clean;
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
    LIST *values = NULL;
    LIST *value = NULL;
    char *temp = NULL;

    if (line == NULL)
        return NULL;

    values = list_strsplit(line, ',');
    for (value = values->next; value != NULL; inc(value))
        temp = tidy_string(value->value),
        free(value->value),
        value->value = temp;

    return values;
}

/**
 * writes a new ASCII line in the selected buffer
 * @param outlet joe_buffer for the output file
 * @param stuff  joe_list containing the CSV columns
 */
void write_line(BUFFER *outlet, LIST *stuff)
{
    LIST *item = stuff->next;

    buffer_write(outlet, item->value);
    for (inc(item); item != NULL; inc(item))
        buffer_write(outlet, concat(ctos(' '), item->value));
    buffer_write(outlet, "\n");
}

/*
# Main functions

+ void csv2single(char *input);
+ void csv2multiple(char *input);
*/

/**
 * Translates a `csv` file to the ascii format
 * @param input  csv file name
 * @param output ascii file name
 */
#include "csv2ascii/single.h"
void csv2single(char *input)
{
    BUFFER *inlet = buffer_new(input, "r", 256);
    BUFFER *outlet = buffer_new(single_get_output(input), "w", 256);
    LIST *line = parse_header(buffer_readline(inlet));

    while ((line = parse_line(buffer_readline(inlet))) != NULL)
        write_line(outlet, line),
        list_free(line);

    buffer_close(inlet);
    buffer_close(outlet);
}

/**
 * separates a `csv` file into many `ascii` files, one for each signal.
 * WARNING: this function is currently crashing.
 * @param input a c_string naming the `csv` file
 */
#include "csv2ascii/multiple.h"
void csv2multiple(char *input)
{
    BUFFER *inlet = buffer_new(input, "r", 256);
    LIST *line = parse_header(buffer_readline(inlet));
    BUFFER **outlets = multiple_buffers_new(input, line);

    while ((line = parse_line(buffer_readline(inlet))) != NULL)
        multiple_write_lines(outlets, line),
        list_free(line);

    buffer_close(inlet);
    multiple_buffers_close(outlets);
}

#endif
