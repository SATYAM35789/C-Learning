### Add 2 number 
Do linked list humko given hai un dono ko add karo , unke addition ka result ko link list wapas kardo. 
Appproch:- In dono linked list mai given numbers ko humko add karna hai , jaise hum manually aoni copy par karte hai, so list ko humko pichhe se add karna padega, so kya kare? reverse the list. 

1. Reverse both the linked list. 
2. Addition 
3. Ek variable, carry naam ka, jo carry store karega.  

Reverse function:- 
1. Base Condtion :  jaise he curr, null ke barabar ho jata hai waise prev ko return kar do. 
2. Main L-
   1. ek pointer , front naam ka jo curr->next ko point karega. 
   2. curr->next mai prev daal do. 
   3. reverse mai front and curr pass kar do. 

Code Implementation :-
```

```

main function:- 
1. Do pointer First and Scecond . First mai jo point kar raha hoga pahle linked list ke head ko same with Second. First = Reverse(First, NULL)
2. Create two pointer curr1 and Curr2 , jo point karenge. Reverse linked list ke pahle Node ko. Simuntaneously. 
3. Ek aur pointer jo point head jo null hoga , and tail jo null hoga to add new node at end. Aur ek varaible carry.  
4. Jab  curr1 and curr2 exist karte hai, tab rak 
   1. int sum ke ander curr1->data + curr2>data + carry ko add kar dunga. 
   2. create new node aur uske ander summod10 daal do.  isko daal do tail->next mai. 
      tail->next mai dalne se pahle, humko check karna padega ki kahi tail null toh nahi hai. 
      So iske liye hum ek dummy node create kar sakte hai. 
   3. curr1 mai curr1->next aage kar do. 
   4. curr2 mai curr2->next se aage kar do.
   5. carry = sum/10;  
5. Ab agar carry1 exist karta hai, tab 
  1. int sum mai curr1->data + carry kar do
  2. tail->next mai new Node(sum%10)
  3. Tail ko tail->next se aage bada do. 
  4. carry ko carry->next kar do
  5. carry = sum/10

6. 5. Ab agar carry2 exist karta hai, tab 
  1. int sum mai curr2->data + carry kar do
  2. tail->next mai new Node(sum%10)
  3. Tail ko tail->next se aage bada do. 
  4. carry ko carry->next kar do
  5. carry = sum/10

7. Jab tak carry exist karta, tab tak :-
  tail ke next mai new node(sum%10) kardo. 
  carry ko /= 10 kar do. 
8. Remove dummy node and reverse the linked list , we have created now of addition. 

Code Implementation:-
```

``` 

### Reverse a linked list ingroup of sizes k. 
problem:- humko ek linked list di hogi aur ek size k diya hoga , in linked list 4 ke group mai reverse kardo, end mai jitna bhi bache unko reverse kardo and ab jo linked list bana hai usko reverse kardo. 
Approch:- 
1. first pointer given hai, hamko so
2. ek pointer second naam jo point karega first->next ko, ek pointer prev jo point karega first ko, ek pointer hai curr naam ka jo point karega first ke next ko, ek pointer front jo point karega curr->next ko. 
3. Jab tak k, 0 ke barabar nahi ho jata, tab tak
   1. front ke curr->next se aage bada do
   2. curr->next mai  prev daal do
   3. prev mai curr daal do
   4. curr mai front daal do 
   5. k-- ek se kam kardo. 
4. Abhi tak hamne k node ko reverse kar diya hai, ab humko k node ko bache hue node se connectivity karna hai:- 
   1. first->next ko prev(last of k reverse node) mai daal do.
   2. second-> next  mai curr daal do. 

We create dummy node here. kyuki starting mai first hamre pass nahi hoga so iske liye. And shifing head too. 
1. first ke pointer mai new Node(0)(dummy node)
2. first->next mai head daal do
3. head mai first daal do. 

Note :Ab hum group mai toh change kar le rahe hai, but synchronized form mai nahi kiye hai means ek k group ko change karna aa gaya hai, isko pure list mai apply kar rahe hai

Updating the value :- 
1. First mai second ko daal do. 
2. Barbar k update ho raha hai iske liye hum ek variable x banalenge

K se kam node ke liye,  adding condition jab tak curr exist kare. 

Code Implementation :- 
```
// Reverse the given linked list in group of k order
Node *reverselt(Node *head, int k)
{
    // Creating Dummy Node
    Node *first = new Node(0);
    first->next = head;
    head = first;

    // Reverse in Group of 4
    int x;
    Node *second, *prev, *curr, *front;
    while (first->next)
    {
        x = k;
        second = first->next;
        prev = first;
        curr = first->next;

        // Jab tak x aur curr exist karta , reversing the Node
        while (x && curr)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
            x--;
        }
        // Connecting the Node After reverse in k or x order
        first->next = prev;
        second->next = curr;
        first = second;
    }
    //  Dummy node delete
    first = head;
    head = head->next;
    delete first;

    return head;
}
```

2nd Approch :- ek vector le leta aur unko reverse order mai store kar leta phir list update kar deta.




