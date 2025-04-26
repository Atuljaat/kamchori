#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

int main() {
    printf("Prerit || BCA-2A");
    char str[100];
    printf("\nEnter a string: ");
    scanf("%s", str);

    int n = strlen(str);
    struct Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
    }

    printf("Reversed string: ");
    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
    printf("\n");

    free(stack->array);
    free(stack);

    return 0;
}