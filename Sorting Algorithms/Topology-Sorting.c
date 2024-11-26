Here is an example of Topology Sort algorithm implemented in C:
#include
#include <stdlib.h>

// Structure to represent a graph node
typedef struct Node {
int data;
struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
Node* newNode = (Node*) malloc(sizeof(Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}

// Function to add an edge between two nodes
void addEdge(Node** graph, int src, int dest) {
Node* newNode = createNode(dest);
newNode->next = graph[src];
graph[src] = newNode;
}

// Function to perform Topology Sort
void topologySort(Node** graph, int numNodes) {
int* visited = (int*) calloc(numNodes, sizeof(int));
int* stack = (int*) malloc(numNodes * sizeof(int));
int top = -1;

// Perform DFS and push nodes to stack
for (int i = 0; i
if (!visited[i]) {
topologySortUtil(graph, i, visited, stack, &top);
}
}

// Print the sorted nodes
while (top != -1) {
printf("%d ", stack[top--]);
}
}

// Helper function for Topology Sort
void topologySortUtil(Node** graph, int node, int* visited, int* stack, int* top) {
visited[node] = 1;

for (Node* temp = graph[node]; temp != NULL; temp = temp->next) {
int adjNode = temp->data;
if (!visited[adjNode]) {
topologySortUtil(graph, adjNode, visited, stack, top);
}
}

stack[++(*top)] = node;
}

int main() {
int numNodes = 6;
Node** graph = (Node**) malloc(numNodes * sizeof(Node*));

// Create nodes and add edges
for (int i = 0; i
graph[i] = NULL;
}
addEdge(graph, 0, 1);
addEdge(graph, 0, 2);
addEdge(graph, 1, 3);
addEdge(graph, 1, 4);
addEdge(graph, 2, 4);
addEdge(graph, 3, 5);
addEdge(graph, 4, 5);

// Perform Topology Sort
printf("Topology Sort: ");
topologySort(graph, numNodes);

return 0;
}

