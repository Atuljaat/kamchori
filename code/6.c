#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int arr[100], n, position, i;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > n) {
        printf("Invalid position\n");
    } else {
        for (i = position - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("Resultant array: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}