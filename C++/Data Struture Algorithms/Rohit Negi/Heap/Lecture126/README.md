### Merge K sorted linked List
Today we come to know that how can we able custmize the priority queue. And more concepts regarding the heap which capable to enhance your understanding to heap. 

Hamko k linked list de rakhi hai aur ek list sorted order mai hai, diya hua hai aur question hamko bol raha hai ki in sabko merge kardo aur single sorted form mai wapas kardo. 

Solution :- 
1. Brute Force , we have discussed this in Linked List.
2. Merge Sort , we have discussed this in Linked List. 
3. Heap :- 
So hamko ek array diya hai, usme sare k nodes ke root element store hai, 
1. Approch :- Ki ham ek ek karke sare nodes ko heap ke ander daale phir bahar nikalte samay unko aapas mai linked karte jaye, until heap ke element khatam nahi ho jate. 
Time Complexity :- 
1. Insertion  : nklognk
2. Deletion : nklognk
nklognk + nklognk = nklognk
Space Complexity :- nk

Approch 2nd :- 
1. Ek min heap lo isme sare root element ko daal do , kyuki hamko pata hai ki sabse chhota inme koi ek hoga.
2. Apne min heap se top element bahar nikalo, agar uska next exist karta hai toh daal do  
3. Phir se min heap se top nikalo agar uska next exist karta hai then usko daal do and this so on jab tak min heap empty n ho jaye. 

Time Complexity :- 
1. Insertion :- Hamne pahle k element daala hai. So ham in element ko pahle array ke ander daal do then heap build karlo O(k).
2. Now we have n-k element left
   - Ek element ko bahar nikal rahe hai phir uska next daal de rahe if exist logk
   - so total deletion :- nk
   Total Complexity :- nklogk
Space Complexity :- k 

Note :-  
1. Agar ham priority queue nai root ke data ko daal dete hai, then hamko sabse chhota element to mil jayega but uska next element nahi mil payega. So hamko Node typa ka data dalna hoga jiske help se uske data aur next dono ko access kar payenege.
2. Agar Node type ka data ko store karwa rahe hai the heap toh unke address ke based par dega sort kar dega , aur yaha toh data randomly stored hote hai. So yaha introduced hota hai customized heap ka , so ham yaha bata sakte hai ki tum kis based par data bahar nikaloge or dalenge. So ham bata denge ki hamko data ke based par min heap ko rakhna hai uske node ke based par nahi. 
3. Priority queue ko batana hoga ki Node kya hai wo is baat ko bhi nahi samjh payega. 
Syntex :
   - priority_queue< int , vector< int> , greater< int>> Name ;
   - priority_queue< Node* , vector< Node*> , Compare > Name ;

Class Compare ko define :- 
1. ek class banao Compare naam ka, jisme public mai,
2. bool type ka Operator()(parameter), parameter : Node type ka pointer a and b
   1. a->data bada hai b->data isko return kardo :- return a->data > b->data  (create min heap) and max heap ke liye sign ulta ho jayega. 
   Note :-  
   1. Yaha jo do pointer aa raha (a aur b) ye normally puchh raha hai kya inka order sahi hai ki nahi. means  if a chhota ho b se. and if hamare statement false hoti hai then ye atomatically samajh jayega ki pahle b then a hoga. 
   2. Dekho ye statement jo hamko uppar patah chala hai ye sabke case mai aise kaam karta hai (set,pair, sort, etc) lekin heap ke case mai ults kaam karta hai. 

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
    // Kya a aur b ka order sahi hai and Heap ke case mai ulta kaam karta hai.
};

Node *mergeKLists(Node *arr[], int k)
{
    // Min Heap
    priority_queue<Node *, vector<Node *>, Compare> p(arr, arr + k);

    Node *root = new Node(0); // Creating duplicate node so ki linked list return aur banane mai east ho.
    Node *tail = root;

    Node *temp;

    while (!p.empty())
    {
        temp = p.top(); // 0 ,1,3,4 5,6,7
        p.pop();
        tail->next = temp;
        tail = tail->next; // increment
        if (temp->next)
            p.push(temp->next);
    }
    return root->next; // 0 wale ko remove karke ke bhej rahe hai.
}
```

### Merge K sorted Array :- 
Hamko ek 2d array diya hua  hai aur usme k sorted array di gai hai(treat each rows as array in 2d). Let's take a k=4 and the size of each array is also 4. sO K sorted array ko merge karke ek single array mai hamko de do. 

Approch 1 (Brute Force Approch) :- 
2d elements ke sare ekements ko copy karo single 1d arrat mai phir unko sort karke ans dedo. Phir ans ko return kardo. 
Time Complexity
1. Element Copying :- O(ksq)
2. Merge sort :- ksqlogk 
Space Complexity :- Space Complexity while using merge sort = ksq
Or 
3. Heap sort :k2logk
Space Complexity :- Space Complexity while using heap sort = O(1)

Approch 2:- Using Min Heap :-
Ek min heap le lo aur sare 2d elements ko store karwa lo , phir ek ek karke apne ans mai dalte jao  jabtak heap khali nahi ho jata. 
Time Complexity
1. Insertion :- log k in insertion single element , total element to insert (ksq) ksqlogk
2. Deletion :- ek ek karke sabko delete bhi kar rahe hai : ksqlogksq = ksqlogk
Space Complexity : k2sq

Approch 3rd :- 
1. Jitne bhi k array unke pahle element ko insert karwa denge, as we know ki sab sorted array aur inme se he hamko 1st sabse chhota milega.
2. Element nikalo aur uske next element ko ander daal do and so on. 

Time Complexity :-  O(ksqlogk)
Deletion : ksqlogk
Insertion : k + (ksq - k)logk 
Space Complexity :- O(k)

Note :-  Heap ke ander ye teen chiz jaynegi data,row,col of each element . Isko hum pair ke help se sort kar sakte hai. 
1. Agar hum is values ko node ke form mai dale like Node(int value,row ,col), then hamko purne methos se he daalne padega Compartor class banake and so on. 

Code Implementation :- 
```
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    // Creating pair so ki multiple value apne heap mai daal paye.
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
    }
    // Min Heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

    vector<int> ans; // Vector jo hamra soted value ko store karega
    pair<int, pair<int, int>> Element;
    int i, j;

    while (!p.empty())
    {
        Element = p.top();
        p.pop();
        ans.push_back(Element.first);
        i = Element.second.first;
        j = Element.second.second;

        if (j + 1 < k)
            p.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
    }

    return ans;
}
```

Approch 4th :- Merge Concept (with sum addition )
Hamko pata hai ki hamara kuchh portion of array sorted hai jab hum isko 1d mai copy karte hai, so is approch mai ham try kar rahe hai ki jo sorted hai unko phir se sort n karna pade. 
So merge sort mai jab single element last mai bachta hai , toh ham usko ek sorted array jaisa treat karte hai, sorted array ko aapas mai merge karte the so waisa ye yaha bhi karenge.
Jab sorted array  ke size ke barabar(k) ho  toh ham divide karna apne array band kar denge and conquer karna start kar denge. 
Divide kaise karenge:- Apne array ko portion ke basis par divide karenge.  
Time Complexity :- 
1. Compairsion ksq
2. dividion logk

mid = (Portion)/2*k-1   :- 3/2= 1X3 = 3-1 = 2(index value)
(Portion)/2 : kitna portion hai
(Portion)/2*k : ek portion mai kitna element hai 
(Portion)/2*k-1 : jo last element hai  portion  ka uska index 

Code Implementation :- 
```

```

