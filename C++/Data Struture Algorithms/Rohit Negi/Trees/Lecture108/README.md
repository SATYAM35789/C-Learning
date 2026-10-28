### Vertiacal Traversal of  Binary Tree
Vertical order mai left to right print karna hai, Agar hum left side jayenge tab bolenge -1 agar right side jayenge toh +1. Agar same level par do ya jyda nodes aa rahe hai tab jiska level kam hoga pahle we print hoga then next wala hoga. 
Approch :-
1. jiska index kam hoga pahle wo print hoga
2. Agar index is same then jiska level kam hoga wo print hoga.

Traversing kaise kare
1. Depth wise : recursive or iterative method
2. Breadth wise : Level wise
3. ula direction 

1. Level travering :- Apne tree mai jitna chhota negaitive utne size ka ek 2d array le lenge jaha hum sare negative index ke value ko store karenge. Apne tree mai jitna bada positive  utne size ka ek 2d array le lenge jaha hum sare positive index ke value ko store karenge.
How to find the size? 
Negative side : ham apne left most jate jayenge jitna size hoga usme +1 kar denge. Ex abs((-3) +1) = 4 
Positive side : ham apne right most jate jayenge jitna size hoga usme +1 kar denge. Ex abs((3) +1) = 4 

Level order traversal mai hamko level dekhne ki zarurat nahi padegi, ye automatically

find() parameter: ek node type ka root pointer , int pos, int &l and int &r
1. jaise he root null hota hai return ho jao
2. l mai min(l,pos): minimum of l and position mai se return ho jayega.
3. r mai max(l,pos): maximum of r and position mai se return ho jayega.
4.find(root->left, pos-1,l,r):- agar hum left root ke taraf ja rahe then pos ko -- kardo aur apne current l and r ko bhej do.
4.find(root->right, pos+1,l,r):- agar hum right root ke taraf ja rahe then pos ko ++ kardo aur apne current l and r ko bhej do.


Code Part :- 
1. verticalOrder() vector type ka bana lo, parametere :ek node type ka root pointer.
2. ek int l aur ek int r , initialize it with 0. 
3. call find(root,o,l,r)
4. ek 2d array bano positive naam ka, r+1 size ka, vector vector , int type ka
5. ek 2d array bano negative naam ka, abs(l+1) size ka, vector vector , int type ka
6. ek queue bana lo Node type ka , naam q
7. ek queue bana lo int type ka, index naam ka
8. q mai root ko daal do
9. index mai 0 daal do. 
10. jab tak hamari q empty naa ho jaye
   1. ek node type ka temp pointer le lenge jisme q ke front lo daal denge
   2. q.pop kardo
   3. int type ka pos le lo, jisme index ka front daal do
   4. index ko pop kardo
   5. agar pos bada ya barabar aata hai 0 ke, tab positive of pos mai temp ke data ko push_back kardo. 
   6. agar chhota aata hai, tab negative of abs(pos) mai temp ke data ko push_back kardo.
   7. Agar temp ka left exist karta hai toh, q mai push kardo temp ke left ko aur index ko pos-1 kardo  
   8. Agar temp ka right exist karta hai toh, q mai push kardo temp ke right ko aur index ko +1 kardo.  
11. ek vector bana lo int type ka ans naam ka
12. Storing the negative 2d array value from the back, row wise
    1. ek for loop banao jo negative.size se lakar 0 exclude karne tak chalega -> no of rows
    2. ek for loop jo 0 se lker negative of i of size se ek kam tak chalega  -> us particular row ke column
    3. ans mai push_back kardo negative of i, j ko
13. Storing the positive 2d array value 
    1. ek for loop banao jo 0 se lakar positive of size se ek kam tak chalega -> no of rows
    2. ek for loop jo 0 se lker positive of i of size se ek kam tak chalega  -> us particular row ke column
    3. ans mai push_back kardo positive of i, j ko
retuen ans;

Time and space complexity : O(n)

