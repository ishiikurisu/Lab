#include <stdlib.h>
#include <stdio.h>
#include "oa.h"

int isnum(char ch)
{ return (ch >= '0' && ch <= '9')? 1 : 0; }

char* get_new_name(char* old)
{
    char* new = "";
    int limit = strlen(old);
    int i = -1;

    for (i = 0; isnum(old[i]); ++i)
        ;
    for (; i < limit; ++i)
        cat(new, ctos(old[i]));

    return new;
}

int main(int argc, char const *argv[]) {
    FILE* files = fopen("files.txt", "r");
    char* line = read_from_file(files);
    char* old_name = NULL;
    char* new_name = NULL;

    while (line)
    {
        old_name = line;
        new_name = get_new_name(line);

        printf("%s...", old_name);
        rename(old_name, new_name);
        getchar();
        rename(new_name, old_name);

        line = read_from_file(files);
    }

    fclose(files);
    return 0;
}
