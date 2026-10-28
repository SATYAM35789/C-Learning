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

void correctBST(Node *root)
{
    Node *curr = NULL;
    Node *first = NULL, *second = NULL;
    Node *last = NULL, *present = NULL;

    // Morris Traversal
    while (!root)
    {
        // Left doesnot exist
        if (!root->left)
        {
            last = present;
            present = root;
            if (last && last->data > present->data) // gadbad hai
            {
                if (!first)
                {
                    first = last;
                    second = present;
                }
                second = present;
            }
            root = root->right;
        }
        // left exist
        else
        {
            curr = root->left;

            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }
            // Agar left sub tree traversed nagi hai, then
            if (curr->right == NULL)
            {
                curr->right = root;
                root = root->left;
            }
            // Agar already traversed hai
            else
            {
                curr->right = NULL;

                last = present;
                present = root;
                if (last && last->data > present->data) // gadbad hai
                {
                    if (!first)
                    {
                        first = last;
                        second = present;
                    }
                    second = present;
                }
                root = root->right;
            }
        }
    }

    // Swapping the nodes :-
    if (first && second)
    {
        int num = first->data;
        first->data = second->data;
        second->data = num;
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

// Verification ke liye Inorder
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
    // Manually making a swapped BST
    // Correct order should be: 1, 2, 3, 4
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2); // 2 and 3 are swapped

    cout << "Inorder before correcting: ";
    inOrder(root);
    cout << endl;

    correctBST(root);

    cout << "Inorder after correcting: ";
    inOrder(root);
    cout << endl;

    return 0;
}

//  Normal morris mai jaha hum cout karte the sirf eahi apni logic ko likha hai.
