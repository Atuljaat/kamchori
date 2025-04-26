#include <stdio.h>
#include <stdlib.h>

int main() {
printf("Prerit || BCA-2A");
int n1, n2, n3, i, j;

printf("Enter the size of the first array: ");
scanf("%d", &n1);

int arr1[n1];
printf("Enter elements of the first array:\n");
for (i = 0; i < n1; i++) {
scanf("%d", &arr1[i]);
}

printf("Enter the size of the second array: ");
scanf("%d", &n2);

int arr2[n2];
printf("Enter elements of the second array:\n");
for (i = 0; i < n2; i++) {
scanf("%d", &arr2[i]);
}

n3 = n1 + n2;
int merged_arr[n3];

for (i = 0; i < n1; i++) {
merged_arr[i] = arr1[i];
}

for (i = 0, j = n1; i < n2; i++, j++) {
merged_arr[j] = arr2[i];
}

printf("Merged array:\n");
for (i = 0; i < n3; i++) {
printf("%d ", merged_arr[i]);
}
printf("\n");

return 0;
}