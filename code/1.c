#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int n, key, i, first_occurrence = -1, count = 0;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            first_occurrence = i;
            break;
        }
    }

    if (first_occurrence == -1) {
        printf("Element not found\n");
    } else {
        printf("First occurrence at index: %d\n", first_occurrence);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Occurrence at index: %d\n", i);
            count++;
        }
    }
if(first_occurrence != -1 && count == 0)
{
}
}