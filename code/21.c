#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = head;
head = newNode;
}

void insertAtEnd(int data) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
return;
}
struct Node *temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}

void insertAfter(int key, int data) {
struct Node *temp = head;
while (temp != NULL && temp->data != key) {
temp = temp->next;
}
if (temp == NULL) {
printf("Node with key %d not found\n", key);
return;
}
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = temp->next;
temp->next = newNode;
}

void insertBefore(int key, int data) {
if (head == NULL) return;

if (head->data == key) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = head;
head = newNode;
return;
}

struct Node *current = head;
struct Node *previous = NULL;

while (current != NULL && current->data != key) {
previous = current;
current = current->next;
}

if (current == NULL) {
printf("Node with key %d not found\n", key);
return;
}

struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = current;
previous->next = newNode;
}

void displayList() {
struct Node *temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main() {
printf("Prerit || BCA-2A");
int choice, data, key;

do {
printf("\nSingly Linked List Operations:\n");
printf("1. Insert at Beginning\n");
printf("2. Insert at End\n");
printf("3. Insert After\n");
printf("4. Insert Before\n");
printf("5. Display List\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter data to insert at the beginning: ");
scanf("%d", &data);
insertAtBeginning(data);
break;
case 2:
printf("Enter data to insert at the end: ");
scanf("%d", &data);
insertAtEnd(data);
break;
case 3:
printf("Enter the key after which to insert: ");
scanf("%d", &key);
printf("Enter data to insert: ");
scanf("%d", &data);
insertAfter(key, data);
break;
case 4:
printf("Enter the key before which to insert: ");
scanf("%d", &key);
printf("Enter data to insert: ");
scanf("%d", &data);
insertBefore(key, data);
break;
case 5:
printf("Linked List: ");
displayList();
break;
case 0:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 0);

return 0;
}