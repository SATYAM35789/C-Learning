#include <iostream>
#include <vector>
#include <climits>
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

int n1, n2; // Global variable .

void find(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->data > n1 && root->data > n2)
        find(root->left, ans);
    else if (root->data < n1 && root->data < n2)
        find(root->right, ans);

    else
    {
        find(root->left, ans);
        ans.push_back(root->data);
        find(root->right, ans);
    }
}

vector<int> printNearNodes(Node *root)
{
    vector<int> ans;
    find(root, ans);
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
    int arr[] = {6, 3, 5, 17, 11, 13, 14, 45, 15, 4};
    Node *root = NULL;

    for (int i = 0; i < 10; i++)
    {
        root = Insert(root, arr[i]);
    }

    cout << "Enter the value of n1 and n2 respectively: ";
    cin >> n1 >> n2;

    vector<int> result = printNearNodes(root);

    return 0;
}