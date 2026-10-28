### Merge Two Binary Max Heap :- 
Hamko dono max heap array ke form mai de rakha hai, ab in dono ko merge karke hamko single max heap return karna hai. 
Approch 1 :- Ek max heap bana lo aur in dono max heap ke value ko us max heap(priority queue) mai entere karwa do. Phie ek ek karke value ko ans mai store karwa lo aur return kardo. 
Time complexity
1. Creating and inserting : (n+m)(no. of element in heap1 and heap2)*log(n+m)(inserting element)
2. Deletion : n+m*log(n+m) :- to store the value in ans. 

Approch 2:- Ham dono heap ke value ko direct ek array meai ek ek karke store karlo than  then isko step-down or heapify approch ke through isko solve kardo.
Time Complexity :
1. Creating and inserting :- O(n+m)
2. Deletion : O(n+m)

Code Implementation :- 
```
void Heapify(vector<int> &arr, int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
        ans.push_back(a[i]);

    for (int i = 0; i < m; i++)
        ans.push_back(b[i]);

    // convert the vector into max Heap
    n = ans.size();
    for (int i = n / 2 - 1; i >= 0; i++)
        Heapify(ans, i, n);

    return ans;
}

int main()
{
    vector<int> a = {2, 4, 6, 8, 10};
    vector<int> b = {2, 4, 6, 8, 10};
    int n = a.size();
    int m = b.size();

    vector<int> result = mergeHeaps(a, b, n, m);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
```

### Is Bianary Tree Heap(max)
A Binary to be the Max Heap :- 1. CBT  2. Every parent should be greater than it's child.  
Approch :-. Ek array le lo apne heap ko usme store karwa lo , agar array ko traverse karte samay kahi empty jagah mili toh max heap nahi hai.  This is not eficient ways as we use extra space and traverse for the empty index. 

Approch 2:- Agar hamre tree mai 6 node hai tab toh array mai 0-5 index cover honge means sare index hamare no of nodes se chhota hona chahiye agar kiski ka index iske barabar ya greater hai then toh max heap nahi hoga. 
Phir check karlo ki Node hamara apne children se bada hai ki nahi. 
Time Complexity :- 
1. No. of nodes ko count karna :O(n)
2. CBT : check index chhote hai ki nahi uske size se. O(n)
3. parent is greater than child :O(n)

Code Implementation :- 
```
int count(Node *root)
{
    if (!root)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

bool CBT(Node *root, int index, int totalNodes)
{
    if (!root)
        return 1;

    if (index >= totalNodes)
        return 0;

    return CBT(root->left, 2 * index + 1, totalNodes) && CBT(root->right, 2 * index + 2, totalNodes); // ek bhi side se zero then return 0
}

bool maxHeap(Node *root)
{
    // root null
    // left Child exist only
    // Right side exist only
    // Both child exist

    // Given in the question One node will exist
    if (root->left)
    {
        if (root->data < root->left->data)
            return 0;

        else if (!maxHeap(root->left))
            return 0;
    }
    if (root->right)
    {
        if (root->data < root->right->data)
            return 0;

        return maxHeap(root->right); // Yaha hum direct return kar rahe because kyuki right ke baad humko
        // kuchh check karne ki zarurat nahi, lakin agar left exist karta hai then hamko right ko bhi check karenge
    }
}

bool isHeap(Node *tree)
{
    // Counts nodes in tree
    int num = count(tree);

    // CBT hai ki nahi
    if (!CBT(tree, 0, num))
        return 0;

    // Every Parents > child
    return maxHeap(tree);
}
```

### BST to max Heap :- 
Hamko ek bst diya hua hai node ke form mai aur hamko max heap mai convert karna hai, 
Conditions are given :- 
1. Values present are unique
2. Every parent should be greater than its parents. 
3. Left subtree wale element chhote honge right subtree se. 
Note : Question mai ye necessary nahi hai ki CBT ko follow ho ya n ho.

Agar question mai 3rd condition nahi deta toh, ham normally InOrder traversal nikal lete phir hamko incresing order mai mil jata, pichh se apni value ko bhad dete hamara kaam ho jata. 

Agar apne given tree ko apne would be answer tree se match kare toh hamko ek parent milega ki jo value bdadi gai would be tree mai wo LRN ko follow kar rahi hai. 
Approch :
1. Inorder nikalo so ki hamko sorted form mai value mil jaye, so ki ham LRN ke throght data fill kar paye
2. Post Order traversal kardo data ko fill karne ke liye. 
Time Complexity : O(n).

Code Implementation :- 
```
void inOrder(Node *root, vector<int> &ans)
{
    if(!root)
    return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}

void postOrder(Node *root, vector<int> &ans , int index)
{
    if(!root)
    return;

    postOrder(root->left,ans,index);
    postOrder(root->right,ans,index);
    root->data = ans[index++];

}

void convertToMaxHeap(Node *root)
{
    // Inorder Traversal
    vector<int> ans;
    inOrder(root,ans);
    // PostOrder Traversal
    int index =0 ;
    postOrder(root, ans, index);   
}
```