Code Implementation :- 
```
void find(Node *root, int pos, int &l, int &r)
{
    if (!root)
        return;
    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}

// Function to find the level order traversal
vector<int> verticalOrder(Node *root)
{
    if (!root)
        return {};
    int l = 0, r = 0;
    find(root, 0, l, r);
    // positive index ke liye 2d vector bana lo
    vector<vector<int>> positive(r + 1);
    // negative index ke liye 2d vector bana lo
    vector<vector<int>> negative(abs(l) + 1);

    // need queue because ham yaha level order traversal laga rahe hai
    queue<Node *> q;
    q.push(root);
    queue<int> index;
    index.push(0);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if (pos >= 0)
            positive[pos].push_back(temp->data);
        else
            negative[abs(pos)].push_back(temp->data);

        //  root ke left value ko daal do queue mai
        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }
        //  root ke right value ko daal do queue mai
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    // Now we have negative and positive 2d array , so we need to make store it in single 1d array
    vector<int> ans;
    for (int i = negative.size() - 1; i > 0; i--)
        for (int j = 0; j < negative[i].size(); j++)
            ans.push_back(negative[i][j]);

    for (int i = 0; i < positive.size(); i++)
        for (int j = 0; j < positive[i].size(); j++)
            ans.push_back(positive[i][j]);

    return ans;
}
```
### Diagonal traversal :-
Ab given tree ko hamko diagonal wise solve karna hai aur top to down or increment of level mai value ko print karke dena hai. 
Dekho jo is type ki problem hoti wo kafi easy hoti hamko apni traversing technique choose karni hogi then koi ek pattern recoginized karna hoga just like in this question ki hamko kaise pata chalega ki ye diagonal wise he print ho rahe hai. Is question mai sare left wale pahle print honge leke sare 0 wale, then sare 1 wale then sare 2 wale and so on. 
Dekho isme level order traversing lagayenge toh ye hard hojayenga, Dusra koi traversing suitable nahi ho raha hai so we need a 2d array jaha hum l of 0 jo aaye unko date ja raha , l of 1 jo aaye unko dalte ja rahe hai and so on and baad mai single array mai convert karke answer de denge. 

Note : Agar ek element par multiple same condition based element then ham pahle left wale ko then right wale ko print karenge. Toh hamko bola gaya hai ki pahle node ko print karao then left then right ko (NLR).
means preorder traversing. 

find() parameter : Node type ka root pointer, int type pos and int l as reference
1. Agar root null ke barabar hai toh return ho jao
2. l mai max daal do pos and l mai se
3. jaise left mai ja rahe hai waise apne pos ko ek se increse kardo find(root->left,pos+1,l)
4. right side kuchh nahi karo , pos aur l dono ko wiase he pass kardo. find(root->right,pos,r)

findDioginal() , paremeter : ek node type ka root pointer, int pos aur 2d vector int type ka ans as reference pass kardo
1. ans of pos mai pushback ardo root ke data ko
2. leftside jane ke liye find(root->left,pos+1,ans)
2. rightside jane ke liye find(root->right,pos,ans)
edgecase: agar root exist nahi karta hai tab return ho jao. 

Code Part:-
1. Diagonal() vector type ka, Parameter: node type ka root pointer. 
2. int l lo 0 se initialize kardo.
3. call find(root,0,l)
4. Ek 2d vector banao int type ka ans naam ka size l+1
5. call findDioginal(), parameter: root , 0(pos) and ans ko. 
6. ek vector banao int type ka, temp naam ka
7. ek for loop jo chalega 0 se ans.size() se ek kam tak
8. ek for loop jo chalega j 0  se lakar anso of i of size tak
9. temp mai pushback kardo ans of i j ko.
10. return ans 

Time ans space complexity : O(n)

Code Implementation :-
```
void find(Node *root, int pos, int &l)
{
    if (!root)
        return;

    l = max(pos, l);

    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}

void findDiagonal(Node *root, int pos, vector<vector<int>> &ans)
{
    if (!root)
        return;

    ans[pos].push_back(root->data);
    findDiagonal(root->left, pos + 1, ans);
    findDiagonal(root->right, pos, ans);
}

vector<int> diagonalTraversal(Node *root)
{
    int l = 0; // left most diagonal ki value hamko yaha milega jo find()
    find(root, 0, l);

    vector<vector<int>> ans(l + 1);
    findDiagonal(root, 0, ans);

    vector<int> ans2;

    for (int i = 0; i < ans.size(); i++)        // no of rows
        for (int j = 0; j < ans[i].size(); j++) // particular row mai column kitne hai
            ans2.push_back(ans[i][j]);

    return ans2;
}
```

### Boundary Traversal :- 
Jo bhi nodes boundary par present hai hamko wo print karke dena hai. 
Sabse pahle left boundary ko print karna hai uske baad leaf boundary then right boundary ko print karna hai.
Left boundary nodes :- from root node to left most node
Leaf nodes : all the leaf nodes except left and right boundary. 
Right Most Nodes : reverse order of root to right most node
Note :  Agar right aur left mai agar koi bhi exist nahi karta then the root will be their left or right. 

Approch :- Hamko leaf nodes mai confusion na isiliye ham leaf nodes ko print karwayenge he nahi, ham pahle 
root se left-most-node -1 tak print karwayenge then all leaf node including left-most and right most then ham right most node par jayenge usko chod kar uske uppar wale se print karna start kar denge. 
1. Root node ko answer mai dalo
2. Left subtree ko traverse karo, node ko add karo, jab tak leaft node n mile
3. Leaf node ko add karo
4. Right subtree traverse karo, nodes ko reverse order mai print karwana hai except leaf node. 

Code Implementation :- 