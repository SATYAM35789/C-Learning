#include <iostream>
#include <queue>
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

void RView(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    RView(root->right, level + 1, ans);
    RView(root->left, level + 1, ans);
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge case

    RView(root, 0, ans);
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

    cout << " Level order traversal in spiral form :";
    vector<int> result = rightView(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}