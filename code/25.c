#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertAtEnd(int value) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (head == NULL) {
newNode->prev = NULL;
head = newNode;
tail = newNode;
} else {
newNode->prev = tail;
tail->next = newNode;
tail = newNode;
}
}

void displayList() {
struct Node *current = head;
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}

void searchElement(int key) {
struct Node *current = head;
while (current != NULL) {
if (current->data == key) {
printf("Element found\n");
return;
}
current = current->next;
}
printf("Element not found\n");
}

int main() {
printf("Prerit || BCA-2A");
int n, value, key;
printf("Enter the number of elements: ");
scanf("%d", &n);
printf("Enter the elements: ");
for (int i = 0; i < n; i++) {
scanf("%d", &value);
insertAtEnd(value);
}
printf("Doubly Linked List: ");
displayList();
printf("Enter the element to search: ");
scanf("%d", &key);
searchElement(key);
return 0;
}