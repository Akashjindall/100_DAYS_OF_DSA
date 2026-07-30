#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node for stack
struct Node {
    int data;
    struct Node *next;
};

// Push operation
void push(struct Node **top, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct Node *temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    struct Node *top = NULL;
    char *token = strtok(exp, " ");

    while (token != NULL) {

        // If operand
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&top, atoi(token));
        }
        // If operator
        else {
            int b = pop(&top);
            int a = pop(&top);
            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                case '%':
                    result = a % b;
                    break;
                default:
                    printf("Invalid Operator\n");
                    exit(1);
            }

            push(&top, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&top);
}

int main() {
    char exp[200];

    printf("Enter postfix expression:\n");
    fgets(exp, sizeof(exp), stdin);

    // Remove newline character
    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluatePostfix(exp);

    printf("%d\n", result);

    return 0;
}