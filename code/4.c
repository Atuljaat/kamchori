#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prerit || BCA-2A");
    int n1, n2, i, j, k;

    printf("\nEnter the size of the first array: ");
    scanf("%d", &n1);

    int *arr1 = (int *)malloc(n1 * sizeof(int));
    printf("Enter the elements of the first array (sorted order):\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("\nEnter the size of the second array: ");
    scanf("%d", &n2);

    int *arr2 = (int *)malloc(n2 * sizeof(int));
    printf("Enter the elements of the second array (sorted order):\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int *mergedArray = (int *)malloc((n1 + n2) * sizeof(int));

    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k] = arr1[i];
            i++;
        } else {
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        mergedArray[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        mergedArray[k] = arr2[j];
        j++;
        k++;
    }

    printf("\nMerged sorted array:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(mergedArray);

    return 0;
}