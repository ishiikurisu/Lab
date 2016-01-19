#ifndef FLAGS_H
#define FLAGS_H
#include <stdlib.h>
#include <oa.h>

typedef struct {
    const char *input_file;
    bool single;
} 
OPTIONS;

OPTIONS* parse_flags(int argc, char **argv)
{
    OPTIONS *options = (OPTIONS*) malloc(sizeof(options));
    options->single = true;
    int i = 0;

    for (i = 1; i <= argc; ++i)
    {

    }

    return options;
}

char* get_output(char *input)
{
	char *output = substring(input, 0, strlen(input)-4);
	cat(output, ".ascii");
	return output;
}

#endif
