#include <stdio.h>

#define MAX 100

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int topo[MAX];
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v), where u -> v:\n");

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        indegree[v]++;
    }

    // Step 1: Add all vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 2: Kahn's Algorithm
    while (front < rear) {
        int u = queue[front++];

        topo[count++] = u;

        // Decrease in-degree of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // Step 3: Check for cycle
    if (count != n) {
        printf("Topological sorting is not possible.\n");
        printf("The graph contains a cycle.\n");
    } else {
        printf("Topological Order: ");

        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }

        printf("\n");
    }

    return 0;
}