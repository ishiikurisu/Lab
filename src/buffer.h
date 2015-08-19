#ifndef BUFFER_H
#define BUFFER_H 0
#include <stdlib.h>
#include <stdio.h>
#include "oa.h"

typedef struct
{
    char *data;
    int size;
    bool available;
    FILE *stream;
}
BUFFER;

BUFFER* buffer_new(FILE *stream, int buffer_size)
{
	BUFFER *buffer = malloc(sizeof(BUFFER));

	buffer->data = "";
	buffer->size = buffer_size;
	buffer->stream = stream;
    buffer->available = 1;

	return buffer;
}

void buffer_status(BUFFER *buffer)
{
	printf("!%s\n", buffer->data);
}

BUFFER* buffer_flush(BUFFER *buffer)
{
	fwrite(buffer->data, strlen(buffer->data), 1, buffer->stream);
	free(buffer->data);
	buffer->data = "";
	return buffer;
}

BUFFER* buffer_feed(BUFFER *buffer)
{
	int char_count = 0;
	char read_char;

	while ((char_count < buffer->size) && (!feof(buffer->stream)))
	{
		read_char = fgetc(buffer->stream);
		cat(buffer->data, ctos(read_char));
		char_count++;
	}

	return buffer;
}

void buffer_write(BUFFER *buffer, char *to_write)
{
	cat(buffer->data, to_write);

	if (strlen(buffer->data) >= buffer->size)
		buffer = buffer_flush(buffer);
}

char buffer_read(BUFFER *buffer)
{
	char outlet = '\0';

	if (strlen(buffer->data) == 0) {
        if (!feof(buffer->stream))
		    buffer = buffer_feed(buffer);
        else {
            buffer->available = 0;
            return outlet;
        }
	}

	outlet = buffer->data[0];
    buffer->data++;

	return outlet;
}

int buffer_is_available(BUFFER *buffer)
{
    return buffer->available;
}

void buffer_close(BUFFER *buffer)
{
	/* if it was open for reading, do not forget to flush it */
    buffer->available = 0;
	fclose(buffer->stream);
	free(buffer->data);
	free(buffer);
}

#endif
