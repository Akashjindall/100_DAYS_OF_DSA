#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

int main() {
    int n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    while (front <= rear) {
        stack[++top] = queue[front++];
    }

    front = 0;
    rear = -1;

    while (top != -1) {
        queue[++rear] = stack[top--];
    }

    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}