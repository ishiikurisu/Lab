#include <stdlib.h>
#include <stdio.h>
#include "joe_pack.h"
#include "csv_to_ascii.h"

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

    for (i = 0; i < 4; ++i)
    {
        value = get_from_map(labels, IDS[i]);
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
        sscanf(get_from_map(values, id), "%d", &channel->position);

        channels[i] = channel;
    }

    return channels;
}

void polish_data(char *raw_line, CHANNEL **channels)
{
    static int buffer = 0;
    CHANNEL *channel;
    LIST *line = NULL;
    int position;

    line = split(raw_line, ',');
    free(raw_line);
    for (i = 0; i < NCH; ++i)
    {
        free(raw_line);
        channel = channels[i];
        position = channel->position;
        raw_line = get_from_list(line, position);
        fprintf(channel->outlet, "%s", raw_line);
        free_list(line);
    }

    ++buffer;
    if (buffer == 256) {
        for (i = 0; i < NCH; ++i)
            fflush(channels[i]->outlet);
        buffer = 0;
    }
}
void mine_data(FILE *mine, CHANNEL **channels)
{
    CHANNEL* channel = NULL;
    char* raw_line = NULL;
    LIST* line = NULL;
    int position = -1;
    int i = 0;

    raw_line = read_from_file(mine);
    polish_data();

    while (raw_line = read_from_file(mine))
    {
        line = split(raw_line, ',');
        free(raw_line);
        for (i = 0; i < NCH; ++i)
        {
            channel = channels[i];
            position = channel->position;
            raw_line = get_from_list(line, position);
            fprintf(channel->outlet, ", %s", raw_line);
            free_list(line);
        }
    }

    /* close data buckets */
    for (i = 0; i < NCH; ++i)
        fclose(channel->outlet);
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

    channels = init_channels(IDS, labels);
    mine_data(csv, channels);

    fclose(csv);
    return 0;
}