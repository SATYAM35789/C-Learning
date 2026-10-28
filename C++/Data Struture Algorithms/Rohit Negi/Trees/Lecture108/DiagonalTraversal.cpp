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

void find(Node *root, int pos, int &l)
{
    if (!root)
        return;

    l = max(pos, l);

    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}

void findDiagonal(Node *root, int pos, vector<vector<int>> &ans)
{
    if (!root)
        return;

    ans[pos].push_back(root->data);
    findDiagonal(root->left, pos + 1, ans);
    findDiagonal(root->right, pos, ans);
}

vector<int> diagonalTraversal(Node *root)
{
    int l = 0; // left most diagonal ki value hamko yaha milega jo find()
    find(root, 0, l);

    vector<vector<int>> ans(l + 1);
    findDiagonal(root, 0, ans);

    vector<int> ans2;

    for (int i = 0; i < ans.size(); i++)        // no of rows
        for (int j = 0; j < ans[i].size(); j++) // particular row mai column kitne hai
            ans2.push_back(ans[i][j]);

    return ans2;
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

    if (!root)
    {
        cout << "Tree is empty!" << endl;
        return 0;
    }

    cout << " Diagonal traversal :";
    vector<int> result = diagonalTraversal(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}