#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

Node *head[4];

void enqueue(int data, int priority) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (head[priority] == NULL) {
        head[priority] = newNode;
    } else {
        Node *current = head[priority];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int dequeue() {
    for (int i = 3; i >= 1; i--) {
        if (head[i] != NULL) {
            Node *temp = head[i];
            int data = temp->data;
            head[i] = temp->next;
            free(temp);
            return data;
        }
    }
    return -1;
}

int isEmpty() {
    for (int i = 1; i <= 3; i++) {
        if (head[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

void display() {
    for (int i = 3; i >= 1; i--) {
        printf("Priority %d: ", i);
        Node *current = head[i];
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    printf("Prerit || BCA-2A");
    for (int i = 0; i <= 3; i++)
        head[i] = NULL;

    enqueue(10, 2);
    enqueue(14, 3);
    enqueue(16, 1);
    enqueue(12, 2);
    enqueue(18, 3);

    printf("Priority Queue:\n");
    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    printf("Priority Queue after dequeues:\n");
    display();

    return 0;
}