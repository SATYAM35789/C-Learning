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

Node *Insert(Node *root, int target)
{
    if (!root)
    {
        Node *temp = new Node(target);
        return temp;
    }
    // left side
    if (target < root->data)
    {
        root->left = Insert(root->left, target);
    }
    else
        root->right = Insert(root->right, target);

    return root;
}

void inOrder(Node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

bool search(Node *root, int target)
{
    if (!root)
        return 0;

    if (root->data == target)
        ;
    return 1;

    if (root->data > target) // agar root ka data bada hai then target left side hoga
        return search(root->left, target);

    else
        return search(root->right, target);
}

int main()
{
    int arr[] = {6, 3, 5, 17, 11, 13, 14, 45, 15, 4};
    Node *root = NULL;

    for (int i = 0; i < 10; i++)
    {
        root = Insert(root, arr[i]);
    }

    // Traverse of BST, by inOrder then it will give the sorted array.
    inOrder(root);

    cout << search(root, 11);
}