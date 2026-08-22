#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Convert tree into its mirror
void mirror(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror both subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 0)
        return 0;

    struct Node** nodes = (struct Node**)malloc(N * sizeof(struct Node*));

    // Read level-order input
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);

        if (value == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(value);
    }

    // Connect nodes according to level order
    for (int i = 0; i < N; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < N)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < N)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    struct Node* root = nodes[0];

    // Convert to mirror
    mirror(root);

    // Print inorder traversal
    inorder(root);

    free(nodes);

    return 0;
}