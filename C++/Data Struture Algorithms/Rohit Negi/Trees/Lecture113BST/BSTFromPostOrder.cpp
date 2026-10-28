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

Node *BST(int post[], int &index, int lower, int upper)
{
    // Base Case
    if (index == 0 || post[index] < lower || post[index] > upper)
        return NULL;

    Node *root = new Node(post[index]);
    index--;

    // Right child ke liye upper bound wahi rahega jo parent ka tha
    root->right = BST(post, index, root->data, upper);

    //  Left child ke liye upper bound root->data hoga
    root->left = BST(post, index, lower, root->data);

    return root;
}

Node *constructTree(int post[], int size)
{
    int index = size - 1;
    return BST(post, index, INT_MIN, INT_MAX);
}

// Verification ke liye Inorder Print (BST ka inorder sorted hona chahiye)
void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    // Postorder: Left -> Right -> Root
    // Example: 1, 7, 5, 50, 40, 10
    int post[] = {1, 7, 5, 50, 40, 10};
    int n = sizeof(post) / sizeof(post[0]);

    cout << "Building BST from Postorder using Range Logic..." << endl;
    Node *root = constructTree(post, n);

    cout << "Inorder Traversal (Should be sorted): ";
    inOrder(root);
    cout << endl;

    return 0;
}