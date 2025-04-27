#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prerit || BCA-2A");
    int n, i, j;

    printf("\nEnter the size of the matrix: ");
    scanf("%d", &n);

    int upper[n][n], lower[n][n], tridiagonal[n][n];

    printf("\nEnter elements for the Upper Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j >= i) {
                scanf("%d", &upper[i][j]);
            } else {
                upper[i][j] = 0;
            }
        }
    }

    printf("\nUpper Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", upper[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter elements for the Lower Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j <= i) {
                scanf("%d", &lower[i][j]);
            } else {
                lower[i][j] = 0;
            }
        }
    }

    printf("\nLower Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", lower[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter elements for the Tri-diagonal Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (abs(i - j) <= 1) {
                scanf("%d", &tridiagonal[i][j]);
            } else {
                tridiagonal[i][j] = 0;
            }
        }
    }

    printf("\nTri-diagonal Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", tridiagonal[i][j]);
        }
        printf("\n");
    }

    return 0;
}