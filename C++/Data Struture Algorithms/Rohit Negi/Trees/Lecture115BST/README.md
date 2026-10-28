### Sorted LL to BST :- 
Hamko ek sorted LL diya hoga aur hamko Balance BST mai change karna hai. 
Balance BST means The Dofference of Hight of the Left and Height of the Right Part should lie in -1, 0, 1. 
Required Time and Space Complexity is O(n). 

Approch :- Sabse pahle mid par jao, phir LL ke left part ko node ka left part mai bhej do aur phir LL ke right ko node ke right side bhej do and do so on till node exist. 
Time Complexity :- O(nsq) kyuki hara bar hamko middle nikalna padega, traverse karke

Approch :-  Agar ek baar traverse karke apni LL ko ham, ek vector bana kar usme store karle tab mid nikalne easy ho jayega. aur phir ham uppar wala approch use kar sakte hai. 

Code Part :- 
1. createBST() node type ka, parameter: Lhead type ka head.
2. ek vector Tree naam ka, int type ka
3. jab tak head exist karta hai, tab tak
   1. Tree mai pushback kardo, head ke data ko
   2. head mai head ke next ko daal do. 
4. BuildBST(Tree,0,Tree.size()) call kardo,
Note: Is question mai mid odd ke case mai like 1.5 = 2 maan liya gaya hai. So toh hamko question ke example se pata karna pata hai nahi toh kabhi kabhi ans wronge bhi aa jate hai. So +1 kardo while calculating mid it handle the both cases. 


1. BuidBST() node type ka, parameter : vector type ka Tree(as reference), int type ka start aur end.
2. int typa ka mid mai (start+end+1)/2 or start+(end-start+1)/2 kardo. 
3. Node type ka root mai new node(Tree[mid]) daal do. 
4. root ke left mai Build(Tree, strat, mid-1) call kar do
4. root ke right mai Build(Tree, mid+1, end) call kar do
Base Case :- Agar start bada hai end tab return kardo NULL ko. 

Code Implementatin :- 
```
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

class LNode
{
public:
    int data;
    LNode *next;

    LNode(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *BuildBST(vector<int> &Tree, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start + 1) / 2;
    Node *root = new Node(Tree[mid]);

    root->left = BuildBST(Tree, start, mid - 1);
    root->right = BuildBST(Tree, mid + 1, end);

    return root;
}

Node *sortedListToBST(LNode *head)
{
    vector<int> Tree;
    while (head)
    {
        Tree.push_back(head->data);
        head = head->next;
    }

    return BuildBST(Tree, 0, Tree.size() - 1);
}
```

### Merge Two BST :- 
Hamko ek vector lena hai in dono tree ko uske ander dalna hai aue merge karke de dena hai (sorted fprm mai). 
Approch :- Ki ek ek karke done tree ke value ko vector ke ander daal de. phir is vector ko koi bhi sorting algo(merge sort) laga kar sort kardo karke answer mai de do. ye sab karne mai O(nlogn) time complexity lag raha.

Approch 2nd :- Ek tree ko ek vector mai store karo, dusre tree ko ek tree mai store karo (in inorder form), then check jo chhota usko daal do, ans vector mai. 
Time and Space Complexity :- O(n)

Code Part :- 
1. MergeTwoBST() vector type ka, parameter :Node type ka root1 and root2 pointer le lenge.
2. vector type ka ans1 aur ans2 le lenge.
3. inOrder(root1,ans1) call kar denge
4. inOrder(root2,ans2) call kar denge
5. ek vector ans naam ka aur int type ka i aur j aur dono ko 0 se initialize kar denge. 
6. jab tak ans1 aur ans2 exist karte hai tab tak:-
   1. Agar ans1 of i chhota hai ans2 of j se then ans mai pushback kardo ans of i ko and i++ kardo
   1. Agar ans2 of j chhota hai ans1 of i se then ans mai pushback kardo ans of j ko and j++ kardo
7. Agar ans ke element bachha hua hai, jab tak i chhota hai ans1.size tab tak ans mai push back kardo ans1 mai element ko and i++ kardo
7. Agar ans ke element bachha hua hai, jab tak jchhota hai ans2size tab tak ans mai push back kardo ans1 mai element ko and j++ kardo.
8. return kardo ans ko.

Code Implementation :- 
```
void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> mergeBST(Node *root1, Node *root2)
{
    vector<int> ans1;
    vector<int> ans2;
    inorder(root1, ans1);
    inorder(root2, ans2);

    vector<int> ans;
    int i = 0, j = 0;
    while (i < ans1.size() && j < ans2.size())
    {
        if (ans1[i] < ans2[j])
            ans.push_back(ans1[i++]);
        else
        {
            ans.push_back(ans2[j]);
            j++;
        }
    }
    while (i < ans1.size())
    {
        ans.push_back(ans1[i++]);
    }

    while (j < ans2.size())
    {
        ans.push_back(ans2[j++]);
    }
    return ans;
}
```

