#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

Node *deleteNode(Node *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->data) // Left Side
        root->left = deleteNode(root->left, key);

    else if (key > root->data) // Right side
        root->right = deleteNode(root->right, key);
    else
    {
        // Leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // Only One Child exist
        else if (root->left && !root->right) // When  Only left child exist
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // Both child exist
        else
        {
            // Right Side Smallest element dhoondhkar lao
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }

            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data); // kyuki ham right side move ho rahe hai so root ke right mai store
        }
    }

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check the balance
    int balance = getBalance(root);

    // Left Side
    if (balance > 1)
    {
        // LL
        if (getBalance(root->left) >= 0)
            return rightRotation(root);
        // LR
        else // Jab getBlance ki vlue -ve hogi
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // Right Side
    else if (balance < -1)
    {
        // RR
        if (getBalance(root->right) <= 0)
            return leftRotation(root->right);
        // RL
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    // No Unbalance case
    else
    {
        return root;
    }
}

int getHeight(Node *root)
{
    if (!root)
        return 0;

    return root->height;
}

int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

// Right Rotation
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

// Left Rotation
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node *insert(Node *root, int key)
{
    // Doesnot exist
    if (!root)
        return new Node(key);
    // root Exist karta hai then
    if (key < root->data) // left side attach ho jao
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // Duplicates element hoga toh waise usko wapas bhej denge

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balance check karo ki tree balance hai ki nahi
    int balance = getBalance(root);

    // Left Left unbalance case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root); // Top element
    }
    // Right Right unbalance case
    else if (balance < -1 && root->right->data < key)
    {
        return leftRotation(root); // Top element
    }
    // Left Right unbalance case
    else if (balance > 1 && key > root->right->data)
    {
        root->left = leftRotation(root->left); // Middle element
        return rightRotation(root);            // top
    }
    // Right Left unbalance case
    else if (balance < -1 && root->right->data > key)
    {
        root->right = rightRotation(root->right); // middle
        return leftRotation(root);                // Top
    }
    // No unbalance case
    else
    {
        return root;
    }
}

void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = NULL;

    // Duplicates element are not allowed.
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "PreOrder : " << endl;
    preorder(root);
}

// Is Code mai ham dekh pa rahe honge ki, Jab hum different path pae ja rahe tab hum return nahi karwa rahe hai,
// kyuki hamko balancing and height bhi check karni hoti hai, While deleting node In case of leaf Node and When Olny
// one child exist, When both child exist hum waha return nahi karwa rahe hai.