#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countLeafNodes(struct TreeNode *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->data = 1;

    root->left = malloc(sizeof(struct TreeNode));
    root->left->data = 2;

    root->right = malloc(sizeof(struct TreeNode));
    root->right->data = 3;

    root->left->left = NULL;
    root->left->right = NULL;

    root->right->left = malloc(sizeof(struct TreeNode));
    root->right->left->data = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;

    root->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->data = 5;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    printf("%d\n", countLeafNodes(root));

    return 0;
}