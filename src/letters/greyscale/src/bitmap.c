#include "bitmap.h"

int main(int argc, char *argv[]) {
	BITMAP *bitmap = bitmap_load(argv[1]);

	bitmap_write(bitmap);
	free(bitmap);

	return 0;
}
