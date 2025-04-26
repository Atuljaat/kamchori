#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertBetween(struct Node **head, int data, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot insert at specified position.\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp = *head;
    int count = 1;
    while (temp->next != *head && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (count != position - 1) {
        printf("Position not found.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
    } else {
        struct Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = temp->next;
        last->next = *head;
        free(temp);
    }
}

void deleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
}

void deleteBetween(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    int count = 1;

    if(position == 1){
        deleteAtBeginning(head);
        return;
    }

    while (temp->next != *head && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count != position) {
        printf("Position not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void traverse(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int linearSearch(struct Node *head, int key) {
    if (head == NULL) {
        return 0;
    }
    struct Node *temp = head;
    int position = 1;
    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    return 0;
}

int main() {
    printf("Prerit || BCA-2A");
    struct Node *head = NULL;
    int choice, data, position, searchKey, searchResult;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Between\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete Between\n");
        printf("7. Traverse\n");
        printf("8. Linear Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertBetween(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteBetween(&head, position);
                break;
            case 7:
                printf("Circular Linked List: ");
                traverse(head);
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &searchKey);
                searchResult = linearSearch(head, searchKey);
                if (searchResult) {
                    printf("%d found at position %d\n", searchKey, searchResult);
                } else {
                    printf("%d not found in the list\n", searchKey);
                }
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