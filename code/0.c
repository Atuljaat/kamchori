#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int intArray[5] = {10, 20, 30, 40, 50};
    float floatArray[5];
    int n, i;

    printf("Enter the number of elements for the floating-point array (up to 5): ");
    scanf("%d", &n);

    printf("Enter %d floating-point elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &floatArray[i]);
    }

    printf("Integer Array Elements:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    printf("Floating-Point Array Elements:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", floatArray[i]);
    }
    printf("\n");

    return 0;
}