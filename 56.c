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

// Check whether two trees are mirror images
int isMirror(struct Node* left, struct Node* right) {
    // Both are NULL
    if (left == NULL && right == NULL)
        return 1;

    // One is NULL and the other is not
    if (left == NULL || right == NULL)
        return 0;

    // Values must be equal and subtrees must be mirrors
    return (left->data == right->data &&
            isMirror(left->left, right->right) &&
            isMirror(left->right, right->left));
}

// Check symmetry
int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    if (N == 0 || arr[0] == -1) {
        printf("YES\n");
        return 0;
    }

    // Create nodes
    struct Node* nodes[N];

    for (int i = 0; i < N; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Connect nodes according to level-order representation
    for (int i = 0; i < N; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < N)
                nodes[i]->left = nodes[left];

            if (right < N)
                nodes[i]->right = nodes[right];
        }
    }

    if (isSymmetric(nodes[0]))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}