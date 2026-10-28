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

void mirror(Node *root)
{
    if (!root)
        return;

    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;
    // Left
    mirror(root->left);
    // Right
    mirror(root->right);
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
void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{

    cout << "Enter the root Node";
    Node *root;
    root = BinaryTree();

    cout << "\nOriginal Tree (Pre-order): ";
    preOrder(root);

    mirror(root);

    cout << "\nMirror Tree (Pre-order): ";
    preOrder(root);
    cout << endl;

    return 0;
}