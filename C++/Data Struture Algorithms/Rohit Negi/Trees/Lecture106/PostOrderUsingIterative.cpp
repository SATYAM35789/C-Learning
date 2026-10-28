#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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

vector<int> postOrder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge Case Fix

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        // left
        if (temp->left)
            s.push(temp->left);
        // Right
        if (temp->right)
            s.push(temp->right);
    }

    reverse(ans.begin(), ans.end());
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

    cout << " PreOrder using Iterative method :";
    vector<int> result = postOrder(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}