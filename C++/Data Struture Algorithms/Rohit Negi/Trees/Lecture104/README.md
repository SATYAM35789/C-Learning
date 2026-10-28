### Two trees are identical :- 
Hamare pass do tree ke root nodes hai r1 and r2. Hamko batana hai ki ye do trees hai ye identical hai ki nahi. Inke data aur structure bhi same hone chahiye. 
Approch :- On a particular node, Check karo ki ye node identical hai, if yes than ab check karo kya isak left identical hai aur phir check karo ki iska right identical hai ki nahi on each node. 
Code Part :- 
1. IsIdentical() bool type ka, paraneter : Node type ka r1 pointer , Node type ka r2 pointer bana lo. 
2. r1 barabar hai Null ke aur r2 barabar hai null ke toh return kar do 1.
3. ab agar r1 nahi exist karta hai aur r2 exist karta hai aur agar r2 nahi exist karta hai aur r1 exist karta hai tab return kardo 0.
4. Agar r1 ka data barabar nahi hai r2 ke data ke toh return kardo 0;
5. ab mujko bata do ki r1 ka left aur r2 ka left barabar hai aur ab mujko bata do ki r1 ka right aur r2 ka right barabar hai  tab return kardo. 

Time and space complexity  : O(n)
Code Implementation :-
```
bool isIdentical(Node *r1, Node *r2)
{
    // Base Condition
    if (!r1 && !r2)
        return 1;
    if ((!r1 && r2) || (r1 && !r2))
        return 0;

    if (r1->data != r2->data)
        return 0;

    return (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
}
```
### Mirror Tree :- 
Ek tree hai hamare pass hame uska mirror image return karna hai.
Approch:- Hamko tree ka root milega jiska hamko left node ko right node aur right node ko left node mai convert kardo on a particular node, we do the same thing. 
Code Part :- 
1. Mirror() void type ka, parameter: Node type ka root pointer. 
2. Ab humko root ke left ko root ke right ko aapas mai change karenge with the help of temp variable.
3. Mirror image de root ka left side ka aur mirror image dedo root ke right side ka
Base Case :- Agar root null ho jata hai ua exist nahi karta then return ho jao. 

Code Implementation :- 
```
void mirror(Node *root)
{
    if (!root)
        return;

    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;
    // Left
    mirror(root->left);
    // Right
    mirror(root->right);
}
```

### Check For Balance Tree :- 
Balance Tree :- heght of left subtree - height of right sub tree is greater than equal to -1 and less then equal to -1 , this property should be held on each node in a tree. answer should lie in (-1,0,1). 
Ek bool type ka valid variable lenge jisko inialize kar denge 1 se. Ham apne tree ko starting mai balanced maan kar chalenge if koi node balance nahi hai toh hum is valid ko 0 kar denge aur apna ans return kar denge. 
abs() :- jo bhi value usko positive mai lakar dega. 
Approch :
1. Balance check karo
2. return height

Code part :- 
1. ek IsBalance() bool type ka bana denge, parameter : Node type ka ek root pointer bana denge.
2. ek bool type ka variable bana denge, jiska naam valid hoga. 
3. height() mai, parameter : root aur valid pass kardenge.

1. ek height() int type ka, parameter : Ek node type ka root pointer bana lenge, ek bool type ka valid variable as referrence
2. int l bana ko jo hako root ke left side ka height la kar dega.
3. int R bana ko jo hako root ke right side ka height la kar dega.
4. agar L-R agar bada hai, 1 se tab, valid ko 0 bana do. 
5. return kardo 1 + max(L, R):- left aur right mai se jo bhi bada hai usko return kardo. 
Base Condition :
Agar root barabar hai null ke toh return kardo, 0.

Time and Space Complexity : O(n).

Code Implementation :- 
```
int height(Node *root , bool & valid)
{
    if(!root)
    return 0;

    int L = height(root->left, valid);
    int R = height(root->right, valid);
    if(abs(L-R) >1)
    valid = 0;

    return(1 + max(L,R));
}

bool isBalanced(Node *root)
{
    bool valid = 1;
    height(root, valid);
    return valid;
}
```

### Level Order in Traversal in spiral form:-
spiral form means S form mai . Ham level traversing queue ka use kiye the. Lets try that one. 
If traversing L->R than inserting the value in queue in Left and Right order. and If traversing in R->L yhan inserting the valeue in the R->L order. 
note : Jab bhi hamara ek level of traversing complete ho raha tab hum , abhi tak ke apne queue ke element ko stack mai daal rahe phir wapas queue mai daal rahe hai so ki ham reverse kar paye taki L to R or R to L traversing kar paye. So is tarah hamari complexity bad ja rahi hai. 

