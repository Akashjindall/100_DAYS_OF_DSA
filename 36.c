#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        return; 
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
}

int dequeue() {
    if (front == -1) {
        return -1; 
    }

    int value = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return value;
}

void display() {
    if (front == -1)
        return;

    int i = front;
    while (1) {
        printf("%d", queue[i]);
        if (i == rear)
            break;
        printf(" ");
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        x = dequeue();
        if (x != -1)
            enqueue(x);
    }

    display();

    return 0;
}