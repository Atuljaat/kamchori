#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prerit || BCA-2A");
    int rowsA, colsA, rowsB, colsB, choice, i, j, k;
    int A[10][10], B[10][10], C[10][10];

    printf("\nEnter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Transpose\n");
        printf("4. Multiplication\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Matrices cannot be added.\n");
                } else {
                    printf("Addition:\n");
                    for (i = 0; i < rowsA; i++) {
                        for (j = 0; j < colsA; j++) {
                            C[i][j] = A[i][j] + B[i][j];
                            printf("%d ", C[i][j]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 2:
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Matrices cannot be subtracted.\n");
                } else {
                    printf("Subtraction:\n");
                    for (i = 0; i < rowsA; i++) {
                        for (j = 0; j < colsA; j++) {
                            C[i][j] = A[i][j] - B[i][j];
                            printf("%d ", C[i][j]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 3:
                printf("Transpose:\n");
                int matrix_choice;
                printf("Transpose which matrix? (1 for A, 2 for B): ");
                scanf("%d", &matrix_choice);

                if (matrix_choice == 1) {
                    printf("Transpose of Matrix A:\n");
                    for (i = 0; i < colsA; i++) {
                        for (j = 0; j < rowsA; j++) {
                            printf("%d ", A[j][i]);
                        }
                        printf("\n");
                    }
                } else if (matrix_choice == 2) {
                    printf("Transpose of Matrix B:\n");
                    for (i = 0; i < colsB; i++) {
                        for (j = 0; j < rowsB; j++) {
                            printf("%d ", B[j][i]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("Invalid Matrix Choice\n");
                }
                break;

            case 4:
                if (colsA != rowsB) {
                    printf("Matrices cannot be multiplied.\n");
                } else {
                    printf("Multiplication:\n");
                    for (i = 0; i < rowsA; i++) {
                        for (j = 0; j < colsB; j++) {
                            C[i][j] = 0;
                            for (k = 0; k < colsA; k++) {
                                C[i][j] += A[i][k] * B[k][j];
                            }
                            printf("%d ", C[i][j]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}