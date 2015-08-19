#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char *joe = "joe frank";

    while (strlen(joe) > 0)
    {
        printf("%s\n", joe);
        joe++;
    }

    return 0;
}
