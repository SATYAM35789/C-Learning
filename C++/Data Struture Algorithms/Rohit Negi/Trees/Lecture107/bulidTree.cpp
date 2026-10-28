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

Node *Tree(int in[], int pre[], int InStart, int InEnd, int index)
{
    if (InStart > InEnd)
        return NULL;

    Node *root = new Node(pre[index]);
    int pos = find(in, pre[index], InStart, InEnd);

    // left part ko build karo
    root->left = Tree(in, pre, InStart, pos - 1, index + 1);
    // right part ko build karo
    root->right = Tree(in, pre, pos + 1, InEnd, index + (pos - InStart) + 1);

    return root;
}
// Build tree with the help of preOrder and Inorder given in array form
Node *buildTree(int in[], int pre[], int n)
{
    return Tree(in, pre, 0, n - 1, 0);
}

// Tree sahi bana hai ya nahi, check karne ke liye Post-order function
void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    // Test Case:
    // Inorder: Left -> Root -> Right
    // Preorder: Root -> Left -> Right
    int in[] = {4, 2, 5, 1, 3};
    int pre[] = {1, 2, 4, 5, 3};
    int n = sizeof(in) / sizeof(in[0]);

    Node *root = buildTree(in, pre, n);

    cout << "Tree successfully built!" << endl;
    cout << "Post-order traversal of the built tree: ";
    printPostOrder(root);
    // Expected Output: 4 5 2 3 1
    cout << endl;

    return 0;
}
