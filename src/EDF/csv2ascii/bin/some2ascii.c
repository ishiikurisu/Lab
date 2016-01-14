#include <stdlib.h>
#include <stdio.h>
#include "some2ascii.h"

#define NCH (4)
char *IDS[] = {
    "FC5",
    "FC6",
    "T7",
    "T8"
};

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

void test_map(DICT *labels)
{
    char* value = NULL;
    int i;

    for (i = 0; i < NCH; ++i)
    {
        value = map_get(labels, IDS[i]);
        printf("%s: %s\n", IDS[i], value);
    }
}

CHANNEL **init_channels(char *keys[], DICT *values)
{
    CHANNEL **channels = (CHANNEL**) malloc(sizeof(CHANNEL*)* NCH);
    CHANNEL *channel = NULL;
    char *ascii = ".ascii";
    char *id = NULL;
    int i;

    for (i = 0; i < NCH; ++i)
    {
        channel = (CHANNEL*) malloc(sizeof(CHANNEL));

        id = keys[i];
        channel->id = id;
        channel->outlet = fopen(concat(id, ascii), "w");
        sscanf(map_get(values, id), "%d", &channel->position);

        channels[i] = channel;
    }

    return channels;
}

void polish_data(char *raw_line, CHANNEL **channels)
{
    static int first = 0;
    static int buffer = 0;
    CHANNEL *channel;
    LIST *line = NULL;
    int position;
    int i;

    line = list_strsplit(raw_line, ',');
    free(raw_line);
    for (i = 0; i < NCH; ++i)
    {
        channel = channels[i];
        position = channel->position;
        raw_line = list_get(line, position);
        if (first != 0)
            fprintf(channel->outlet, ", %s", raw_line);
        else
            fprintf(channel->outlet, "%s", raw_line);
    }

    list_free(line);
    if (first == 0) ++first;
    ++buffer;
    if (buffer == 256) {
        for (i = 0; i < NCH; ++i)
            fflush(channels[i]->outlet);
        buffer = 0;
    }
}
void mine_data(FILE *mine, CHANNEL **channels)
{
    char* raw_line = NULL;
    int i = 0;

    while ((raw_line = read_from_file(mine)))
    {
        polish_data(raw_line, channels);
    }

    for (i = 0; i < NCH; ++i)
        fclose(channels[i]->outlet);
}

int main(int argc, char *argv[])
{
    char* input = NULL;
    FILE* csv = NULL;
    DICT* labels = NULL;
    CHANNEL **channels = NULL;

    input = ask_for_name(argc, argv);
    csv = fopen(input, "r");
    labels = get_labels(csv);
    labels = get_needed_labels(labels, IDS);
    test_map(labels);

    channels = init_channels(IDS, labels);
    mine_data(csv, channels);

    fclose(csv);
    return 0;
}