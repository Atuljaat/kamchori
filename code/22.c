#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}

void insertNode(struct Node** head, int data) {
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

struct Node* createList() {
int size, data;
struct Node* head = NULL;
printf("Enter the size: ");
scanf("%d", &size);
printf("Enter elements: ");
for (int i = 0; i < size; i++) {
scanf("%d", &data);
insertNode(&head, data);
}
return head;
}

void displayList(struct Node* head) {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node* temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
struct Node* mergedList = NULL;
struct Node* tail = NULL;

while (list1 != NULL && list2 != NULL) {
struct Node* newNode;
if (list1->data <= list2->data) {
newNode = createNode(list1->data);
list1 = list1->next;
} else {
newNode = createNode(list2->data);
list2 = list2->next;
}

if (mergedList == NULL) {
mergedList = newNode;
tail = newNode;
} else {
tail->next = newNode;
tail = newNode;
}
}

while (list1 != NULL) {
struct Node* newNode = createNode(list1->data);
if (mergedList == NULL) {
mergedList = newNode;
tail = newNode;
} else {
tail->next = newNode;
tail = newNode;
}
list1 = list1->next;
}

while (list2 != NULL) {
struct Node* newNode = createNode(list2->data);
if (mergedList == NULL) {
mergedList = newNode;
tail = newNode;
} else {
tail->next = newNode;
tail = newNode;
}
list2 = list2->next;
}

return mergedList;
}

void sortList(struct Node* head) {
if (head == NULL || head->next == NULL) {
return;
}

struct Node* current;
struct Node* index;
int temp;

for (current = head; current != NULL; current = current->next) {
for (index = current->next; index != NULL; index = index->next) {
if (current->data > index->data) {
temp = current->data;
current->data = index->data;
index->data = temp;
}
}
}
}

void freeList(struct Node* head) {
struct Node* temp;
while (head != NULL) {
temp = head;
head = head->next;
free(temp);
}
}

int main() {
printf("Prerit || BCA-2A");
struct Node* list1;
struct Node* list2;
struct Node* mergedList;

printf("\nCreating List 1:\n");
list1 = createList();

printf("\nCreating List 2:\n");
list2 = createList();

sortList(list1);
sortList(list2);

mergedList = mergeSortedLists(list1, list2);

printf("\nMerged and Sorted List:\n");
displayList(mergedList);

freeList(list1);
freeList(list2);
freeList(mergedList);

return 0;
}