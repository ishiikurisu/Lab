#include <stdlib.h>
#include <stdio.h>
#include <oa.h>
#include <buffer.h>

int main(int argc, char *argv[]) {
    BUFFER *inlet = buffer_new(argv[1], "r", 2048);
    BUFFER *outlet = buffer_new(argv[2], "w", 2048);
    char just_read = ' ';

    just_read = buffer_read(inlet);
    while (just_read != EOF)
    {
        buffer_write(outlet, ctos(just_read));
        just_read = buffer_read(inlet);
    }

    buffer_close(inlet);
    buffer_close(outlet);
    return 0;
}
