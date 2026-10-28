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

void kSum(Node *root, int &sum, int &k)
{
    if (!root)
        return;

    kSum(root->left, sum, k);
    k--;
    if (k > 0)
        sum = sum + root->data;
    else
        return;
    kSum(root->right, sum, k);
}

int Sum(Node *root, int k)
{
    int sum = 0;
    kSum(root, sum, k);
    return sum;
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

int main()
{
    int arr[] = {6, 3, 5, 17, 11, 13, 14, 45, 15, 4};
    Node *root = NULL;

    for (int i = 0; i < 10; i++)
    {
        root = Insert(root, arr[i]);
    }

    cout << "Enter the value of k : f";
    int k;
    cin >> k;
    cout << Sum(root, k) << endl;
}