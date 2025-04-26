#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int arr[100];
int size, location, i;

printf("Enter the size of the array: ");
scanf("%d", &size);

printf("Enter the elements of the array: ");
for (i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}

printf("Enter the location to delete (0 to %d): ", size - 1);
scanf("%d", &location);

if (location < 0 || location >= size) {
printf("Invalid location!\n");
return 1;
}

for (i = location; i < size - 1; i++) {
arr[i] = arr[i + 1];
}

size--;

printf("Array after deletion: ");
for (i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");

return 0;
}