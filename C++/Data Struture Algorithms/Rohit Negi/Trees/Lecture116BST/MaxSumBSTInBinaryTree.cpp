#include <iostream>
#include <climits>
#include <algorithm>
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

class Box
{
public:
    bool isBST;
    int minVal, maxVal;
    int sum;

    Box()
    {
        isBST = true;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        sum = 0;
    }
};

Box solve(Node *root, int &maxSum)
{
    // Base Case: NULL node is a BST with sum 0
    if (!root)
    {
        return Box();
    }

    // Bottom-Up: Niche se report mangao
    Box left = solve(root->left, maxSum);
    Box right = solve(root->right, maxSum);

    Box current;
    // Condition: Kya current node apne bacho ke saath milkar BST bana raha hai?
    if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal)
    {
        current.isBST = true;
        current.sum = root->data + left.sum + right.sum;

        // Range update for parent
        current.minVal = min(root->data, left.minVal);
        current.maxVal = max(root->data, right.maxVal);

        // Agar ye BST hai, toh iska sum check karo
        maxSum = max(maxSum, current.sum);
    }
    else
    {
        // Agar BST property yahan toot gayi
        current.isBST = false;
        current.sum = 0; // Ab ye upar kisi ke saath BST nahi bana payega
        // min/max update karne ki zaroorat nahi kyunki isBST false hai
    }

    return current;
}

int maxSumBST(Node *root)
{
    int maxSum = 0; // Question ke hisaab se agar koi BST nahi toh sum 0
    solve(root, maxSum);
    return maxSum;
}

int main()
{
    /* Tree Structure:
             1
           /   \
          4     3
         / \   / \
        2   4 2   5
    */
    Node *root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(5);

    cout << "Maximum Sum BST in Binary Tree: " << maxSumBST(root) << endl;

    return 0;
}