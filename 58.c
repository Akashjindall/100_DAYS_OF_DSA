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

// Find the index of a value in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Construct tree from preorder and inorder
struct Node* buildTree(int preorder[], int inorder[],
                       int inStart, int inEnd, int *preIndex) {

    if (inStart > inEnd)
        return NULL;

    // First element of preorder is the root
    int rootValue = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = createNode(rootValue);

    // Find root in inorder
    int inIndex = search(inorder, inStart, inEnd, rootValue);

    // Construct left subtree
    root->left = buildTree(preorder, inorder,
                           inStart, inIndex - 1, preIndex);

    // Construct right subtree
    root->right = buildTree(preorder, inorder,
                            inIndex + 1, inEnd, preIndex);

    return root;
}

// Print postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);

    int preorder[N], inorder[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder,
                                  0, N - 1, &preIndex);

    postorder(root);

    return 0;
}