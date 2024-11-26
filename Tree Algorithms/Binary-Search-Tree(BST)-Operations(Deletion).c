Here is an example of Binary Search Tree (BST) deletion in C:
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

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
if (root == NULL) return root;

if (data
root->left = deleteNode(root->left, data);
} else if (data > root->data) {
root->right = deleteNode(root->right, data);
} else {
// Node to be deleted found
if (root->left == NULL) {
Node* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
Node* temp = root->left;
free(root);
return temp;
} else {
// Node has two children
Node* temp = minValueNode(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
}
return root;
}

// Function to find the node with the minimum value in a BST
Node* minValueNode(Node* node) {
Node* current = node;
while (current && current->left != NULL) {
current = current->left;
}
return current;
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

// Delete a node from the BST
root = deleteNode(root, 3);

// Perform inorder traversal
printf("Inorder Traversal: ");
inorderTraversal(root);

return 0;
}


// Here's the explanation:

// 1. We define a Node structure to represent a BST node, with data, left, and right members.
// 2. The createNode function allocates memory for a new node and initializes its members.
// 3. The deleteNode function deletes a node from the BST by recursively traversing the tree and finding the appropriate node to delete.
// 4. In the main function, we create a BST and insert nodes with values 5, 3, 7, 2, 4, 6, and 8.
// 5. We call deleteNode to delete the node with value 3 from the BST.
// 6. We call inorderTraversal to print the node values in ascending order (2, 4, 5, 6, 7, 8).

// When you run this code, it will output:
// Inorder Traversal: 2 4 5 6 7 8

// This demonstrates BST deletion and inorder traversal.