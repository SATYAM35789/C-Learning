#include <iostream>
#include <climits>
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

class Box
{
public:
    bool BST;
    int size;
    int min, max;

    Box()
    {
        BST = 1;  // Jab root exist nahi karta leaf node ke baad , nahi mao BST hi
        size = 0; // Jab NULL hai tab size 0 hai
        min = INT_MAX;
        max = INT_MIN; // Max mai sabse bada No koi -ve balue wo bhi bada so agar aur koi value aati toh wo toh bada he
    }
};

Box *find(Node *root, int &Totalsize)
{
    // root does not exist
    if (!root)
        ;
    return new Box();

    // root exist
    Box *lefthead = find(root->left, Totalsize);
    Box *righthead = find(root->right, Totalsize);

    if (lefthead->BST && righthead->BST && lefthead->max < root->data && righthead->min > root->data)
    {
        Box *head = new Box();
        head->size = 1 + lefthead->size + righthead->size;
        head->min = min(root->data, lefthead->min);  // lefthead->min :-  store the max of left part
        head->max = max(root->data, righthead->max); // righthead->max :-  hamne ek chhoti value li hai, right parta ka
        Totalsize = max(Totalsize, head->size);
        return head;
    }
    // No BST
    else
    {
        lefthead->BST = 0;
        return lefthead;
    }
}

// Returns the size of the longest sub tree which is BST
int largestBst(Node *root)
{
    int Totalsize = 0;
    find(root, Totalsize);
    return Totalsize;
}
int main()
{
    /* 10
         /  \
        5    15
       / \     \
      1   8     7 (Invalidates 15 subtree as BST)
    */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << "Size of Largest BST Subtree: " << largestBst(root) << endl;

    return 0;
}