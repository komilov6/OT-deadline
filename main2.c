#include <stdio.h>
#define MAX 100

// Matritsani ko'paytirish funksiyasi (bir o'lchamli massiv bilan)
void multiplyMatrices1D(const int *A, const int *B, int *C, int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            C[i * k + j] = 0;
            for (int l = 0; l < m; l++) {
                C[i * k + j] += A[i * m + l] * B[l * k + j];
            }
        }
    }
}

// Matritsani chop etish funksiyasi (bir o'lchamli massiv bilan)
void printMatrix1D(const int *mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, k;
    int A[MAX * MAX], B[MAX * MAX], C[MAX * MAX];

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
            scanf("%d", &A[i * m + j]);
        }
    }

    // B matritsasini kiritish
    printf("B matritsasini kiriting:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &B[i * k + j]);
        }
    }

    // Matritsalarni ko'paytirish
    multiplyMatrices1D(A, B, C, n, m, k);

    // Natijani chop etish
    printf("Natija matritsasi:\n");
    printMatrix1D(C, n, k);

    return 0;
}