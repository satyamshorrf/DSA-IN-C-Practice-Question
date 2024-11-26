Here is an example of Breadth-First Search (BFS) algorithm implemented in C:
#include <stdio.h>
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

// Function to implement BFS
void BFS(Node** graph, int start, int numNodes) {
 int* visited = (int*) calloc(numNodes, sizeof(int));
 Node* queue[numNodes];
 int front = 0, rear = 0;

 // Mark the starting node as visited and enqueue it
 visited[start] = 1;
 queue[rear++] = graph[start];

 while (front != rear) {
  Node* currNode = queue[front++];
  printf("%d ", currNode->data);

  // Dequeue a node and enqueue its adjacent nodes
  for (Node* temp = currNode->next; temp != NULL; temp = temp->next) {
   int adjNode = temp->data;
   if (!visited[adjNode]) {
    visited[adjNode] = 1;
    queue[rear++] = graph[adjNode];
   }
  }
 }
}

int main() {
 int numNodes = 6;
 Node** graph = (Node**) malloc(numNodes * sizeof(Node*));

 // Create nodes and add edges
 for (int i = 0; i < numNodes; i++) {
  graph[i] = NULL;
 }
 addEdge(graph, 0, 1);
 addEdge(graph, 0, 2);
 addEdge(graph, 1, 3);
 addEdge(graph, 1, 4);
 addEdge(graph, 2, 4);
 addEdge(graph, 3, 5);
 addEdge(graph, 4, 5);

 // Perform BFS starting from node 0
 printf("BFS Traversal: ");
 BFS(graph, 0, numNodes);

 return 0;
}
