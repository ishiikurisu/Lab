#include <stdio.h>

int before()
{
	static int arg = 0;
	return (++arg % 2 == 0)? 0 : arg;
}

int after()
{
	static int arg = 0;
	return (arg++ % 2 == 0)? 0 : arg;
}

int main(int argc, char const *argv[])
{
	int i = 0;

	for (i = 0; i < 10; ++i)
		printf("%d %d\n", before(), after());

	return 0;
}