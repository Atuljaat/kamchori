#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

int evaluatePostfix(char *expression) {
    Stack stack;
    initialize(&stack);
    int i, operand1, operand2, result;

    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == ' ') {
            continue;
        }
        else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid Operator\n");
                    return -1;
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}

int main() {
    printf("Prerit || BCA-2A");
    char expression[MAX_SIZE];

    printf("\nEnter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = 0;

    int result = evaluatePostfix(expression);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}