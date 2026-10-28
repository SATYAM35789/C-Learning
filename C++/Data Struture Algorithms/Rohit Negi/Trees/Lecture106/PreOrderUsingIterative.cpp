#include <iostream>
#include <stack>
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

vector<int> preOrder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    vector<int> ans;

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);

        if (temp->right)
            s.push(temp->right);

        if (temp->left)
            s.push(temp->left);
    }
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
    vector<int> result = preOrder(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}