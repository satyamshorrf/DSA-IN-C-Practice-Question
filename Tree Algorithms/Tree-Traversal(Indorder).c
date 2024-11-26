Here is an example of Inorder Tree Traversal in C:
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a tree node
typedef struct Node {
int data;
struct Node* left;
struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
Node* newNode = (Node*) malloc(sizeof(Node));
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}

// Function to perform Inorder Traversal
void inorderTraversal(Node* root) {
if (root != NULL) {
inorderTraversal(root->left);
printf("%d ", root->data);
inorderTraversal(root->right);
}
}

int main() {
// Create a sample tree
Node* root = createNode(1);
root->left = createNode(2);
root->right = createNode(3);
root->left->left = createNode(4);
root->left->right = createNode(5);

// Perform Inorder Traversal
printf("Inorder Traversal: ");
inorderTraversal(root);

return 0;
}



// Here's the explanation:

// 1. We define a Node structure to represent a tree node, with data, left, and right members.
// 2. The createNode function allocates memory for a new node and initializes its members.
// 3. The inorderTraversal function performs the Inorder Traversal. It recursively traverses the left subtree, visits the current node, and then traverses the right subtree.
// 4. In the main function, we create a sample tree with nodes 1, 2, 3, 4, and 5. 
// 5. We call inorderTraversal to print the node values in Inorder Traversal order (4, 2, 5, 1, 3).

// When you run this code, it will output:
// Inorder Traversal: 4 2 5 1 3

// This demonstrates Inorder Traversal, which visits nodes in ascending order.