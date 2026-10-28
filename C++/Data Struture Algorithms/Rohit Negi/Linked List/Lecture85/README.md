 ### Remove Loop in linked List :-
 1. Loop ko detect kar sabse pahle. 
 2. uske jaha detect jua hai waha fast pointer ko chod do, aur slow pointer ko stating mai la do. 
 3. Ab dono pointer ko ek ek kadamaage badayenge. the position where they meet is the starting Node of the loop. 
 4. Ab slow aur fast ko haha mile the, waha se phire se, slow ko aage badeyenge tab tak dono pointer barabar na hote. means jaha barabar hua toh aage nahi badayenge ruk jaye aur next ka
 connextion tod denge. 

 Proof of they meet at starting of the node only:- 
 1.We having three variable A,B and C. i and j jo batate hai slow and fast kitne chakar lagaye hain . 
 
 1. Detect the loop full concept. 
 2. slow mai head ko point karwa do. 
 3. jab tak slow fast ke barabar nahi hota, tab tak:-
    1. slow ko slow->next se aage bada do.
    2. fast ko bhi fast->next se bada do.
4. Ab phir se jab tak slow->next barabar n jaye fast ke, tab tak
   1. slow ko slow->next se increase kar do. 
5. slow->next mai NULL daal do.

Code Implementation:-
```
// Function to remove a loop in the linked list
void removeLoop(Node *head)
{
    //  Detect the loop
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }
    if (fast == NULL && fast->next == NULL)
        return;

    slow = head;
    // Meet the slow and fast
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //  Slow ko last node par lekar jao, for breaking the loop
    while (slow->next != fast)
    {
        slow = slow->next;
    }

    slow->next = NULL;
}
```

2nd Method :- 
1. Loop detect karna.
2. length of loop find karo.
3. slow point karega head ko. 
4. fast badega slow + Length of node se aage badao. 
2. Dekho dono pointer slow and fast starting mai head ko point karenge, ab fast ko hum length of loop se aage badayenge , dobara agar slow and fast milte hai , dono ek he point kar rahe hai, ab slow ko slow->next se bada do. 

Code Implementation:-
```
void removeLoop(Node *head)
{
    //  Detect the loop
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        break;
    }
    if (fast == NULL && fast->next == NULL)
    return;

    // Find the Length of Loop
    slow = fast->next;
    int count = 1;

    while(slow!=fast)
    {
        count++;
        slow = slow->next;
    }

    // Ab humko length of loop ka pata chal gaya hai. 
    slow = head , fast = head;
    
    // Fast ko count itna door rakhna hai,
    while(count--)
    {
        fast = fast->next;
    }

    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //  Bring slow to Last Node
    while(slow->next!=fast)
    {
        slow = slow->next;
    }

    slow->next = NULL;
    
}
```

### Intersection point in Y shaped Linked List :- 
Jaha intersect ho raha hai us node ki value ko return karna hai. 
dono branches mai se jo bhi branches badi hai, usno same level pad layenge uske jaha match ho raha hai usko wapas kardo. Jab ye intersect n ho toh -1 return kardo.
1. do pointer banayenge curr1 naam ka jo point karega head1 ko, curr2 naam ka pointer jo point karega head2 ko. 
2. Do varible count1 = 0 and count2 = 0. 
3. jab tak curr1 exist karta hai tab tak
   1. count1++
   2. curr1 ko curr1->next se bada do
4. jab tak curr2 exist karta hai tab tak
   1. count2++
   2. curr2 ko curr2->next se bada do
5. curr1 aur curr2 ko equal karna iske liye
   1. curr1= head1 , curr2=head2
   2. jab tak count1 bada hai count2 se tab tak,
      1.curr1 ko curr1->next se badate raho. 
      2. count1-- ko ek se decrease kar do
    3. jab tak count2 bada hai count1 se tab tak,
      1. curr2 ko curr2->next se badate raho. 
      2. count2-- ko ek se decrease kar do
6. Jab tak curr1 aur curr2 barabar n ho jaye, tab tak
   1. curr1 mai curr1->next se bada denge
   2. curr2 mai curr2->next se bada do.
7. Jaise he dono mile , curr1->data ko return kar denge. 

Edgecase:- agar curr1 || curr2 null ke barabar hote toh -1 return kar do. 

Code Implementation:- 
```
// Function to find intersection point in Y shaped linked list
int intersectPoint(Node *head1, Node *head2)
{
    // Number of nodes Counting
    Node *curr1 = head1, *curr2 = head2;
    int count1 = 0, count2 = 0;

    while (curr1)
    {
        count1++;
        curr1 = curr1->next;
    }

    while (curr2)
    {
        count2++;
        curr2 = curr2->next;
    }
    // Level matching of the Nodes
    curr1 = head1, curr2 = head2;

    while (count1 > count2)
    {
        count1--;
        curr1 = curr1->next;
    }

    while (count2 > count1)
    {
        count2--;
        curr2 = curr2->next;
    }

    // Jaha dono same ho kaye us node ka data ko wapas karna hai.
    while (curr1 != curr2)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // Agar in dono branxhes mai se koi bhi ek null means , intersection point nahi hai.
    if (!curr1)
        return -1;

    return curr1->data;
}
```

 

