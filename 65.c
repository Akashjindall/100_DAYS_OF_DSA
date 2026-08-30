#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

/* DFS with parent tracking */
int dfs(int node, int parent)
{
    visited[node] = 1;

    for (int neighbor = 0; neighbor < n; neighbor++)
    {
        if (graph[node][neighbor] == 1)
        {
            // If neighbor is not visited, visit it
            if (!visited[neighbor])
            {
                if (dfs(neighbor, node))
                    return 1;
            }
            // If visited and it is not the parent, cycle exists
            else if (neighbor != parent)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;   // undirected graph
    }

    // Check every component
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}