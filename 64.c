#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, i, j;
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int s;

    // Number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Source vertex
    printf("Enter source vertex: ");
    scanf("%d", &s);

    // Start BFS
    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal: ");

    while (front < rear) {
        int u = queue[front++];

        printf("%d ", u);

        // Visit all adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[u][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}