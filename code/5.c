#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int arr[100];
    int size, num, location, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be inserted: ");
    scanf("%d", &num);

    printf("Enter the location at which to insert the number: ");
    scanf("%d", &location);

    if (location < 0 || location > size) {
        printf("Invalid location. Location should be between 0 and %d\n", size);
        return 1;
    }

    for (i = size - 1; i >= location; i--) {
        arr[i + 1] = arr[i];
    }

    arr[location] = num;
    size++;

    printf("The modified array is: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}