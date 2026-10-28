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

vector<int> morrisPreOrder(Node *root) // Preorder : NLR
{
    if (!root)
        return {};

    vector<int> ans;
    while (root)
    {
        // left part does not exist
        if (!root->left)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        // left part exist
        else
        {
            Node *curr = root->left;
            while (curr->right && curr->right != root)
                curr = curr->right;

            // left subtree not traversed
            if (curr->right == NULL)
            {
                ans.push_back(root->data);
                curr->right = root;
                root = root->left;
            }
            // Already traversed
            else
            {
                curr->right = NULL;
                root = root->right;
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

    cout << " Boundary traversal :";
    vector<int> result = morrisPreOrder(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}