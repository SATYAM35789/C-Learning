### Remove Nth Node from End:-
Given list mai hum sirf aage ke taraf ja sakte hai so nth node ko delete karne ke liye
Approch :-  Humko pata hai ki pichhe se konse nodes ko delete karna hai , aur humko count bhi pata hai ki kitna node hai, with count. Jisko hatana hai uske just pahle pahuch jayenge with cout - nth nodes from the end. 
1. count no of nodes present in the LinkedList. 
2. Create the pointer temp which points to head (traversing), which give the count. 
3. Jab tak temp null nahi ho jata count ko badate jao.
4. count -=N
5. Craete pointer curr which points to head and preb have null. 
6. ab hum check karenge jab tak count 0 n ho jaye tab chalte raho. 
   - prev mai current
   - curr mai curr->next
7. prev-next mai curr->next daal do. 
8. delete the curr. 

Constraints handeing of this code :-  When count is eaqual = 0 
  if(count==0)
     {
        temp = head;
        head=head->next;
        delete temp;
     }
Code Implementation 
```
#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    //  Creating Node
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

ListNode *reverseNthFromList(ListNode *head , int n)
{
    int count = 0;
    ListNode *temp = head;
    // Count total Number of Listnodes
    while(temp)
    {
        count++;
        temp = temp->next;
    } 
     count -=n;
     if(count==0)
     {
        temp = head;
        head=head->next;
        delete temp;
     }
     ListNode * curr = head , *prev = NULL;
     while(count--)
     {
        prev = curr;
        curr = curr->next;
     }
     prev->next = curr->next;
     delete curr ;
     return head ;
}
```

### Remove every k node :- 
yaha humko linked list mai, jitne bhi k no par node present hai usko delete karna hai. 
Approch :- count aur curr, prev ko badate jayenge aur check karenge ki wo count ke barabar hai ki nahi if yes then delete the node and reset the count to initial value and go so on,  When curr is eaqual to null then we stop. 
1. Initialize curr which points to head, prev have Null value and count is eaqual to 1. 
2. jab tak curr, null n ho jaye tab tak ye kaam karte rahenge :- 
   -Agar count barabar hai k ke (if)
        Removing the node :-
       -prev->next mai curr-> ka next daal do
       - delete the curr
       - curr mai prev->next daal do
       - count = 1 kar do
   -else
      prev mai curr daal do
      cur ko curr->next se bada do
      count++ kar do. 
3. return head

Constraints :- 
K=1 :- Head same address ko point kar raha hoga so humko head ko null karna hoga
means humko sari list delete karni hai. 

Code implementation :- 
```
#include <iostream>
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

Node *deleteK(Node *head , int k){
   Node *curr = head, *prev = NULL;
   int count = 1;

   if(k==1)
    return NULL;
    
   while(curr)
   {
    // k==count,  delete node
    if(k==count)
    {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
        count =1;
    }
    //  k != count , skip the node
    else
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
   }
   return head ;
}
```

