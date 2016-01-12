#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;

	/* this doesn't compile! */
	printf("type a number from 0 to 10: ");
	scanf("%d", &n);
	if (n >= 5)
#define TEXT ("big");
	else
#define TEXT ("small");
	printf("this number is %s\n", TEXT);
#undef TEXT
	return 0;
}