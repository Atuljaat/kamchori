#include <stdio.h>

int main() {
    int a[10][10], b[10][10], sum[10][10], diff[10][10], product[10][10], transpose[10][10];
    int row1, col1, row2, col2, i, j, k;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &row2, &col2);

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    if (row1 == row2 && col1 == col2) {
        for (i = 0; i < row1; i++) {
            for (j = 0; j < col1; j++) {
                sum[i][j] = a[i][j] + b[i][j];
                diff[i][j] = a[i][j] - b[i][j];
            }
        }

        printf("Sum of the matrices:\n");
        for (i = 0; i < row1; i++) {
            for (j = 0; j < col1; j++) {
                printf("%d ", sum[i][j]);
            }
            printf("\n");
        }

        printf("Difference of the matrices:\n");
        for (i = 0; i < row1; i++) {
            for (j = 0; j < col1; j++) {
                printf("%d ", diff[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Addition and subtraction are not possible.\n");
    }

    if (col1 == row2) {
        for (i = 0; i < row1; i++) {
            for (j = 0; j < col2; j++) {
                product[i][j] = 0;
                for (k = 0; k < col1; k++) {
                    product[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("Product of the matrices:\n");
        for (i = 0; i < row1; i++) {
            for (j = 0; j < col2; j++) {
                printf("%d ", product[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Multiplication is not possible.\n");
    }

    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            transpose[j][i] = a[i][j];
        }
    }

    printf("Transpose of matrix A:\n");
    for (i = 0; i < col1; i++) {
        for (j = 0; j < row1; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}