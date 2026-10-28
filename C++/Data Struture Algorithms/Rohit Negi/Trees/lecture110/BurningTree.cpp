#include <iostream>
#include <queue>
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
// return burn or hright daily
int BurnOrHeight(Node *root, int &timer, int target)
{
    // root not exist
    if (!root)
        return 0;

    // root exist
    // target node

    if (root->data == target)
        return -1;

    // On at node we ask kya burn node hamare left mai to(h  burn do nahi toh height de us side ki
    int left = BurnOrHeight(root->left, timer, target);
    // On at node we ask kya burn node hamare right mai toh  burn do nahi toh height de us side ki
    int right = BurnOrHeight(root->right, timer, target);

    // Burn ki condition
    if (left < 0)
    {
        timer = max(timer, abs(left) + right);
        return left - 1;
    }
    if (right < 0)
    {
        timer = max(timer, abs(right) + left);
        return right - 1;
    }

    // Agar left side be burn nahi aur right side bhi then return height
    return 1 + max(left, right);
}

void find(Node *root, int target, Node *&BurnNode)
{
    if (!root)
        return;

    if (root->data == target)
    {
        BurnNode = root;
        return;
    }
    find(root->left, target, BurnNode);
    find(root->right, target, BurnNode);
}

int height(Node *root)
{
    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int minTimeToBurn(Node *root, int target)
{
    int timer = 0;
    BurnOrHeight(root, timer, target);
    // Nichhe wale ko jalne mai kitna time lagega

    // Height of target node ki
    Node *BurnNode = NULL;
    find(root, target, BurnNode); // Burn node khah present hai

    int high = height(BurnNode) - 1;

    return max(timer, high);
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

    cout << "Enter the target node";
    int target;
    cin >> target;

    int result = minTimeToBurn(root, target);
    cout << " Minimum time to burn a tree :" << result << " sec" << endl;

    return 0;
}