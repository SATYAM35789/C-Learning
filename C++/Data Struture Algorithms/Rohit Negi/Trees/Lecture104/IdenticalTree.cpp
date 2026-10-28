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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return (1 + height(root->left) + height(root->right));
}

bool isIdentical(Node *r1, Node *r2)
{
    // Base Condition
    if (!r1 && !r2)
        return 1;
    if ((!r1 && r2) || (r1 && !r2))
        return 0;

    if (r1->data != r2->data)
        return 0;

    return (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
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

    cout << "Enter the root Node for tree 1";
    Node *r1;
    r1 = BinaryTree();

    cout << "Enter the root Node for tree 2";
    Node *r2;
    r2 = BinaryTree();

    if (isIdentical(r1, r2))
        cout << "\nTwo trees are identical (1)" << endl;
    else
        cout << "\nTwo trees are not identical (0)" << endl;

    return 0;
    return 0;
}