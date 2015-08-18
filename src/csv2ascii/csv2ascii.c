#include <stdlib.h>
#include <stdio.h>
#include <oa.h>
#include <buffer.h>
#include "csv2ascii.h"

char* ask_for_name(int argc, char *argv[])
{
    char* answer = "";

    if (argc == 1) {
        answer = read_from_file(stdin);
    }
    else {
        answer = argv[1];
    }

    return answer;
}

LIST *process_header(FILE *csv)
{
    char *header = read_from_file(csv);
    LIST *fields = list_strsplit(header, ',');
    return get_labels(get_labels_field(fields));
}

/*
void process_channels(FILE *csv, LIST *channels)
{
    char comment[] = "this string is the objective!";
    BUFFER **buffers = get_buffers_from_channels(channels);


    return;
}
*/

int main(int argc, char *argv[])
{
    char *input = NULL;
    FILE *csv = NULL;
    LIST *channels = NULL;

    input = ask_for_name(argc, argv);
    csv = fopen(input, "r");

    channels = process_header(csv);
    printf("%s\n", list_yaml(channels));
    /* process_channels(csv, channels); */
    
    fclose(csv);

    return 0;
}
