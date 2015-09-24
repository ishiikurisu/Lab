#include <iostream>
#include "analyze.hpp"

int main(int argc, char const *argv[]) {
    char const *input = argv[1];
    analyze(input, true);
    return 0;
}
