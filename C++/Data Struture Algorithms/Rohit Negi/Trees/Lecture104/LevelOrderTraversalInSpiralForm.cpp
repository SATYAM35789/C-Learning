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

vector<int> findSpiral(Node *root)
{

    stack<Node *> s1; // Right to left
    stack<Node *> s2; // left to right
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge Case Check
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        // Right to left
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                Node *temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
                // Right
                if (temp->right)
                    s2.push(temp->right);
                // Left
                if (temp->left)
                    s2.push(temp->left);
            }
        }
        // left to right
        else
        {
            while (!s2.empty())
            {
                Node *temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);
                // Left
                if (temp->left)
                    s1.push(temp->left);
                // Right
                if (temp->right)
                    s1.push(temp->right);
            }
        }
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

    cout << " Level order traversal in spiral form :";
    vector<int> result = findSpiral(root);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}