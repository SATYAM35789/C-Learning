#include <iostream>
#include <vector>
#include <stack>
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

vector<int> findCommon(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> s1, s2;
    while (root1) // all the left side push into  stack1
    {
        s1.push(root1);
        root1 = root1->left;
    }
    while (root2) // all the left side push into  stack2
    {
        s1.push(root2);
        root1 = root2->left;
    }

    while (!s1.empty() && !s2.empty())
    {
        // top element equal hai
        if (s1.top()->data == s2.top()->data)
        {
            ans.push_back(s1.top()->data);
            root1 = s1.top()->right;
            s1.pop();
            root2 = s2.top()->right;
            s2.pop();
        }
        // s1 > s2
        else if (s1.top()->data > s2.top()->data)
        {
            root2 = s2.top()->right;
            s2.pop();
        }
        // s2 > s1
        else
        {
            root1 = s1.top()->right;
            s1.pop();
        }

        while (root1) // all the left side push into  stack1
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2) // all the left side push into  stack2
        {
            s1.push(root2);
            root1 = root2->left;
        }
    }

    return ans;
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
    Node *root1 = NULL, *root2 = NULL;

    // Tree 1: {5, 1, 10, 0, 4, 7, 9}
    int arr1[] = {5, 1, 10, 0, 4, 7, 9};
    for (int x : arr1)
        root1 = Insert(root1, x);

    // Tree 2: {10, 7, 20, 4, 9}
    int arr2[] = {10, 7, 20, 4, 9};
    for (int x : arr2)
        root2 = Insert(root2, x);

    cout << "Common elements in both BSTs: ";
    vector<int> common = findCommon(root1, root2);

    for (int x : common)
        cout << x << " ";
    cout << endl;

    return 0;
}
