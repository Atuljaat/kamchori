#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int i;

    head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &(head->data));
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &(newNode->data));
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void displayList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Prerit || BCA-2A
    int n;
    struct Node *head = NULL, *reversedHead = NULL;

    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    head = createList(n);
    reversedHead = reverseList(head);

    printf("Reversed Linked List: ");
    displayList(reversedHead);

    return 0;
}