#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

int precedence(char symbol) {
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    char symbol;
    char temp[MAX];
    int len = strlen(infix);

    for (i = 0; i < len; i++) {
        temp[i] = infix[len - 1 - i];
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
    }
    temp[len] = '\0';
    strcpy(infix, temp);

    for (i = 0; i < len; i++) {
        symbol = infix[i];

        if (isalnum(symbol)) {
            prefix[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (stack[top] != '(') {
                prefix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(symbol) <= precedence(stack[top])) {
                prefix[j++] = pop();
            }
            push(symbol);
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
    len = strlen(prefix);
    for (i = 0; i < len / 2; i++) {
        char t = prefix[i];
        prefix[i] = prefix[len - 1 - i];
        prefix[len - 1 - i] = t;
    }
}

int main() {
    printf("Prerit || BCA-2A");
    char infix[MAX], prefix[MAX];

    printf("\nEnter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}