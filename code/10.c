#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int choice, rows1, cols1, rows2, cols2, i, j, k;
int matrix1[10][10], matrix2[10][10], result[10][10];

do {
printf("\nMatrix Operations:\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Transpose\n");
printf("4. Multiplication\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter the number of rows and columns for matrix 1: ");
scanf("%d %d", &rows1, &cols1);
printf("Enter the number of rows and columns for matrix 2: ");
scanf("%d %d", &rows2, &cols2);

if (rows1 != rows2 || cols1 != cols2) {
printf("Matrices cannot be added. Dimensions are not compatible.\n");
break;
}

printf("Enter the elements of matrix 1:\n");
for (i = 0; i < rows1; i++) {
for (j = 0; j < cols1; j++) {
scanf("%d", &matrix1[i][j]);
}
}

printf("Enter the elements of matrix 2:\n");
for (i = 0; i < rows2; i++) {
for (j = 0; j < cols2; j++) {
scanf("%d", &matrix2[i][j]);
}
}

for (i = 0; i < rows1; i++) {
for (j = 0; j < cols1; j++) {
result[i][j] = matrix1[i][j] + matrix2[i][j];
}
}

printf("Resultant matrix after addition:\n");
for (i = 0; i < rows1; i++) {
for (j = 0; j < cols1; j++) {
printf("%d ", result[i][j]);
}
printf("\n");
}
break;

case 2:
printf("Enter the number of rows and columns for matrix 1: ");
scanf("%d %d", &rows1, &cols1);
printf("Enter the number of rows and columns for matrix 2: ");
scanf("%d %d", &rows2, &cols2);

if (rows1 != rows2 || cols1 != cols2) {
printf("Matrices cannot be subtracted. Dimensions are not compatible.\n");
break;
}

printf("Enter the elements of matrix 1:\n");
for (i = 0; i < rows1; i++) {
for (j = 0; j < cols1; j++) {
scanf("%d", &matrix1[i][j]);
}
}

printf("Enter the elements of matrix 2:\n");
for (i = 0; i < rows2; i++) {
for (j = 0; j < cols2; j++) {
scanf("%d", &matrix2[i][j]);
}
}

for (i = 0; i < rows1; i++) {
for (j = 0; j < cols1; j++) {
result[i][j] = matrix1[i][j] - matrix2[i][j];
}
}

printf("Resultant matrix after subtraction:\n");
for (i = 0; i < rows1; i++) {
for (j = 0; j < cols1; j++) {
printf("%d ", result[i][j]);
}
printf("\n");
}
break;

case 3:
printf("Enter the number of rows and columns for the matrix: ");
scanf("%d %d", &rows1, &cols1);

printf("Enter the elements of the matrix:\n");
for (i = 0; i < rows1; i++) {
for (j = 0; j < cols1; j++) {
scanf("%d", &matrix1[i][j]);
}
}

printf("Transpose of the matrix:\n");
for (i = 0; i < cols1; i++) {
for (j = 0; j < rows1; j++) {
printf("%d ", matrix1[j][i]);
}
printf("\n");
}
break;

case 4:
printf("Enter the number of rows and columns for matrix 1: ");
scanf("%d %d", &rows1, &cols1);
printf("Enter the number of rows and columns for matrix 2: ");
scanf("%d %d", &rows2, &cols2);

if (cols1 != rows2) {
printf("Matrices cannot be multiplied. Dimensions are not compatible.\n");
break;
}

printf("Enter the elements of matrix 1:\n");
for (i = 0; i < rows1; i++) {
for (j = 0; j < cols1; j++) {
scanf("%d", &matrix1[i][j]);
}
}

printf("Enter the elements of matrix 2:\n");
for (i = 0; i < rows2; i++) {
for (j = 0; j < cols2; j++) {
scanf("%d", &matrix2[i][j]);
}
}

for (i = 0; i < rows1; i++) {
for (j = 0; j < cols2; j++) {
result[i][j] = 0;
for (k = 0; k < cols1; k++) {
result[i][j] += matrix1[i][k] * matrix2[k][j];
}
}
}

printf("Resultant matrix after multiplication:\n");
for (i = 0; i < rows1; i++) {
for (j = 0; j < cols2; j++) {
printf("%d ", result[i][j]);
}
printf("\n");
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