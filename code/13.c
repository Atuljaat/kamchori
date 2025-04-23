#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Tuple;

void createSparse(int matrix[][100], int rows, int cols, Tuple sparse[], int *size) {
    *size = 0;
    sparse[0].row = rows;
    sparse[0].col = cols;
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                (*size)++;
                sparse[*size].row = i;
                sparse[*size].col = j;
                sparse[*size].value = matrix[i][j];
                count++;
            }
        }
    }
    sparse[0].value = count;
}

void displaySparse(Tuple sparse[], int size) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= size; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int rows, cols;
    int matrix[100][100];
    Tuple sparse[10000];
    int size;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    createSparse(matrix, rows, cols, sparse, &size);

    printf("\nSparse Matrix (3-tuple representation):\n");
    displaySparse(sparse, size);

    return 0;
}