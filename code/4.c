#include <stdio.h>

int main() {
    int n, i, num, found = 0, index;

    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &num);

    for (i = 0; i < n; i++) {
        if (arr[i] == num) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) {
        for (i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Element not found\n");
    }

    return 0;
}