#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	short joe = 1246;
	short frank = -4568;
	int i;

	for (i = 0; i < 16; ++i)
	{
		printf("%d\t%d\n", (joe >> i) & 0x1, (frank >> i) & 0x1);
	}

	return 0;
}