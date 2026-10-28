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

void TotalNode(Node *root, int &count)
{
    if (root == NULL)
        return;
    count++;
    TotalNode(root->left, count);
    TotalNode(root->right, count);
}

int getSize(Node *root)
{
    int count = 0;
    TotalNode(root, count);
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

    cout << "Total no. of nodes : ";
    getSize(root);

    return 0;
}