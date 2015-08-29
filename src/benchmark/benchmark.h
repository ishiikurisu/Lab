#pragma once
#include <stdio.h>
#include <time.h>

void write_results(clock_t what)
{
    printf("... # %.3fs\n", (float) what/CLOCKS_PER_SEC);
}

#ifdef _WIN32
#include <process.h>

void execute(char const **argv)
{
    char **arg = argv;
    spawnv(P_WAIT, argv[1], ++arg);
}

#else
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void execute(char **argv)
{
	char app[256];
	char **arg = argv;

	++arg;
	sprintf(app, "./%s", *arg);
	for (++arg; *arg; ++arg)
	{
		sprintf(app, "%s %s", app, *arg);
	}

	printf("<%s>\n", app);
    system(app);
}

#endif
