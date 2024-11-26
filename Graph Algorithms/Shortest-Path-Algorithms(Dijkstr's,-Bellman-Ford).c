Here are examples of shortest path algorithms implemented in C:

Dijkstra's Algorithm:
#include
#include <stdio.h>

#define V 6

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
int dist[V];
int visited[V];
int i, minDistance, minIndex;

// Initialize distances and visited array
for (i = 0; i
dist[i] = INT_MAX;
visited[i] = 0;
}

dist[src] = 0;

// Find shortest path for all vertices
for (int count = 0; count
minDistance = INT_MAX;
minIndex = -1;

// Find the vertex with minimum distance value
for (i = 0; i
if (visited[i] == 0 && dist[i]
minDistance = dist[i];
minIndex = i;
}
}

// Update the distance values of adjacent vertices
visited[minIndex] = 1;
for (i = 0; i
if (visited[i] == 0 && graph[minIndex][i] && dist[minIndex] != INT_MAX && dist[minIndex] + graph[minIndex][i]
dist[i] = dist[minIndex] + graph[minIndex][i];
}
}
}

// Print the shortest distances
printf("Vertex\tDistance from Source\n");
for (i = 0; i
printf("%d \t%d\n", i, dist[i]);
}
}

int main() {
int graph[V][V] = {
{0, 4, 0, 0, 0, 0},
{4, 0, 8, 0, 0, 0},
{0, 8, 0, 7, 0, 4},
{0, 0, 7, 0, 9, 14},
{0, 0, 0, 9, 0, 10},
{0, 0, 4, 14, 10, 0}
};

dijkstra(graph, 0);

return 0;
}

Bellman-Ford Algorithm:
#include
#include <stdio.h>

#define V 5
#define E 8

// Function to implement Bellman-Ford algorithm
void bellmanFord(int graph[E][3], int V, int E, int src) {
int dist[V];
int i, j;

// Initialize distances
for (i = 0; i
dist[i] = INT_MAX;
}

dist[src] = 0;

// Relax edges |V| - 1 times
for (i = 1; i
for (j = 0; j
int u = graph[j][0];
int v = graph[j][1];
int weight = graph[j][2];

if (dist[u] != INT_MAX && dist[u] + weight
dist[v] = dist[u] + weight;
}
}
}

// Check for negative weight cycles
for (i = 0; i
int u = graph[i][0];
int v = graph[i][1];
int weight = graph[i][2];

if (dist[u] != INT_MAX && dist[u] + weight
printf("Graph contains negative weight cycle\n");
return;
}
}

// Print the shortest distances
printf("Vertex\tDistance from Source\n");
for (i = 0; i
printf("%d \t%d\n", i, dist[i]);
}
}

int main() {
int graph[E][3] = {
{0, 1, -1},
{0, 2, 4},
{1, 2, 3},
{1, 3, 2},
{1, 4, 2},
{3, 2, 5},
{3, 1, 1},
{4, 3, -3}
};

bellmanFord(graph, V, E, 0);

return 0;
}

