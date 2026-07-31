#include <stdio.h>
#define MAX 1000

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear)
            printf(" ");
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    return 0;
}