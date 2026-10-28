### PreOrder Traversal using Iterative Appproch :- 
To remember the data we need to store it, so in iterative method we used stack data structure. In preorder we Three steps were done on every and each node :
1. Print the node 2. Left side par jao 3. Right side par jao.
While inserting the element in stack we insert right side , then left side.  
So sabse pahle root elemnt daal do, phir element ko khali karte hue chalna hai.

Code Part:- 
1. PreOrder() vector type ka bana lo , parameter : ek node type ka root pointer.
2. ek stack le lo Node type ka, jiska naam s.
3. stack mai push kardo root ko.
4. ek vector lelo int type ka, ans naam ka. 
5. jab tak satck khali na ho jaye, tab tak
   1. Ek node type ka temp pointer mai stack ke top ko daal do.
   2. stack ko pop kardo.
   3. ans mao pushback kardo temp ke data ko
   4. if temp ka right exist karta hai then stack mai push kardo temp ke right ko
   5. if temp ka left exist karta hai then stack mai push kardo temp ke left ko
6. return kardo ans ko. 

Time and Space Complexity: O(n)

Code Implementation :
```
vector<int> preOrder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    vector<int> ans;

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);

        if (temp->right)
            s.push(temp->right);

        if (temp->left)
            s.push(temp->left);
    }
    return ans;
}

```

### Post Order Traversal
Agar kisi node ko last time dekh rahe tab ham usko print kardo. Post order traversing are going to be in happened three steps :- 
1. Pahle left side 
2. uske baad right side
3. Phir node ko print karo
Agar root ka left exist karta hai tab waha jao, right par jao tab exist karta hai phir , jab left aur right  exist nahi karega phir node ke print kardo.
Iterative method :- LRN = NRL 
LRN se preorder achive karte hai, agar ham reverse karte apne processes ko NRL karte means ulta side se apne tree ko traverse karne ki kosis karte hai tab ek fayda milega then hum apne node ko pahle print karwa sakte hai phir right ko daal do and left ko daal do. Jo bhi print ka process kar rahe the usko ans mai bhej rahe the bas uske reverse order kar denge hamko hamara final ans mil jayega. 

Inserting in stack : pahle left ko phir right ko. (stack mai hum ulta daalte jo hamko chahiye wo baad mai)

Time and Space Complexity: O(n)

Implementation part :- 
```
vector<int> postOrder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    vector<int> ans;
    if (root == NULL)
        return ans; // Edge Case Fix

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        // left
        if (temp->left)
            s.push(temp->left);
        // Right
        if (temp->right)
            s.push(temp->right);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
```

### InOrder Traversal using iterative method
In Inorder traversal we generally print the node data, while visiting it second time. InOrder use these steps to include so :
1. Go to left node till exist
2. Print the node while return from the left
3. Then after printing the value go to the right side of the node till exist and so on these steps. 
Inserting order in stack:- RNL on each order. 
Jab bhi 2nd time visit kar rahe means do baar bahar nikal chuke hai then usko ans mai daal denge. 
Approch:-
1. 1st Time visit karenge RNL
2. 2nd time visit direcy print

While visiting current Node = 1 lenge and left = right = 0. 
Note : Jis bhi node ka visiting 0 hai then uske left aur right ko daal if exist and do so until they exist.

Code Part :- 
1. Inorder() vector type ka, Parameter : Node type ka pointer le lo. 
2. Ek stack banao s naam ka , Node type ka aur ek stack banao bool type ka, visited naam ka
3. s mai push kardo, root ke value ko.
4. visited mai daal do 0 (remember visited ko ++ karenge jab ham isko stack s mai se value bahar nikalenge)
5. ek vector bana lo ans naam ka
6. ab jab tak stack empty nahi ho jata tab tak, 
   1. ek node type ka temp pointer banao jisme stack s ka top daal do
   2. stack s ko pop kardo
   3. bool type ke flage mai visited ke top ko daal do,
   4. visited stack ko pop kardo
   5. Ab fisrt time visiting means flage ki value 0 hai or not flage then,
      1. Agar temp ka right exist karta hai then s stack mai temp ke right ko push kardo aur visited stack mai 0 daal do
      2. stack s mai push kardo temp ko aur visited mai push kardo 1 ko (current node)
      3. Agar temp ka left exist karta hai then s stack mai temp ke left ko push kardo aur visited stack mai 0 daal do
   6. agar flag exist karta hai then
       1. ans mai pushback kardo, temp ke data ko. 
return kardo ans ko. 

Code Implementation :- 
```
vector<int> InOrder(Node *root)
{
    vector<int> ans;
    if(!root)
      return ans;

    stack<Node*> s;
    stack<bool> visited;
    s.push(root);
    visited.push(0);

    while(!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        bool flag = visited.top();
        visited.pop();

        // Kya hum first time visit kar rahe hai
        if(flag==0)
        {
            // Right ko dalo
            if(temp->right)
            {
                s.push(temp->right);
                visited.push(0);
            }
            // phir node ko 
            s.push(temp);
            visited.push(1);
            // phir left wale ko
            if(temp->left)
            {
                s.push(temp->left);
                visited.push(0);
            }

        }
        // Kya hum second time visit kar rahe hai
        else 
        ans.push_back(temp->data);
    }
    return ans;   
}
```

   