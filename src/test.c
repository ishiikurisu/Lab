#include <stdio.h>
#include <stdlib.h>
#include "src/string.h"
#include "src/list.h"

int main(int argc, char const *argv[])
{
	char* joe = "joe";
	char* frank= "frank";
	LIST* list = list_new();

	push(list, joe);
	push(list, frank);
	cat(joe, ctos(' '));
	cat(joe, frank);

	/* printf("* %s\n", joe); */ 
	printf("%s", list_yaml(list));

	return 0;
}