Here is an example of Depth-First Search (DFS) algorithm implemented in C:
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

// Function to implement DFS
void DFS(Node** graph, int start, int numNodes) {
int* visited = (int*) calloc(numNodes, sizeof(int));
DFSUtil(graph, start, visited);
}

// Helper function for DFS
void DFSUtil(Node** graph, int node, int* visited) {
visited[node] = 1;
printf("%d ", node);

for (Node* temp = graph[node]; temp != NULL; temp = temp->next) {
int adjNode = temp->data;
if (!visited[adjNode]) {
DFSUtil(graph, adjNode, visited);
}
}
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

// Perform DFS starting from node 0
printf("DFS Traversal: ");
DFS(graph, 0, numNodes);

return 0;
}

