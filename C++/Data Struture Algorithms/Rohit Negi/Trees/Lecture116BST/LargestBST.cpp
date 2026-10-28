#include <iostream>
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

    Box(int data)
    {
        BST = 1;
        size = 1;
        min = data;
        max = data;
    }
};

Box *find(Node *root, int &Totalsize)
{
    // leaf Node
    if (!root->left && !root->right)
    {
        Box *head = new Box(root->data);
        Totalsize = max(Totalsize, head->size);
        return head;
    }
    // Only right side exist
    else if (!root->left && root->right)
    {
        Box *head = find(root->right, Totalsize);
        if (head->BST && head->min > root->data) // Right side ka minmum element bada hona chahiye uske upper wale node(root Node)
        {
            head->size++;
            head->min = root->data; // because naya minimum ye ho jeyenga
            Totalsize = max(Totalsize, head->size);
        }
        else
        {
            head->BST = 0;
            return head;
        }
    }
    // Only left side exist kare
    else if (root->left && !root->right)
    {
        Box *head = find(root->left, Totalsize);
        if (head->BST && head->max < root->data) // Left side ka maximum element chhota hona chahiye root node(current Node)
        {
            head->size++;
            head->max = root->data; // Ab jab iske upper wale node ko par jayenge so uske liye max ye hoga
            Totalsize = max(Totalsize, head->size);
            return head;
        }
        else
        {
            head->BST = 0;
            return head;
        }
    }
    // Dono part exist karte ho
    else
    {
        Box *lefthead = find(root->left, Totalsize);
        Box *righthead = find(root->right, Totalsize);

        if (lefthead->BST && righthead->BST && lefthead->max < root->data && righthead->min > root->data)
        {
            Box *head = new Box(root->data);
            head->size += lefthead->size + righthead->size;
            head->min = lefthead->min;
            head->max = righthead->max;
            Totalsize = max(Totalsize, head->size);
            return head;
        }
        else
        {
            // Kisi ek part ko pakado aur bole do ki BST nahi hai
            lefthead->BST = 0;
            return lefthead;
        }
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