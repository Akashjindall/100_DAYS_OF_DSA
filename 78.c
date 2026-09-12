#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    int graph[MAX][MAX] = {0};

    scanf("%d %d", &n, &m);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;   // Undirected graph
    }

    int key[MAX];
    int visited[MAX];

    // Initialization
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start Prim's algorithm from vertex 1
    key[1] = 0;

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {

        // Find vertex with minimum key
        int u = -1;
        int min = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        // Mark vertex as included in MST
        visited[u] = 1;

        totalWeight += key[u];

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}