### Create Binary Tree
Method First : We have creating the binary tree level wise in last lecture where we used enter the value in queue if the value given user is greater than -1 . So we include the value in the left or right side of the parent. 
Method 2 :- Dekho is method mai hum sirf left side bhar rahe until hamko -1 na mil jata . Agar milta hai ask for the right side last node jis node par -1 mila hai. uske right puchhenge agar ye bhi -1 toh uske parent ke pass cahle jayenge and again do the same.  
Approch :- 
1. If x==-1, return NULL
2. Agar uppar wli condition nahi hai toh, create Node
3. Left side 
4. right side 
5. Return the address of Node
Code Part :-
1. Creating Node classs Jaha public mai int type ka data aur do Node type ka pointer left and right aur Constructor mai value ko initialize kar lenege. 
2. Ek integer banayenge x naam jisko user se input karwa lenge. 
3. Agar x barabar hai -1 ke toh, return kardo NULL ko. 
4. Agar aisa nahi hai tab, ek temp pointer banalenge Node type ka jisme x ko daal denge.
5. temp ke left mai BinaryTree() jo address return karega usko daal do 
6. temp ke Right mai BinaryTree() jo address return karega usko daal do 

Code Implementation :- 
```
#include<iostream>
using namespace std;

class Node
{
    public :
    int data;
    Node *left , *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node * BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    // Left side create karo
    cout<<"Enter the left child of "<<x<<":";
    temp->left = BinaryTree();
    // Right side create karo
    cout<<"Enter the Right child of "<<x<<":";
    temp->right = BinaryTree();

    return temp;
}

int main()
{

    cout<<"Enter the root Node";
    Node *root;
    root = BinaryTree();
}
```
Time Complexity :- O(n)
Space Complexity : O(h) h: longest path of the tree. Jitna maximum height tak stack use hoga while function calling hoga, uska maximum of calling no is the Order of space complexity. Worse Case mai space complexity O(n).

### Traversal in the Tree 
1. PreOrder Traversal (NLR) 
2. In-Order Traversal (LNR)
3. Post-Order Traversal (LRN)

1. PreOrder Traversal (NLR) :-Pahle node par jao(print karo), aur us node ke left subarry par ko visit karo then right side jao, aisa har node par jao karo means agar particular node ki baat kare toh pahle us node ka value phir left side mai then right side.

Code Part :- 
1. Ek fun bana lo PreOrder naam ka, parameter : root pointer Node type ka
2. root ke data ko print kardo.
3. Preorder fun ko call karo jike ander root ka left daal do.
4. Preorder fun ko call karo jike ander root ka right daal do.
Base Case :- Agar root barabar aa jata hai  null ke toh, return ho jao. 

Code Implementation :- 
```

```

2. In-Order Traversal (LNR) : Mujko print karna se pahle, mere left side ko print karwa do. 
Root node par jao aur phir uske left jate raho tab tak left, null nahi ho jata node ko print kardo, phir right par jao aagar exist nahi karta toh return ho jao, agar karta hai toh phir same procedure karo. 

Code Part :- 
1. Ek fun bana lo InOrder naam ka, parameter : root pointer Node type ka
2. Inorder fun ko call karo jike ander root ka left daal do.
3. root ke data ko print kardo.
4. Inorder fun ko call karo jike ander root ka right daal do.
Base Case :- Agar root barabar aa jata hai  null ke toh, return ho jao. 

Code Implementation :-
```
```

3. 3. Post-Order Traversal (LRN)  :- 
For particular node pahle left jate par jao phir Right par jao then node ko print karo. 

Code Part :- 
1. Ek fun bana lo PostOrder naam ka, parameter : root pointer Node type ka
2. Postorder fun ko call karo jike ander root ka left daal do.
3. Postorder fun ko call karo jike ander root ka right daal do.
4. root ke data ko print kardo.
Base Case :- Agar root barabar aa jata hai  null ke toh, return ho jao. 

Code Implementation:-
```
```   