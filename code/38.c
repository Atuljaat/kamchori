#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
};

int queue1[100], queue2[100], queue3[100];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
int front3 = -1, rear3 = -1;

void enqueue(int data, int priority) {
    if (priority == 1) {
        if (rear1 == 99) printf("Queue 1 is full\n");
        else {
            if (front1 == -1) front1 = 0;
            queue1[++rear1] = data;
        }
    } else if (priority == 2) {
        if (rear2 == 99) printf("Queue 2 is full\n");
        else {
            if (front2 == -1) front2 = 0;
            queue2[++rear2] = data;
        }
    } else if (priority == 3) {
        if (rear3 == 99) printf("Queue 3 is full\n");
        else {
            if (front3 == -1) front3 = 0;
            queue3[++rear3] = data;
        }
    } else {
        printf("Invalid priority\n");
    }
}

int dequeue() {
    if (front3 != -1) {
        int data = queue3[front3++];
        if (front3 > rear3) front3 = rear3 = -1;
        return data;
    } else if (front2 != -1) {
        int data = queue2[front2++];
        if (front2 > rear2) front2 = rear2 = -1;
        return data;
    } else if (front1 != -1) {
        int data = queue1[front1++];
        if (front1 > rear1) front1 = rear1 = -1;
        return data;
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

void displayQueues() {
    printf("Queue 3: ");
    if (front3 == -1) printf("Empty\n");
    else {
        for (int i = front3; i <= rear3; i++) {
            printf("%d ", queue3[i]);
        }
        printf("\n");
    }
    printf("Queue 2: ");
    if (front2 == -1) printf("Empty\n");
    else {
        for (int i = front2; i <= rear2; i++) {
            printf("%d ", queue2[i]);
        }
        printf("\n");
    }
    printf("Queue 1: ");
    if (front1 == -1) printf("Empty\n");
    else {
        for (int i = front1; i <= rear1; i++) {
            printf("%d ", queue1[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Prerit || BCA-2A");
    int choice, data, priority;

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queues\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                printf("Enter priority (1: Lowest, 2, 3: Highest): ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                displayQueues();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}