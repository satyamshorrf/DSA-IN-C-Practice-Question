#include <stdio.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph

void topologicalSort(int graph[V][V], int in_degree[V], int stack[V], int *top)
{
    int i;
    for (i = 0; i < V; i++)
    {
        if (in_degree[i] == 0)
        {
            stack[(*top)++] = i;
        }
    }

    while (*top > 0)
    {
        int u = stack[--(*top)];
        for (i = 0; i < V; i++)
        {
            if (graph[u][i]!= 0)
            {
                in_degree[i]--;
                if (in_degree[i] == 0)
                {
                    stack[(*top)++] = i;
                }
            }
        }
    }
}

void shortestPath(int graph[V][V], int src)
{
    int in_degree[V];
    int stack[V];
    int top = 0;
    int i;

    // Calculate in-degrees of all vertices
    for (i = 0; i < V; i++)
    {
        in_degree[i] = 0;
        for (int j = 0; j < V; j++)
        {
            if (graph[j][i]!= 0)
            {
                in_degree[i]++;
            }
        }
    }

    // Perform topological sorting
    topologicalSort(graph, in_degree, stack, &top);

    // Initialize distances to all vertices as infinity
    int dist[V];
    for (i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }

    // Distance to source vertex is 0
    dist[src] = 0;

    // Process vertices in topological order
    while (top > 0)
    {
        int u = stack[--top];
        for (i = 0; i < V; i++)
        {
            if (graph[u][i]!= 0 && dist[u] + graph[u][i] < dist[i])
            {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    // Print shortest distances
    printf("Vertex \t Distance from Source\n");
    for (i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 5, 0, 10, 0, 0},
        {0, 0, 3, 0, 0, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int src = 0;
    shortestPath(graph, src);

    return 0;
}