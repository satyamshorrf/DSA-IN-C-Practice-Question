Here is an example of Strongly Connected Components (SCC) algorithm implemented in C:
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

// Function to perform DFS and find SCCs
void SCC(Node** graph, int numNodes) {
int* visited = (int*) calloc(numNodes, sizeof(int));
int* stack = (int*) malloc(numNodes * sizeof(int));
int top = -1;

// Perform DFS and push nodes to stack
for (int i = 0; i
if (!visited[i]) {
SCCUtil(graph, i, visited, stack, &top);
}
}

// Print the SCCs
while (top != -1) {
int node = stack[top--];
printf("%d ", node);
while (top != -1 && stack[top] == node) {
top--;
}
printf("\n");
}
}

// Helper function for SCC
void SCCUtil(Node** graph, int node, int* visited, int* stack, int* top) {
visited[node] = 1;

for (Node* temp = graph[node]; temp != NULL; temp = temp->next) {
int adjNode = temp->data;
if (!visited[adjNode]) {
SCCUtil(graph, adjNode, visited, stack, top);
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
addEdge(graph, 1, 2);
addEdge(graph, 2, 3);
addEdge(graph, 3, 0);
addEdge(graph, 2, 4);
addEdge(graph, 4, 5);
addEdge(graph, 5, 4);

// Perform SCC
printf("Strongly Connected Components:\n");
SCC(graph, numNodes);

return 0;
}

