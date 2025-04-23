#include <stdio.h>

int main() {
  int num1, num2, product;

  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);

  product = num1 * num2;

  printf("Product = %d\n", product);

  return 0;
}