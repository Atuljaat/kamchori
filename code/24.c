#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int data) {
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

void displayList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteAtBeginning() {
    if (head == NULL) return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) return;
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

void deleteAfterGivenNode(int givenData) {
    if (head == NULL) return;
    struct Node *temp = head;
    while (temp != NULL && temp->data != givenData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (temp->next == NULL) {
        printf("No node after the given node.\n");
        return;
    }
    struct Node *nextNode = temp->next;
    temp->next = nextNode->next;
    free(nextNode);
}

void searchAndDelete(int key) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    printf("Prerit || BCA-2A");
    int choice, data, givenData, key;
    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Delete After Given Node\n");
        printf("6. Search and Delete\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                printf("Linked List: ");
                displayList();
                break;
            case 3:
                deleteAtBeginning();
                printf("Deleted node at beginning.\n");
                break;
            case 4:
                deleteAtEnd();
                printf("Deleted node at end.\n");
                break;
            case 5:
                printf("Enter data of the node after which to delete: ");
                scanf("%d", &givenData);
                deleteAfterGivenNode(givenData);
                break;
            case 6:
                printf("Enter element to search and delete: ");
                scanf("%d", &key);
                searchAndDelete(key);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}