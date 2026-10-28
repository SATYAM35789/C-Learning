#include <iostream>
#include <queue>
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

void find(Node *root, int pos, int &l, int &r)
{
    if (!root)
        return;

    l = min(pos, l);
    r = max(pos, r);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}

void Tview(Node *root, int pos, vector<int> &ans, vector<int> &level, int l)
{
    if (!root)
        return;

    if (level[pos] > l)
    {
        ans[pos] = root->data;
        level[pos] = l;
    }
    Tview(root->left, pos - 1, ans, level, l + 1);
    Tview(root->right, pos - 1, ans, level, l + 1);
}

vector<int> topView(Node *root)
{
    int l = 0, r = 0;
    find(root, 0, l, r);

    vector<int> ans(r - l + 1);
    vector<int> level(r - l + 1, INT_MAX);

    Tview(root, -1 * l, ans, level, 0);
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

    cout << " Top view of the tree :";
    vector<int> result = topView(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}