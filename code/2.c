#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];
    int sum = 0;

    for (i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }

    float average = (float)sum / size;

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", average);

    return 0;
}