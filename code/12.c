#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int rows, cols, i, j, k = 1;

printf("Enter the number of rows: ");
scanf("%d", &rows);
printf("Enter the number of columns: ");
scanf("%d", &cols);

int matrix[rows][cols];
int tuple[rows * cols][3];

printf("Enter the elements of the matrix:\n");
for (i = 0; i < rows; i++) {
for (j = 0; j < cols; j++) {
scanf("%d", &matrix[i][j]);
}
}

tuple[0][0] = rows;
tuple[0][1] = cols;
tuple[0][2] = 0;

for (i = 0; i < rows; i++) {
for (j = 0; j < cols; j++) {
if (matrix[i][j] != 0) {
tuple[k][0] = i;
tuple[k][1] = j;
tuple[k][2] = matrix[i][j];
k++;
}
}
}

tuple[0][2] = k - 1;

printf("3-Tuple representation:\n");
for (i = 0; i < k; i++) {
printf("%d %d %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
}

return 0;
}