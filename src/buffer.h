#ifndef BUFFER_H
#define BUFFER_H 0
#include <stdlib.h>
#include <stdio.h>
#include <oa.h>

typedef struct
{
    char *data;
    int size;
    FILE *stream;
}
BUFFER;

BUFFER* buffer_new()
{

}

#endif
