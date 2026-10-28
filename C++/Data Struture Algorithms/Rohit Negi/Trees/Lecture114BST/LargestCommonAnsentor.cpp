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

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    else
        return root;
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

    int n1, n2;
    cout << "Enter the value of n1 and n2 respectively: ";
    cin >> n1 >> n2;

    Node *ans = LCA(root, n1, n2);

    if (ans)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ans->data << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}