#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertAtEnd(struct Node *list, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list == NULL) {
        return newNode;
    }
    struct Node *temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return list;
}

struct Node *createList(struct Node *list, int size) {
    int data;
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        list = insertAtEnd(list, data);
    }
    return list;
}

struct Node *mergeSortedLists(struct Node *list1, struct Node *list2) {
    struct Node *mergedList = NULL;
    struct Node *tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct Node *newNode;
        if (list1->data <= list2->data) {
            newNode = list1;
            list1 = list1->next;
        } else {
            newNode = list2;
            list2 = list2->next;
        }

        if (mergedList == NULL) {
            mergedList = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        newNode->next = NULL;
    }

    if (list1 != NULL) {
        if (mergedList == NULL) {
            mergedList = list1;
        } else {
            tail->next = list1;
        }
    }

    if (list2 != NULL) {
        if (mergedList == NULL) {
            mergedList = list2;
        } else {
            tail->next = list2;
        }
    }

    return mergedList;
}


void printList(struct Node *list) {
    struct Node *temp = list;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node *list) {
    struct Node *temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}


int main() {
    printf("Prerit || BCA-2A");
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *mergedList = NULL;
    int size1, size2;

    printf("Enter the size of list1: ");
    scanf("%d", &size1);
    printf("Enter elements for list1: ");
    list1 = createList(list1, size1);

    printf("Enter the size of list2: ");
    scanf("%d", &size2);
    printf("Enter elements for list2: ");
    list2 = createList(list2, size2);

    mergedList = mergeSortedLists(list1, list2);

    printf("Merged sorted list: ");
    printList(mergedList);

    freeList(list1);
    freeList(list2);
    freeList(mergedList);

    return 0;
}