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

int height(Node *root, bool &valid)
{
    if (!root)
        return 0;

    if (valid)
    {
        int L = height(root->left, valid);
        int R = height(root->right, valid);
        if (abs(L - R) > 1)
            valid = 0;

        return (1 + max(L, R));
    }

    return -1;
}

bool isBalanced(Node *root)
{
    bool valid = 1;
    height(root, valid);
    return valid;
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

    cout << " Balanced tree or not? " << isBalanced(root);
}