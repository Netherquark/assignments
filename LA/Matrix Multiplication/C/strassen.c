#include <stdio.h>

/**
 * Function: add_matrices
 * ----------------------
 * Takes two 2x2 matrices A and B and adds them, storing result in C
 */
void add_matrices(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/**
 * Function: subtract_matrices
 * ---------------------------
 * Takes two 2x2 matrices A and B, subtracting B from A, storing result in C
 */
void subtract_matrices(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/**
 * Function: strassen_multiply
 * ---------------------------
 * Recursively multiplies two matrices using Strassen's algorithm.
 * n is from nxn (dimensionality of matrix)
 * Only n==4 and n==2 (base case) are supported presently.
 */
void strassen_multiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 2) {
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        return;
    }
    
    int half = n / 2;  // For n==4, half will be 2

    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];

    int A11[2][2] = { { A[0][0], A[0][1] }, { A[1][0], A[1][1] } };
    int A12[2][2] = { { A[0][2], A[0][3] }, { A[1][2], A[1][3] } };
    int A21[2][2] = { { A[2][0], A[2][1] }, { A[3][0], A[3][1] } };
    int A22[2][2] = { { A[2][2], A[2][3] }, { A[3][2], A[3][3] } };

    int B11[2][2] = { { B[0][0], B[0][1] }, { B[1][0], B[1][1] } };
    int B12[2][2] = { { B[0][2], B[0][3] }, { B[1][2], B[1][3] } };
    int B21[2][2] = { { B[2][0], B[2][1] }, { B[3][0], B[3][1] } };
    int B22[2][2] = { { B[2][2], B[2][3] }, { B[3][2], B[3][3] } };

    int T1[2][2], T2[2][2];

    add_matrices(A11, A22, T1);
    add_matrices(B11, B22, T2);
    strassen_multiply(2, T1, T2, M1);

    add_matrices(A21, A22, T1);
    strassen_multiply(2, T1, B11, M2);

    subtract_matrices(B12, B22, T1);
    strassen_multiply(2, A11, T1, M3);

    subtract_matrices(B21, B11, T1);
    strassen_multiply(2, A22, T1, M4);

    add_matrices(A11, A12, T1);
    strassen_multiply(2, T1, B22, M5);

    subtract_matrices(A21, A11, T1);
    add_matrices(B11, B12, T2);
    strassen_multiply(2, T1, T2, M6);

    subtract_matrices(A12, A22, T1);
    add_matrices(B21, B22, T2);
    strassen_multiply(2, T1, T2, M7);

    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];

    add_matrices(M1, M4, T1);
    subtract_matrices(T1, M5, T2);
    add_matrices(T2, M7, C11);

    add_matrices(M3, M5, C12);
    add_matrices(M2, M4, C21);

    add_matrices(M1, M3, T1);
    subtract_matrices(T1, M2, T2);
    add_matrices(T2, M6, C22);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

int main() {
    int A[4][4], B[4][4], C[4][4];

    printf("Enter elements of matrix A (4x4):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B (4x4):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen_multiply(4, A, B, C);

    printf("Resultant Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
