#include <stdio.h>
#define MAX 100

// Matritsani ko'paytirish funksiyasi
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = 0;
            for (int l = 0; l < m; l++) {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }
}

// Matritsani chop etish funksiyasi
void printMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, k;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    // Matritsa o'lchamlarini kiritish
    printf("A matritsasining o'lchamlarini kiriting (n m): ");
    scanf("%d %d", &n, &m);
    printf("B matritsasining o'lchamlarini kiriting (m k): ");
    scanf("%d %d", &m, &k);

    if (n <= 0 || m <= 0 || k <= 0 || n > MAX || m > MAX || k > MAX) {
        printf("Xatolik: o'lchamlar noto'g'ri!\n");
        return 1;
    }

    // A matritsasini kiritish
    printf("A matritsasini kiriting:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // B matritsasini kiritish
    printf("B matritsasini kiriting:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Matritsalarni ko'paytirish
    multiplyMatrices(A, B, C, n, m, k);

    // Natijani chop etish
    printf("Natija matritsasi:\n");
    printMatrix(C, n, k);

    return 0;
}