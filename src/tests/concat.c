#include <stdlib.h>
#include <stdio.h>
#include "oa.h"

char* new_concat(char* to_hold, char* to_add)
{
    int l1 = strlen(to_hold);
    int l2 = strlen(to_add);
    int len = l1 + l2;
    char* new_str = malloc(sizeof(char) * (len + 1));
    
    memcpy(new_str, to_hold, l1);
    memcpy(new_str + l1, to_add, l2);

    new_str[len] = '\0';
    return new_str;
}

int main()
{
	char *string = "joe";

	string = new_concat(string, " frank");
	printf("%s\n", string);

	return 0;
}