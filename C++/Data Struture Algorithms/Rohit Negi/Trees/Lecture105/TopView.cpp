#include <iostream>
#include <queue>
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

vector<int> topView(Node *root)
{
    int l = 0, r = 0;
    find(root, 0, l, r);

    vector<int> ans(r - l + 1);
    vector<bool> filled(r - l + 1, 0);

    queue<Node *> q;
    queue<int> index;
    q.push(root);
    index.push(-1 * l);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if (!filled[pos])
        {
            filled[pos] - 1;
            ans[pos] = temp->data;
        }

        // Left
        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }
        // Right
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
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

    cout << " Top view of the tree :";
    vector<int> result = topView(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}