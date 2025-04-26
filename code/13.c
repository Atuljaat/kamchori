#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int n, i, j, min_index, temp;

printf("\nEnter the size of the array: ");
scanf("%d", &n);

int array[n];

printf("Enter the elements: ");
for (i = 0; i < n; i++) {
scanf("%d", &array[i]);
}

for (i = 0; i < n - 1; i++) {
min_index = i;
for (j = i + 1; j < n; j++) {
if (array[j] < array[min_index]) {
min_index = j;
}
}
if (min_index != i) {
temp = array[i];
array[i] = array[min_index];
array[min_index] = temp;
}
}

printf("Sorted array: ");
for (i = 0; i < n; i++) {
printf("%d ", array[i]);
}
printf("\n");

return 0;
}