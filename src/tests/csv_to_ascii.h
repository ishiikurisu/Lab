#include "joe_pack.h"
#include "src/hashfunctions.h"

typedef struct
{
	char *id;
	FILE *outlet;
	int position;

} CHANNEL;

DICT* process_labels(char* raw_data)
{
    LIST* labels = split(raw_data, ' ');
    LIST* label = NULL;
    DICT* enumeration = new_map(7, dumb);
    char* indexstr;
    int index = 0;

    for (label = labels->next; label != NULL; inc(label), ++index)
    {
        indexstr = itos(index);
        enumeration = put_in_map(enumeration, label->info, indexstr);
    }

    return enumeration;
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

DICT* get_needed_labels(DICT *all, char **channels)
{
    DICT *labels = new_map(3, dumb);
    char *key, *value;
    int i = 0;

    for (i = 0; i < 4; ++i)
    {
        key = channels[i];
        value = get_from_map(all, key);
        labels = put_in_map(labels, key, value);
    }

    return labels;
}

