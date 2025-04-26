#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}

void insertAtBeginning(int data) {
struct Node* newNode = createNode(data);
newNode->next = head;
head = newNode;
}

void insertAtEnd(int data) {
struct Node* newNode = createNode(data);
if (head == NULL) {
head = newNode;
return;
}
struct Node* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}

void insertAtPosition(int data, int position) {
struct Node* newNode = createNode(data);
if (position == 1) {
newNode->next = head;
head = newNode;
return;
}
struct Node* temp = head;
int i = 1;
while (i < position - 1 && temp != NULL) {
temp = temp->next;
i++;
}
if (temp == NULL) {
printf("Invalid position\n");
free(newNode);
return;
}
newNode->next = temp->next;
temp->next = newNode;
}

void deleteNode(int data) {
struct Node* temp = head;
struct Node* prev = NULL;

if (temp != NULL && temp->data == data) {
head = temp->next;
free(temp);
return;
}

while (temp != NULL && temp->data != data) {
prev = temp;
temp = temp->next;
}

if (temp == NULL) {
printf("Node not found\n");
return;
}

prev->next = temp->next;
free(temp);
}

void displayList() {
struct Node* temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main() {
printf("Prerit || BCA-2A");
int choice, data, position;

do {
printf("\nSingly Linked List Operations:\n");
printf("1. Insert at Beginning\n");
printf("2. Insert at End\n");
printf("3. Insert at Position\n");
printf("4. Delete Node\n");
printf("5. Display List\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter data to insert: ");
scanf("%d", &data);
insertAtBeginning(data);
break;
case 2:
printf("Enter data to insert: ");
scanf("%d", &data);
insertAtEnd(data);
break;
case 3:
printf("Enter data to insert: ");
scanf("%d", &data);
printf("Enter position to insert at: ");
scanf("%d", &position);
insertAtPosition(data, position);
break;
case 4:
printf("Enter data to delete: ");
scanf("%d", &data);
deleteNode(data);
break;
case 5:
printf("Linked List: ");
displayList();
break;
case 6:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 6);

return 0;
}