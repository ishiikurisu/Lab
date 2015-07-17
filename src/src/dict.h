#ifndef HASH_H
#define HASH_H 0
#include "string.h"
#include "list.h"
#include "coseq.h"

/*
# REQUIREMENTS
+ string.h
+ list.h
+ coseq.h
*/

typedef struct {
    int size;
    char** data;
    int (*hash)(char*);
} hashmap;

hashmap* new_map(int size, int (*func)(char*))
{
    hashmap* map  = (hashmap*) malloc(sizeof(hashmap));
    char**   keys = (char**) malloc(size * sizeof(char*));
    int i = 0;

    for (i = 0; i < size; ++i)
        keys[i] = NULL;

    map->size = size;
    map->data = keys;
    map->hash = func;

    return map;
}

hashmap* add_to_map(hashmap* map, char* to_add)
{
    if (to_add == NULL) return map;

    int index = map->hash(to_add) % map->size;

    if (map->data[index] != NULL)
        printf("replacing %s\n", map->data[index]);
    map->data[index] = to_add;

    return map;
}

void write_keys(hashmap* map)
{
    int i = 0;

    for (i = 0; i < map->size; ++i)
    {
        if (map->data[i] != NULL)
            printf("%d: %s\n", i, map->data[i]);
        else
        printf("%d: NULL\n", i);
    }
}

#endif
