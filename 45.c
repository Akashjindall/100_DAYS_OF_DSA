#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node **arr;
    int front;
    int rear;
} Queue;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int values[], int n) {
    if (n == 0 || values[0] == -1)
        return NULL;

    Node *root = createNode(values[0]);

    Queue q;
    q.arr = (Node**)malloc(n * sizeof(Node*));
    q.front = 0;
    q.rear = 0;

    q.arr[q.rear++] = root;

    int i = 1;

    while (i < n && q.front < q.rear) {
        Node *current = q.arr[q.front++];

        // Left child
        if (i < n && values[i] != -1) {
            current->left = createNode(values[i]);
            q.arr[q.rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && values[i] != -1) {
            current->right = createNode(values[i]);
            q.arr[q.rear++] = current->right;
        }
        i++;
    }

    free(q.arr);
    return root;
}

int height(Node *root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int N;
    scanf("%d", &N);

    int values[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    Node *root = buildTree(values, N);

    printf("%d\n", height(root));

    return 0;
}