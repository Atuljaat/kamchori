#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int n, i, key, found = 0;

printf("Enter the size of the list: ");
scanf("%d", &n);

int list[n];

printf("Enter the elements of the list: ");
for (i = 0; i < n; i++) {
scanf("%d", &list[i]);
}

printf("Enter the element to be searched: ");
scanf("%d", &key);

for (i = 0; i < n; i++) {
if (list[i] == key) {
found = 1;
break;
}
}

if (found == 1) {
printf("Element found\n");
} else {
printf("Element not found\n");
}

return 0;
}
#include <stdio.h>

int main() {
printf("Prerit || BCA-2A");
int n, i, key, found = 0;

printf("Enter the size of the list: ");
scanf("%d", &n);

int list[n];

printf("Enter the elements of the list: ");
for (i = 0; i < n; i++) {
scanf("%d", &list[i]);
}

printf("Enter the element to be searched: ");
scanf("%d", &key);

for (i = 0; i < n; i++) {
if (list[i] == key) {
found = 1;
break;
}
}

if (found == 1) {
printf("Element found\n");
} else {
printf("Element not found\n");
}

return 0;
}