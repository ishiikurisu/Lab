#include <stdlib.h>
#include <stdio.h>
#include <oa.h>
#include <buffer.h>
#include "csv2ascii.h"

char* ask_for_name(int argc, char *argv[])
{
    return (argc == 1)? read_from_file(stdin) : argv[1];
}

LIST *process_header(BUFFER *csv)
{
    char *header = buffer_read_line(csv);
    LIST *fields = list_strsplit(header, ',');
    return get_labels(get_labels_field(fields));
}

void process_channels(BUFFER *csv, LIST *channels)
{
    /* char comment[] = "this string is the objective!"; */
    BUFFER **buffers = get_buffers_from_channels(channels);
    char *current_line = buffer_read_line(csv);

    /*
    BUFFER **buffer = buffers;
    while (*buffer != NULL)
    {
        printf("@ %s\n", (*buffer)->source);
        buffer++;
    }
    */

    current_line = buffer_read_line(csv);
    while (current_line != NULL)
    {
        buffers = treat_line(current_line, buffers);
        current_line = buffer_read_line(csv);
    }

    close_all_buffers(buffers);
    return;
}

int main(int argc, char *argv[])
{
    char *input = NULL;
    BUFFER *csv = NULL;
    LIST *channels = NULL;

    input = ask_for_name(argc, argv);
    csv = buffer_new(input, "r", 2048);

    channels = process_header(csv);
    process_channels(csv, channels);
    
    buffer_close(csv);
    return 0;
}
