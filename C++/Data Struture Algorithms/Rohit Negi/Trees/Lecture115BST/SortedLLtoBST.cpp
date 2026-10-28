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

class LNode
{
public:
    int data;
    LNode *next;

    LNode(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *BuildBST(vector<int> &Tree, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start + 1) / 2;
    Node *root = new Node(Tree[mid]);

    root->left = BuildBST(Tree, start, mid - 1);
    root->right = BuildBST(Tree, mid + 1, end);

    return root;
}

Node *sortedListToBST(LNode *head)
{
    vector<int> Tree;
    while (head)
    {
        Tree.push_back(head->data);
        head = head->next;
    }

    return BuildBST(Tree, 0, Tree.size() - 1);
}

// Tree verify karne ke liye Pre-order traversal
void preOrder(Node *root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Helper to create a Linked List from array
LNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    LNode *head = new LNode(arr[0]);
    LNode *curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new LNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    LNode *head = createList(arr, n);

    cout << "Converting Sorted Linked List to Balanced BST..." << endl;
    Node *root = sortedListToBST(head);

    cout << "Pre-order Traversal of Resulting BST: ";
    preOrder(root);
    cout << endl;

    return 0;
}