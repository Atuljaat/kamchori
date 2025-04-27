#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Prerit || BCA-2A");
    int n, i, j, k;

    printf("\nEnter the size of the list: ");
    scanf("%d", &n);

    int list[n];
    int uniqueList[n];
    int uniqueSize = 0;

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    for (i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (j = 0; j < uniqueSize; j++) {
            if (list[i] == uniqueList[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueList[uniqueSize] = list[i];
            uniqueSize++;
        }
    }

    printf("Output: ");
    for (i = 0; i < uniqueSize; i++) {
        printf("%d ", uniqueList[i]);
    }
    printf("\n");

    return 0;
}