Approch 2nd: Hamne do stack use kar liye, ek R to L lo store karega and ek l to right ko. Jise ek stack khali hota hai toh ham dura stack par chale jaye aur us stack mai jo bhi top par us se releted left aur right ko khali mai dalte chale jayenge and so on tab dono stack khali n ho jaye. Order same rahega inserting wala.   

Code Part :- 
1. ek levelOrder(), vector<int> type ka banalenge, parameter : Ek Node type ka root pointer bana lenge.
2. Do stack bana lo ek stack s1 Node type ka store the R to L aur ek stack s2 Node type ka store the l to R
3. s1 mai push kardo root ko, aur ek vector bana lo ans naam ka.
4. Agar stack1 khali nahi hota ya stack2 khali nahi hota tab tak
   1. Agar stack1 khali nahi hai
   2. Jab tak stack1 exist karta hai tab tak,
      1. ek Node type ka temp bana lo jisme s1 ka top daal do.
      2. stack ko pop kardo. 
      3. ans mai pushback kardo temp ka data. 
      4. agar temp ka right exist karta hai toh, temp ke left ko stack2 mai push kardo. 
      4. agar temp ka left exist karta hai toh, temp ke right ko stack2 mai push kardo.
  else Agar stack2 exist karta hai toh , 
  2. Jab tak stack2 exist karta hai tab tak,
      1. ek Node type ka temp bana lo jisme s2 ka top daal do.
      2. stack ko pop kardo. 
      3. ans mai pushback kardo temp ka data.  
      4. agar temp ka left exist karta hai toh, temp ke right ko stack1 mai push kardo. 
      5. agar temp ka right exist karta hai toh, temp ke left ko stack1 mai push kardo.
Return kardo ans ko. 

Time and Space Complexity : O(n).

Code Implementation :- 
```
vector<int> findSpiral(Node *root)
{

    stack<Node *> s1; // Right to left
    stack<Node *> s2; // left to right
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge Case Check
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        // Right to left
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                Node *temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
                // Right
                if (temp->right)
                    s2.push(temp->right);
                // Left
                if (temp->left)
                    s2.push(temp->left);
            }
        }
        // left to right
        else
        {
            while (!s2.empty())
            {
                Node *temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);
                // Left
                if (temp->left)
                    s1.push(temp->left);
                // Right
                if (temp->right)
                    s1.push(temp->right);
            }
        }
    }
    return ans;
}
```

### Check if 2 Nodes are cousin :-
Cosion Node : 1. same level par hane chahiye  2. Parent different hone chahiye.
Hamko do level di gai hogi, aur hamko pata karna hai ki wo cousin hai ki nahi. 
Code Part :- 
1. Ek IsCousion() bool type ka , parameter : Ek Node type ka root pointer lelo, ek int a aur ek int b lelenge.
2. ek queue bana lo node type ka jiska naam q hoga.
3. queue mai push kardo root ko,
4. aur do int l1 and l2 , dono -1 se initialize kardo. aur ek int level naam ka jisko 0 se initialize kardo
5. Agar hamara queue empty nahi hai, tab tak
   1. ek int n naam ka jisme q.size daal do
   2. jab tak n, 0 ke barabar nahi hota tab tak,
      1. ek node type ka temp mai queue ke front ko daal do.
      2. queue ko pop kardo.
      3. Agar temp->data barabar aata hai a tab
         1. l1 mai level daal do. 
      4. 3. Agar temp->data barabar aata hai b tab
         1. l2 mai level daal do. 
      5. Agar temp ka left exist karta hai, tab queue mai push kardo temp ke left ko.
      5. Agar temp ka right exist karta hai, tab queue mai push kardo temp ke right ko.
6. count++ kardo.
Note : Agar yaha tak code chal chuka hai means ek level par ham apne values ko khoj chuke hai , agar ek l1 mila hai aur l2 nahi ya phir vise-versa means ye cousin nahi hai kyu same levele nahi mile hai. 
7. Agar l1 barabar nahi hai l2 ke tab return kardo 0.
8. Agar l1 barabar nahi hai -1 ke break kar do, means ye update ho chuke hai. 

Ab Hamko inke parents khojne hai,

1. parent() bool typa ka, parameter: Node type ka ek root pointer, ek int a aur ek int b
2. Agar rrot ka left aur root ka right exist karta hai, tab
   1. root ka left ka data barabar aata hai a ke ya root ka right ka data barabar aat hai b tab return kardo 1 ko
   1. root ka left ka data barabar aata hai b ke ya root ka right ka data barabar aat hai a tab return kardo 1 ko
3. return (parent(root->left,a,b) || parent(root->right,a,b) ) :- root ka left ya right aagar koi bhi ye answer la deta hai toh wahi answer hoga. 
Edge case : Agar root barabar hai null ke toh return kardo 0. 

Code Implementation :
```

```
