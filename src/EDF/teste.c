#include <stdio.h>
#include "edf.h"

int main(int argc, char const *argv[]) {
	int array[] = {5, 1, 2, 3, 4, 5, 6, 7};
    EDF_SETUP();

    printf("%s\n", list_yaml(EDF_SPEC));
    printf("%s\n", map_yaml(EDF_SPECS));

    return 0;
}
