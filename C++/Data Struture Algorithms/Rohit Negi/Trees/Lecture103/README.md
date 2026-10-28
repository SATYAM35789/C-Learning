### Level Order Traversal :- 
Level wise nodes ko traverse karna from left to right in each of level of a tree. Aur isko hamko direct print nahi karwana isko ek vector ke ander store karwana hai , phir us vector ko return kar dena hai.  
Data structure using :- Queue.

Code Part :- 
1. Ek vector type ka LevelOrder() banayenge, parameter Node type ka root pointer
2. ek queue bana lo Node type ka , q naam ka.
3. queue ke ander push kardo root ko.
4. ek vector bana lo ans naam ka
5. ek node type ka temp bana lenge,
6. Jab tak queue empty n ho jaye tab tak , 
   1. temp ke ander queue ka front daal do.
   2. queue se pop kardo
   3. ans mai push_back kardo temp ke data ko. 
   4. Agar temp ka left exist karta hai, queue mai temp ke left ko push kardo.
   5. Agar temp ka right exist karta hai, queue mai push kardo temp ke right ko. 
7. ans ko return kardo

Time Complexity = Space width par depend karta hai (O(width)) -> O(n)
Space Complexity = If Perfect Binary tree
Note :- space used bu queue is space complexity of this program because rest of others are constant in nature. 
1. Har ek level par no. of nodes doble hote ja rahe hai.
2. If n is the total no. of Nodes, then No. of nodes in last level = n/2 +1 i.e n = 15 then last level = 8.
3. Ek highest no. nodes present in the queue the space Complexity of the program. that is O(n) in worst case jab sabke pass left aur right ho sakte hai. 
4. DFS (Recursive): Space height par depend karta hai (O(height)).
5. Memory-efficient techniques (jaise Morris Traversal) ka use karte hain jo O(1) space leti hain.

Code Implementation :- 
```
vector<int> levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        ans.push_back(temp->data);
        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
    return ans;
}
```

Trick :- 
PreOrder :-  Pahli baar node ko dekho print kardo. 
InOrder  Second time node ko dekho print kardo. 
PostOrder :- 3rd time node dekhenge usko print karwa denge. 

### Size of Binary Tree :- 
Ek binary tree given hoga hamko usko total no. nodes lakar batana hai. Simply traverse karte jao koi node mile toh apne count ek se bada do. 
Traversing technique :- PreOrder
Approch : 
1. Count ko ek se bada do 
2. Left side jao
3. Right side jao

Code part :- 
1. ek Total() banao void type ka, parameter : Node type root pointer aur ek global count++. 
2. Agar root barabar ho jaye Null ke toh return ho jao. 
3. Agar aisa nahi hai , count ++ kardo
4. Total() : root->left , count pass kardo.
5. Total() : root->right , count pass kardo.

2nd Method :-
Har node se ek sawal puchho mere left mai kitne hai, aur right mai kitne  lakar bata do aur mai khud ek hu.
(Left +Right + Current = Total count.) 
Code Part :- 
1. Ek TotalNode() bana lo int type ka, parameter : node type ka root pointer. 
2. Agar root barabar ho jaye Null ke toh return kardo 0. 
3. Agar aisa nahi hai toh return karo (1 + TotalNode(root->left) + TotalNode(root->right) )

Time and Space Complexity :- O(n)

Code Implementation :- 
Method 1:-
```
void TotalNode(Node *root, int &count)
{
    if (root == NULL)
        return;
    count++;
    TotalNode(root->left, count);
    TotalNode(root->right, count);
}

int getSize(Node *root)
{
    int count = 0;
    TotalNode(root, count);
    return count;
}
```

2nd Method :
```
int getSize(Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + getSize(root->left) + getSize(root->right));
}
```

### Sun of Binary Tree
Ab hamko puri nodes ke data ka summation return karna hai, Simply traverse karo aur har nodes par jane ke baad usko sum variable add karte jao. We are using PreOrder here. 
Code Part :- 
1. Ek TotalSum() void type ka bana lenge, Parameter: Node type ka root pointer aur ek sum naam ka reference variable.
2. sum mai add kardo sum aur root ke data ko.
3. TotalSum() parameter root ka left aur sum daal do , left side of root node ko calculate karne ke liye.
4. TotalSum() parameter root ka right aur sum daal do , right side of root node ko calculate karne ke liye.
5. Edge Case :-  agar root barabar ho jaye NULL ke toh return ho jao. 

