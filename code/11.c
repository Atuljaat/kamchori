#include <stdio.h>

int main() {
  int choice;

  printf("Menu:\n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("Enter your choice (1-4): ");
  scanf("%d", &choice);

  float num1, num2, result;

  switch (choice) {
    case 1:
      printf("Enter two numbers: ");
      scanf("%f %f", &num1, &num2);
      result = num1 + num2;
      printf("Result: %.2f\n", result);
      break;
    case 2:
      printf("Enter two numbers: ");
      scanf("%f %f", &num1, &num2);
      result = num1 - num2;
      printf("Result: %.2f\n", result);
      break;
    case 3:
      printf("Enter two numbers: ");
      scanf("%f %f", &num1, &num2);
      result = num1 * num2;
      printf("Result: %.2f\n", result);
      break;
    case 4:
      printf("Enter two numbers: ");
      scanf("%f %f", &num1, &num2);
      if (num2 == 0) {
        printf("Error: Division by zero!\n");
      } else {
        result = num1 / num2;
        printf("Result: %.2f\n", result);
      }
      break;
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}