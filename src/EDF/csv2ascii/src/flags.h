#ifndef FLAGS_H
#define FLAGS_H

typedef struct
{
    const char *input_file;
    bool single;
} OPTIONS;

OPTIONS* parse_flags(int argc, const char **argv)
{
    OPTIONS *options = (OPTIONS*) malloc(sizeof(options));
    options->single = true;
    int i = 0;

    for (i = 1; i <= argc; ++i)
    {

    }

    return options;
}

#endif
