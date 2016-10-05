#include <stdio.h>
#include "oa.h"

int main() 
{
	char *joe = cat("joe", " frank");
	printf("Hello %s!\n", joe);
	return 0;
}