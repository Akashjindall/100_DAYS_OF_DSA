#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[100];
int visited[100];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void DFS(int s) {
    struct Node* temp;

    visited[s] = 1;
    printf("%d ", s);

    temp = adj[s];

    while (temp != NULL) {
        int v = temp->vertex;

        if (!visited[v]) {
            DFS(v);
        }

        temp = temp->next;
    }
}

int main() {
    int n, edges, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph
        addEdge(u, v);
        addEdge(v, u);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    DFS(s);

    return 0;
}