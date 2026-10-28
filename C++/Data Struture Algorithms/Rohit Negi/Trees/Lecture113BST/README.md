### Construct BST from PreOrder Traversal
 Dekho isme hamko preOrder traversal diya gaya hai kisi tree ka, hamko is se BST bananahai. 
 Approch:- Hamko pata hai ki preOrder jo pahla element hai wo Node(root) hoga, phir array mai traverse kar lenge ki jai koi ek bada elemnt milta hai, waha se tak right hoga aur us bade ke just pahle se starting +1 tak sare root node se chhote honge, do this till the array exist. Is method ki time Complexity O(n2) aayegi.
 Approch2nd :- Hamne pahal element ko node bana liya , ab next element par gaye agar chhota hai left mai add kardo and if next elemnt bada hai then right side add kardo do this with every node, till preorder array exist karta hai. Is method ki time Complexity O(n2) aayegi.  

Approch3rd :-Range Property:- There are the specific range jo hamko batata hai ki value is range ke ander lie karte hai. 

Range Logic: Is approach mein hum har node ko batate hain ki "Bhai, teri value $X$ aur $Y$ ke beech honi chahiye." Agar preorder ka agla element us range mein fit baithta hai, toh hum node create karte hain, warna recursion wapas (backtrack) chala jata hai

Code Part :- 
1. BST() node type ka, parameter: vactor int type ka naam preorder, int type ka index(as refference) ,lower and upper bana lo.
2. node type ka root pointer mai new node(index) bana do. aur index++ kar do
3. BST() Parameter :- preorder, index, lower, root ka data(for left part), isko daal do root ke left mai
4. BST() Parameter :- preorder, index, root->data, upper isko daal do root ke right mai
5. return kardo root ko. 
Edge Case :- 
1. Agar index barbar ho jata hai preorder.size ke.  or preorder ka index bada hai lower se or preoder ka index chhota hai upper se tab. 

Time and space Complexity :- O(n).

Code Implementation :- 
```
Node *BST(vector<int> &preorder, int &index, int lower, int upper)
{
    // Base Case
    if (index == preorder.size() || lower > preorder[index] || upper < preorder[index])
        return NULL;

    Node *root = new Node(preorder[index]);
    index++;

    // 3. Left child ke liye upper bound root->data hoga
    root->left = BST(preorder, index, lower, root->data);

    // 4. Right child ke liye upper bound wahi rahega jo parent ka tha
    root->right = BST(preorder, index, root->data, upper);
    return root;
}

Node *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return BST(preorder, index, INT_MIN, INT_MAX);
}
```

### Construct BST from post order :-
Hamko postOrder diya hoga in vector form hamko iske help se BST banana hai. 
Approch1 :-  Root node last of the vector hoga postorder ke case mai, iske baad apni value ko dekhete jao aur according values ko set karte jao and we got our ans. 
Time Complexity :- O(nsq).

Approch :- In last question we use NLR, in this we use NRL. And we use our range based approch.

1. BST() node type ka, parameter: vactor int type ka naam post, int type ka index(as refference) ,lower and upper bana lo.
2. node type ka root pointer mai new node(index) bana do. aur index-- kar do
3. BST() Parameter :- post, index, root->data, upper isko daal do root ke right mai
4. BST() Parameter :- post, index, lower, root ka data(for left part), isko daal do root ke left mai
5. return kardo root ko. 
Edge Case :- 
1. Agar index barbar ho jata hai 0 ke.  or preorder ka index bada hai lower se or preoder ka index chhota hai upper se tab. 

Time and space Complexity :- O(n)

Code Implementation :- 
```
Node *BST(int post[], int &index, int lower, int upper)
{
    // Base Case
    if (index == 0 || post[index] < lower || post[index] > upper)
        return NULL;

    Node *root = new Node(post[index]);
    index--;

    // Right child ke liye upper bound wahi rahega jo parent ka tha
    root->right = BST(post, index, root->data, upper);

    //  Left child ke liye upper bound root->data hoga
    root->left = BST(post, index, lower, root->data);

    return root;
}

Node *constructTree(int post[], int size)
{
    int index = size - 1;
    return BST(post, index, INT_MIN, INT_MAX);
}
```

### Preorder and BST
Is problem mai jo preorder hai wo sahi bhi de sakta hai aur galat bhi, so hameshe puchhe raha hai kya is se ek valid BST ban sakta hai ki nahi hamko ye answer dena hai. 
Approch :- Preorder diya hai by NLR use karke ham tree construct kar sakte hai phir iska preorder nikal sakte hai agar ue same aata hai toh answer mil chuka hai hamko. 
Time Complexity :- O(nsq)

Approch2nd Range based approch ko phir se use kar rahe hai, Agar koi paricular index value na left mai exist hai na he right mai then ham return ho jayenge.
Time and space complexity :- 

Code Implmentation :- 
```
void BST(int arr[], int &index, int lower, int upper, int N)
{
    if (index == N || arr[index] < lower || arr[index] > upper)
        return;

    int value = arr[index];
    index++;
    // Left
    BST(arr, index, lower, value, N);

    // Right
    BST(arr, index, value, upper, N);
}

int canRepresentBST(int arr[], int N)
{
    int index = 0;
    BST(arr, index, INT_MIN, INT_MAX, N);

    return index == N;
}
```

Segementation fault :- Accessing memory, not haiving permission. (got maximum input liike 1 lakhs)
Dekho agar same problem ko ham agar syack se karte ye submit bhi ho jata or error bhi nahi aata so question arises that why having same complexity O(n) stack is capable but recursion fails. 
In Memoery management :- We learnt that in recursive call stack is used so stack is used for that of max Value as input. aur hamre stack mai itni capacity he nahi the so we got this error. So STL Standard template library ke liye heap mai memory locate hoti hai. 

pseudo Part:- 
1. Agar arr of i chhota hai lower.top() se then return 0 kardo.
2. Kab hamko pata chalega ki jo hamara node ke value hai hamare range ke bahar, jab arr of i bada hoga upper of top se. 
   1. upper ko pop kardo
   2. lower ko pop kardo
3. Jab value range mai aati hai, toh
   1. left mai lower daal do
   2. right mai upper daal do
   3. lower aur upper ko pop kardo
   4. lower mai push kardo arr of i ko
   5. upper mai push kardo right ko
   6. lower mai push kardo left ko
   7. upper mai push kardo arr of i ko

Code Implementation :-
```
int canRepresentBST(int arr[], int N)
{
    stack<int> lower, upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    int left, right;
    
    for(int i=0; i<N;i++)
    {
        // 1St Condition :- 
        if(arr[i] < lower.top())  // range se bahar hai, lower se bhi chhota
        return 0 ;

        // 2nd Condition :- upper se bahar ho sakta hai
        while(arr[i]>upper.top())
        {
            upper.pop();
            lower.pop();
        }
        // When the value is in range
        left = lower.top();
        right = upper.top();
        lower.pop();
        upper.pop();
        // Stack ke ander right side wale liye lower and upper bound
        lower.push(arr[i]);
        upper.push(right);
        // Stack ke ander left side wale liye lower and upper bound
        lower.push(left);
        upper.push(arr[i]);
    }
}
```
