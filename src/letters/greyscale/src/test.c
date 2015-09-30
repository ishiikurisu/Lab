#include <stdio.h>
#include <stdlib.h>
#include "toolbox.h"

int main(int argc, char const *argv[]) {
	double **id = load_matrix("data/id.ascii");
	double **pascal = load_matrix("data/pascal.ascii");
	double **square = load_matrix("data/sqrt-2.ascii");

	write_matrix(pascal);
	write_matrix(square);

	write_matrix(matrix_product(pascal, square));
	write_matrix(matrix_product(id, square));
	write_matrix(matrix_product(transpose(square), id));

	return 0;
}
