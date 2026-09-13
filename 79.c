#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for an edge
struct Edge {
    int vertex;
    int weight;
    struct Edge* next;
};

// Structure for priority queue node
struct Node {
    int vertex;
    int distance;
};

// Min Heap
struct MinHeap {
    struct Node heap[MAX * MAX];
    int size;
};

// Add edge to adjacency list
void addEdge(struct Edge* graph[], int u, int v, int w) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));

    newEdge->vertex = v;
    newEdge->weight = w;
    newEdge->next = graph[u];

    graph[u] = newEdge;
}

// Swap two heap nodes
void swap(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into min heap
void push(struct MinHeap* pq, int vertex, int distance) {
    int i = pq->size++;

    pq->heap[i].vertex = vertex;
    pq->heap[i].distance = distance;

    // Move upward
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (pq->heap[parent].distance <= pq->heap[i].distance)
            break;

        swap(&pq->heap[parent], &pq->heap[i]);
        i = parent;
    }
}

// Remove minimum element
struct Node pop(struct MinHeap* pq) {
    struct Node result = pq->heap[0];

    pq->heap[0] = pq->heap[--pq->size];

    int i = 0;

    // Move downward
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pq->size &&
            pq->heap[left].distance < pq->heap[smallest].distance)
            smallest = left;

        if (right < pq->size &&
            pq->heap[right].distance < pq->heap[smallest].distance)
            smallest = right;

        if (smallest == i)
            break;

        swap(&pq->heap[i], &pq->heap[smallest]);
        i = smallest;
    }

    return result;
}

// Dijkstra's Algorithm
void dijkstra(struct Edge* graph[], int n, int source) {

    int dist[MAX];

    // Initialize distances
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    struct MinHeap pq;
    pq.size = 0;

    // Insert source
    push(&pq, source, 0);

    while (pq.size > 0) {

        struct Node current = pop(&pq);

        int u = current.vertex;
        int currentDist = current.distance;

        // Ignore outdated priority queue entries
        if (currentDist != dist[u])
            continue;

        // Traverse all adjacent vertices
        struct Edge* temp = graph[u];

        while (temp != NULL) {

            int v = temp->vertex;
            int weight = temp->weight;

            // Relaxation
            if (dist[u] != INT_MAX &&
                dist[u] + weight < dist[v]) {

                dist[v] = dist[u] + weight;

                push(&pq, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("-1 ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");
}

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    struct Edge* graph[MAX + 1];

    // Initialize graph
    for (int i = 1; i <= n; i++)
        graph[i] = NULL;

    // Input edges
    for (int i = 0; i < m; i++) {

        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        // For directed graph
        addEdge(graph, u, v, w);

        /*
           If graph is undirected, also add:
           addEdge(graph, v, u, w);
        */
    }

    int source;
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}