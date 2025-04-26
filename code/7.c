#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int arr[100], size, num, i, j, found = 0;

printf("Enter the size of the array: ");
scanf("%d", &size);

printf("Enter the elements of the array: ");
for (i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}

printf("Enter the number to be searched and deleted: ");
scanf("%d", &num);

for (i = 0; i < size; i++) {
if (arr[i] == num) {
for (j = i; j < size - 1; j++) {
arr[j] = arr[j + 1];
}
size--;
found = 1;
printf("Element deleted successfully.\n");
break;
}
}

if (!found) {
printf("Element not found.\n");
} else {
printf("Modified array: ");
for (i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}

return 0;
}