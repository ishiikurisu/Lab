#ifndef BITMAP_H
#define BITMAP_H
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char *name;

	/* HEADER */
	char identifier[2+1];
	int size;
	char reserved[4+1];
	int offset;

	/* DIB */
	/* currently void of stuff :( */
} BITMAP;

BITMAP *bitmap_new(char *path)
{
	BITMAP *bm = (BITMAP*) malloc(sizeof(BITMAP));
	bm->name = path;
	return bm;
}

BITMAP *bitmap_readheader(BITMAP* bitmap, FILE* stream)
{
	fread(bitmap->identifier, sizeof(char), 2, stream);
	fread(&bitmap->size, sizeof(int), 1, stream);
	fread(bitmap->reserved, sizeof(char), 4, stream);
	fread(&bitmap->offset, sizeof(int), 1, stream);

	bitmap->identifier[2] = '\0';
	bitmap->reserved[4] = '\0';

	return bitmap;
}

BITMAP *bitmap_readdib(BITMAP *bitmap, FILE *stream)
{
	return bitmap;
}

BITMAP *bitmap_load(char *path)
{
	BITMAP *bitmap = bitmap_new(path);
	FILE *stream = fopen(path, "r");

	bitmap = bitmap_readheader(bitmap, stream);
	/* read dib */

	fclose(stream);
	return bitmap;
}

void bitmap_write(BITMAP* bm)
{
	printf("--- # %s\n", bm->name);
	printf("identifier: %s\n", bm->identifier);
	printf("size: %d\n", bm->size);
	printf("offset: %d\n", bm->offset);
	printf("...\n");
}

#endif
