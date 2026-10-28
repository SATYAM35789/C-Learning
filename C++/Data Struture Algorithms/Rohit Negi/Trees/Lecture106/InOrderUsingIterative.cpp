#include <iostream>
#include <stack>
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

vector<int> InOrder(Node *root)
{
    vector<int> ans;
    if(!root)
      return ans;

    stack<Node*> s;
    stack<bool> visited;
    s.push(root);
    visited.push(0);

    while(!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        bool flag = visited.top();
        visited.pop();

        // Kya hum first time visit kar rahe hai
        if(flag==0)
        {
            // Right ko dalo
            if(temp->right)
            {
                s.push(temp->right);
                visited.push(0);
            }
            // phir node ko 
            s.push(temp);
            visited.push(1);
            // phir left wale ko
            if(temp->left)
            {
                s.push(temp->left);
                visited.push(0);
            }

        }
        // Kya hum second time visit kar rahe hai
        else 
        ans.push_back(temp->data);
    }
    return ans;   
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

    cout << " PreOrder using Iterative method :";
    vector<int> result = InOrder(root);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}