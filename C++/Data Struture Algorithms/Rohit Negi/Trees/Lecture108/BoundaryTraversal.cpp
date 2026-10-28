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

void leftSub(Node *root, vector<int> &ans)
{
    // Base Case
    if (!root || (!root->left && !root->right)) // leaf condition (!root->left&&!root->right)
        return;

    ans.push_back(root->data);
    if (root->left)
        leftSub(root->left, ans);
    else
        leftSub(root->right, ans);
}

void leaf(Node *root, vector<int> &ans)
{
    // Base case
    if (!root)
        return;

    // leaf node
    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    // left part
    leaf(root->left, ans);
    // right part
    leaf(root->right, ans);
}

void RightSub(Node *root, vector<int> &ans)
{
    // base
    if (!root || (!root->left && !root->right))

        // right part mai jai if exist
        if (root->right)
            RightSub(root->right, ans);
        else
            RightSub(root->left, ans);

    ans.push_back(root->data);
}

// Function to find the level order traversal
vector<int> BoundaryTraversal(Node *root)
{
    if (!root)
        return {};

    vector<int> ans;
    // Root element ko daal do pahle
    ans.push_back(root->data);
    // left boundary ko daal do pahle, except leaf node
    leftSub(root->left, ans);
    // leaf ko insert karwa do
    if (root->left || root->right)
        ; // right or left agar exist karta hai tab, ham leaf ko call karenge.
    leaf(root, ans);
    // Right Boundary ko reverse order mai daal do except leaf node
    RightSub(root->right, ans);

    return ans;
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
    vector<int> result = BoundaryTraversal(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}