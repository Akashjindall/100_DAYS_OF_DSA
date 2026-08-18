#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct {
    Node *node;
    int hd;
} QueueItem;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Build tree from level-order array */
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node *root = createNode(arr[0]);

    Node **queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        Node *current = queue[front++];

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

void verticalOrder(Node *root, int n) {
    if (root == NULL)
        return;

    QueueItem *queue = (QueueItem*)malloc(n * sizeof(QueueItem));

    int front = 0, rear = 0;
    int minHD = 0, maxHD = 0;

    queue[rear++] = (QueueItem){root, 0};

    // Store nodes according to horizontal distance
    int **columns = (int**)malloc((2 * n + 1) * sizeof(int*));
    int *sizes = (int*)calloc(2 * n + 1, sizeof(int));

    for (int i = 0; i < 2 * n + 1; i++)
        columns[i] = (int*)malloc(n * sizeof(int));

    while (front < rear) {
        QueueItem current = queue[front++];

        Node *node = current.node;
        int hd = current.hd;

        if (hd < minHD)
            minHD = hd;

        if (hd > maxHD)
            maxHD = hd;

        int index = hd + n;

        columns[index][sizes[index]++] = node->data;

        if (node->left != NULL) {
            queue[rear++] = (QueueItem){node->left, hd - 1};
        }

        if (node->right != NULL) {
            queue[rear++] = (QueueItem){node->right, hd + 1};
        }
    }

    // Print from leftmost vertical line to rightmost
    for (int hd = minHD; hd <= maxHD; hd++) {
        int index = hd + n;

        for (int j = 0; j < sizes[index]; j++) {
            if (j > 0)
                printf(" ");

            printf("%d", columns[index][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < 2 * n + 1; i++)
        free(columns[i]);

    free(columns);
    free(sizes);
    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node *root = buildTree(arr, n);

    verticalOrder(root, n);

    free(arr);

    return 0;
}