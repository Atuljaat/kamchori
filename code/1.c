#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int n, key, firstOccurrence = -1;
    int arr[100];
    int allOccurrences[100];
    int count = 0;

    printf("\nEnter the size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter search item: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            firstOccurrence = i;
            break;
        }
    }

    if (firstOccurrence == -1) {
        printf("Element not found\n");
    } else {
        printf("First occurrence at index: %d\n", firstOccurrence);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            allOccurrences[count] = i;
            count++;
        }
    }

    if (count == 0) {
        printf("Element not found\n");
    } else {
        printf("All occurrences at indices: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", allOccurrences[i]);
        }
        printf("\n");
    }

    return 0;
}