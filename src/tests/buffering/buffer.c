#include <stdlib.h>
#include <stdio.h>
#include <oa.h>
#include "buffer.h"

int main(int argc, char const *argv[]) {
    BUFFER *inlet = buffer_new(fopen(argv[1], "r"), 1024);
    BUFFER *outlet = buffer_new(fopen(argv[2], "w"), 1024);
    char just_read = ' ';

    while (buffer_is_available(inlet))
    {
        just_read = buffer_read(inlet);
        buffer_write(outlet, ctos(just_read));
    }
    buffer_write(outlet, ctos(just_read));

    buffer_close(inlet);
    buffer_close(outlet);
    return 0;
}
