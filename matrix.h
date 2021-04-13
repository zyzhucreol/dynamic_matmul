#pragma once
#include "stdint.h"
#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"

typedef int16_t DATA_TYPE;

typedef struct matrix {
	int n_rows;
	int n_cols;
	DATA_TYPE data[];
} matrix;

matrix* matrix_calloc(int n_rows, int n_cols);
void matrix_free(matrix* input);
void matmul(matrix* result, matrix* A, matrix* B);
void printmat(matrix* input);