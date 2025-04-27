#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int n, target, i, found = 0, index = -1;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    int list[n];

    printf("Enter the elements of the list: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++) {
        if (list[i] == target) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found == 1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found in the list.\n");
    }

    return 0;
}