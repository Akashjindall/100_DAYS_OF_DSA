#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

// DFS function
int dfs(int node)
{
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++)
    {
        // If there is an edge node -> i
        if (graph[node][i])
        {
            // i is not visited, explore it
            if (!visited[i])
            {
                if (dfs(i))
                    return 1;
            }

            // i is already in current recursion stack
            else if (recStack[i])
            {
                return 1;   // Cycle found
            }
        }
    }

    // Remove node from recursion stack
    recStack[node] = 0;

    return 0;
}

int main()
{
    int edges;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter directed edges (u v):\n");

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
    }

    // Check all components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}