### Merge two sort using iterative approch :- 
Toh recursion use nahi kar sakte so hamko stack use karna padega. So hamne kuchh din pahle BST using stack pada tha jaha hum :- InOrder(iterative immplementation)
Pahle left side ko ander daalte the, phir then ham compairsion karte the , phir compair karlo agar jiska value chhota hai usko bahar nikalte the then uske right side jate the phir uske sare left ko ko stack mai dalte the. phir compairsion karte the and so on. 
Note :-  if values are equal then dono ko ek ek karke daalo do aur uskr right mai jao aur uske sare left ko daal do.  


### Fixing two Nodes of a Binary Tree :- 
Hamko ek BST diya hua hai, jaha par koi do node galat position par set ho gaye hai means galti se swape ho gaya jai, so hamko inki position ko wapas se fixed  karna hai. 

Approch Dekho agar ham iska inorder nikalte hai then ascending order mai value aayegi agar do value swap hai toh order galat hoga hamara so, agar ham isko sort karde phir BST bana le toh problem solve ho jayegi. 

Time Complexity : vcetor mai value store O(n) + Merge Sort O(nlogn) + InOrder Traversal se wapas BST banane ke liye O(n).

Swaping when found error:- pahle gadbadi ka pahle aur dusri gadbadi ka dusre ko aapas mai swap kar do. 
Ab time Complexity :- O(n) ho jayegi (swape ke liye ek baar traverse kar rahe hai). Space Complexity : O(n). Agar ek baar garbad milti hai then gadbad position aur uski next se swap kar do. Sirf yahi possibilty ho sakti hai. 
Using Two Variable swaping :- Sabse pahle inko -1 rakhenge. Agar pahli gadbad aati hai then gadbad aur uske next wale index ko store kar lenge. agar dusri gadbad milti hai then second variable mai jaha gadbad usindex ko daal do. 

Now If the question ask to solve this in O(1) space Complexity. Using Morris traversal Inorder Inorder.
So isme ham sabse pahle left most node par chale jate hai agar left left exist nahi karta then ham wapas aate hai present mai value ka daal dete , phir right side move karte hai agar nahi hai toh back aa jate hai is node ko left traverse kar chuke hote hai, then is ke data ko last mai daal dete, phir check karte hai kya ye prsent chhota hai last then we go update the last and present value so ki aage bhi same kaam kar sake jab tak tree khatam nahi jata. If bada ,ilta then isko store kar lo First and second mai. 

Morris Traversal :- LNR
Apne left par jao, phir uske right most ko root ko point karwa do so on till left most element reached agar iske baad kuchh nahi then print elemnt and go back to the right side and so on. 
1. Left doesnot exist 
   1. Print Node
   2. Right side move
2. Left side exist
   1. Already traversed : wapas se ghum kar root par aa jeyenge.
   2. Not Traversed : right side NUll mil jayegi

Code Part :- 
1. CreateBST() void type ka,Parameter :  Node type ka root pointer le lo. 
2. Node type ka curr le lo jisme NULL daal do
3. Node type ka First and Second lelo jisme Null daal do
4. Node type ka last aur present le lo jisme NULL daal do
5. Agar root ka left exist nahi karta then , 
   1. last mai present daal do
   2. present mai root daal do
   3. Agar last exist karta hai aur last->data bada hai present ke data se meand gadbad mil gaya hai,
      1. Agar first exist nahi karta hai, then first mai last daal do and second mai daal di present ko
      2. else second time gadbad hai then second mai daal do present ko. 
   4. root mai root ka right side daal do. 
6. Agar root ka left exist karta hai, 
   1. curr mai daal do root ke left ko
   2. Jab tak curr ka right exist karta hai aur curr ka right barabar naho hota root ke tabtak
      1. Curr ko curr ke next se aage badate raho. 
      2. Agar curr ka right exist nahi karta then,
        1. Curr ke right mai root ko daal do.
        2. root mai root ke next ko daal do
      3. Agar curr ka right root ke barabar aata hai, then traverse ho chuka hai aur hum root ke left side jayenge,
        1. curr ke right ko null kardo(coonection tod do)
        2. last mai present daal do
        3. present mai root dal do
        4. Agar last exist karta hai aur last->data bada hai present ke data se meand gadbad mil gaya hai,
          1. Agar first exist nahi karta hai, then first mai last daal do and second mai daal di present ko
          2. else second time gadbad hai then second mai daal do present ko.
    3. root mai root ka right side daal do. 
7. Swapping the nodes :- 
   1. int type ke num mai first ka data daal do
   2. first ke data mai second ka data daal do
   3. second ke data mai num daal do. 

