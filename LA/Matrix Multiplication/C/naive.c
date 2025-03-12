#include <stdio.h>

/**
 * Function: multiply_matrices
 * ---------------------------
 * Takes 2 3x3 matrices A and B as input from user. Multiplies them using naive formula, storing the result in matrix C.
 *
 * Matrix multiplication formula:
 * C[i][j] = sum(A[i][k] * B[k][j]) for all k
 *
 */
void multiply_matrices(int A[3][3], int B[3][3], int C[3][3]) {
    // matrix C init
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
        }
    }

    // loop for matrix_mul
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3];

    // User interaction with printf/scanf
    printf("Enter elements of matrix A (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    //repeat for B
    printf("Enter elements of matrix B (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Multiply matrices
    multiply_matrices(A, B, C);

    // Iterate thru matrix C
    printf("Resultant Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}