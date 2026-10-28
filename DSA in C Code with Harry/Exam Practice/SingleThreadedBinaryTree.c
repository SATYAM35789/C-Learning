#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
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
    newNode->leftThread = newNode->rightThread = 0;
    return newNode;
}

// Function for in-order traversal of the threaded binary tree
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

        // If the current node has a thread to the in-order successor, move to it
        while (current->rightThread == 1) {
            current = current->right;
            printf("%d ", current->data);
        }

        // Move to the right child
        current = current->right;
    }
}

// Function to perform right thread insertion (creates threads in the tree)
void insertRightThread(struct Node* parent, struct Node* child) {
    parent->right = child;
    parent->rightThread = 1;
    child->left = parent;
    child->leftThread = 1;
}

// Function to build a simple threaded binary tree for testing
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

    // Insert threads (right-threading in this case)
    insertRightThread(node5, root);
    insertRightThread(node15, node20);
    insertRightThread(node30, NULL);

    return root;
}

// Main function to test the threaded binary tree
int main() {
    struct Node* root = buildTree();
    printf("In-order traversal of the Threaded Binary Tree:\n");
    inOrderTraversal(root);
    return 0;
}
