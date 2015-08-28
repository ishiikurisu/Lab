#pragma once
#include <time.h>
#include <process.h>

void execute(char const **argv)
{
    const char **arg = argv;
    spawnv(P_WAIT, argv[1], ++arg);
}

void write_results(clock_t what)
{
    printf("\t#%.3fs\n", (float) what/CLOCKS_PER_SEC);
}
