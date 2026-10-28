### Left view of Binary Tree
Ek given tree ka left view , hamko bata do. Left view : at each level uske sabse left mai jo bhi nodes wo lakar dedo. Left view means left side se dekh rahe ho aur at same level par sirf pahle wala element dikhega baki sab us element se dhak jayenge. 
Note : Har level ka pahle element hamara ans ho sakta hai. 
Approch :- Sabse pahle ek int bana lo n type ka jo q.size store karega, ham level order traversing kar rahe honge, sabse pahle root element daal do aur apne queue ko update kardo, aur n ko , aub jab tak n, 0 ke barabar nahi hota tab tak root ke left aur right ko daal , Jaise he n==0 hota hai means loop khatam aur level ko increse kar do.
Code Part :- 
1. LeftView(), vector type ka, parameter : Node type ka root pointer.
2. queue bana lo Node type ka, jiska naam q hoga.
3. queue mai root ko push kardo.
4. ek vector bana lo unt type ka , ans naam ka. 
5. Ab jab tak queue empty nahi ho jata, tab tak,
   1. ek integer n mai q.size daal do.
   2. ans vector mai pushback kardo, queue ke front ke data ko.
   3. Ab jab tak n barabar nahi hota 0 ke tab tak,
     1. Ek Node type ka temp pointer mai queue ka front daal do. 
     2. queue ko pop kardo
     3. agar temp ka left exist karta hai tab, queue mai temp ke left ko push kardo. 
     4. agar temp ka right exist karta hai tab, queue mai temp ke right ko push kardo. 
6. return kardo ans ko.

Code Implementation :- 
```
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge case
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // First node of the current level is our ans
        ans.push_back(q.front()->data);
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            // Apne next level ke element ko ander daal lo
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}
```

2nd Method :- Recursion :- 
Har ek level ka left most wala element je hamara ans hai. While moving if you notice that First time kisi level par ja rahe toh wahi hamara ans ho raha hai. or Kisi level ko agar haum pahli baar visit kar rahe hai toh wahi hamara ans hoga. 
How can come to know that ham pahli baar level aa rahe hai?
1st :- Pahle doodh lo ki kitne level hone wale hai. Iske hum do vector ka use karenge Visited (hamko bata dega ki ham level ko visit kiye hai ki nahi) aur ans(ans store karenge) ko.
Note :- Ham yaha tree ko do baar visit kar rahe hai ek bar level find karne ke liye 2nd ans find karne ke liye. Ab hamko ek he baar travserse karke answer nikalana hai. Jis node par hai waha hamu check karenge like mera level aur queue ka size same aata hai , toh this means ham pahli baar visit kar rahe hai.Insert opertion will occur when level == sizeofqueue. 

Code Part :-
1. Ek LView() void type ka, parameter: ek node type ka root pointer, int level jo starting mai 0 hoga and ek vector type ka ans as reference pass kardo. 
2. Agar level barabar hai ans.size ke toh ans mai pushback kardo root ke data ko.
3. Current node ke left side check karlo ki kahi udhar elelment hai ki nahi like LView(root->left,level+1,ans)
4. Current node ke right side check karlo ki kahi udhar elelment hai ki nahi like LView(root->right,level+1,ans)
5. Edge Case :- Agar root exist nahi karta tab return ho jao.

Code Implementation :- 
```
void LView(Node *root, int level, vector<int> & ans)
{
    if(!root)
    return;

    if(level==ans.size())
    ans.push_back(root->data);

    LView(root->left , level+1 , ans);
    LView(root->right , level+1 , ans);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge case

    LView(root,0,ans);
    return ans;
}
```

### Right view of Binary Tree :- 
Iske pahle question mai hamne 1st approch ja lagai thi, same approch yaha bhi lagani hai bas while inserting element in queue we have to ensure that 1st right will insert then left one will be inserted in the queue on a particular node. 

Code Implementation :- 
1st Method:-
```
vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge case

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // First node of the current level is our ans
        ans.push_back(q.front()->data);
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            // Apne next level ke element ko ander daal lo
            // Right
            if (temp->right)
                q.push(temp->right);
            // Left
            if (temp->left)
                q.push(temp->left);
        }
    }
    return ans;
}
```
2nd Method :- 
```
void RView(Node *root, int level, vector<int> & ans)
{
    if(!root)
    return;

    if(level==ans.size())
    ans.push_back(root->data);

    RView(root->right , level+1 , ans);
    RView(root->left , level+1 , ans);
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge case

    RView(root,0,ans);
    return ans;
}
```

