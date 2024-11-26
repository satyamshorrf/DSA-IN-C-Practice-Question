Here are examples of Minimum Spanning Tree (MST) algorithms implemented in C:

Prim's Algorithm:
#include
#include <stdio.h>

#define V 5

// Function to find the minimum spanning tree
void primMST(int graph[V][V]) {
int parent[V];
int key[V];
int visited[V];
int i, minIndex, minKey;

// Initialize arrays
for (i = 0; i
key[i] = INT_MAX;
visited[i] = 0;
}

key[0] = 0;
parent[0] = -1;

// Find the minimum spanning tree
for (int count = 0; count
minKey = INT_MAX;
minIndex = -1;

// Find the vertex with minimum key value
for (i = 0; i
if (visited[i] == 0 && key[i]
minKey = key[i];
minIndex = i;
}
}

visited[minIndex] = 1;

// Update the key values of adjacent vertices
for (i = 0; i
if (graph[minIndex][i] && visited[i] == 0 && graph[minIndex][i]
key[i] = graph[minIndex][i];
parent[i] = minIndex;
}
}
}

// Print the minimum spanning tree
printf("Edge \tWeight\n");
for (i = 1; i
printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}
}

int main() {
int graph[V][V] = {
{0, 2, 0, 6, 0},
{2, 0, 3, 8, 5},
{0, 3, 0, 0, 7},
{6, 8, 0, 0, 9},
{0, 5, 7, 9, 0}
};

primMST(graph);

return 0;
}

Kruskal's Algorithm:
#include
#include <stdio.h>

#define V 5
#define E 6

// Function to find the minimum spanning tree
void kruskalMST(int graph[E][3]) {
int i, minIndex, minWeight;
int parent[V];
int visited[V];
int MSTweight = 0;

// Initialize arrays
for (i = 0; i
parent[i] = i;
visited[i] = 0;
}

// Sort the edges in non-decreasing order of their weights
for (i = 0; i
for (int j = i + 1; j
if (graph[i][2] > graph[j][2]) {
int temp = graph[i][0];
graph[i][0] = graph[j][0];
graph[j][0] = temp;

temp = graph[i][1];
graph[i][1] = graph[j][1];
graph[j][1] = temp;

temp = graph[i][2];
graph[i][2] = graph[j][2];
graph[j][2] = temp;
}
}
}

// Find the minimum spanning tree
for (i = 0; i
minWeight = graph[i][2];
minIndex = i;

// Find the edge with minimum weight
for (int j = i + 1; j
if (graph[j][2]
minWeight = graph[j][2];
minIndex = j;
}
}

// Check if the edge forms a cycle
if (visited[graph[minIndex][0]] == 0 || visited[graph[minIndex][1]] == 0) {
MSTweight += minWeight;

// Mark the vertices as visited
visited[graph[minIndex][0]] = 1;
visited[graph[minIndex][1]] = 1;

// Update the parent array
if (parent[graph[minIndex][0]]
parent[graph[minIndex][1]] = parent[graph[minIndex][0]];
} else {
parent[graph[minIndex][0]] = parent[graph[minIndex][1]];
}
}
}

// Print the minimum spanning tree
printf("Edge \tWeight\n");
for (i = 0; i
if (visited[graph[i][0]] && visited[graph[i][1]]) {
printf("%d - %d \t%d\n", graph[i][0], graph[i][1], graph[i][2]);
}
}

printf("Minimum Spanning Tree Weight: %d\n", MSTweight);
}

int main() {
int graph[E][3] = {
{0, 1, 2},




2nd code in this question 


Here is the complete code for Prim's and Kruskal's algorithms:

Prim's Algorithm:
#include <stdio.h>
#include <limits.h>

#define V 5

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int visited[V];
    int i, minIndex, minKey;

    // Initialize arrays
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    // Find the minimum spanning tree
    for (int count = 0; count < V - 1; count++) {
        minKey = INT_MAX;
        minIndex = -1;

        // Find the vertex with minimum key value
        for (i = 0; i < V; i++) {
            if (visited[i] == 0 && key[i] < minKey) {
                minKey = key[i];
                minIndex = i;
            }
        }

        visited[minIndex] = 1;

        // Update the key values of adjacent vertices
        for (i = 0; i < V; i++) {
            if (graph[minIndex][i] && visited[i] == 0 && graph[minIndex][i] < key[i]) {
                key[i] = graph[minIndex][i];
                parent[i] = minIndex;
            }
        }
    }

    // Print the minimum spanning tree
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}


Kruskal's Algorithm:
#include <stdio.h>
#include <limits.h>

#define V 5
#define E 6

void kruskalMST(int graph[E][3]) {
    int i, minIndex, minWeight;
    int parent[V];
    int visited[V];
    int MSTweight = 0;

    // Initialize arrays
    for (i = 0; i < V; i++) {
        parent[i] = i;
        visited[i] = 0;
    }

    // Sort the edges in non-decreasing order of their weights
    for (i = 0; i < E; i++) {
        for (int j = i + 1; j < E; j++) {
            if (graph[i][2] > graph[j][2]) {
                int temp = graph[i][0];
                graph[i][0] = graph[j][0];
                graph[j][0] = temp;

                temp = graph[i][1];
                graph[i][1] = graph[j][1];
                graph[j][1] = temp;

                temp = graph[i][2];
                graph[i][2] = graph[j][2];
                graph[j][2] = temp;
            }
        }
    }

    // Find the minimum spanning tree
    for (i = 0; i < E; i++) {
        minWeight = graph[i][2];
        minIndex = i;

        // Find the edge with minimum weight
        for (int j = i + 1; j < E; j++) {
            if (graph[j][2] < minWeight) {
                minWeight = graph[j][2];
                minIndex = j;
            }
        }

        // Check if the edge forms a cycle
        if (visited[graph[minIndex][0]] == 0 || visited[graph[minIndex][1]] == 0) {
            MSTweight += minWeight;

            // Mark the vertices as visited
            visited[graph[minIndex][0]] = 1;
            visited[graph[minIndex][1]] = 1;

            // Update the parent array
            if (parent[graph[minIndex][0]] != parent[graph[minIndex][1]]) {
                if (parent[graph[minIndex][0]] < parent[graph[minIndex][1]]) {
                    parent[graph[minIndex][1]] = parent[graph[minIndex][0]];
                } else {
                    parent[graph[minIndex][0]] = parent[graph[minIndex][1]];
                }
            }
        }
    }

    // Print the minimum spanning