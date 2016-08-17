#include "stdio.h"
#include "stdlib.h"
#include "C/buffer.h"
#include "csv2ascii.h"

int main(int argc, char *argv[]) {
    BUFFER *inlet = buffer_new(argv[1], "r", 256);
    char* line = buffer_readline(inlet);
    int chan = 0;

    printf("---\n");
    printf("# Getting channels\n");
    chan = get_chan(line);
    printf("chan: %d\n", chan);

    printf("...\n");
    buffer_close(inlet);
    return 0;
}
