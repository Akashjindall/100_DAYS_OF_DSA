#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void push_front(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }

    if (front == -1) { 
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = value;
}

void push_back(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

int getFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    return deque[front];
}

int getBack() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    return deque[rear];
}

int size() {
    if (isEmpty()) return 0;

    if (rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    int i = front;
    printf("Deque: ");

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void clearDeque() {
    front = rear = -1;
}

void reverseDeque() {
    if (isEmpty()) return;

    int temp[MAX];
    int i = front, j = 0;

    while (1) {
        temp[j++] = deque[i];
        if (i == rear) break;
        i = (i + 1) % MAX;
    }

    for (int k = 0; k < j / 2; k++) {
        int t = temp[k];
        temp[k] = temp[j - k - 1];
        temp[j - k - 1] = t;
    }

    front = 0;
    rear = j - 1;
    for (int k = 0; k < j; k++) {
        deque[k] = temp[k];
    }
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getBack());

    pop_front();
    pop_back();

    display();

    printf("Size: %d\n", size());

    reverseDeque();
    printf("After Reverse:\n");
    display();

    clearDeque();
    display();

    return 0;
}