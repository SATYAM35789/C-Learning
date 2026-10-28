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

void find(Node *root, int pos, int &l, int &r)
{
    if (!root)
        return;
    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}

// Function to find the level order traversal
vector<int> verticalOrder(Node *root)
{
    if (!root)
        return {};
    int l = 0, r = 0;
    find(root, 0, l, r);
    // positive index ke liye 2d vector bana lo
    vector<vector<int>> positive(r + 1);
    // negative index ke liye 2d vector bana lo
    vector<vector<int>> negative(abs(l) + 1);

    // need queue because ham yaha level order traversal laga rahe hai
    queue<Node *> q;
    q.push(root);
    queue<int> index;
    index.push(0);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if (pos >= 0)
            positive[pos].push_back(temp->data);
        else
            negative[abs(pos)].push_back(temp->data);

        //  root ke left value ko daal do queue mai
        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }
        //  root ke right value ko daal do queue mai
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    // Now we have negative and positive 2d array , so we need to make store it in single 1d array
    vector<int> ans;
    for (int i = negative.size() - 1; i > 0; i--)
        for (int j = 0; j < negative[i].size(); j++)
            ans.push_back(negative[i][j]);

    for (int i = 0; i < positive.size(); i++)
        for (int j = 0; j < positive[i].size(); j++)
            ans.push_back(positive[i][j]);

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

    cout << " Vertical order with level order traversal :";
    vector<int> result = verticalOrder(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}