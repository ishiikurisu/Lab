#ifndef BITMAP_H
#define BITMAP_H
#include <stdlib.h>
#include <stdio.h>
#include "toolbox.h"

typedef struct {
	char *name;

	/* HEADER */
	char identifier[2+1];
	int size;
	char reserved[4+1];
	int offset;

	/* DIB */
	int header_size;
	int width;
	int height;
	short color_panes;
	short bits_per_pixel;
	int compression;
	int image_size;

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

/*
Offset (hex)	Offset (dec)	Size (bytes)	Windows BITMAPINFOHEADER[2]
0E	14	4	the size of this header (40 bytes)
12	18	4	the bitmap width in pixels (signed integer)
16	22	4	the bitmap height in pixels (signed integer)
1A	26	2	the number of color planes (must be 1)
1C	28	2	the number of bits per pixel, which is the color depth of the image. Typical values are 1, 4, 8, 16, 24 and 32.
1E	30	4	the compression method being used. See the next table for a list of possible values
22	34	4	the image size. This is the size of the raw bitmap data; a dummy 0 can be given for BI_RGB bitmaps.
26	38	4	the horizontal resolution of the image. (pixel per meter, signed integer)
2A	42	4	the vertical resolution of the image. (pixel per meter, signed integer)
2E	46	4	the number of colors in the color palette, or 0 to default to 2n
32	50	4	the number of important colors used, or 0 when every color is important; generally ignored
*/
BITMAP *bitmap_readdib(BITMAP *bitmap, FILE *stream)
{
	int empty[6];

	fread(&bitmap->header_size, sizeof(int), 1, stream);
	fread(&bitmap->width, sizeof(int), 1, stream);
	fread(&bitmap->height, sizeof(int), 1, stream);
	fread(&bitmap->color_panes, sizeof(short), 1, stream);
	fread(&bitmap->bits_per_pixel, sizeof(short), 1, stream);
	fread(&bitmap->compression, sizeof(int), 1, stream);
	fread(&bitmap->image_size, sizeof(int), 1, stream);
	fread(&empty, sizeof(int), 4, stream);

	return bitmap;
}

BITMAP *bitmap_load(char *path)
{
	BITMAP *bitmap = bitmap_new(path);
	FILE *stream = fopen(path, "r");
	char bit;

	bitmap = bitmap_readheader(bitmap, stream);
	bitmap = bitmap_readdib(bitmap, stream);

	fclose(stream);
	return bitmap;
}

void bitmap_write(BITMAP* bm)
{
	printf("--- # %s\n", bm->name);
	printf("identifier: %s\n", bm->identifier);
	printf("size: %d\n", bm->size);
	printf("offset: %d\n", bm->offset);
	printf("DIB:\n");
	printf("  header size: %d\n", bm->header_size);
	printf("  width: %d\n", bm->width);
	printf("  height: %d\n", bm->height);
	printf("  no. of color panes: %d\n", bm->color_panes);
	printf("  bits per pixel: %d\n", bm->bits_per_pixel);
	printf("  compression method: %d\n", bm->compression);
	printf("  image size: %d\n", bm->image_size);
	printf("...\n");
}

#endif
