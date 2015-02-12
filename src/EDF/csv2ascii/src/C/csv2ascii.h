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

BUFFER* populate_buffer(LIST *channel)
{
	return buffer_new(concat(channel->value, ".ascii"), "w", 2048);
}

BUFFER** get_buffers_from_channels(LIST* channels)
{
	int number_buffers = list_length(channels);
	BUFFER **buffers = malloc((number_buffers + 1) * sizeof(BUFFER*));
	LIST* channel = channels->next;
	int i = 0;

	for (channel = channels->next; channel != NULL; inc(channel), ++i)
		buffers[i] = populate_buffer(channel);

	buffers[i] = NULL;
	return buffers;
}

BUFFER** treat_line(char *line, BUFFER **buffers)
{
	LIST *values = list_strsplit(line, ',');
	LIST *list_it = values->next;
	BUFFER **buffer_it = buffers;
	char comma[] = ",";
	char* to_write = NULL;

	for (list_it = values->next; list_it != NULL; inc(list_it), buffer_it++)
	{
		to_write = concat(list_it->value, comma);
		buffer_write((*buffer_it), to_write);
	}

	return buffers;
}

void close_all_buffers(BUFFER **buffers)
{
	BUFFER **it = buffers;

	for (it = buffers; *it != NULL; ++it)
	{
		buffer_close(*it);
	}
}