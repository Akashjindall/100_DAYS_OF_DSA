#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for an edge
typedef struct {
    int vertex;
    int weight;
} Edge;

// Structure for priority queue node
typedef struct {
    int vertex;
    int distance;
} PQNode;

// Priority Queue
PQNode pq[MAX * MAX];
int pqSize = 0;

// Insert into min-heap
void push(int vertex, int distance) {
    int i = pqSize++;
    
    pq[i].vertex = vertex;
    pq[i].distance = distance;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (pq[parent].distance <= pq[i].distance)
            break;

        PQNode temp = pq[parent];
        pq[parent] = pq[i];
        pq[i] = temp;

        i = parent;
    }
}

// Remove minimum element
PQNode pop() {
    PQNode result = pq[0];
    pq[0] = pq[--pqSize];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pqSize &&
            pq[left].distance < pq[smallest].distance)
            smallest = left;

        if (right < pqSize &&
            pq[right].distance < pq[smallest].distance)
            smallest = right;

        if (smallest == i)
            break;

        PQNode temp = pq[i];
        pq[i] = pq[smallest];
        pq[smallest] = temp;

        i = smallest;
    }

    return result;
}

// Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    // Insert source into priority queue
    push(source, 0);

    while (pqSize > 0) {
        PQNode current = pop();

        int u = current.vertex;
        int d = current.distance;

        // Ignore outdated entry
        if (d != dist[u])
            continue;

        // Relax all adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0) {

                if (dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];

                    push(v, dist[v]);
                }
            }
        }
    }

    // Print shortest distances
    printf("\nShortest distances from vertex %d:\n", source);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("Vertex %d : INF\n", i);
        else
            printf("Vertex %d : %d\n", i, dist[i]);
    }
}

int main() {

    int n, source;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}