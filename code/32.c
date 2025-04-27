#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int main() {
    printf("Prerit || BCA-2A");
    char expression[100];
    char *e;
    int n1, n2, num, result;

    printf("Enter postfix expression: ");
    scanf("%s", expression);

    e = expression;

    while (*e != '\0') {
        if (isdigit(*e)) {
            num = *e - 48;
            push(num);
        } else {
            n1 = pop();
            n2 = pop();
            switch (*e) {
                case '+':
                    result = n2 + n1;
                    break;
                case '-':
                    result = n2 - n1;
                    break;
                case '*':
                    result = n2 * n1;
                    break;
                case '/':
                    result = n2 / n1;
                    break;
            }
            push(result);
        }
        e++;
    }
    printf("Result of expression: %d\n", pop());
    return 0;
}