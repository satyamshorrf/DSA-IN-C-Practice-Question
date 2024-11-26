Here is an example of Postorder Tree Traversal in C:
#include
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

// Function to perform Postorder Traversal
void postorderTraversal(Node* root) {
if (root != NULL) {
postorderTraversal(root->left);
postorderTraversal(root->right);
printf("%d ", root->data);
}
}

int main() {
// Create a sample tree
Node* root = createNode(1);
root->left = createNode(2);
root->right = createNode(3);
root->left->left = createNode(4);
root->left->right = createNode(5);

// Perform Postorder Traversal
printf("Postorder Traversal: ");
postorderTraversal(root);

return 0;
}


// Here's the explanation:

// 1. We define a Node structure to represent a tree node, with data, left, and right members.
// 2. The createNode function allocates memory for a new node and initializes its members.
// 3. The postorderTraversal function performs the Postorder Traversal. It recursively traverses the left subtree, then the right subtree, and finally visits the current node.
// 4. In the main function, we create a sample tree with nodes 1, 2, 3, 4, and 5.
// 5. We call postorderTraversal to print the node values in Postorder Traversal order (4, 5, 2, 3, 1).

// When you run this code, it will output:
// Postorder Traversal: 4 5 2 3 1

// This demonstrates Postorder Traversal, which visits nodes in the order: left subtree, right subtree, root.