### Burning tree 
Hamko ek tree diya hoga aur ek target hoga hamare pass. Hamare pass sari node ke data unique hai, agar ham apne target ko jala de toh kitna time lagega is pure tree ko jalane mai. Jo bhi target se directly connected hai  wo 1 sec mai burn ho jayenge. ab us se connected jitne bhi node honge wo bhi way se jalna start ho jayenge. Time bhi icrese ho jayega and do so on. 
Note: Ek target node ko pakado usko jalao, us connected aur se connected 1 sec 1 sec mai jalte jayneg aur is tarah pura tree jal jayega aur hamko time batana kitne time ye lega. 

Target ke niche ke nodes ko jalne mai kitna time lagega uske liye nichewale nodes ki height ko calculate kar lenge. Uppar wale nodes ke liye :- root to target node ke liye path find karlo usko store karlo ek array mai , waha se pichhse traverse karnege toh hamko hamara uppar ka node milte jayega. 

Dekho jab hum root to target nodes ko store karwa rahe us samay ham apne left aur right arr mai un nodes ke right aur left height ko bhi store karwaenge. Ab hamko ye pata karna hai ki hamko konsa nodes ko select karna hai, current node jo root to target array mai usko apne aage wale ko dekhne hai, uske basis par. 

2nd Approch :- 
Nichhe wale ke liye same approch. Uppar wale ke maan lo uppar ke liye ham recursion ke help se chale ja rahe then, apne upper node par jate uske niche ki height pata karlo, and do the same so on.
On each node ask this :-  
1. Aapke side se burn aaya hai, then mujo bata do ki mujko jalne mai kitne second lagenge. 
3. Agar aapke se burn nahi hua hai toh apni height bata do mujo. 
Actually dono ek no he return kar rahe hai, so hamko kaise pata chalega ki height hai ya burning sec hai So burning ko ham -ve se show karnege aur height ko +ve.  
Note :-  Jab bhi hamare pass height aur burning dono aaya hai then hm return karenge burn + (-1).

Code Part :- 
1. Burn() int type ka, Parameter: node type a root pointer le lo, int type ka Timer as reference stores the max time to burn. int target
2. Agar root null hua toh return kardo 0.
3. Agar root node barabar aata hai target node ke then return -1. 
4. ek int banao Left type ka jisme Burn() ko call kar denge root ke left ke liye
5. ek int banao Left type ka jisme Burn() ko call kar denge root ke right ke liye
6. Agar aag left side se aayi toh left < 0 hoga,
   1. Timer mai max() ko call kardo parameter: Timer, abs(left)+Right ko
   2. return left-1 (upper -1 return hoga)
6. Agar aag right side se aayi toh right < 0 hoga,
   1. Timer mai max() ko call kardo parameter: Timer, abs(Right)+left ko
   2. return Right-1 (upper -1 return hoga)
7. Jab left and right dono positive hai
   return 1+max(left+right)

Niche height bhi calculate karna hai .

Code Implementation :- 
```
// return burn or hright daily
int BurnOrHeight(Node *root, int &timer, int target)
{
    // root not exist
    if (!root)
        return 0;

    // root exist
    // target node

    if (root->data == target)
        return -1;

    // On at node we ask kya burn node hamare left mai to(h  burn do nahi toh height de us side ki
    int left = BurnOrHeight(root->left, timer, target);
    // On at node we ask kya burn node hamare right mai toh  burn do nahi toh height de us side ki
    int right = BurnOrHeight(root->right, timer, target);

    // Burn ki condition
    if (left < 0)
    {
        timer = max(timer, abs(left) + right);
        return left - 1;
    }
    if (right < 0)
    {
        timer = max(timer, abs(right) + left);
        return right - 1;
    }

    // Agar left side be burn nahi aur right side bhi then return height
    return 1 + max(left, right);
}

void find(Node *root, int target, Node *&BurnNode)
{
    if (!root)
        return;

    if (root->data == target)
    {
        BurnNode = root;
        return;
    }
    find(root->left, target, BurnNode);
    find(root->right, target, BurnNode);
}

int height(Node *root)
{
    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int minTimeToBurn(Node *root, int target)
{
    int timer = 0;
    BurnOrHeight(root, timer, target);
    // Nichhe wale ko jalne mai kitna time lagega

    // Height of target node ki
    Node *BurnNode = NULL;
    find(root, target, BurnNode); // Burn node khah present hai

    int high = height(BurnNode) - 1;

    return max(timer, high);
}
```

### Max Path Sum between two Nodes :-
Problem statement :- 
Find max possible path sum from one special node to another special Node. 
Special node is a node which is connected to exactly one different node.(leaf node)

Hamko ek tree diya hoga, hamko leaf to leaf nodes ke path ka , jo max sum de raha hoga usko wapas karna hoga. 

Approch :- 
On each node ask for the give me the max of right and left of it, and return the max one. Dekho agar kisi node ka left aur right exist nahi karta toh ham us node ko calculate nahi karenge. 
Sum = one special node to another special node path sum. 
Cases to handle :- 
1. Node does not exist, then return 0.
2. Leaf Node, return data. 
3. left aur right dono exist then calulate sum = max(sum , data+left+right) and return data +max(left+ right) 
4. Agar sirf left exist then simple return data + left
5. Agar sirf right exist karta hai, tab return kardo, data + right ko. 

Special Case which make it HardProblem :- ki root bhi special node ho skata hai. if aisa hota then isko calculate karke ek vaible mai store kar lenge last mai check kar lenge ki hamare sum is variable mai ji bada hai usko return kardo. 

Code Implementation :- 
```

```