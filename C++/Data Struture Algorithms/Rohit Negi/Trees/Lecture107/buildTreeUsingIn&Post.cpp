#include <iostream>
#include <stack>
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

int find(int in[], int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}

Node *Tree(int in[], int post[], int InStart, int InEnd, int index)
{
    if (InStart > InEnd)
        return NULL;

    Node *root = new Node(post[index]);
    int pos = find(in, post[index], InStart, InEnd);

    // right part ko build karo
    root->right = Tree(in, post, pos + 1, InEnd, index - 1);

    // left part ko build karo
    root->left = Tree(in, post, InStart, pos - 1, index - (InEnd - pos) - 1);

    return root;
}
// Build tree with the help of preOrder and Inorder given in array form
Node *buildTree(int in[], int post[], int n)
{
    return Tree(in, post, 0, n - 1, n - 1);
}

// Tree sahi bana hai ya nahi, check karne ke liye Post-order function
void printPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    // Test Case:
    // Inorder: Left -> Root -> Right
    // Preorder: Root -> Left -> Right
    int in[] = {4, 2, 5, 1, 3};
    int post[] = {1, 2, 4, 5, 3};
    int n = sizeof(in) / sizeof(in[0]);

    Node *root = buildTree(in, post, n);

    cout << "Tree successfully built!" << endl;
    cout << "Pre-order traversal of the built tree: ";
    printPreOrder(root);
    cout << endl;

    return 0;
}
