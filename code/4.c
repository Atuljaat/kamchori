#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prerit || BCA-2A");
    int array1_size, array2_size, i, j, k;
    int *array1, *array2, *merged_array;

    printf("Enter the size of the first sorted array: ");
    scanf("%d", &array1_size);

    array1 = (int *)malloc(array1_size * sizeof(int));
    if (array1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the first sorted array: ");
    for (i = 0; i < array1_size; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Enter the size of the second sorted array: ");
    scanf("%d", &array2_size);

    array2 = (int *)malloc(array2_size * sizeof(int));
    if (array2 == NULL) {
        printf("Memory allocation failed.\n");
        free(array1);
        return 1;
    }

    printf("Enter the elements of the second sorted array: ");
    for (i = 0; i < array2_size; i++) {
        scanf("%d", &array2[i]);
    }

    merged_array = (int *)malloc((array1_size + array2_size) * sizeof(int));
    if (merged_array == NULL) {
        printf("Memory allocation failed.\n");
        free(array1);
        free(array2);
        return 1;
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < array1_size && j < array2_size) {
        if (array1[i] <= array2[j]) {
            merged_array[k] = array1[i];
            i++;
        } else {
            merged_array[k] = array2[j];
            j++;
        }
        k++;
    }

    while (i < array1_size) {
        merged_array[k] = array1[i];
        i++;
        k++;
    }

    while (j < array2_size) {
        merged_array[k] = array2[j];
        j++;
        k++;
    }

    printf("Merged sorted array: ");
    for (i = 0; i < array1_size + array2_size; i++) {
        printf("%d ", merged_array[i]);
    }
    printf("\n");

    free(array1);
    free(array2);
    free(merged_array);

    return 0;
}