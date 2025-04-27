#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  printf("Prerit || BCA-2A");
  int num;
  printf("\nEnter a positive integer: ");
  scanf("%d", &num);
  if (num < 0) {
      printf("Factorial is not defined for negative numbers.\n");
  } else {
      printf("Factorial of %d = %d\n", num, factorial(num));
  }
  return 0;
}