#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    int i, j = 0;
    int len = strlen(infix);
    char stack[len];
    int top = -1;

    char reversedInfix[len + 1];
    for (i = 0; i < len; i++) {
        reversedInfix[i] = infix[len - 1 - i];
        if (reversedInfix[i] == '(')
            reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')')
            reversedInfix[i] = '(';
    }
    reversedInfix[len] = '\0';

    for (i = 0; reversedInfix[i] != '\0'; i++) {
        if (isalnum(reversedInfix[i])) {
            prefix[j++] = reversedInfix[i];
        } else if (reversedInfix[i] == '(') {
            stack[++top] = reversedInfix[i];
        } else if (reversedInfix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                prefix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
                top--;
        } else {
            while (top >= 0 && precedence(reversedInfix[i]) <= precedence(stack[top])) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = reversedInfix[i];
        }
    }

    while (top >= 0) {
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0';

    char tempPrefix[j + 1];
    for (i = 0; i < j; i++) {
        tempPrefix[i] = prefix[j - 1 - i];
    }
    tempPrefix[j] = '\0';

    strcpy(prefix, tempPrefix);
}

int main() {
    printf("Prerit || BCA-2A");
    char infix[100];
    char prefix[100];

    printf("\nEnter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}