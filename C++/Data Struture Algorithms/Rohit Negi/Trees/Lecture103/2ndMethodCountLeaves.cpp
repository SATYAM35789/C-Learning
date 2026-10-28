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
int countLeaves(Node *root)
{
    if(root==NULL)
    return 0;
    if(!root->left&&!root->right)
    return 1;

    return(countLeaves(root->left) + countLeaves(root->right));
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