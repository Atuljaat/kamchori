#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertBetween(int data, int position) {
    if (head == NULL) {
        printf("List is empty. Cannot insert between.\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp = head;
    int count = 1;
    while (count < position && temp->next != head) {
        temp = temp->next;
        count++;
    }
    if (count != position) {
        printf("Position not found.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    head = head->next;
    last->next = head;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

void deleteBetween(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->next == head && position == 1) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    int count = 1;

    while (count < position && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count != position) {
        printf("Position not found.\n");
        return;
    }

    if (temp == head) {
      printf("Deletion at beginning required\n");
      return;
    }
    prev->next = temp->next;
    free(temp);
}


void traverse() {
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

int linearSearch(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return -1;
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
    return -1;
}

int main() {
    printf("Prerit || BCA-2A");
    int choice, data, position, key, searchResult;

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
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert after: ");
                scanf("%d", &position);
                insertBetween(data, position);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteBetween(position);
                break;
            case 7:
                printf("Circular Linked List: ");
                traverse();
                break;
            case 8:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                searchResult = linearSearch(key);
                if (searchResult == -1) {
                    printf("Key not found.\n");
                } else {
                    printf("Key found at position %d.\n", searchResult);
                }
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}