#include <stdlib.h>
#include <stdio.h>
#include "oa.h"

char* new_concat(char* string, char* to_add)
{
    char* new_str;
    int len;
    int i, j;

    len = strlen(string) + strlen(to_add);
    string = realloc(string, sizeof(char) * (len + 1));

    for (i = 0, j = strlen(string); i <= strlen(to_add); ++i, ++j)
        string[j] = to_add[i];

    return string;
}

int main()
{
	char *string = "joe";

	string = new_concat(string, " frank");
	printf("%s\n", string);

	return 0;
}