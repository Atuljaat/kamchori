#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};

struct Node *head = NULL;

void insertNode(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
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

int countNodes() {
int count = 0;
struct Node *temp = head;
while (temp != NULL) {
count++;
temp = temp->next;
}
return count;
}

void findMinMax() {
if (head == NULL) {
printf("List is empty.\n");
return;
}

int min = head->data;
int max = head->data;
struct Node *temp = head->next;

while (temp != NULL) {
if (temp->data < min) {
min = temp->data;
}
if (temp->data > max) {
max = temp->data;
}
temp = temp->next;
}

printf("Minimum value: %d\n", min);
printf("Maximum value: %d\n", max);
}

int main() {
printf("Prerit || BCA-2A");
int n, data, i;

printf("\nEnter the number of elements: ");
scanf("%d", &n);

printf("Enter the elements: ");
for (i = 0; i < n; i++) {
scanf("%d", &data);
insertNode(data);
}

printf("Number of nodes: %d\n", countNodes());
findMinMax();

struct Node *temp = head;
struct Node *next;
while(temp!=NULL){
next = temp->next;
free(temp);
temp = next;
}
head = NULL;

return 0;
}