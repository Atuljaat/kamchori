#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
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

    int minVal = head->data;
    int maxVal = head->data;

    struct Node *temp = head->next;
    while (temp != NULL) {
        if (temp->data < minVal) {
            minVal = temp->data;
        }
        if (temp->data > maxVal) {
            maxVal = temp->data;
        }
        temp = temp->next;
    }

    printf("Minimum value: %d\n", minVal);
    printf("Maximum value: %d\n", maxVal);
}
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("Prerit || BCA-2A");
    int n, data, count;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(data);
    }

    displayList();

    count = countNodes();
    printf("Number of nodes: %d\n", count);

    findMinMax();

    return 0;
}