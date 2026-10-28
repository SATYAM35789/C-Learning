#include <iostream>
#include <queue>
#include <vector>
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

vector<int> flatten(Node *root) // Preorder : NLR
{
    if (!root)
        return {};

    while (root)
    {
        // Left exist nahi karta
        if (!root->left)
            root = root->right;
        // left exist karta hai
        else
        {
            Node *curr = root->left;
            while (curr->right)
                curr = curr->right;

            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
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

    cout << " Boundary traversal :";
    vector<int> result = flatten(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}