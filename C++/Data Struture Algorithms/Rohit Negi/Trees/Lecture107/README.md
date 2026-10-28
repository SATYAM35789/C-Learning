### Construct a Tree from inorder And PreOrder :- 
Hamko inorder aur preorder diya hoga aur hamko Binary tree construct karna hai. 
1. Hamko inorder aur preorder dono kyu diya hai kya ham sirf kis ek se Ham Binary tree ko construct nahi kar sakte?
kisi ek tree se ham uniqe tree nahi create kar sakte.
Note Pre or post order agar hamare pass hai toh hum kabhi bhi uniqe BT tree nahi bana sakte.
PreOrder mai jo pahla element hoga wo node hoga he hoga. So dusra type hai InOrder wo hamko batayega direction jo next elemnt hai preorder mai kis side locate hoga. 
Note:- Jab ham tree bana rahe tab hum ye check kar lenge ki element uniqe exist kare. Duplicate element exist n kare kyuki tab ham direction decide nahi kar payenge. 
Approch :- 
1. First element dekho preOrder mai
2. InOrder mai postion dekho
3. position ke basis par left aur right devide karlo

Code Part :- 
1. Tree() node type ka, parameter : ek int type ka in naam ka array referrence lelo , ek int type ka pre naam ka array referrence lelo , ek int InStart ek int inEnd aur ek int index.

instart : inorder ke starting  element ko show kar raha hai
inEnd : inorder ke last element ko show kar raha hai
index : ye preorder ke starting ko show kar raha hai
pos :- jo hamre pre mai element hai wo in kis jagah present hai
jab root ke left side  badenge tab index ko ek se increse kar denge lakin jab hum root ke right side ke taraf move karenge tab index + (pos - inStart) +1.

2. ek Node type ka root pointer mai new Node create karo jo hamre pre of index mai hai.
3. int type ka pos mai find() daal do jo position batayege, parameter: in , pre[index], inStart, inEnd.

int Find(int * in, int target, int start, int end)
1. ek for loop chalao start se laker end tak
2. agar in of i barabar aa jata hai target ke toh return kardo i ko
3. Agar nahi milta toh return i kardo. 

4. root ke left mai tree(in, pre, InStart, pos-1, index+1)
5. root ke right mai tree(in, pre, pos+1, InEnd, index+(pos-inStart)+1 )
6. return kardo root
Edge case: jaise he instart , greater ho jaye InEnd se tab return ho jao. 

Time Complexity :- O(nsq)
Space Complexity :- O(n)

Code Implementation :-
```
int find(int in[], int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}

Node *Tree(int in[], int pre[], int InStart, int InEnd, int index)
{
    if (InStart > InEnd)
        return NULL;

    Node *root = new Node(pre[index]);
    int pos = find(in, pre[index], InStart, InEnd);

    // left part ko build karo
    root->left = Tree(in, pre, InStart, pos - 1, index + 1);
    // right part ko build karo
    root->right = Tree(in, pre, pos + 1, InEnd, index + (pos - InStart) + 1);

    return root;
}
// Build tree with the help of preOrder and Inorder given in array form
Node *buildTree(int in[], int pre[], int n)
{
    return Tree(in, pre, 0, n - 1, 0);
}
```

### Construct a Tree from Inorder And PostOrder :-
PostOrder mai jo root node hota hai wo sabse last mai hota hai.  PostOrder mai LRN so isme pahle right ko solve karenge or pahle right side se solve karenge in inOrder jaha position mila hai hamko.
Note inOrder mai jaha root mila hai , waha pahle right then left aur postOrder mai pichhe se eke ek kadam aate aayenge yaha hamko root ke baad right he milega uske baad left. 

Code Implementation :
Index :- postOrder ka last element ko show karta hai. Aur sab same hai. 
right side mai index : index-1 se decrese hoga
left side mai index : index-(end-pos)-1 se increse hoga
```
int find(int in[], int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}

Node *Tree(int in[], int post[], int InStart, int InEnd, int index)
{
    if (InStart > InEnd)
        return NULL;

    Node *root = new Node(post[index]);
    int pos = find(in, post[index], InStart, InEnd);

    // right part ko build karo
    root->right = Tree(in, post, pos+1, InEnd, index-1);

    // left part ko build karo
    root->left = Tree(in, post, InStart, pos-1, index-(InEnd-pos)-1);

    return root;
}
// Build tree with the help of preOrder and Inorder given in array form
Node *buildTree(int in[], int post[], int n)
{
    return Tree(in, post, 0, n-1, n-1);
}
```

### Check Tree Traversal
Hamko preOder, InOrder, PostOrder diya hoga hamka check karke ke batana hai ki kya ye ek he tree ke hai ki nahi. So Pre aur In se ek tree construct karo aur post aur in se ek tree construct karo aur agar ye dono same aate hai toh hamko ans mil jayega. 

Maan lo tino alag alag tree ke in, pre aur post tab hamne jo find function banaya tha wo -1 de dega aur tree construct nahi hoga. 