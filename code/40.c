#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int n, i, a = 0, b = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    printf("%d %d ", a, b);

    for (i = 3; i <= n; ++i) {
        nextTerm = a + b;
        printf("%d ", nextTerm);
        a = b;
        b = nextTerm;
    }

    return 0;
}