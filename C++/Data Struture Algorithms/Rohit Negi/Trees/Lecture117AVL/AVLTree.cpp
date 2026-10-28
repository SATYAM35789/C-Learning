#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root)
{
    if (!root)
        return 0;

    return root->height;
}

int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

// Right Rotation
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

// Left Rotation
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node *insert(Node *root, int key)
{
    // Doesnot exist
    if (!root)
        return new Node(key);
    // root Exist karta hai then
    if (key < root->data) // left side attach ho jao
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // Duplicates element hoga toh waise usko wapas bhej denge

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balance check karo ki tree balance hai ki nahi
    int balance = getBalance(root);

    // Left Left unbalance case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root); // Top element
    }
    // Right Right unbalance case
    else if (balance < -1 && root->right->data < key)
    {
        return leftRotation(root); // Top element
    }
    // Left Right unbalance case
    else if (balance > 1 && key > root->right->data)
    {
        root->left = leftRotation(root->left); // Middle element
        return rightRotation(root);            // top
    }
    // Right Left unbalance case
    else if (balance < -1 && root->right->data > key)
    {
        root->right = rightRotation(root->right); // middle
        return leftRotation(root);                // Top
    }
    // No unbalance case
    else
    {
        return root;
    }
}

void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = NULL;

    // Duplicates element are not allowed.
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "PreOrder : " << endl;
    preorder(root);
}