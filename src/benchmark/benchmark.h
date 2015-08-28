#pragma once
#include <oa.h>
#include <process.h>
#include <time.h>

char *get_process_name(int argc, char **argv)
{
    char *process_name = malloc(sizeof(char));
    int i = -1;

    process_name[0] = '\0';
    for (i = 1; i < argc; ++i)
    {
        process_name = concat(process_name, argv[i]);
        cat(process_name, ctos(' '));
    }

    return tidy_string(process_name);
}

void execute(char *process_name, char *process)
{
    printf("<%s>\n", process);
    spawnl(P_WAIT, process_name, process);
}

void write_results(clock_t what)
{
    printf("\t#%.3fs\n", (float) what/CLOCKS_PER_SEC);
}
