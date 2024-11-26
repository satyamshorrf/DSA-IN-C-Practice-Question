Here is an example of Binary Search Tree (BST) searching in C:
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

// Function to search for a node in the BST
Node* searchNode(Node* root, int data) {
if (root == NULL || root->data == data) {
return root;
} else if (data
return searchNode(root->left, data);
} else {
return searchNode(root->right, data);
}
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

// Search for a node in the BST
Node* searchedNode = searchNode(root, 4);

if (searchedNode != NULL) {
printf("Node found: %d\n", searchedNode->data);
} else {
printf("Node not found\n");
}

// Perform inorder traversal
printf("Inorder Traversal: ");
inorderTraversal(root);

return 0;
}

