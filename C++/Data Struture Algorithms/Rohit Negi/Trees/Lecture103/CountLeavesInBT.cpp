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
void CountLeaf(Node *root, int &count)
{
    if (root == NULL)
        return;

    // leaf node condition
    if (!root->left && !root->right)
    {
        count++;
        return;
    }
    // Non Leaf node condition
    CountLeaf(root->left, count);
    CountLeaf(root->right, count);
}

int countLeaves(Node *root)
{
    int count = 0;
    CountLeaf(root, count);
    return count;
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

    cout << "Count total no. of leaf nodes : ";
    int TotalCount = countLeaves(root);

    return TotalCount;
}