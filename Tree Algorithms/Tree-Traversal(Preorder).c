
#include<stdlib.h>

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

// Function to perform Preorder Traversal
void preorderTraversal(Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorderTraversal(root->left);
preorderTraversal(root->right);
}
}

int main() {
// Create a sample tree
Node* root = createNode(1);
root->left = createNode(2);
root->right = createNode(3);
root->left->left = createNode(4);
root->left->right = createNode(5);

// Perform Preorder Traversal
printf("Preorder Traversal: ");
preorderTraversal(root);

return 0;
}


// Here's the explanation:

// 1. We define a Node structure to represent a tree node, with data, left, and right members.
// 2. The createNode function allocates memory for a new node and initializes its members.
// 3. The preorderTraversal function performs the Preorder Traversal. It visits the current node, recursively traverses the left subtree, and then traverses the right subtree.
// 4. In the main function, we create a sample tree with nodes 1, 2, 3, 4, and 5.
// 5. We call preorderTraversal to print the node values in Preorder Traversal order (1, 2, 4, 5, 3).

// When you run this code, it will output:
// Preorder Traversal: 1 2 4 5 3

// This demonstrates Preorder Traversal, which visits nodes in the order: root, left subtree, right subtree.