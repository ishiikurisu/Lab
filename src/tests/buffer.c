#include <stdio.h>
#include <stdlib.h>
#include "oa.h"
#include "buffer.h"

int main(int argc, char const *argv[])
{
	FILE *fp = fopen("joe.txt", "r");
	BUFFER *buf = buffer_new(fp, 5);

	printf("---\n");
	while(!feof(fp))
	{
		buffer_status(buf);
		printf("\t%c\n", buffer_read(buf));
	}
	buffer_close(buf);
	printf("...\n");

	fp = fopen("frank.txt", "w");
	buf = buffer_new(fp, 5);
	buffer_write(buf, "hi ");
	buffer_status(buf);
	buffer_write(buf, "my name ");
	buffer_status(buf);
	buffer_write(buf, "is frank\n");
	buffer_status(buf);
	buffer_close(buf);
	printf("...\n");

	return 0;
}