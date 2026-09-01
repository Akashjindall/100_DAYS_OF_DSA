#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// DFS function
void dfs(int node)
{
    visited[node] = 1;

    // Visit all adjacent vertices
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }

    // Add node to stack after visiting all neighbours
    stack[++top] = node;
}

// Topological Sort
void topologicalSort()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    printf("Topological Ordering: ");

    // Print stack in reverse order
    while (top >= 0)
    {
        printf("%d ", stack[top--]);
    }

    printf("\n");
}

int main()
{
    int edges;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v), where u -> v:\n");

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();

    return 0;
}