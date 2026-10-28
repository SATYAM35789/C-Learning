### Binary Search tree 
Why Binary Search Tree :- Ex Linear search O(n) and Binary Search O(nlogn). Wise he binary tree ham randomely data stored hai so isme traverse aur search ke liye sabko visit karna padta hai, in BST node left side chhota and right side bada element ho. then traversing complexity kam ho jayengi. 

Inserting an BST :- Is order ko maintain karte hue insert karenge, left side chhota and right side bada element.If Duplicate element exist, we set in the program that ki agar do equal element aate hai toh usko right side bhej do.  

Code Part :- 
Node Structure :- Public mai int type ka data declare kardo, then Node type ka left aur right. Node ke construbtor mai, different data memberko initialize kardo.

Insertion in BST:-
1. Ek insert() Node type ka, Parameter : ek node type ka root pointer, ek int type ka pointer, int type ka target.
2. Agar root exist nahi karta, tab
   1. ek node type ka temp pointer bana lo, jisme new Node(target) daal do
   2. retern kardo temp ko. 
3. Agar target chhota hai, root ke data se, tab
   1. root ke left mai insert(root->left, target) call kar do. 
4. Agar uppar wala nahi, then 
   1. root ke right mai insert(root->right, target) call kar do.
return kardo root ko. 

Time complexity :- Is approch mai agar koi bhi node create kar rahe hai, usko leaf mai he connect kar rahe the. O(n)-> scenario :-(ascending and descending )
While Creating :- Recursion ke case mai Time Complexity O(nsq), space complexity:- O(n). 

Code Implementation :- 
```
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
        root->left = Insert(root->left,target);
    }
    else
    root->right = Insert(root->right,target);

    return root;
}

void inOrder(Node *root)
{
    if(!root)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    int arr[] = {6, 3, 5, 17, 11, 13, 4, 45, 15, 4};
    Node *root = NULL;

    for (int i = 0; i < 10; i++)
    {
        root = Insert(root, arr[i]);
    }

    // Traverse of BST, by inOrder then it will give the sorted array. 
    inOrder(root);
}
```

### Search in BST :-
Jab ham BST mai search kar rahe hai toh, agar value present hai 1 return kardo if value prsent nahi toh 0 return kardo. Jab search kar rahe honge tab ham apne target ko compair karlenge root ke data se agar wo bada hai toh right side move karke check karenge agar wo chhota hai toh left side move karke dekh lenge. 

Code Part
1. search() bool typa ke le lenge, parameter : Node type ka root pointer, int type ka target le lo.
2. Agar root null ho gaya tab return kardo 0 (present nahi hai)
3. agar root ka data barabar aa jaye target toh return kardo 1. 
4. agar root ka data chhota hai, target se then return kardo search(root->left, target)
5. agar root ka data bada hai, target se then return kardo search(root->right, target)

Time Complexity :- O(h) = O(n). and space complexity:- O(n) recursive call.

### Delete in BST :- 
Hamko ek BST diya hoga aur hamko ek target value di hogi  usko dhondh ke delete kardo. 
Agar target element leaf node hai toh return kardo null ko. 
Agar aise node ko delete karte hai jiske ek child hai left ya right then delete the node and uske left ya right child ko return kardo.
Agar aisa node hai jiska do child hai, then ek aise node ko select karna padega apne left part aur right part mai jo is position par suitable rahe, so
1. agar left side se nikal rahe tab hamko left side ke right most value ko rakhna padega
1. agar right side se nikal rahe tab hamko right side ke left most value ko rakhna padega 

Pseudo Code :- 
1. If leaf node: -> delete node ->return NULL
2. If Only One Child 
    if only left child : ->delete node return left child
    if only right child : ->delete node return right child
3. If both child (root != parent ) 
   Find the greatest  in left child
   parent ke right ko bolo child ke left ko point kare
   child ke lrft mai root ka left daal do
   child ke right mai root ka right daal do
   delete kardo root ko
   return kardo child ko
4. Agar parent aur root node same ya barabar hai hai tab kya karna hai
   1. child ke right mai root ka right daal do
   2. delete kardo right ko
   3. return kardo child ko

Code Implementation :- 
```
Node *deleteNode(Node *root, int target)
{
    if (!root)
        return NULL;

    if (root->data > target)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }
    else if (root->data < target)
    {
        root->right = deleteNode(root->right, target);
        return root;
    }

    // root ka node target ke barabar
    else
    {
        // leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // 1 child exist
        else if (!root->right) //  Left child exist
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left) // Right child exist
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child exist
        else
        {
            // find the gratest element from the left
            Node *child = root->left;
            Node *parent = root;

            // Right most tak pahuchna hai
            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            // right most tak pahuch chuke ab, condtions jo ayengi
            if (root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
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
```



