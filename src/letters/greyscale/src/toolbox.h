#pragma once
#define SIDE 4
#include <stdlib.h>

double** new_matrix()
{
	double **matrix = (double**) malloc(SIDE*sizeof(double*));
	int i, j;

	for (i = 0; i < SIDE; ++i)
	{
		matrix[i] = (double*) malloc(SIDE*sizeof(double));
		for (j = 0; j < SIDE; ++j)
			matrix[i][j] = 0.0;
	}

	return matrix;
}

double** transpose(double **matrix)
{
	double** transposed = new_matrix();
	int i, j;

	for (i = 0; i < SIDE; ++i)
		for (j = 0; j < SIDE; ++j)
			transposed[i][j] = matrix[j][i];

	return transposed;
}

double internal_product(double *a, double *b)
{
	double result = 0.0;
	int i;

	for (i = 0; i < SIDE; ++i)
		result += a[i] * b[i];

	return result;
}

double** matrix_product(double **a, double **b)
{
	double **bt = transpose(b);
	double **result = new_matrix();
	int i, j;

	for (i = 0; i < SIDE; ++i)
		for (j = 0; j < SIDE; ++j)
			result[j][i] = internal_product(a[j], bt[i]);

	free(bt);
	return result;
}

/* calculate matrix modulus */
