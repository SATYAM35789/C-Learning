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

bool Dead(Node *root, int lower, int upper)
{
    if (!root)
        return 0;

    // Leaf Node
    if (!root->left && !root->right)
    {
        if (root->data - lower == 1 && upper - root->data == 1)
            return 1;
        else
            return 0;
    }
    return (Dead(root->left, lower, root->data) || Dead(root->right, root->data, upper));
}

bool isDeadEnd(Node *root)
{
    return Dead(root, 0, INT_MAX);
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
    if (isDeadEnd(root))
        cout << "Yes, there is a Dead End in the BST!" << endl;
    else
        cout << "No Dead End found." << endl;

    return 0;
}