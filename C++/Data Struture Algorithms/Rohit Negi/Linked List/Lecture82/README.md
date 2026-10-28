### Doubly Linked List
Gives the advantage to move in the both direction to the pointer. 
Creating doubly linked list :- 
calss className:- 
  - integer type data , className type ek pointer hoga next naam ka and prev naam ka. 
  To initialze the value we need constructor :- 
    -Node(int value )
code Implementation :- 
```
class Node 
{
    public:
    int data;
    Node *next;
    Node *prev;

    // Constructor to initialize 
    Node(int data)
    {
        data = value;
        next= NULL;
        prev = NUll;
    }
};
```
To create linked list we should know the Insertion. 

## Insertion in Doubly Linkedlist :- 
1. Insert at start
2. Insert at particular place
3. Insert at End

### Insert at Start in Doubly LikedList:- 
1.  temp naam ka pointer le lenge ,  new Node(5) , daal denge, jis se ek node banega jisme ek prev mai NULL hoga and value mai 5 hoga , next mai NULL hoga. 
2. temp->next mai head daal do.
3. head->prev mai temp daal do
4. head ko temp daal do 

contraints:-
1. When head is NULL :- 
    - agar head==NULL then head = new Node(5) kar do. 

code implementation :-
```
#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node * next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
   Node * head = NULL;
    //  Insert at start 
    //  Linked Doesnot exist
    if(head==NULL)
     {
        head = new Node(5);
     }

    //  Linked List Exist
    else
    {
      Node * temp = new Node(5);
      temp->next = head;
      head->prev = temp;
      head = temp;
    }

    // Print the value of Doubly linked list
    Node *trav = head;
    while(trav)
    {
        cout<<trav->data<<" ";
        trav = trav->next;
    }
}
```

### Insert at End in Doubly linked List :- 
End par jana padega, end mai add karne ke liye, iske liye ek pointer lenge curr. 
1. curr ko jab aage badayenge jab tak , Null n ho jaye
2. Ab ek pointer lenge, jiske throgh ek node banayenge , jiske andar value 5 hoga iske next and prev NULL hoga. 
3. curr ke next mai temp daal denge.
4. temp->prev mai curr daal do

Constraints :- 
 1. Head is equal NUll.

 Code Implementation :- 
 ```

 ```

 ### How to convert Array in doubly linked list
 Ek node hai , jiske end mai insert karte ja rahe hai, abhi tak , we approch that ki Pure linked list ko traverse kar rahe the, last mai ja raha the , phir waha se ek new node create kar rahe the phir unko aaapa mai link karte the, Ab traverse nahi karna chahte iske liye hum ek pointer banayenge jo ki hamesha last node ko point karega. 

 1. Do pointer banayenge head naam ko jo initial mai NULL hoga. aur ek pointer tail naam ka wo bhi Null hoga. 
 2. Agar head null hai, tab 
    - head = new Node(arr[i]) daal do. 
    - Tail mai head daal do 
3. ek pointer temp naam ka jis mmai New Node(arr[i]) karte jayenge
4. tail ke next mai temp daal do.
5. temp->prev mai tail dal do
6. Tail mai temp daal do
 
 Code Implementaion :-
 ```
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node *head=NULL , *tail = NULL;
    //  Create doubly linked list 
    int arr[] = {1,2,3,4,5};

    for(int i=0; i<5 ; i++)
    {
        //  Linked List doesnot exist
        if(head==NULL)
        {
            head = new Node(arr[i]);
            tail = head;
        } 
        // Linked list exist
        else{
            Node *temp = new Node(arr[i]);
            tail->next= temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    // Print the value of Doubly linked list
    Node *trav = head;
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
} 
 ```

 ### How to create Doubly Linked list using Recursion :- 
 Approch :- While calling the fun , jis node par hai usko call kar denge (Back naam ka) and while returning jaha node create hua hai, wo address rerturn kar denge. 
 Base Case:-
  -jab index barbar ho jaye size ke return kardo Null.
Main:- 
   - create new node
   - temp ke next mai back value do
   - call for another mode createDll(arr , index+1, size , temp) isko daal do temp ke next mai. 
   - return temp
code Implementation :- 
```
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

Node *CreateDLL(int arr[], int index, int size, Node *back)
{
   if(index==size)
   return NULL;

    //  Creating Node
    Node * temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = CreateDLL(arr,index +1, size, temp);
    return temp;
}

int main()
{
    Node *head=NULL , *tail = NULL;
    //  Create doubly linked list 
    int arr[] = {1,2,3,4,5};

    head = CreateDLL(arr,0,5,NULL);

    // Print the value of Doubly linked list
    Node *trav = head;
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
} 
``` 
HomeWork:- Do same with Inserting it at start.

### Inserting node at particular place in doubly linked list :-
if the position given, then sabse pahla task hoga us node tak pahuchna.
1. Ek pointer curr jo head ko point karega.
2. curr tab tak chalega tab tak pos, 0 n ho jaye. 
3. create a node to add it with temp pointer 
4. temp ka next mai curr ka next daal do. 
5. temp ke prev mai curr daal do
6. curr ka next hai mai temp daal do
7. temp->next->prev mai temp daal do. 

constaints :- 
Startig : Fail at pos=0
Ending :  Fail at the end

Code Implementation :- 
```
int main()
{
    Node *head = NULL;
    //   Insert at any given postion
    int pos = 2;

    //  insert at start
    if (pos == 0)
    {
        //  Linked list exist na kare
        if (head == NULL)
        {
            head = new Node(5);
        }
        //  Linked list exist
        else
        {
            Node *temp = new Node(5);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else
    {
        Node *curr = head;
        // Go to the node after which i have to insert
        while (--pos)
        {
            curr = curr->next;
        }
        // insert at end
        if (curr->next == NULL) // Last Node
        {
            Node *temp = new Node(5);
            temp->prev = curr;
            curr->next = temp;
        }
        //  insert at middle
        else
        {
            Node *temp = new Node(5);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
        }
    }
      // Print the value of Doubly linked list
    Node *trav = head;
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}
``` 

### Deletion Operation on Doubly Linked list   
1. Delete at start
2. Delete at a particular position
3. Delete at End

### Delete at start:
1. Agar head null nahi hai to,
   - ek pointer banao jo point karega head ko
   - head ke ander head->next daal do
   - delete kardo head ko. 
   - ab agar head exist karta hai, tab
     - head->prev ko null kar do. 

Code Implementation:- 
```

```

### Delete node at end :- 
Sabse pahle last tak pahuchna padega.
1. Agar head null ke barabar nahi hai, tab 
   - ek node banao curr naam ka jo point karega head ko.
   - jab tak curr->next null nahi hota tab tak
     -curr mai curr->next se aage bad jao
   - curr->prev->next hai usko null kardo
   - delete curr

Constraints :- 
jab sirf ek node he present ho tab ,
Agar head ka next null hai tab,
  -delete head means head jisko point kar raha hai
  - head head ko null kar do. 

Code Implementation :- 
```
```

### Delete At any Given postion :- 
Jis node ko delete karna hai, waha pahuchna padega. 
1. ek curr naam ka pointer, jo point karega 
2. jab tak pos hai , tab tak
   - curr mai curr->next se aage bada do.
3. curr->prev->next mai curr->next daal do. 
4. curr->next->prev mai curr->prev daal do. 
5. delete curr

contraints
1. starting Node
2. end node 

Code Implementation :- 
```
```

### Applications of Doubly linked list :- 
1. undo and redu opertion. 
2. spotify song button