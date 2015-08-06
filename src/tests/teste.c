#include <stdio.h>

int main(int argc, char const *argv[]) {
	int array[] = {5, 1, 2, 3, 4, 5, 6, 7};
	const char* str_with_double = "156";
	int integer;
	double real;

    sscanf(str_with_double, "%d", &integer);
    real = (double) integer;
    printf("%lf\n", real);

    return 0;
}
