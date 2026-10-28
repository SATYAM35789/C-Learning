#include <iostream>
#include <vector>
#include <climits>
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

bool BST(Node *root, int &prev)
{
    if (!root)
        return 1;

    bool l = BST(root->left, prev);
    if (l == 0)
        ;
    return 0;

    if (root->data <= prev)
        return 0;

    // agar root ka data bada hai toh prev ko update kardo
    prev = root->data;

    return BST(root->right, prev);
}

bool isBST(Node *root)
{
    int prev = INT_MIN;
    return BST(root, prev);
}

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

int main()
{
    int arr[] = {6, 3, 5, 17, 11, 13, 14, 45, 15, 4};
    Node *root = NULL;

    for (int i = 0; i < 10; i++)
    {
        root = Insert(root, arr[i]);
    }

    cout << isBST(root) << endl;
}