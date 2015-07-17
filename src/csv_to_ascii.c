#include <stdlib.h>
#include <stdio.h>
#include "src/string.h"
#include "src/pair.h"
#include "src/list.h"
#include "src/coseq.h"
#include "src/dict.h"
#include "src/hashfunctions.h"

char *CHANNELS[] = {
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

DICT* process_labels(char* raw_data)
{
    LIST* labels = split(raw_data, ' ');
    LIST* label = NULL;
    DICT* enumaration = new_map(7, dumb);
    char* indexstr;
    int index = 0;

    for (label = labels->next; label != NULL; inc(label), ++index)
    {
        indexstr = itos(index);
        enumaration = put_in_map(enumaration, label->info, indexstr);
    }

    return enumaration;
}
DICT* process_column(char* column)
{
    DICT* labels = NULL;
    LIST* data = split(column, ':');
    char* key = get_from_list(data, 0);
    char* value = get_from_list(data, 1);

    if (compare(key, " labels") == EQUAL) {
        labels = process_labels(value);
    }

    return labels;
}
DICT* get_labels(FILE* csv)
{
    char* header = read_from_file(csv);
    LIST* columns = split(header, ',');
    LIST* column = NULL;
    DICT* labels = NULL;

    for (column = columns->next; column != NULL && labels == NULL; inc(column))
    {
        labels = process_column(column->info);
    }

    return labels;
}

void test_map(DICT* map)
{
    char* value = NULL;
    int i;

    for (i = 0; i < 4; ++i)
    {
        value = get_from_map(map, CHANNELS[i]);
        printf("%s: %s\n", CHANNELS[i], value);
    }
}
int main(int argc, char *argv[])
{
    char* input = NULL;
    FILE* csv = NULL;
    DICT* labels = NULL;

    input = ask_for_name(argc, argv);
    csv = fopen(input, "r");
    labels = get_labels(csv);
    test_map(labels);
    /* labels = get_needed_labels(labels); */

    return 0;
}
