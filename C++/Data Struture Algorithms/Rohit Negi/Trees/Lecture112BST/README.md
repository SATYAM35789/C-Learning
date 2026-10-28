### Check BST
Hamko ek tree do hogi aur hamko check karke batana hai ki ye BST hai Ki nahi. On ecah node , uske left side us se chhote hone chahiye aur right side usse bade hone chahiye. 
Approch :- Sare node par jaye is property ko search karlo, why not? Aise possibility ho sakti hai current nodes ke liye ye tarika sahi ho but ye ensure nahi honge ke kisi node ke sare element uske left side chhote ho aur right side us se bada ho. 

Approch 2nd :- Ek aur Property hoti hai ki Agar hum BST ka InOrder Traversal nikal de aur sorted form mai milta then that is BST. 

Code part :- 
1. inOrder() void type ka, parameter : Node type ka root pointer le lo, vector type ka ans as reference le lo
2. Agar root exist nahi karta hai, than return ho jao.
3. root ke left mai chale jao 
4. ans mai push back kardo current ke data ko
5. right side chale jao agar exist karta hai so on . 

IsBST():-
1. Isbst() bool type ka, parameter : Node type ka root pointer. 
2. inOder() ko call kardo
3. ek for loop chalayenge 1 se size tak
4. agar ans of i is lessthan equal to ans of i-1
5. agar aisa nahi hai then return kardo 1. 

Time ans Space complexity :- O(n). 

Optimized Approch :- 
Hamara jo answer hai wo depend karta hai karta hai previous element aur current element , agar curr bada the move to next if curr chhota hai then return not BST. 
On particular node we ask for kya hamara left part BST hai , phir check the node BST or not, then check right part is BST or not. 

Code Part :-
1. BST() bool type ka, parameter: Node type ka root pointer, ek int prev as reference
2. bool type ke l mai BST() ko left side ke liye call kar do
   1. Agar l barabar hai 0 ke tab return 0 kardo
3. Agar root ka data greater than equal prev hai tab return 0 kardo 
4. Agar aisa nahi hai toh prev mai root ke daat ko daal do
5. ab BST() ko right side ke liye call karlo, aur jo aaye usko return kardo.
Edge Case :- If root null hota hai then return karlo 1 ko because leaf node ke baad agar rot null hota then 0 return nahi kar sakte nahi hamara ans wrong ho jayega. 

Code Implementatiom :- 
First Method :- 
```
void inOrder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inOrder(root->left, ans);
    cout << root->data << " ";
    inOrder(root->right, ans);
}

bool isBST(Node *root)
{
    vector<int> ans;
    inOrder(root, ans);
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] <= ans[i - 1])
            ;
        return 0;
    }
    return 1;
}
```
Second Method :- 
```
bool BST(Node *root, int &prev)
{
    if (!root)
        return 1;

    bool l = BST(root->left, prev);
    if (l == 0)
        ;
    return 0;

    if (root->data <= prev)
        return 0;

    // agar root ka data bada hai toh prev ko update kardo
    prev = root->data;

    return BST(root->right, prev);
}

bool isBST(Node *root)
{
    int prev = INT_MIN;
    return BST(root, prev);
}
```

### Minimum Distance Between BST Nodes :- 
Hamko ek binary tree diys hoga aur ab hamko minimum distance between two node nikalkar batana hai means do nodes ke differnce nikal as abs return karna hai.
Approch :- BST diya then some sortcut will exist there, so BST then It is in the sorted form , the minimum distance between two node will exist in sorted array, the difference b/w next element of currnt element will be the minimum only. 

Code Part :- 
1. MinDist() void type ka, parameter : Node type ka root pointer, int type ka ans and prev as reference.
2. Agar root exist nahi karta then return ho jao
3. MinDist() call kardo for the root ke left ke liye.
4. ans mai daal do min(), parameter : ans aur root ke data minus prev ko
5. prev mai root ke data ko daal do
6. MinDist() ko call kardo, for root ke right ke liye. 

Edge Case :- Agar prev barabar nahi hai INT_MIN ke tabhi 4 wala chalega.

One Problem that that ki ham ans mai min value store karwa rahe hai, starting mai prev ko INT_MIN se initialize kiya means ka ye koi 0 se bhi chhoti ho sakti hai means negative so if - any negative value from a positive it got add up the.   
  
Code Implementation :- 
```
void minDist(Node *root , int &prev, int &ans)
{
    if(!root)
    return;

    minDist(root->left , prev, ans);
    if(prev!=INT_MIN)
    ans = min(ans , root->data - prev);

    prev = root->data;
    minDist(root->right , prev, ans);
}

bool MinDistInBST(Node *root)
{
    int prev = INT_MIN;
    int ans = INT_MAX;
    minDist( root,prev,ans);
    return ans;    
}
```
### Sum of k smallest Element in BST :- 
Hamko ek BST tree diya hoga aur hamko us ka first k smallest elemnt nikal kar dena hoga. 
Approch : InOrder traverse karlo aur value ko store karlo, aur 1st k tak ke value ko sum karke dedo. so this is not that good method. 
Approch :- Jab hamko InOrder lagana he hai toh , sum ko 0 lelo aur k lelo, ab inOrder lagao jaise he Node mile tab k-- aur sum mai add kardo node ke value ko. 

