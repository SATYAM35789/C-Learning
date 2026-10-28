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

void Total(Node *root, long int &sum)
{
    if (root == NULL)
        return;

    sum += root->data;
    Total(root->left, sum);
    Total(root->right, sum);
}

long int TotalSum(Node *root)
{
    long int sum = 0;
    Total(root, sum);
    return sum;
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

    cout << "Sum of total no. of nodes : ";
    int ans = TotalSum(root);

    return ans;
}