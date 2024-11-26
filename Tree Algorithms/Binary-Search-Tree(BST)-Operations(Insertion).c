Here is an example of Binary Search Tree (BST) insertion in C:
#include
#include <stdlib.h>

// Structure to represent a BST node
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

// Function to insert a node into the BST
Node* insertNode(Node* root, int data) {
if (root == NULL) {
return createNode(data);
} else if (data
root->left = insertNode(root->left, data);
} else if (data > root->data) {
root->right = insertNode(root->right, data);
}
return root;
}

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
if (root != NULL) {
inorderTraversal(root->left);
printf("%d ", root->data);
inorderTraversal(root->right);
}
}

int main() {
Node* root = NULL;

// Insert nodes into the BST
root = insertNode(root, 5);
root = insertNode(root, 3);
root = insertNode(root, 7);
root = insertNode(root, 2);
root = insertNode(root, 4);
root = insertNode(root, 6);
root = insertNode(root, 8);

// Perform inorder traversal
printf("Inorder Traversal: ");
inorderTraversal(root);

return 0;
}


// Here's the explanation:

// 1. We define a Node structure to represent a BST node, with data, left, and right members.
// 2. The createNode function allocates memory for a new node and initializes its members.
// 3. The insertNode function inserts a node into the BST by recursively traversing the tree and finding the appropriate position for the new node.
// 4. In the main function, we create a BST and insert nodes with values 5, 3, 7, 2, 4, 6, and 8.
// 5. We call inorderTraversal to print the node values in ascending order (2, 3, 4, 5, 6, 7, 8).

// When you run this code, it will output:
// Inorder Traversal: 2 3 4 5 6 7 8

// This demonstrates BST insertion and inorder traversal.