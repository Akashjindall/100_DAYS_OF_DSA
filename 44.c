#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level-order array
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node** queue = (Node**)malloc(n * sizeof(Node*));

    Node* root = createNode(arr[0]);
    queue[0] = root;

    int front = 0, rear = 1;
    int i = 1;

    while (i < n && front < rear) {
        Node* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, N);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}