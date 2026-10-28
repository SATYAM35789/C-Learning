#include <iostream>
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

Node *deleteNode(Node *root, int target)
{
    if (!root)
        return NULL;

    if (root->data > target)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }
    else if (root->data < target)
    {
        root->right = deleteNode(root->right, target);
        return root;
    }

    // root ka node target ke barabar
    else
    {
        // leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // 1 child exist
        else if (!root->right) //  Left child exist
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left) // Right child exist
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child exist
        else
        {
            // find the gratest element from the left
            Node *child = root->left;
            Node *parent = root;

            // Right most tak pahuchna hai
            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            // right most tak pahuch chuke ab, condtions jo ayengi
            if (root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
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
    int arr[] = {6, 3, 5, 17, 11, 13, 14, 45, 15, 4};
    Node *root = NULL;

    for (int i = 0; i < 10; i++)
    {
        root = Insert(root, arr[i]);
    }

    cout << "Original BST (Inorder): ";
    inOrder(root); // BST ka inorder hamesha sorted hota hai
    cout << endl;

    int toDelete = 17;
    cout << "Deleting " << toDelete << "..." << endl;
    root = deleteNode(root, toDelete);

    cout << "BST after deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}