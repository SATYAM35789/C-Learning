#include <iostream>
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

void inOrder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

void postOrder(Node *root, vector<int> &ans, int index)
{
    if (!root)
        return;

    postOrder(root->left, ans, index);
    postOrder(root->right, ans, index);
    root->data = ans[index++];
}

void convertToMaxHeap(Node *root)
{
    // Inorder Traversal
    vector<int> ans;
    inOrder(root, ans);
    // PostOrder Traversal
    int index = 0;
    postOrder(root, ans, index);
}

int main()
{
    /* Sample Valid Heap:
              10
            /    \
           9      8
          / \    /
         7   6  5
    */
    Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    convertToMaxHeap(root);
    return 0;
}