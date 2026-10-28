### Morris Traversal :-
Abhi tak ke traversal techniques like In-order, Recursive, Iterative  Inki time ans space complexity O(n) hoti in techniqes mai ab hamko space O(1) karna hai. 
Pahle hamare pass recursive call or stack hota tha different nodes par chale jate hai lakin ab O(1) ek space use karna hai tab ham dusre nodes par kaise ja payenge. 
Approch :-
LNR use kar rahe hai lakin ab ham root se left part ko traverse kar rahe honge is samay jo left most node hai humko ek link set up karna hoga ki ham direct apne root par wapas aa jaye and same with right part. 

Note: Left part:- Agar left exist karta hai toh uske right most ko, current jaha hai usse connect kardo.Agar right most not exist left ko uske current node se connect kardo.  

On Node:- 
1. left doesnot exist ?
Agar exist nahi karta toh esay hai node par jao aur direct value print kardo.
2. left exist ?  
1. Left part traverse? :- jis node ko check karte hai, us node se ek pointer chalao agar ye wapas aur apne pichhle node par chale ja rahe hai. 
2. Not traversed ?  linke generate karo current node se connect kardo
Agar apne left mai jakar ham wapas aa ja rahe tab, hamko confirm ho jayega ki left exist karta hai. 

Code Part :-
1. InOrder() vector type ka, parameter : ek Node type ka root pointer le lo.
2. Ek vector banao , ans naam ka
3. Jab tak root exist karta hai, tab tak
   1. Agar root->left exist nahi karta tab, 
      1. ans mai pushback kardo root ke data ko.
      2. root mai root ke right ko daal do
   2. Agar left exist karta hai, tab 
      1. ek node pointer curr le lo jisme root ka left daal do.
      2. jab tak curr ka right exist karta hai aur curr ka right hai wo barabar nahi hai root ke tab tak :-
         1. curr ko curr ke right badate jao
      // Left ka subtree not traverse
      3. Agar curr ka right barabar hai null ke tab
         1. curr ke right mai root ko daal do
         2. root mai root ke left ko daal do
      4. Agar left subtree traversed hai , tab
         1. curr ke right ko null kardo
         2. ans mai pushback kardo root ke data ko
         3. root mai root ke right ko daaldo. 
4. return kardo ans ko
Note: root ka next left ko curr se point karwa rahe hai. 

Time complexity: O(n) and space Complexity : O(1)

Taversed ho chuka ya nahi ye information kyu zaruri hai,  Agar hamne left subtrr ko traverse nahi kiya hai hamko pahle left jana hoga phir, Node ko print karo phir right jayenge, agar traverse kar chuka hu then then node ko ans mai dalo and move to right. 

Implemention part :- 
```
vector<int> morrisInOrder(Node *root)   // inorder : LNR
{
    if(!root)
    return {};

    vector<int> ans;
    while(root)
    {
        // left part does not exist
        if(!root->left)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        // left part exist
        else
        {
            Node *curr = root->left;
            while(curr->right && curr->right!=root)
            curr = curr->right;

            // left subtree not traversed
            if(curr->right==NULL)
            {
                curr->right = root;
                root = root->left;
            }
           // Already traversed
           else
           {
            curr->right = NULL;
            ans.push_back(root->data);
            root = root->right;
           }
        }
    }
    return ans;
}
```
Pseudo code :- 
1. Left does not exist
   1. Note down the data
   2. Move to right
2. Left part exist
   1. not traverse:- -> create the link  -> move to left
   2. traverse:- -> Remove the link -> Note down the data  -> move to right. 

### Same Algorithum ka use karke preorder bhi kar sakte hai
Pseudo code :- 
1. Left does not exist
   1. Note down the data
   2. Move to right
2. Left part exist
   1. not traverse:- -> Note down the data -> create the link  -> move to left
   2. traverse:- -> Remove the link  -> move to right. 

Code Implementation :- 
```
```

### PostOrderTraversal by morris :- 
Isko karne ke liye hamko pata hona chahiye ki kya hamne lrft aur right part  dono ko puri tarah se traverse kar liya hai tab ham apne current node ko print karwa payenge.
PostOrder (LRN) -> NRL is order mai change karde phir reverse karle toh ham apni problem ko solve kar sakte hai. But in preOrder we have used the NLR . So lets make some conclusion on the basis:- 
1. NRL :- Node ko print karwate rahe tab right most nahi milta if found then create connection to comeback to the root node. 
Note :- right side jayenge tab ham uske left most ko bolenge ki wo mujko yani root node ko connect karle.

Code Implementation :-
```
```

### Flatten Binary to linked list :- 
Isme hamko ek tree diya hoga bolega ki is tree ko preOrder form mai nikalo aur iske answer ko tree form kardo. Aur is tree ke left sare ke sare NULL honge. Complexity Boundary for :- Time O(n) and space O(1).
Direct Connect nahi kar sakta becuse we loose the couples of data means ham direct apne right mai NLR ka use karke coonect nahi bana sakte. 
Approch : 
Apne root ke left par jao agar us node ka right exist karta hai toh uske eight most postion par jao aur usko bole ki wo  root ke right point kare.

Code Part :- 
1. Agar left exist nahi karta tab root mai root ke right ko daal do. 
2. Agar left exist karta hai,
   1. Node type curr mai root ka left daal do.
   2. Jab tak curr->right exist karta hai, tab curr mai curr->right dalte raho (increment)
   3. curr ke right mai root ke right ko daal do.
   4. root ke right mai root ka left daal do
   5. root ke lrft ko null bana do. 
   6. root mai root ka right daal do

Implementation Part :- 
```

```