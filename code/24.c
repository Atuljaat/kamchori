#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int data) {
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

void deleteBeginning() {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node *temp = head;
head = head->next;
free(temp);
}

void deleteEnd() {
if (head == NULL) {
printf("List is empty\n");
return;
}
if (head->next == NULL) {
free(head);
head = NULL;
return;
}
struct Node *current = head;
struct Node *previous = NULL;
while (current->next != NULL) {
previous = current;
current = current->next;
}
previous->next = NULL;
free(current);
}

void deleteAfter(int key) {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node *current = head;
while (current != NULL) {
if (current->data == key) {
if (current->next == NULL) {
printf("No node exists after the given node\n");
return;
}
struct Node *temp = current->next;
current->next = temp->next;
free(temp);
return;
}
current = current->next;
}
printf("Node with the given key not found\n");
}

void searchAndDelete(int key) {
if (head == NULL) {
printf("List is empty\n");
return;
}

if (head->data == key) {
struct Node *temp = head;
head = head->next;
free(temp);
return;
}

struct Node *current = head;
struct Node *previous = NULL;

while (current != NULL && current->data != key) {
previous = current;
current = current->next;
}

if (current == NULL) {
printf("Element not found\n");
return;
}

previous->next = current->next;
free(current);
}

void printList() {
if (head == NULL) {
printf("List is empty\n");
return;
}
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
while (1) {
printf("\n1. Insert at end\n2. Delete at beginning\n3. Delete at end\n4. Delete after\n5. Search and Delete\n6. Print list\n7. Exit\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert: ");
scanf("%d", &data);
insertEnd(data);
break;
case 2:
deleteBeginning();
break;
case 3:
deleteEnd();
break;
case 4:
printf("Enter the key after which to delete: ");
scanf("%d", &key);
deleteAfter(key);
break;
case 5:
printf("Enter the element to search and delete: ");
scanf("%d", &key);
searchAndDelete(key);
break;
case 6:
printList();
break;
case 7:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}