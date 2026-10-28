### Reverse Linked List (only data)
So we have target to reverse the linked list. so 1st we traverse the the linked list and store it in the Arrray. Array mai se data ko wapas in reverse order mai we restore the data in the linked list. 
Consideration:-
1. Linked List ke data ko reverse kar rahe hai. 
2. Head point kar raha hai same address ko.
```
ListNode *reverseList(ListNode *head)
{
    vector<int> ans;
    ListNode *temp = head;

    while (temp != NULL)
    {
        ans.push_back(temp->val);
        temp = temp->next;
    }

    int i = ans.size() - 1;
    temp = head;

    while (temp != NULL)
    {
        temp->val = ans[i];
        i--;
        temp = temp->next;
    }
    return head;
}
```
### Reverse the whole node with 
consideration
 Reverse karte samay hum whole node ko reverse kar raha hai with head bhi end node ko point karega.  
 1. Initalize two pointer curr which point to the head, prev pointer with NULL.
 Another pointer fut (future) naam ka jo ki link khatam hone ke badd curr ko update mai help karega.  
 2. Jab tak curr pointer null nahi hota tab tak chalna hai :-
    - fut->next mai daal denge curr->next value. 
    - curr->next mai prev dal do
    - prev mai curr dal do. 
    - curr = fut daal denge. 
3 head ke ander prev ki value dange 
code:-
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

ListNode *reverseList(ListNode *head)
{
   ListNode *curr= head,  *prev = NULL, *fut = NULL;

   while(curr)
   {
    fut = curr->next;
    curr->next= prev;
    prev = curr;
    curr = fut;
   };

   head = prev;
   return head;
}
```
### Reverse Nodes of linkedList using Recursion. 
1. Take three pointer in the recursive fun. prev, curr , fut
2. Base case:-
   - Agar curr null ke barabar hota hai toh return thr prev .
3. Main 
   - fut = curr->next daal do
   - Curr->next mai prev daal do. 
   - return 

Code implementation
```
ListNode * Reverse(ListNode *curr, ListNode *prev){
   if(curr==NULL)
   {
     return prev;
   }
   ListNode * fut = curr->next;
   curr->next = prev;
   return Reverse(fut, curr);
}

ListNode *reverseList(ListNode *head)
{
    Reverse(head , NULL);
}
```

### Middle of the Linked List :- 
Jo mid mai us node ka address return karna hai. 
so iske pahle humko pata hona chaiye ki total kitna node hai present hai linked list mai. So iske liye hum temp pointer banayenge jo count bateyega linked list ka. 
1. count ko inialize with 0. 
2. creat temp pointer which points to the head.
3. Ab check karenge ki total no. of node kitna present hai list mai. 
   - temp ko aage badeyenge ek ek kadam aur count increase with 1 kar denge. 
4. count ka adha kar do to find mid. and phirse temp ko head ko point karwa denge.  
5. Count tab 0 nahi ho jata tab tak temp ko badate raho
6. ye hone ke baad temp ko return kar denge as our answer. 

Code Implementation:
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

ListNode *middleList(ListNode *head)
{
  int count = 0;
  //   Count total number of nodes
   ListNode *temp = head;
   while(temp!=NULL)
   {
    count++;
    temp=temp->next;
   }
   count/=2;
    //  Number of steps to take from the start
    temp = head;
    while(count--)
    {
        temp = temp->next;
    }
    return temp;
}
```

### 2nd Method:- Slow Pointer and fast Pointer concept 
constraints 
  - Agar fast ki value Null or fast->next null ho dono case mai he rook jayenge. 
1. We have to create two pointer, slow and fast naam ki. Starting mai dono head ko point kar rahe honge. 
2. jab fast null ke barabar nahi hai and fast ka next null nahi hai tab tak loop kaam karega. 
   - slow= slow->next. 
   - fast = fast->next->next 
3. return slow

Code Implementation. 
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

ListNode *reverseList(ListNode *head)
{
    ListNode * slow = head, *fast = head;
    while(fast&&fast->next)
    {
      slow=slow->next;
      fast = fast->next->next;
    }
     return slow;
}
```

### Homework 
Rotate List k times. 

   
