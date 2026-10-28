### Lowest Common Ancestor in a BST
Hamko do node ka data diya hoga hamko uska lowest common Ancestor nikalna hoga.
Approch :- Dono given nodes ke liye path nikal lo, ek path 1 jo n1 tak hoga, dusra path jisme n2 hoga, so ab dono path check karenge, ki kaha tak ye similar jaha non similar hue uske pahle jo similar tha wo answer hoga. If the question ask that do not extra space. so this approch failed. 

Optimized Approch :- 
Har node ek sawal karenge ki n1 and n2 kaha milenge, agar left/right then go to left/right. Jaha wo hamko alag raste dega ki n1 left mai milega aur n2 right mai then wahi hamara ans hoga. 
1. ya toh dono node left mai milenge
2. ya toh dono node right mai milenge
3. ya toh ek left aur dusra right mai

Code Part :- 
1. LCA() node type ka, parameter : node type ka root pointer, int type ka n1 aur n2
2. Agar root ka data bada hai n1 se aur root ka data bada hai n2 se then LCA(root->left,n1,n2) call kardo root ke left ke liye and isko return kardo
3. Agar root ka data chhota hai n1 se aur root ka data chhota hai n2 se then LCA(root->right,n1,n2) call kardo root ke right ke liye and isko return kardo
4. else :- Agar dono case nahi hai toh, return kardo root ko. 

Time and Space Complexity :- O(n)

Code Implementation :- 
```
Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2)
      return  LCA(root->right, n1, n2);

    else
        return root;
}
```

### Print BST element in given range :- 
BST given hoga , Hamko ek range milga aur hamko us range ke elements ko print karwana hoga in sorted form . 
Approch :- Ham iska inOrder traversal nikal sakte hai, phir given range ko if  ke help se solve kar lenge. 
Optimized Approch :- Har node par jayenge aur puchhenge ki kya node ka data hai wo hamare range mai hai ya nahi. if mila then app LNR(preorder) so we got in sorted form. phir return hoke bahara aa jao. 
1. left side jao agar root ka data bada hai, range se
2. right side jao agar root ka data chhota hai, range se

Code Part :- 
1. find() void type ka, Parameter : Node type ka root pointer, vector type ka ans(as reference).
2. Agar root ka data bada hai n1 se aur root ka data bada hai nw se find(root->left, ans) call for left
2. Agar root ka data chhota hai n1 se aur root ka data chhota hai nw se find(root->left, ans) call for right
4. Agar dono nahi hai, toh(preorder)
   1. find(root->left,ans)
   2. ans mai pushback kardo root ke data ko
   3. find function ko call kardo right side ke liye, root ka right aur ans ko daal do. 
   Base :-  if root not exist then return.

Code Implementation :- 
```
void find(Node *root, vector<int> &ans )
{
    if(!root)
    return ;

    if(root->data>n1 && root->data > n2)
    find(root->left,ans);
    else if(root->data<n1 && root->data < n2)
    find(root->right,ans);

    else
    {
        find(root->left,ans);
        ans.push_back(root->data);
        find(root->right, ans);
    }

}
vector<int> printNearNodes(Node *root)
{
    vector<int> ans;
    find(root , ans );
    return ans;
}
```

### Check whether BST contains Dead End :- 
Ek BST tree diya jiska range 0  se bada ho till INT_MAX aur data unique present hai, yaha. Dead End means:-  kya koi leaf node hai jo jaha koi aur node attach nahi kar sakta. Aisa node jaha agar koi aur node add nahi kar sakte nahi to range ke bahar chale jayenge means attach nahi ho sakta. (na left side na right se attach na ho ).

Approch :- Leaf node par jao aur uska range nikalo, agar us range mai aur bhi no. exists karte hai then then not dead node if not exist then dead node exist. Aur agar difference of upper bound and lower bound is 1 then not attachment is possible.   

Code Part :- 
1. Dead() bool type ka, Node type ka root pointer bana lo, int type ka lower and upper le lo. 
2. Leaf Node :- Agar root ka left aur root ka right exist nahi karta than ,
   1. root ka data minus lower barabar aa jata hai 1 aur upper minus root ka data barabar tan return kardo 1 ko. 
   2. Agar aisa nahi toh return  kardo 0. 
3. Dead(root->left, lower, upper) call karodo for the root ke left ke liye
4. Dead(root->right, lower, upper) call karodo for the root ke right ke liye 
5. Base Case :- root exist nahi karta then return 0.

Code Implementation :- 
```
bool Dead(Node *root, int lower, int upper)
{
    if (!root)
        return 0;

    // Leaf Node
    if (!root->left && !root->right)
    {
        if (root->data - lower == 1 && upper - root->data == 1)
            return 1;
        else
            return 0;
    }
    return (Dead(root->left, lower, root->data) || Dead(root->right, root->data, upper));
}

bool isDeadEnd(Node *root){
   return Dead(root, 0, INT_MAX);
}
```

### Common node in two Binary tree :- 
Hamko do binary tree diya hoga aur hamko, unke common node(data same) ko wapas karna hai. 

Approch :- Dono tree ka InOrder nikal lo, phir dono ki traverse karo aur check karo ki varaible present hai ki naho same, ek pointer ek ke start, ek pointer dusre ke start par tnow check if element is match then push it in the ans if not then jis bhi preorder ka data chhota  uske ek se aage badao and so on . 
Solve this without using this two array of preOrder. 

Recursion Approch nahi use kar sakte kyuki ye hamko flexibility nahi deta ki ham duro node ko bhi check kar paye, means compairson karte waqat musqil bada deta hai. 

New way to implementating inOrder with using stack :- 
1. Left most element ko stack ke ander daal do
2. pop the element and print it
3. Right side mai jo hai aur uske left wale ko stack mai daal do

Code Implementation :- 
```
vector<int> findCommon(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node*> s1, s2;
    while(root1) // all the left side push into  stack1
    {
        s1.push(root1);
        root1 = root1->left;

    }
    while(root2) // all the left side push into  stack2
    {
        s1.push(root2);
        root1 = root2->left;

    }

    while(!s1.empty()&&!s2.empty())
    {
        // top element equal hai
        if(s1.top()->data==s2.top()->data)
        {
            ans.push_back(s1.top()->data);
            root1 = s1.top()->right;
            s1.pop();
            root2 = s2.top()->right;
            s2.pop();
        }
        // s1 > s2
        else if(s1.top()->data > s2.top()->data)
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
    }

    while(root1) // all the left side push into  stack1
    {
        s1.push(root1);
        root1 = root1->left;

    }
    while(root2) // all the left side push into  stack2
    {
        s1.push(root2);
        root1 = root2->left;

    }
    return ans;

}

```
