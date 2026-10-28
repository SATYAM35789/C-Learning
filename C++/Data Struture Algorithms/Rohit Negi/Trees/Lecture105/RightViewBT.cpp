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

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge case

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // First node of the current level is our ans
        ans.push_back(q.front()->data);
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            // Apne next level ke element ko ander daal lo
            // Right
            if (temp->right)
                q.push(temp->right);
            // Left
            if (temp->left)
                q.push(temp->left);
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

    cout << " Right view of the tree :";
    vector<int> result = rightView(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}