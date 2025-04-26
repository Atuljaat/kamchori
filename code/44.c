#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int search(struct Node* root, int data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findMax(struct Node* root) {
    if (root == NULL) return -1;
    if (root->right == NULL) return root->data;
    return findMax(root->right);
}

int findMinVal(struct Node* root) {
    if (root == NULL) return -1;
    if (root->left == NULL) return root->data;
    return findMinVal(root->left);
}

int height(struct Node* root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}

int main() {
    printf("Prerit || BCA-2A");
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Count Nodes\n");
        printf("5. Find Maximum\n");
        printf("6. Find Minimum\n");
        printf("7. Find Height\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 4:
                printf("Number of nodes: %d\n", countNodes(root));
                break;
            case 5:
                printf("Maximum element: %d\n", findMax(root));
                break;
            case 6:
                printf("Minimum element: %d\n", findMinVal(root));
                break;
            case 7:
                printf("Height of the tree: %d\n", height(root));
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}