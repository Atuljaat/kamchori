#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int size, i;

printf("Enter the size of the list: ");
scanf("%d", &size);

int list[size];

printf("Enter the elements of the list: ");
for (i = 0; i < size; i++) {
scanf("%d", &list[i]);
}

printf("The elements of the list are: ");
for (i = 0; i < size; i++) {
printf("%d ", list[i]);
}
printf("\n");

return 0;
}