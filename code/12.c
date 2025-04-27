#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int rows, cols, i, j, k = 1, count = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int sparseMatrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &sparseMatrix[i][j]);
            if (sparseMatrix[i][j] != 0) {
                count++;
            }
        }
    }

    int tupleMatrix[count + 1][3];
    tupleMatrix[0][0] = rows;
    tupleMatrix[0][1] = cols;
    tupleMatrix[0][2] = count;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                tupleMatrix[k][0] = i;
                tupleMatrix[k][1] = j;
                tupleMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    printf("3-Tuple Representation:\n");
    for (i = 0; i <= count; i++) {
        printf("%d %d %d\n", tupleMatrix[i][0], tupleMatrix[i][1], tupleMatrix[i][2]);
    }

    return 0;
}