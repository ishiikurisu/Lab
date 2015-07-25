#include <stdio.h>

int main(int argc, char const *argv[]) {
    rename("flow.c", "flow.cpp");
    getchar();
    rename("flow.cpp", "flow.c");
    return 0;
}
