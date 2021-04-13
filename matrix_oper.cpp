#include "matrix.h"

matrix* matrix_calloc(int n_rows, int n_cols) {//dynamically allocate a matrix.
	matrix* output;
	output= (matrix*)malloc(sizeof(matrix) + (size_t)n_rows * (size_t)n_cols * sizeof(DATA_TYPE));
	if (output != NULL) {
		output->n_rows = n_rows;
		output->n_cols = n_cols;
		for (int i = 0; i < n_rows * n_cols; i++)
		{
			output->data[i] = 0;
		}
	}
	else {
		free(output);
		printf("Error allocating matrix of %d X %d", n_rows, n_cols);
		exit(EXIT_FAILURE);
	}
}

void matrix_free(matrix* input) {
	free(input);
}

void printmat(matrix* input) {
	for (int i = 0; i < input->n_rows; i++) {
		for (int j = 0; j < input->n_cols; j++) {
			printf("%d ", input->data[i + j * input->n_rows]);
		}
		printf("\n");
	}
}

void matmul(matrix* result, matrix* matrixA, matrix* matrixB) {//Assign matrix multiplication results to a pre-defined buffer "result". Matrix are indexed in row-major order.
	if (matrixA->n_cols != matrixB->n_rows)
	{
		printf("Input matrices are incompatible in shape\n");
		exit(EXIT_FAILURE);
	}

	if (result->n_rows != matrixA->n_rows || result->n_cols != matrixB->n_cols)
	{
		printf("Output matrix is incompatible with input matrices\n");
		exit(EXIT_FAILURE);
	}

	DATA_TYPE* interim_sum = (DATA_TYPE*)calloc((size_t)matrixA->n_rows * (size_t)matrixB->n_cols, sizeof(DATA_TYPE));
	if (interim_sum == NULL) {
		printf("Failed to allocate interim sum\n");
		exit(EXIT_FAILURE);
	}
	else {
		for (int ii = 0; ii < matrixA->n_rows; ii++) {
			for (int jj = 0; jj < matrixA->n_cols; jj++) {
				for (int kk = 0; kk < matrixB->n_cols; kk++) {
					interim_sum[ii + kk * matrixA->n_rows] += matrixA->data[ii + jj * matrixA->n_rows] * matrixB->data[jj + kk * matrixB->n_rows];
				}
			}
		}
		for (int i = 0; i < matrixA->n_rows; i++) {
			for (int j = 0; j < matrixB->n_cols; j++) {
				result->data[i + j * result->n_rows] = interim_sum[i + j * matrixA->n_rows];
			}
		}
		free(interim_sum);
	}
}