Code Part :- 
1. kSum() void type ka lelo, parameter : Node type ka root pointer lelo, int type ka sum aur k lelo as reference
2. Agar root not exist then return ho jao
3. kSum() ko call kardo root ke left ke liye;
4. k-- kar do
5. Agar k bada hai 0 se tab , sum mai sum + root ka data kardo. 
6. Agar ke chhota hai ya barabar hai 0 ke tab return ho jao
7. kSum() call kardo right side ke liye. 

Time ans Space complexity : O(n)
Code Implementation :- 
```
void kSum(Node *root, int &sum, int &k)
{
    if (!root)
        return;

    kSum(root->left, sum, k);
    k--;
    if (k > 0)
        sum = sum + root->data;
    else
        return;
    kSum(root->right, sum, k);
}

int Sum(Node *root, int k)
{
    int sum = 0;
    kSum(root, sum, k);
    return sum;
}
```
### Kth Largest Element in BST:- 
Hamko ek bst tree diya hoga ab jisme se hamko puchhega ki kth largest element batao mujko. 
Approch : InOrder traversing karke n vector mai value store karwa lenge, then pichhse se traverse karke kth position par aa jao value ko store karwa lo. 
Approch :- InOrder LNR use karte hai then we got the value in ascending order so if we RNL then we got the value in descending Order then aram se solve kar sakte hai. count variable le lenge agar ye kth ka barabar aa jata hai then isko return kar denge. 

Code Part :- 
1. kLargest() void type ka lelo, parameter : Node type ka root pointer lelo, int type ka sum aur k lelo as reference
2. Agar root not exist then return ho jao
3. kLargest() call kardo right side ke liye.
4. k-- kar do
5. Agar k bada hai 0 se tab , sum mai sum + root ka data kardo. 
6. Agar ke chhota hai ya barabar hai 0 ke tab return ho jao
7. kLargest() ko call kardo root ke left ke liye;

Code Implementation :- 
```
void kLargest(Node *root, int &ans, int &k)
{
    if (!root)
        return;

    kLargest(root->right, ans, k);
    k--;
    if (k == 0)
        ans = root->data;
    else
        return;
    kLargest(root->left, ans, k);
}

int KthLargest(Node *root, int k)
{
    int ans= 0;
    kLargest(root, ans, k);
    return ans;
}
```
### Array to BST
Hamko ek sorted array given hoga hamko ek BST banana hai phir PreOrder nikal kar return karna hai aur multiple preorder exist kar sakte hai so jiska lexico chhota hai usko return kardo. Hamko ek Balanced BST chaihe means H1= Heght of left subTree H2 = Height of right SubTree should exist in -1<= H1-H2 =<1.

Approch :- Bst kya hota hai ek node(center) jiske left node se chhote rahenge aur jiska right node(center) se bada hoga. on each and particular node. 
Hamko pata hai ki Ek sorted array se bahut sare BST ban sakte hai, hamko wo dena jo lexico graphical chhota hai means ham preOrder nikal sakte hai different trees ka aur jo element small element se start hai usko chhose kar lenge, agar value same hai toh next element ko check kar lenge. 

Approch :- Hamko tree banane ke Zarurat nahi jab hamko answer preOder form mai dena hai, toh mid nikalte jayenge aur jo mid hai wahi hamara ans hote ja raha hai

Code Part :- 
1. ArrayToBST() void type ka, parameter : vector type ka arr and ans(as reference) , int type ka start aur end.
2. Agar start bada ho jata hai end se tab return ho jao. 
3. ek int banao mid naam ka jisme start + (end-start)/2 ko daal do. 
4. ans mai pushback kardo arr of mid ko
5. ArrayToBST() ko call kardo start  to mid -1 tak
5. ArrayToBST() ko call kardo mid+1  to end  tak

Code Implementation :- 
```
void ArrayToBST(vector<int> arr, int start, int end, vector<int> &ans)
{
    if (start > end)
        return;

    int mid = start + (end - start) / 2;
    ans.push_back(arr[mid]);
    // Left Side
    ArrayToBST(arr, start, mid - 1, ans);
    // Right Side
    ArrayToBST(arr, mid + 1, end, ans);
}

vector<int> sortedArrayToBST(vector<int> &nums)
{
    // Array ko sort kar rahe hai, so ki agar user na de toh. Ha mujko pata hai question mai sorted array he diya hai.
    sort(nums.begin(), nums.end());

    vector<int> ans;
    ArrayToBST(nums, 0, nums.size() - 1, ans);
    return ans;
}
```



