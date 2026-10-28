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

Node *BST(vector<int> &preorder, int &index, int lower, int upper)
{
    // Base Case
    if (index == preorder.size() || lower > preorder[index] || upper < preorder[index])
        return NULL;

    Node *root = new Node(preorder[index]);
    index++;

    // 3. Left child ke liye upper bound root->data hoga
    root->left = BST(preorder, index, lower, root->data);

    // 4. Right child ke liye upper bound wahi rahega jo parent ka tha
    root->right = BST(preorder, index, root->data, upper);
    return root;
}

Node *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return BST(preorder, index, INT_MIN, INT_MAX);
}

// Verification ke liye Inorder Print (BST ka inorder sorted hona chahiye)
void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    // Sample Preorder: Root -> Left -> Right
    // Let's take: 10, 5, 1, 7, 40, 50
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    cout << "Building BST from Preorder..." << endl;
    Node *root = bstFromPreorder(preorder);

    cout << "Inorder Traversal of the built BST (Should be sorted): ";
    inOrder(root);
    cout << endl;

    return 0;
}