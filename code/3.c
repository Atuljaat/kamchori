#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prerit || BCA-2A");
    int size1, size2, i, j, merged_size;
    int *arr1, *arr2, *merged_arr;

    printf("\nEnter the size of the first array: ");
    scanf("%d", &size1);

    arr1 = (int *)malloc(size1 * sizeof(int));

    printf("Enter the elements of the first array: ");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    arr2 = (int *)malloc(size2 * sizeof(int));

    printf("Enter the elements of the second array: ");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    merged_size = size1 + size2;
    merged_arr = (int *)malloc(merged_size * sizeof(int));

    for (i = 0; i < size1; i++) {
        merged_arr[i] = arr1[i];
    }

    for (i = 0, j = size1; i < size2; i++, j++) {
        merged_arr[j] = arr2[i];
    }

    printf("Merged array: ");
    for (i = 0; i < merged_size; i++) {
        printf("%d ", merged_arr[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(merged_arr);

    return 0;
}