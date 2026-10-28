### Flattening a linked List 
Jo bhi linked list hum diya hua hai usko single linked list mai, convert kardo. Extra memory use nahi karna hai. example linked list mai root node do direction mai bad raha hai increaing order mai. buttom side aur right side. Ab jitne bhi next right side node aata hai , wo node bhi bottom side flow ho raha hai and so on.
Approch:- jitne bhi right side linked list hai unko bottom mai merge karte jao, sorted form mai.  
1. Do sorted linkedd list ko merge karna. 
-> ek dummy node banate the, aur compairsion karte jate the, jo chhota usko update kar dete the.

Merge Function :-
1. Arguments head1 and head2 were given. 
2. ek pointer banao head naam ka jiske and dummy node create karke daal do. 
3. ek pointer tail naam ka jiske ander head daal do, means tail bhi head ko point karega. 
4. jab tak head1 and head2 exist karta hai, tabtak
   1. Ab Agar head1->data chhota hai ya barabar head2->data se, tab  
      1. tail->bootom mai head1 ko point karwa do. 
      2. head1 ko head->bottom se increment kardo.
      3. tail ko tail->bottom se increment kar do. 
      4. tail->bottom ko null kardo. 
   2. else head2 chhota hoga , do same of above just change head1 to head2. 
   3. Agar ab head1 ya head2 mai se koi bhi bachha hai , tail->bottom mai head1/head2 daal do and so on. 
   4. Return head->next.


// Flattering solving approch
1. take three pointer head1, head2, haed3
2. jab tak root->next exist karta hai
   1. head1 mai root , head2 mai root->next , head3 mai root->next->next daal do. 
   2. head1 and head2 ko merge function mai pass kar do lakin us se pahle unke connection tod do between head1 and head2 , head2 and head3. 
   1. head1->next ko null bano do
   2. head2->next ko null bana do. 
   3. call merge fun. iske return addree ko root ke ander store kardo.
   4. root->next mai head3 daal do.   

Time Complexity :- O(nsqm)
Space Complexity :- O(1)

Code Implementaion :- Ye most optimised approch nahi because uske liye priority queue and heap use hoga

```
// Merge Function
Node *merge(Node *head1, Node *head2)
{
    // Creating dummy node
    Node *head = new Node(0);
    Node *tail = head;

    // Doing Compairsion , to insert in linked list, jab tak ye dono exist kare
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->bottom = head1;
            head1 = head1->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }

        else
        {
            tail->bottom = head2;
            head2 = head2->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }
    }
    if (head1)
        tail->bottom = head1;
    else
        tail->bottom = head2;

    return head->bottom;
}

// Function which return the rrot of the flattered linked list
Node *flatter(Node *root)
{
    Node *head1, *head2, *head3;

    while (root->next)
    {
        head1 = root;
        head2 = root->next;
        head3 = root->next->next;

        // Breaking the connection
        head1->next = NULL;
        head2->next = NULL;

        root = merge(head1, head2);
        root->next = head3;
    }

    return root;
}
```

### Merge k sorted Linked List :- 
K no. of  linked list hai, jo ki sorted form hai , ek array jo inke address ko store karke rakh raha hai, at every index. Inko convert karna hai linked list mai in sorted array.
1. ek head pointer bana lo uske ander arr[0] mai jo usko dal do.
2. Ab jab tak k ki value hai tab tak
   1. Merge fun call kar denge iske return mai jo answer milega usko head mai daal denge. 

Code Implementation :- 
```
Node *merge(Node *head1, Node *head2)
{
    // Creating dummy node
    Node *head = new Node(0);
    Node *tail = head;

    // Doing Compairsion , to insert in linked list, jab tak ye dono exist kare
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }

        else
        {
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if (head1)
        tail->next = head1;
    else
        tail->next = head2;

    return head->next;
}

// Function to merge k sorted Linked List
Node *mergeKLists(Node *arr[], int k)
{
    Node *head = arr[0];

    for (int i = 1; i < k; i++)
    {
        head = merge(head, arr[i]);
    }
    return head;
}
```
Time Complexity :- O(Ksqn)

2nd Approch or Optimizing the above code :- 
Using Merge Sort :-  Concept 
1. mergeSort() : ek Node type ke array , ek int start and ek int end pass kar do
2. int mid = start + (end-start)/2
3. mergeSort(arr, start , mid);
4. mergeSort(arr , mid+1 , end);
Base condition : start bada ya barabar ho jata hai end se, toh rook jao.  
5. merge(arr[start] , arr[mod+1]) stored this in arr[start] ke ander 

Time Complexity:- O(nklogk)

Code Implementation :- 
```
// Merge Function
Node *merge(Node *head1, Node *head2)
{
    // Creating dummy node
    Node *head = new Node(0);
    Node *tail = head;

    // Doing Compairsion , to insert in linked list, jab tak ye dono exist kare
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }

        else
        {
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if (head1)
        tail->next = head1;
    else
        tail->next = head2;

    return head->next;
}

void mergeSort(Node *arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    // left part
    mergeSort(arr, start, mid);
    // Right Part
    mergeSort(arr, mid + 1, end);

    arr[start] = merge(arr[start], arr[mid + 1]);
}

// Function to merge k sorted Linked List
Node *mergeKLists(Node *arr[], int k)
{
    mergeSort(arr, 0, k - 1);
    return arr[0];
}
```
