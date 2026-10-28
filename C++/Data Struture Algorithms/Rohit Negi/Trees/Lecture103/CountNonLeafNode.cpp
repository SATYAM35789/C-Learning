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

int countNonLeafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    // Checking Leaf Nodes
    if (!root->left && !root->right)
        return 0;
    // Checking non leaf nodes
    return (1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
}

Node *BinaryTree()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;

    Node *temp = new Node(x);
    // Left side create karo
    cout << "Enter the left child of " << x << ":";
    temp->left = BinaryTree();
    // Right side create karo
    cout << "Enter the Right child of " << x << ":";
    temp->right = BinaryTree();

    return temp;
}

int main()
{

    cout << "Enter the root Node";
    Node *root;
    root = BinaryTree();

    cout << "Count total no. of non-leaf nodes : ";
    int TotalCount = countNonLeafNodes(root);

    return TotalCount;
}