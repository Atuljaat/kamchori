#include <stdio.h>
#include <stdlib.h>

int main() {
printf("Prerit || BCA-2A");
int n, i, j;

printf("\nEnter the size of the matrices: ");
scanf("%d", &n);

int upper[n][n], lower[n][n], tri[n][n];

printf("\nEnter the elements of the Upper Triangular Matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
if (i <= j) {
scanf("%d", &upper[i][j]);
} else {
upper[i][j] = 0;
}
}
}

printf("\nEnter the elements of the Lower Triangular Matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
if (i >= j) {
scanf("%d", &lower[i][j]);
} else {
lower[i][j] = 0;
}
}
}

printf("\nEnter the elements of the Tri-diagonal Matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
if (i == j || i == j - 1 || i == j + 1) {
scanf("%d", &tri[i][j]);
} else {
tri[i][j] = 0;
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

printf("\nLower Triangular Matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
printf("%d ", lower[i][j]);
}
printf("\n");
}

printf("\nTri-diagonal Matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
printf("%d ", tri[i][j]);
}
printf("\n");
}

return 0;
}