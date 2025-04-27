#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int rows, cols, i, j, k = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sparse_matrix[rows * cols][3];
    sparse_matrix[0][0] = rows;
    sparse_matrix[0][1] = cols;
    sparse_matrix[0][2] = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse_matrix[k][0] = i;
                sparse_matrix[k][1] = j;
                sparse_matrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse_matrix[0][2] = k - 1;

    printf("3-Tuple Representation:\n");
    for (i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse_matrix[i][0], sparse_matrix[i][1], sparse_matrix[i][2]);
    }

    return 0;
}