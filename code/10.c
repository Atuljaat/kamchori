#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int rowsA, colsA, rowsB, colsB, choice, i, j, k;
    int matrixA[10][10], matrixB[10][10], result[10][10];

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("\nMenu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Transpose of A\n");
    printf("4. Transpose of B\n");
    printf("5. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (rowsA != rowsB || colsA != colsB) {
                printf("Matrices cannot be added. Dimensions are not compatible.\n");
                break;
            }
            printf("Resultant matrix after addition:\n");
            for (i = 0; i < rowsA; i++) {
                for (j = 0; j < colsA; j++) {
                    result[i][j] = matrixA[i][j] + matrixB[i][j];
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            if (rowsA != rowsB || colsA != colsB) {
                printf("Matrices cannot be subtracted. Dimensions are not compatible.\n");
                break;
            }
            printf("Resultant matrix after subtraction:\n");
            for (i = 0; i < rowsA; i++) {
                for (j = 0; j < colsA; j++) {
                    result[i][j] = matrixA[i][j] - matrixB[i][j];
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            printf("Transpose of matrix A:\n");
            for (i = 0; i < colsA; i++) {
                for (j = 0; j < rowsA; j++) {
                    printf("%d ", matrixA[j][i]);
                }
                printf("\n");
            }
            break;

        case 4:
            printf("Transpose of matrix B:\n");
            for (i = 0; i < colsB; i++) {
                for (j = 0; j < rowsB; j++) {
                    printf("%d ", matrixB[j][i]);
                }
                printf("\n");
            }
            break;

        case 5:
            if (colsA != rowsB) {
                printf("Matrices cannot be multiplied. Dimensions are not compatible.\n");
                break;
            }
            printf("Resultant matrix after multiplication:\n");
            for (i = 0; i < rowsA; i++) {
                for (j = 0; j < colsB; j++) {
                    result[i][j] = 0;
                    for (k = 0; k < colsA; k++) {
                        result[i][j] += matrixA[i][k] * matrixB[k][j];
                    }
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}