#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int n, i, j, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int uniqueArr[n];
    int uniqueSize = 0;

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (j = 0; j < uniqueSize; j++) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueArr[uniqueSize] = arr[i];
            uniqueSize++;
        }
    }

    printf("Unique elements: ");
    for (i = 0; i < uniqueSize; i++) {
        printf("%d ", uniqueArr[i]);
    }
    printf("\n");

    return 0;
}