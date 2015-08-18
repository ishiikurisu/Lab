#pragma once
#include <oa.h>

char* get_labels_field(LIST *fields)
{
	LIST *walker = fields->next;
	LIST *field = NULL;
	char *key = NULL;
	char *value = NULL;

	while (walker != NULL)
	{
		field = list_strsplit(walker->value, ':');
		key = tidy_string(list_get(field, 0));
		value = list_get(field, 1);

		if (compare(key, "labels") == EQUAL) {
			walker = NULL;
		}
		else {
			value = NULL;
			inc(walker);
		}
	}

	return value;
}

LIST* get_labels(char *fields)
{
	return list_strsplit(fields, ' ');
}

/*
BUFFER** get_buffers_from_channels(LIST* channels)
{
	return NULL;
}
*/