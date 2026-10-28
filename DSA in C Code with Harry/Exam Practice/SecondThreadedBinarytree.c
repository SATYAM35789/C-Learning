#include <stdio.h>
#include <stdlib.h>

// Structure for a Node in the Double Threaded Binary Tree
struct Node {
    int data;
    struct Node *left, *right;
    int leftThread, rightThread;  // Flags for threads
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->leftThread = newNode->rightThread = 0;  // No threads initially
    return newNode;
}

// Function for in-order traversal of the double threaded binary tree
void inOrderTraversal(struct Node* root) {
    struct Node* current = root;

    // Go to the leftmost node
    while (current != NULL) {
        // Traverse to the leftmost node
        while (current->left != NULL && current->leftThread == 0) {
            current = current->left;
        }

        // Print the current node's data
        printf("%d ", current->data);

        // If the current node has a right thread, move to the in-order successor
        if (current->rightThread == 1) {
            current = current->right;
        } else {
            current = current->right;
        }
    }
}

// Function to insert left thread (points to in-order predecessor)
void insertLeftThread(struct Node* parent, struct Node* child) {
    parent->left = child;
    parent->leftThread = 1;  // Mark this as a thread
}

// Function to insert right thread (points to in-order successor)
void insertRightThread(struct Node* parent, struct Node* child) {
    parent->right = child;
    parent->rightThread = 1;  // Mark this as a thread
}

// Function to build a simple double threaded binary tree
struct Node* buildTree() {
    struct Node* root = createNode(10);
    struct Node* node5 = createNode(5);
    struct Node* node20 = createNode(20);
    struct Node* node3 = createNode(3);
    struct Node* node15 = createNode(15);
    struct Node* node30 = createNode(30);

    // Constructing the tree
    root->left = node5;
    root->right = node20;
    node5->left = node3;
    node20->left = node15;
    node20->right = node30;

    // Insert threads (left and right threading)
    insertLeftThread(node5, NULL);  // Thread from 5 to NULL (in-order predecessor)
    insertRightThread(node3, node5); // Thread from 3 to 5 (in-order successor)
    insertRightThread(node5, root); // Thread from 5 to 10 (in-order successor)
    insertLeftThread(node20, root); // Thread from 20 to 10 (in-order predecessor)
    insertRightThread(node15, node20); // Thread from 15 to 20 (in-order successor)
    insertRightThread(node30, NULL);  // Thread from 30 to NULL (in-order successor)

    return root;
}

// Main function to test the double threaded binary tree
int main() {
    struct Node* root = buildTree();
    printf("In-order traversal of the Double Threaded Binary Tree:\n");
    inOrderTraversal(root);
    return 0;
}
