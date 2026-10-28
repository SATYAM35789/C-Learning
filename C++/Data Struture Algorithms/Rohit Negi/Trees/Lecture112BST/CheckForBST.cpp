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
    cout << root->data << " ";
    inOrder(root->right, ans);
}

bool isBST(Node *root)
{
    vector<int> ans;
    inOrder(root, ans);
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] <= ans[i - 1])
            ;
        return 0;
    }
    return 1;
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

    cout << isBST(root) << endl;
}