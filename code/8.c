#include <stdio.h>

int binarySearch(int array[], int low, int high, int target) {
while (low <= high) {
int mid = (low + high) / 2;
if (array[mid] == target) {
return mid;
} else if (array[mid] < target) {
low = mid + 1;
} else {
high = mid - 1;
}
}
return -1;
}

int main() {
printf("Prerit || BCA-2A");
int size, target, i, result;
printf("\nEnter the size of the array: ");
scanf("%d", &size);
int array[size];
printf("Enter the elements of the sorted array: ");
for (i = 0; i < size; i++) {
scanf("%d", &array[i]);
}
printf("Enter the element to search for: ");
scanf("%d", &target);
result = binarySearch(array, 0, size - 1, target);
if (result == -1) {
printf("Element is not found in the array\n");
} else {
printf("Element is found at index: %d\n", result);
}
return 0;
}