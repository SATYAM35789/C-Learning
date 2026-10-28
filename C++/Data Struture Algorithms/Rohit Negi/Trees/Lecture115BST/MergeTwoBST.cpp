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

void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> mergeBST(Node *root1, Node *root2)
{
    vector<int> ans1;
    vector<int> ans2;
    inorder(root1, ans1);
    inorder(root2, ans2);

    vector<int> ans;
    int i = 0, j = 0;
    while (i < ans1.size() && j < ans2.size())
    {
        if (ans1[i] < ans2[j])
            ans.push_back(ans1[i++]);
        else
        {
            ans.push_back(ans2[j]);
            j++;
        }
    }
    while (i < ans1.size())
    {
        ans.push_back(ans1[i++]);
    }

    while (j < ans2.size())
    {
        ans.push_back(ans2[j++]);
    }
    return ans;
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
    Node *root1 = NULL, *root2 = NULL;

    // BST 1: {1, 5, 8}
    root1 = Insert(root1, 5);
    root1 = Insert(root1, 1);
    root1 = Insert(root1, 8);

    // BST 2: {2, 7, 10}
    root2 = Insert(root2, 7);
    root2 = Insert(root2, 2);
    root2 = Insert(root2, 10);

    vector<int> result = mergeBST(root1, root2);

    cout << "Merged Sorted Elements: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
