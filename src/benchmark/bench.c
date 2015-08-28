#include "benchmark.h"

int main(int argc, char const *argv[]) {
    clock_t now = clock();

    now = clock();
    execute(argv);
    now = clock() - now;
    write_results(now);

    return 0;
}
