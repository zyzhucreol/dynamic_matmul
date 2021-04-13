// dynamic_matmul_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "matrix.h"
#include "time.h"

int main()
{
    //Test: random matrix-matrix multiplication with growing size
    srand((uint32_t)time(NULL));
    for (int n_test0 = 0; n_test0 < 512; n_test0 = n_test0 + 16) {
        matrix* A = matrix_calloc(3 + n_test0, 3 + n_test0);
        matrix* B = matrix_calloc(3 + n_test0, 3 + n_test0);
        matrix* result = matrix_calloc(3 + n_test0, 3 + n_test0);
        
        for (int ii = 0; ii < A->n_rows * A->n_cols; ii++) {
            A->data[ii] = rand() % 16 - 8; //elements in A can range from -8 to 7 to prevent overflow
        }
        for (int jj = 0; jj < B->n_rows * B->n_cols; jj++) {
            B->data[jj] = rand() % 16 - 8; //elements in B can range from -8 to 7 to prevent overflow
        }

        matmul(result, A, B);

        printf("\nMatmul Result\n");
        printmat(result);

        matrix_free(A);
        matrix_free(B);
        matrix_free(result);
    }
}