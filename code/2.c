#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int arr[] = {12, 5, 8, 2, 15, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    int max = arr[0];
    int sum = 0;
    float average;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }
    average = (float)sum / size;
    printf("\nMinimum element: %d", min);
    printf("\nMaximum element: %d", max);
    printf("\nSum of elements: %d", sum);
    printf("\nAverage of elements: %.2f", average);
    return 0;
}