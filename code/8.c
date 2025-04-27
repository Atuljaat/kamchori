#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int target, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    printf("Prerit || BCA-2A");
    int size, target, i, index;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the sorted elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    index = binarySearch(arr, target, 0, size - 1);

    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index: %d\n", index);
    }

    free(arr);
    return 0;
}