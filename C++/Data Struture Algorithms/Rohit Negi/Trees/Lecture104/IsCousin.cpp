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

bool parent(Node *root, int a, int b)
{
    if (!root)
        return 0;

    if (root->left && root->right)
    {
        if (root->left->data == a && root->right->data == b)
            return 1;
        if (root->left->data == b && root->right->data == a)
            return 1;
    }
    // left part se parent mil jaye
    // Right part se parent mil jaye
    return parent(root->left, a, b) || parent(root->right, a, b);
}

bool isCousins(Node *root, int a, int b)
{
    queue<Node *> q;
    q.push(root);
    int l1 = -1, l2 = -1;

    int level = 0;

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->data == a)
                l1 = level;
            if (temp->data == b)
                l2 = level;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        level++;
        // agar l1 mil gaya hai aur l2 nahi ya vice versa means same level wali property hold nahi karti
        if (l1 != l2)
            return 0;

        // Hamko kab pata chalega ki dono mil chuke hai at same level
        if (l1 != -1)
            break;
    }
    // Parent :- agar parent same nahi hai toh 1 returb karega
    return !parent(root, a, b); // a and b ke parent same hai ki nahi.
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

    cout << " Level order traversal in spiral form :";
}