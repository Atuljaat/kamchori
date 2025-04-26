#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int num1, num2, difference;

    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    difference = num1 - num2;

    printf("The difference is: %d\n", difference);

    return 0;
}