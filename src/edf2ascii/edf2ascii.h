#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <oa.h>
#define TEMP ("temp.csv")
#define ASCII ("ascii.txt")

#ifdef _WIN32
#include <process.h>
#define EDF2CSV ("edf2csv.exe")
#define CSV2ASCII ("csv2ascii.exe")

void edf2csv(char *source)
{
	char *edf = concat(source, ".edf");
	spawnl(P_WAIT, EDF2CSV, EDF2CSV, edf, TEMP, NULL);
}

void csv2ascii(char *source)
{
	char *os_command = malloc(sizeof(char) * 256);

	spawnl(P_WAIT, CSV2ASCII, CSV2ASCII, TEMP, NULL);
	sprintf(os_command, "dir *.ascii /B > %s", ASCII);
	system(os_command);
	sprintf(os_command, "FOR %%F IN (more %s) DO move %%F %s%%F", ASCII, source);
	system(os_command);

	free(os_command);
}

void clear_folder(char *source)
{
	remove(ASCII);
	remove(TEMP);
}

#else
#endif