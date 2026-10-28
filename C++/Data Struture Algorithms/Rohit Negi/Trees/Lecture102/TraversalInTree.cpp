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
void PreOrder(Node *root)
{
    if (root == NULL)
        return;
    // Node
    cout << root->data << " ";
    // Left
    PreOrder(root->left);
    // Right
    PreOrder(root->right);
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;

    // Left
    InOrder(root->left);
    // Node
    cout << root->data << " ";
    // Right
    InOrder(root->right);
}
void PostOrder(Node *root)
{
    if (root == NULL)
        return;

    // Left
    PostOrder(root->left);
    // Right
    PostOrder(root->right);
    // Node
    cout << root->data << " ";
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

    cout << " Pre Order : ";
    PreOrder(root);

    cout << "\n In Order : ";
    InOrder(root);

    cout << " \n Pre Order : ";
    PostOrder(root);
}