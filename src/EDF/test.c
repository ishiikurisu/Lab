#include <stdio.h>
#include "edf.h"

int main(int argc, char const *argv[]) {
    EDF_SETUP();

    printf("%s\n", list_yaml(EDF_SPEC));
    printf("%s\n", map_yaml(EDF_SPECS));

    return 0;
}
