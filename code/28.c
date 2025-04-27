#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Term *createTerm(int coefficient, int exponent) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Term **poly, int coefficient, int exponent) {
    struct Term *newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
        return;
    }

    if (exponent > (*poly)->exponent) {
        newTerm->next = *poly;
        *poly = newTerm;
        return;
    }

    struct Term *curr = *poly;
    struct Term *prev = NULL;

    while (curr != NULL && curr->exponent > exponent) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->exponent == exponent) return;

    newTerm->next = curr;
    if(prev != NULL)
        prev->next = newTerm;
    else
        *poly = newTerm;
}

struct Term *createPolynomial() {
    int n, coefficient, exponent;
    struct Term *poly = NULL;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly, coefficient, exponent);
    }
    return poly;
}

void displayPolynomial(struct Term *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Term *curr = poly;
    while (curr != NULL) {
        printf("%dx^%d", curr->coefficient, curr->exponent);
        curr = curr->next;
        if (curr != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Term *addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;
    struct Term *curr1 = poly1;
    struct Term *curr2 = poly2;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->exponent == curr2->exponent) {
            int sum = curr1->coefficient + curr2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, curr1->exponent);
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        } else if (curr1->exponent > curr2->exponent) {
            insertTerm(&result, curr1->coefficient, curr1->exponent);
            curr1 = curr1->next;
        } else {
            insertTerm(&result, curr2->coefficient, curr2->exponent);
            curr2 = curr2->next;
        }
    }

    while (curr1 != NULL) {
        insertTerm(&result, curr1->coefficient, curr1->exponent);
        curr1 = curr1->next;
    }

    while (curr2 != NULL) {
        insertTerm(&result, curr2->coefficient, curr2->exponent);
        curr2 = curr2->next;
    }

    return result;
}

void freePolynomial(struct Term *poly) {
    struct Term *curr = poly;
    while (curr != NULL) {
        struct Term *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    printf("Prerit || BCA-2A");
    struct Term *poly1, *poly2, *sum;

    printf("\nPolynomial 1:\n");
    poly1 = createPolynomial();

    printf("\nPolynomial 2:\n");
    poly2 = createPolynomial();

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("\nSum of the polynomials: ");
    displayPolynomial(sum);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);

    return 0;
}