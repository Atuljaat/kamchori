#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

struct HeaderNode {
    int data;
    struct HeaderNode* next;
};

struct DoublyNode* doublyHead = NULL;
struct DoublyNode* doublyTail = NULL;
struct HeaderNode* header = NULL;

void insertDoublyBeginning(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = doublyHead;

    if (doublyHead == NULL) {
        doublyHead = newNode;
        doublyTail = newNode;
    } else {
        doublyHead->prev = newNode;
        doublyHead = newNode;
    }
}

void insertDoublyEnd(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = doublyTail;

    if (doublyTail == NULL) {
        doublyHead = newNode;
        doublyTail = newNode;
    } else {
        doublyTail->next = newNode;
        doublyTail = newNode;
    }
}

void insertDoublyMiddle(int data, int position) {
    if (doublyHead == NULL) {
        printf("List is empty. Cannot insert at middle.\n");
        return;
    }

    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;

    if (position == 1) {
        newNode->next = doublyHead;
        newNode->prev = NULL;
        doublyHead->prev = newNode;
        doublyHead = newNode;
        return;
    }

    struct DoublyNode* current = doublyHead;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of bounds. Cannot insert at middle.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    } else {
        doublyTail = newNode;
    }
    current->next = newNode;
}

void deleteDoublyBeginning() {
    if (doublyHead == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }

    struct DoublyNode* temp = doublyHead;
    doublyHead = doublyHead->next;

    if (doublyHead != NULL) {
        doublyHead->prev = NULL;
    } else {
        doublyTail = NULL;
    }

    free(temp);
}

void deleteDoublyEnd() {
    if (doublyTail == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }

    struct DoublyNode* temp = doublyTail;
    doublyTail = doublyTail->prev;

    if (doublyTail != NULL) {
        doublyTail->next = NULL;
    } else {
        doublyHead = NULL;
    }

    free(temp);
}

void deleteDoublyMiddle(int position) {
    if (doublyHead == NULL) {
        printf("List is empty. Cannot delete from middle.\n");
        return;
    }

    struct DoublyNode* current = doublyHead;
    int count = 1;

    if (position == 1) {
        doublyHead = doublyHead->next;
        if (doublyHead != NULL) {
            doublyHead->prev = NULL;
        } else {
            doublyTail = NULL;
        }
        free(current);
        return;
    }

    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of bounds. Cannot delete from middle.\n");
        return;
    }

    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        doublyTail = current->prev;
    }

    free(current);
}

void displayDoubly() {
    struct DoublyNode* current = doublyHead;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void createHeaderList() {
    header = (struct HeaderNode*)malloc(sizeof(struct HeaderNode));
    header->data = -1;
    header->next = NULL;
}

void insertHeaderBeginning(int data) {
    struct HeaderNode* newNode = (struct HeaderNode*)malloc(sizeof(struct HeaderNode));
    newNode->data = data;
    newNode->next = header->next;
    header->next = newNode;
}

void insertHeaderBetween(int data, int position) {
    struct HeaderNode* current = header;
    int count = 1;

    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of bounds. Cannot insert.\n");
        return;
    }

    struct HeaderNode* newNode = (struct HeaderNode*)malloc(sizeof(struct HeaderNode));
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
}

void insertHeaderEnd(int data) {
    struct HeaderNode* newNode = (struct HeaderNode*)malloc(sizeof(struct HeaderNode));
    newNode->data = data;
    newNode->next = NULL;

    struct HeaderNode* current = header;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteHeaderBeginning() {
    if (header->next == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }

    struct HeaderNode* temp = header->next;
    header->next = temp->next;
    free(temp);
}

void deleteHeaderBetween(int position) {
    struct HeaderNode* current = header;
    int count = 1;

    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position out of bounds. Cannot delete.\n");
        return;
    }

    struct HeaderNode* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void deleteHeaderEnd() {
    if (header->next == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }

    struct HeaderNode* current = header;
    struct HeaderNode* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

void displayHeader() {
    struct HeaderNode* current = header->next;
    printf("Header Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("Prerit || BCA-2A");
    int choice, data, position;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Middle\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Middle\n");
        printf("7. Display Doubly Linked List\n");
        printf("\nHeader Linked List Operations:\n");
        printf("8. Create Header Linked List\n");
        printf("9. Insert at Beginning (Header)\n");
        printf("10. Insert Between (Header)\n");
        printf("11. Insert at End (Header)\n");
        printf("12. Delete at Beginning (Header)\n");
        printf("13. Delete Between (Header)\n");
        printf("14. Delete at End (Header)\n");
        printf("15. Display Header Linked List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertDoublyBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertDoublyEnd(data);
                break;
            case 3:
                printf("Enter data to insert at middle: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertDoublyMiddle(data, position);
                break;
            case 4:
                deleteDoublyBeginning();
                break;
            case 5:
                deleteDoublyEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteDoublyMiddle(position);
                break;
            case 7:
                displayDoubly();
                break;
            case 8:
                createHeaderList();
                break;
            case 9:
                if (header == NULL) {
                    printf("Create Header List first!\n");
                    break;
                }
                printf("Enter data to insert at beginning (Header): ");
                scanf("%d", &data);
                insertHeaderBeginning(data);
                break;
            case 10:
                if (header == NULL) {
                    printf("Create Header List first!\n");
                    break;
                }
                printf("Enter data to insert between (Header): ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertHeaderBetween(data, position);
                break;
            case 11:
                if (header == NULL) {
                    printf("Create Header List first!\n");
                    break;
                }
                printf("Enter data to insert at end (Header): ");
                scanf("%d", &data);
                insertHeaderEnd(data);
                break;
            case 12:
                if (header == NULL) {
                    printf("Create Header List first!\n");
                    break;
                }
                deleteHeaderBeginning();
                break;
            case 13:
                if (header == NULL) {
                    printf("Create Header List first!\n");
                    break;
                }
                printf("Enter the position to delete (Header): ");
                scanf("%d", &position);
                deleteHeaderBetween(position);
                break;
            case 14:
                if (header == NULL) {
                    printf("Create Header List first!\n");
                    break;
                }
                deleteHeaderEnd();
                break;
            case 15:
                if (header == NULL) {
                    printf("Create Header List first!\n");
                    break;
                }
                displayHeader();
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