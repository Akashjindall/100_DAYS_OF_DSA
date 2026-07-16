#include <stdio.h>
#include <stdlib.h>

#define SIZE 200003

typedef struct Node {
    long long sum;
    long long count;
    struct Node *next;
} Node;

Node *hash[SIZE];

int hashFunc(long long x) {
    if (x < 0) x = -x;
    return x % SIZE;
}

long long getCount(long long sum) {
    int idx = hashFunc(sum);
    Node *temp = hash[idx];
    while (temp) {
        if (temp->sum == sum)
            return temp->count;
        temp = temp->next;
    }
    return 0;
}

void insert(long long sum) {
    int idx = hashFunc(sum);
    Node *temp = hash[idx];

    while (temp) {
        if (temp->sum == sum) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->count = 1;
    newNode->next = hash[idx];
    hash[idx] = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    long long prefixSum = 0;
    long long answer = 0;
    int x;

    insert(0); 

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        prefixSum += x;

        answer += getCount(prefixSum);
        insert(prefixSum);
    }

    printf("%lld\n", answer);

    return 0;
}