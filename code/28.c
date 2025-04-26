#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

struct Node *createNode(int coefficient, int exponent) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node **poly, int coefficient, int exponent) {
    struct Node *newNode = createNode(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node *temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *p1 = poly1;
    struct Node *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent > p2->exponent) {
            insertTerm(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            insertTerm(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            int sum = p1->coefficient + p2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, p1->exponent);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertTerm(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

void displayPolynomial(struct Node *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Node *temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Node *poly) {
    struct Node *temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    printf("Prerit || BCA-2A");
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *result = NULL;
    int n1, n2, coeff, exp, i;

    printf("\nEnter the number of terms in polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the terms of polynomial 1 (coefficient exponent):\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("\nEnter the number of terms in polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter the terms of polynomial 2 (coefficient exponent):\n");
    for (i = 0; i < n2; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("\nSum of the polynomials: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}