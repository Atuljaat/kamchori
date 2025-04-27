#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prerit || BCA-2A");
    int n, i, j;

    printf("\nEnter the size of the square matrix: ");
    scanf("%d", &n);

    int upper[n][n], lower[n][n], tridiagonal[n][n];

    printf("\nEnter elements for the Upper Triangular matrix (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &upper[i][j]);
        }
    }

    printf("\nEnter elements for the Lower Triangular matrix (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &lower[i][j]);
        }
    }

    printf("\nEnter elements for the Tridiagonal matrix (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j || i == j - 1 || i == j + 1) {
                printf("Enter element [%d][%d]: ", i, j);
                scanf("%d", &tridiagonal[i][j]);
            }
        }
    }

    printf("\nUpper Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i <= j)
                printf("%d\t", upper[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }

    printf("\nLower Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i >= j)
                printf("%d\t", lower[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }

    printf("\nTridiagonal Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j || i == j - 1 || i == j + 1)
                printf("%d\t", tridiagonal[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }

    return 0;
}