### Rotate List  
k times rotate kar do means last ke k nodes aage aa jayenge. aur head ko update kar denge. 
1. initialize varaible count to count the no of node in the list. 
2. temp ke ander head ko daal do , aur temp ko ek ek kadam badate jao aur count ko jab taj temp null na ho jaye. 
3`:- k = k%count  4th constraints. 
   if k== 0 then return head. 
3. count -=k ki itne node aage se chodna hai. 
4. curr aur prev ko  initaize kar denge. 
5. jab tak count 0 nahi hota tab tak
   - prev mai curr daal do
   - curr mai curr->next daal do. 
6. prev->next ko null kar do.
7. Tail naam ka pointer banayenge aur usko curr mai daal denge
   creating tail so ki hum last mai ja sake aur last ke node ko head ko point karwane ke liye
8.  jab tak tail->next null nahi hota, tab tak ye karo
     - tail mai tail->next daal do.
9. Tail->next mai head daal do. 
10. head= curr daal do 
11. return head; 

Constraints :- 
1 list not exist, head ko return kardo. 
2. jab list mai ek he element present ho , tab jitni baar bhi ghuma lo koi phark nahi padta hai. 
3. k= 0 , means ek baar bhi rotate n karo.
4. Agar list ko, more than node present se rotate karna hai, normally steps waste ho raha hai. 
   Ab is rotation ko skip karne ke liye , means actual pata karne ke liye kitna baar rotate karna hai. 
   k = no. of times rotation % no of node in the list. 


Code Implementation :- 
```
ListNode *reverseNthFromList(ListNode *head, int k)
{
    // no node present
    if(head == NULL || head->next== NULL)
    return head;

    // count number of nodes
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    // when k is grater than No of node in the list
    k = k % count;
    if (k == 0)
        return head;

    count -= k;
    ListNode *curr = head, *prev = NULL;
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    ListNode *Tail = curr;

    // Second list uske last node pe leke jao
    while (Tail->next != NULL)
    {
        Tail = Tail->next;
    }

    Tail->next = head;
    head = curr;
    return head;
}
``` Method 2nd Rotate List 
Approch :- 
 Traverse the list and store it in the vector, Ye approch fail ho sakta hai because yaha hum value exchange kar rahe hai. 
 Isme mai hum last ke node ko aage store kar lenge, phir stating se value daal denge. 

### Check Palindrome 
Given list ko traverse karenge , aue ek pointer starting mai aur ek end mai , aur dono ko ek dusre ke taraf badte jayenge check karenge, same hai ki nahi. 
Linked list mai, end se opposite nahi aa sakte so ek vector ka use karenge. Is  approch se karna hai Homework.

2nd Approch :-  no extra memory using
1. Apne given linked list  ko mid se tod denge so ye do part mai tod denge. 2nd part mai ke list ko rotate ka do. Ab compair karenge dono list ko. 
 - Odd no of nodes ke liye bhi same logic laga sakte hai :- 
   jaise he ek khatam hota hai usko palindrom bol denge. 

1. Initialize temp which points to head and count = 0. 
2. jab tak temp 0 nahi ho jata, tab tak 
    - count++ karte jao
    - temp mai temp->next daal do. 
3. count /=2 , pahle part of the Given linked list, left node will be in another comes in another part. 
4. curr and prev lenge because humko connection ko todna bhhi hai . Do part mai. 
5. jab tak count 0 nahi hota, tab tak
   - prev mai curr dal so
   - curr mai curr->next dal do. 
6. Reversing 2nd part of the linked list
   - We need three pointer prev null ko point karega, curr pahle wala position front ko point to null. 
   - jab tak curr exist karta hai, tab tak
     -front mai curr->next daal do
     - curr->next mai prev wala do
     - prev mai curr dal do
     - curr mai front dal dp
 7. Now ab do pointer lenge, head1 mai head daal denge aur head2 mai prev dal do. 
 8. Jab tak head1 exist kare, tab tak
    - if(head->val != head2->val) return 0
    - head1 ko head1->next se bada do
    - head2 ko head2->next se bada do
    - return 1

    Constraints :-
    yaha no of nodes zero nahi sakte is liye is case ko handle nahi kiye hai. 

    code implementation :- 
    ```
    bool isPalindrome(ListNode *head)
{
    // Count the no. nodes
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    count /= 2;
    ListNode *curr = head, *prev = NULL;
    //  Skip number of nodes
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }
     prev->next = NULL;

    //  Reverse the second linked list, curr is pointing
    ListNode * front ;
    prev = NULL;

    while(curr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    //  Prev is pointing to second list
    //  Head is pinting to first list
    ListNode *head1 = head, *head2 = prev;

    // Check pallindrome
    while(head1)
    {
        if(head1->val!=head2->val)
        return 0; 
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1 ;
}
    ``` 