#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "benchmark.h"

int main(int argc, char *argv[]) {
    char *process_name = NULL;
    clock_t now = clock();

    process_name = get_process_name(argc, argv);
    now = clock();
    execute(argv[1], process_name);
    now = clock() - now;
    write_results(now);

    return 0;
}
