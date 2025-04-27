#include <stdio.h>
#include <stdlib.h>

int queue[100];
int front = -1, rear = -1, size;

void insert() {
    int val;
    if ((rear + 1) % size == front) {
        printf("Queue is full\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &val);
    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    queue[rear] = val;
    printf("Inserted\n");
}

void delete() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element is: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: \n");
    for (i = front; i != rear; i = (i + 1) % size) {
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[rear]);
    printf("\n");
}

int main() {
    printf("Prerit || BCA-2A");
    int choice;
    printf("\nEnter the size of Queue : ");
    scanf("%d", &size);
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}