2nd Method :-
1. Ek TotalSum() int type ka, parameter:  Node type ka root pointer.
2. Agar root Null ke barabar ho jaye toh return 0  kardo. 
3. nahi toh return kardo rootka data + TotalSum(root->left) + TotalSum(root->right) of each node. 

Code Implementation :- 
Method 1 
```
void Total(Node *root , long int &sum)
{
    if(root==NULL)
    return;

    sum += root->data;
    Total(root->left , sum);
    Total(root->right , sum);
}

long int TotalSum(Node *root)
{
    long int sum = 0;
    Total(root, sum);
    return sum;
}
```

2nd Method :- 
```
long int TotalSum(Node *root)
{
    if(root==NULL)
    return 0 ;

    return(root->data + TotalSum(root->left) + TotalSum(root->right));
}
```

### Count Leaves in binary tree
Leves Node wo jisko koi children nahi hota hai. Agar leaf node hai count++ kardo return ho jao, agar nahi hai toh left mai jao phir right mai jao. 
Code Part :- 
1. Ek countLeaf() void type ka, parameter : ek node type ka root pointer , ek count reference variable. 
2. Agar root ka left barabar hai root ke right ka barabar hai NULL ke toh count++ kardo. 
3. Agar aisa nahi hai CountLeaf() parameter root ka left aur count call kardo
r. Agar aisa nahi hai CountLeaf() parameter root ka right aur count call kardo

2nd Method :- 
On Particular node, mere left side kitne leafNode hai aur mere right side kitne LeafNode hai bata do.
1. ek CountLear(), int type ka, parameter : Ek node type ka root pointer.
2. Agar root barabar ho jata hai, null ke tab retyrn 0 kardo.
3. Agar root ka left barbar hai root ke right barabr hai null, ye dono exist nahi karte tab return 1 kardo.
4. mujhko countLeaf() de do root ke left side ka aur root ke right side ka, means root ke left mai kitne leafNode hai aur kitne leafNode root ke right side hai, mujko dedo. 

Code Implementation :- 
Method 1:
```
void CountLeaf(Node *root , int &count)
{
    if(root==NULL)
    return ;

    // leaf node condition
    if(!root->left&& !root->right)
    {
        count++;
        return;
    }
    // Non Leaf node condition
    CountLeaf(root->left, count);
    CountLeaf(root->right, count);
}

int countLeaves(Node *root)
{
    int count = 0;
    CountLeaf(root , count);
    return count;
}

```

Method 2 
```
int countLeaves(Node *root)
{
    if(root==NULL)
    return 0;
    if(!root->left&&!root->right)
    return 1;

    return(countLeaves(root->left) + countLeaves(root->right));
}
```

### Count Non Leaf Nodes :
Har ek node par jayenge aur bolenge tumare left maimkitne non-leafNode hai aur tumhare right mai kitne non-leafNode hai mujko batao, agar leaf node then return 0 , 
Code Part :- 
1. ek nonLeaf() banao int type ka, parameter : Ek node type ka root pointer bana lo. 
2. Agar root ka left aur root ka right exist nahi karta, means Null hai, then return kardo 0.
3. Agar aisa nahi hai, toh return kardo 1 + NonLeaf() ka left side + nonleaf at right side. 

Code Implementation :
```
int countNonLeafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    // Checking Leaf Nodes
    if (!root->left && !root->right)
        return 0;
    // Checking non leaf nodes
    return (1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
}
```

### Height of Binary Tree :- 
Height means finding the highest distance between leaf Node and root node. Kuchh plateforms edges ke basis par height dete jo correct way hai lakin gfg nodes ke basis par deta hai. 
Approch :-
1.Har ek particular nodes par jana hai aur puchhna hai ki tum apne left side aur right side ka height bata do left aur right mai se jo bada hai ham usko select kar lenge. 

Code Part :- 
1. height() int type ka, parameter : ek node type ka root pointer le lenge. 
2. Agar root barabar hai NUll ke toh return kardo 0.
3. jis node par hai(1) + maxmum of root ke left aur root ke right mai se koi ek wapas kardo.

Code Implementation :-
```
int height(Node *root)
{
    if (root == NULL)
     return 0;
    
    return(1 + height(root->left) + height(root->right));
    
}
```

### Largest Value in Each level
