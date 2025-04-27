#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prerit || BCA-2A");
    int size1, size2, merged_array_size, i, j;
    int *array1, *array2, *merged_array;

    printf("\nEnter the size of the first array: ");
    scanf("%d", &size1);

    array1 = (int *)malloc(size1 * sizeof(int));
    if (array1 == NULL) {
        printf("Memory allocation failed for array1.\n");
        return 1;
    }

    printf("Enter the elements of the first array: ");
    for (i = 0; i < size1; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    array2 = (int *)malloc(size2 * sizeof(int));
    if (array2 == NULL) {
        printf("Memory allocation failed for array2.\n");
        free(array1);
        return 1;
    }

    printf("Enter the elements of the second array: ");
    for (i = 0; i < size2; i++) {
        scanf("%d", &array2[i]);
    }

    merged_array_size = size1 + size2;
    merged_array = (int *)malloc(merged_array_size * sizeof(int));
    if (merged_array == NULL) {
        printf("Memory allocation failed for merged_array.\n");
        free(array1);
        free(array2);
        return 1;
    }

    for (i = 0; i < size1; i++) {
        merged_array[i] = array1[i];
    }

    for (j = 0; j < size2; j++) {
        merged_array[size1 + j] = array2[j];
    }

    printf("Merged array: ");
    for (i = 0; i < merged_array_size; i++) {
        printf("%d ", merged_array[i]);
    }
    printf("\n");

    free(array1);
    free(array2);
    free(merged_array);

    return 0;
}