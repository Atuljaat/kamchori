#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int size, i, j, k;

printf("\nEnter the size of the list: ");
scanf("%d", &size);

int list[size];
int uniqueList[size];
int uniqueSize = 0;

printf("Enter elements:\n");
for (i = 0; i < size; i++) {
scanf("%d", &list[i]);
}

for (i = 0; i < size; i++) {
int isDuplicate = 0;
for (j = 0; j < uniqueSize; j++) {
if (list[i] == uniqueList[j]) {
isDuplicate = 1;
break;
}
}
if (!isDuplicate) {
uniqueList[uniqueSize] = list[i];
uniqueSize++;
}
}

printf("List after removing duplicates: ");
for (i = 0; i < uniqueSize; i++) {
printf("%d ", uniqueList[i]);
}
printf("\n");

return 0;
}