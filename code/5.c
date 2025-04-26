#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int arr[100];
int size, num, location, i;

printf("\nEnter the size of the array: ");
scanf("%d", &size);

printf("\nEnter the elements of the array: ");
for (i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}

printf("\nEnter the number to be inserted: ");
scanf("%d", &num);

printf("\nEnter the location at which the number has to be inserted: ");
scanf("%d", &location);

if (location < 0 || location > size) {
printf("\nInvalid location!");
} else {
for (i = size - 1; i >= location - 1; i--) {
arr[i + 1] = arr[i];
}

arr[location - 1] = num;
size++;

printf("\nResultant array is: ");
for (i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
}

return 0;
}