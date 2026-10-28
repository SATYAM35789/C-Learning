### Clone a Linked List :- 
Ek linked list hai hamare pass , jisme do tarah ke pointer hain ek next hai jo apne next element ko point karege, aur ek random  pointer jo randomly linked list mai nodes ko point kar raha hai. Humko is linked list as it is clone banana hai aur create kardo.  
Appproch :- 
1. Create all nodes without random pointer.
2. Assign random pointer from start. 

Code Part step:-
1. ek pointer headCopy naam ko jo dummy Node ko point karega.
2. ek pointer tailCopy naam ka jo headCopy daal denge means ye kisko point karega usko ye bhi karega. 
3. ek pointer temp jo starting mai head ko point karega
4. jab tak temp exist karta hai ,  tab tak
   1. tailCopy->next mai new Node(temp->data) daal do
   2. tailCopy mai tailCopy->next;
   3. temp mai temp->Next se aage bada do.
Removing dummy node 
5. tailCopy = headCopy;
6. headCopy = headCopy->next
7. delete tailCopy kar do
Random pointer ko point karwa raha hai
jab tak temp pointer exist karta hai, tab tak
  1. tailCopy->arb mai fin function call kardo, jo humko ek batayega ki , randomly kisko point karna hai. 
  2. tailCopy ko tailCopy->next se bada do.
  3. temp ko temp->next se bada do.
4. return kar do headCopy ko

Find Function:- 
1. find function jo, tin Node tarah ke arguments lega curr1, head ko point karega , curr2, headCopy ko point karega , x wo addess jisko find karna hai.
2. jab tak curr1 barabar n ho jaye x ke, tab tak
   1. curr1 mai curr1->next daal do
   2. curr2 mai curr2>next daal do 
3. return curr2 
Base/Edge case :- Agar x barabar ho gaya NULL ke toh return kar do NULL . 

Code Implementaion :-
```
Node *find(Node *curr1, Node *curr2, Node *x)
{
    if (x == NULL)
        return NULL;

    while (curr1 != x)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return curr2;
}

Node *copyList(Node *head)
{
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    // Clone created without Random pointer
    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // Assign random pointer to clone it .
    tailCopy = headCopy;
    temp = head;

    while (temp)
    {
        tailCopy->arb = find(head, headCopy, temp->arb);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    return headCopy;
}
```
Ab is Approch optimeize karenge. 
Unordered_map ka concept use karenge. 
1. unordered_map mai do Node type ki value store hongi jis map ka m hoga.
2. jab tak temp exist karta tab tak,
   1. m[temp] mai tailCopy daal do
   2. temp ko temp->next se increse kar do
   3. tailCopy ko bhi tail->next mai move kar do
Random pointer ko assign kar do
1. temp aur headCopy ko starting mai lekar jao
2. Ab jab tak temp exist karta hai, tab tak
   1.tail->arb ke ander m[temp->arb]:- where temp->arb means jis address ko par random point hai in original list m[]:- wo address map mai kis address ke correspondence hai. 
   2. temp aur tailCopy ko ek ek step bada do. 

Time and Space Complexity for this problem : O(n)

Code Implementation :-
```
Node *copyList(Node *head)
{
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    // Clone created without Random pointer
    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // Assign random pointer to clone it .
    tailCopy = headCopy;
    temp = head;

    unordered_map<Node *, Node *> m;
    // Fill the value inside map
    while (temp)
    {
        m[temp] = tailCopy;
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    // Assign random pointer
    tailCopy = headCopy;
    temp = head;

    while (temp)
    {
        tailCopy->arb = m[temp->arb];
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    return headCopy;
}
```

### Most Optimized Approch:-
Dekho abhi bhi hum most optimized approch nahi pahuche hai space complexity O(n) ho gayi hai last approch mai map kw wajah se so spaceComplexity ko humko O(1) karna hoga. 
Approch step:- 
1. Inserting the copy node next to the original node .
2. Randomly pointer ko assign karna 
3. Breaks the links or dono linked list ko alag karna.

Code steps
1. do pointer lenge , curr1 jo point karega head ko, curr2 jo point karega headCopy ko.
2. do pointer assign karenge front1 point karega head->next and frontCopy or curr1 point karga frontCopy or curr2 ko,  
3.ab jab tak curr1 exist karega, tab tak
  1. front1 mai curr1->next daal do
  2. frontCopy mai curr2->next ka daal do
  3. curr1->next mai curr2 ko daal do
  4. curr2->next mai fron1 
  5. curr1 mai front daal do
  6. curr2 mai frontCopy daal do
4. curr1 ko head se point karwa do
5. Ab jabtak curr1 exist karta hai tab tak
     1. curr2 ko curr1->next se point karwa do
     Agar curr1->arb exist karta hai tab
       1. curr2->arb mai curr1->arb->next dal so
       2. curr1 mai curr2->next daal do
Disconnecting :- 
6. curr1 mai head dal do
7. Jab tak curr->next daal do
   1. front1 mai curr1->next daal do
   2. curr1->next mai front1->next
   3. curr1 mai front1
return headCopy

Code Implementation
```

```
