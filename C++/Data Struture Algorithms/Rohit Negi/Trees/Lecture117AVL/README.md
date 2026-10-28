### AVL Tree :- 
BST Operation :- Incresing Order : ek right tree form hoga. 
Insertion : O(n)
Search : O(n)
Deletion : O(n)
Creation :- 
1. Array O(nlogn) :- Array ka use karlo, Data ko array mai store karlo, phir koi sorting algo laga lo Tree create karlo.
2. Runtime O(nsq) :- Ek Karke element milta hai so time complexity O(nsq) ho jati hai. 

BST :- Ye possibility ho sakti hai ki tree ek he side grown kare. So is reason ke wajah se O(n) worst case ho ja raha tha. So we need to reduce this complexity so we need AVL. Jo ek side grow ho raha hai bas is chiz ko reduce karna hai. 

AVL concept reduce this complexity O(nlogn) in all the Scenario. AVL is Self Balance Binary Search Tree. 
means left part ka height and right side ka height is lie between -1 to 1. Ye condition sare nodes par follow hone chahiye.  

LL ke case mai jo top wala hai usko right mai daal do. (top wale ko :- right Rotation kardo)
RR ke case mai jo top mai usko left mai daal do. (Left rotation)
LR ka case mai ek dam niche wala ko pakdo uske top ko left mai dalo aur uske uppar wale ko right mai daal.
(1. Left Rotation  2. Right Rotation)
RL ke case mai ek dam niche wale ko pakdo uske upper right side dalo aur left side mai usko uppar daal do.
(1. Right Rotation 2. Left Rotation)
Note:- mera left aur mera right. 

Left Rotation :- Node ko left side or antiClock or ghuma do / node left side se niche la do.  
Right Rotation :- Node ko right side or Clock or ghuma do / node right side se niche la do.  

Note:- 
1. LL Case : Right Rotation(Top)
2. RR Case : Left Rotation(Top)
3. LR Case : Left Rotation(Middle)
           : Right Rotation(Top)
4. RL Case : Right Rotation(Middle)
           : Left Rotation(Top)

Edge Case In AVL :- 
1. Left Rotation :- A B C increasing Order mai hai(BST), RR hai toh Left rotation karte samay B ke lefT child ko A ke right mai daal do. 
2. Right Rotation :- A B C decresing Order mai hai(BST), LL hai toh rIGHT rotation karte samay B ke right child ko A ke left mai daal do.

How we come to know that ki konsa se node unbalance hai aur kis type ka case hoga?
Note:- Agar Balance greater than 1 hai means positive, then left side ko unbalance hoga. Wahi agar -ve value hota hai then right side gadbad hai. For the first L and R(of different cases).
Ab jo naya node attach hua wahi unbalance karega, so ab check karenge ki kya naya node hai wo achhota hai roh left side unbalance(l) and if bada hua toh right side unbalance hua hai (R).  

Heght ke sath dealing?
Node ki heghy calaculate karne jayenge toh hamari complexity bad jayengi, then node hight ko define kar denge usi samay height ko manage kar lenge. 

Note
1. If Balance > 1 then it is Left Rotation (L)
    key < root->left->data (L)
    key > root->left->data (R)
2. Balance < 1 then it is Right Rotation (R)
      root->right->data > key(L)   :- Agar data bada then jo naya value wo uske left mai jeyega to make BST
      root->right->data < key(R)

Right Rotation :- 
1. child mai daal do root ke left ko
2. childRight mai child ke right ko
3. child ke right mai root ko daal do
4. root ke left mai daal do childRight ko
5. update root ka height
6. update child ka height
7. return kardo child  so ki ye wapas se apne original tree mai connection bana paye.  

LeftRotation :- 
1. Child mai daal do root ke right ko
2. leftchild mai daal do child ke left ko
3. child ke left mai root ko daal do
4. root ke right mai daal do childLeft ko
5. update the root
6. update the height of child.
7. return kardo child ko 

Code Implementation :- 
```
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data, height;
    Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root) {
    return (!root) ? 0 : root->height;
}

int getBalance(Node *root) {
    return (!root) ? 0 : getHeight(root->left) - getHeight(root->right);
}

// Right Rotation (LL Case)
Node *rightRotation(Node *root) {
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

// Left Rotation (RR Case)
Node *leftRotation(Node *root) {
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *insert(Node *root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // Duplicates not allowed

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // 1. Left Left Case
    if (balance > 1 && key < root->left->data)
        return rightRotation(root);

    // 2. Right Right Case
    if (balance < -1 && key > root->right->data)
        return leftRotation(root);

    // 3. Left Right Case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // 4. Right Left Case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void preorder(Node *root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); // Yeh LR case trigger karega

    cout << "PreOrder Traversal of Balanced AVL Tree: " << endl;
    preorder(root);
    cout << endl;

    return 0;
}
```