### Top view of Binary tree :- 
Top se kon kon se node dikh rahe hai print karwa do sabko in Left-Right order mai.
Approch :- Root ko 0 maan lenge jitne iske left node honge unko -1 se badate jayenge if milega, jitne root right node honge unko 1 se badate jayenge if milega. After doing so agar jiska value same hai then jiska level kam hoga usko priorty de denge. if ek he then usko print kar denge. 
Answer : sabse left-most ans aana chahiye then us se kam then so on. 
ans nikalne ke liye two approch ka use kar sakte hai 1. level order traversing 2. By recursion
Level order traversing :- 
1.ans array :- Ham ans ka size kaise nikalenge :- Right most node - left most node + 1. ans create ans vector.
2. Shifting:- Ham shifting karenge ki ham apne data ko correct position par daal sake. By adding the left most postion(node). then sabki indesing sahi ho jayegi. 
3. Filled :- Ek vector bana lenge to ensure that ki hamara count jo pahle aaya usko phil kare.  

Code Part :- 
1. TopView() vector type ka, Parameter : Node type ka root pointer le lenge.
2. ek int l aur ek int r dono ko 0 se initialize kar denge.
3. find() ko call karlo, parameter: root, 0, l r
4. ek vector banalo ans naaam ka jiska size r-l+1 hoga.
5. ek vector bana lo bool type ka filled(r-l+1 , 0), size r-l+1 , aur 0 se initialize kardo. 
Level Order traversing :-  We need two Queue 1. for the level order traversing 2. for storing the index of top view element.
6. Ek queue bana lo Node type ka , naam q.
7. Ek queue bana lo int type ka , naam index.
8. q mai push kardo root ko
9. index mai push kardo(-1*l)  ie (-1) *(-4) = 4
10.  jab tak q khatam n ho jaye tab tak,
    1. Node type ka temp mai q ke front() ko daal do.
    2. q.pop() karwa do
    3. int pos mai index ka front() daal do
    4. index ko pop karddo
    5. Agar filled mai position set nahi hua hai, tab filled of pos mai 1 daal do aur ans of pos mai temp ka data daal do.
    6. Agar temp ka left exist karta hai tab , q mai push kardo temp ke left ko aur index mai push kardo pos -1.
    6. Agar temp ka right exist karta hai tab , q mai push kardo temp ke right ko aur index mai push kardo pos +1.
return kardo ans ko. 

Find() :- left aur right bata do. 
1. ek find() , void type ka, parameter : Node type ka root pointer, int pos, int type l as reference ,  int type r as reference
2. Agar root exist nahi karta , tab return ho jao.
3. l mai min de do l aur pos mai se.
4. r mai max de do r aur pos mai se.
5. Ab mujko find kardo root ke left side se find karke de do  like find(root->left , pos-1,l,r)
5. Ab mujko find kardo root ke right side se find karke de do like find(root->right , pos-1,l,r)

Code Implementation :- 
```
void find(Node *root, int pos, int &l, int &r)
{
    if(!root)
    return;

    l = min(pos,l);
    r = max(pos,r);

    find(root->left,pos-1,l,r);
    find(root->right,pos+1,l,r);
}

vector<int> topView(Node *root)
{
    int l=0, r=0;
    find(root,0,l,r);

    vector<int> ans(r-l+1);
    vector<bool> filled(r-l+1,0);

    queue<Node*> q;
    queue<int>index;
    q.push(root);
    index.push(-1*l);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if(!filled[pos])
        {
            filled[pos] -1;
            ans[pos] = temp->data;
        }

        // Left
        if(temp->left)
        {
            q.push(temp->left);
            index.push(pos-1);
        }
        // Right
        if(temp->right)
        {
            q.push(temp->right);
            index.push(pos+1);
        }
    }
    return ans;
}
```

### Top view of Binary Tree using Recursion :- 
Implementation part :- 
```
void Tview(Node *root, int pos, vector<int>&ans, vector<int>&level, int l)
{ 
    if(!root)
     return;

    if(level[pos]>l)
    {
        ans[pos] = root->data;
        level[pos] = l;
    }
    Tview(root->left,pos-1,ans,level,l+1);
    Tview(root->right,pos-1,ans,level,l+1);
}

vector<int> topView(Node *root)
{
    int l = 0, r = 0;
    find(root, 0, l, r);

    vector<int> ans(r - l + 1);
    vector<int> level(r - l + 1, INT_MAX);
    
    Tview(root , -1*l, ans, level,0);
    return ans;
}
```
