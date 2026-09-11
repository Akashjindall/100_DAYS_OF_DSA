#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n, m;

void DFS(int vertex)
{
    visited[vertex] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int u, v;

    // Input number of vertices and edges
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        // Undirected graph
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Start DFS from vertex 1
    DFS(1);

    // Check if every vertex was visited
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}