#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}

void insertEnd(struct Node** head, int data) {
struct Node* newNode = createNode(data);
if (*head == NULL) {
*head = newNode;
return;
}
struct Node* temp = *head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}

struct Node* reverseList(struct Node* head) {
struct Node* reversedList = NULL;
struct Node* current = head;

while (current != NULL) {
struct Node* newNode = createNode(current->data);
newNode->next = reversedList;
reversedList = newNode;
current = current->next;
}
return reversedList;
}

void printList(struct Node* head) {
struct Node* temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main() {
printf("Prerit || BCA-2A");
int n, data, i;
struct Node* head = NULL;
struct Node* reversedHead = NULL;

printf("Enter the size: ");
scanf("%d", &n);

printf("Enter elements: ");
for (i = 0; i < n; i++) {
scanf("%d", &data);
insertEnd(&head, data);
}

printf("Original List: ");
printList(head);

reversedHead = reverseList(head);

printf("Reversed List: ");
printList(reversedHead);

return 0;
}