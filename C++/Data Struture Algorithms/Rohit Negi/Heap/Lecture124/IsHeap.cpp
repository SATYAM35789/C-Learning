#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

int count(Node *root)
{
    if (!root)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

bool CBT(Node *root, int index, int totalNodes)
{
    if (!root)
        return 1;

    if (index >= totalNodes)
        return 0;

    return CBT(root->left, 2 * index + 1, totalNodes) && CBT(root->right, 2 * index + 2, totalNodes); // ek bhi side se zero then return 0
}

bool maxHeap(Node *root)
{
    // root null
    // left Child exist only
    // Right side exist only
    // Both child exist

    // Given in the question One node will exist
    if (root->left)
    {
        if (root->data < root->left->data)
            return 0;

        else if (!maxHeap(root->left))
            return 0;
    }
    if (root->right)
    {
        if (root->data < root->right->data)
            return 0;

        return maxHeap(root->right); // Yaha hum direct return kar rahe because kyuki right ke baad humko
        // kuchh check karne ki zarurat nahi, lakin agar left exist karta hai then hamko right ko bhi check karenge
    }
}

bool isHeap(Node *tree)
{
    // Counts nodes in tree
    int num = count(tree);

    // CBT hai ki nahi
    if (!CBT(tree, 0, num))
        return 0;

    // Every Parents > child
    return maxHeap(tree);
}

int main()
{
    /* Sample Valid Heap:
              10
            /    \
           9      8
          / \    /
         7   6  5
    */
    Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    if (isHeap(root))
        cout << "Yes, it is a Max Heap!" << endl;
    else
        cout << "No, it is NOT a Max Heap." << endl;

    return 0;
}