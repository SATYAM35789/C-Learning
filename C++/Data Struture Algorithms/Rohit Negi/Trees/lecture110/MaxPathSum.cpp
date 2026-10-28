#include <iostream>
#include <climits>
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

int PathSum(Node *root, int &sum)
{
    if (!root)
        return 0;

    // Leaf Node
    if (!root->left && !root->right)
        root->data;

    int left = PathSum(root->left, sum);
    int right = PathSum(root->right, sum);

    // left and right both exist
    if (root->left && root->right)
    {
        sum = max(sum, root->data + right + left);
        return root->data + max(left, right);
    }
    //  only left exist
    if (root->left)
        return root->data + left;
    // only right exist
    if (root->right)
        return root->data + right;
}

int maxPathSum(Node *root)
{
    int sum = INT_MIN;
    int val = PathSum(root, sum);
    // root node he special node ho sakta hai
    if (root->left && root->right)
        return sum;

    return max(sum, val);
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

    int result = maxPathSum(root);
    cout << "Maximum path sum between 2 special nodes :" << result << " sec" << endl;

    return 0;
}