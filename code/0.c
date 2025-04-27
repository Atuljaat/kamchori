#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int int_array[] = {10, 20, 30, 40, 50};
    int int_array_size = sizeof(int_array) / sizeof(int);
    int float_array_size;
    float float_array[100];

    printf("\nEnter the size of the floating-point array: ");
    scanf("%d", &float_array_size);

    printf("Enter the elements of the floating-point array:\n");
    for (int i = 0; i < float_array_size; i++) {
        scanf("%f", &float_array[i]);
    }

    printf("\nInteger Array Elements:\n");
    for (int i = 0; i < int_array_size; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n");

    printf("\nFloating-Point Array Elements:\n");
    for (int i = 0; i < float_array_size; i++) {
        printf("%f ", float_array[i]);
    }
    printf("\n");

    return 0;
}