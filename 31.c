#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d", stack[i]);
            if (i != 0)
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n, op, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &op);

        switch (op) {
            case 1:
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;
        }
    }

    return 0;
}