#include <stdio.h>
#include <stdlib.h>
#include "oa.h"
#include "buffer.h"
#define __BUFFER_SIZE__ 1024

int main(int argc, char const *argv[])
{
	FILE *fp = fopen("teste.CSV", "r");
	BUFFER *buf = buffer_new(fp, __BUFFER_SIZE__);

	printf("---\n");
	while(!feof(fp))
	{
		printf("%c", buffer_read(buf));
	}
	buffer_close(buf);
	printf("...\n");

	return 0;
}
