### Dequeue :- Double Ended Queue
Push operation :- 1. Starting : push-front  2.  Ending : push-back
Pop Operatiom:- 1.  From starting : pop-front   2. From Ending :- pop-back
start :  at strat of queue mai  konsa element hai.
end :  at end of the queue mai konsa element hai. 

Implementation tecfnology :- 1. Array  2. Linked List

### Implementation of Dequeue using LInked list
When we implementaing deque :-
For pop operation :-  we need two pointer front jo starting of linked list ko point karega and rear jo end of linkrd list ko point karega.
For pop operation :- we need the address of backNode address so we need to take doubly linked list . 

Code part :- 
1. Node structure(class Node) :- Public mai int type ka data , and do node ke type ka pointer *next, *prev and constructor mai value ko initialize kar do.
2. Class Dequeue :-
1. Two pointer banao Node type ka, front and rear. constructor mai in value ko initialize kar do. 
2. Push operation :- 
   #### Push_front
   1. Empty condition : Agar front barabar hai NULL ke toh front mai rear mai new Node ko daal do. Agar hamara queue empty hai toh.
   2. Agar queue empty nahi hai :-
      1. ek pointer temp node type ka jike ander x dal denge. 
      2. temp ka next  mai front daal do
      3. front ka prev mai temp daal denge
      4. front mai temp daal do. 
   #### Push_back 
   1. Empty condition : Agar front barabar hai NULL ke toh front mai rear mai new Node ko daal do. Agar hamara queue empty hai toh.
   2. Agar queue empty nahi hai :- 
      1. ek pointer temp node type ka jike ander x dal denge. 
      2. rear ke next mai temp daal do
      3. temp ke prev mai rear daal do
      4. rear mai temp daal do

3. Pop Operation 
   #### Pop_front 
   1. Empty condition : Agar front barabar hai NULL ke toh return ho jao kuchh bhi pop nahi hoga. 
   2. Agar empty nahi hai :- 
      1. Ek pointer banao temp naam ka jisme front daal do. 
      2. front mai front ka next daal do
      3. delete temp ;
      Checking front null n hua ho :-
       1. Agar front exist karta hai , front ke prev ko null kardo
       2. agar front exist nahi karta tab rear ko bhi null bana do. 
   #### pop_back():-
   1. Empty condition : Agar front barabar hai NULL ke toh return ho jao kuchh bhi pop nahi hoga.
   2. Agar empty nahi hai :-
      1. Ek pointer banao temp naam ka jisme front daal do. 
      2. rear mai rearka prev daal do
      3. delete kardo temp ko
      Checking rear null n hua ho :-
      1. Agar rear exist karta hai tab rear ke next ko null bana do. 
      2. Agar rear exist nahi karta then front ko bhi null bana do. 

 4 Start :-
    1. Empty condition 
    2.  Agar empty nahi hai tab , return kar do front ke data ko. 

 5 End :-
   1. Empty condition.
   2. If not empty than  return kardo rear ke data ko.

Code Implementation :-
```
#include<iostream>
using namespace std;

class Node
{
    public :
    int data;
    Node *next , *prev;
    Node( int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class Dequeue
{
    Node *front , * rear;
    public :
    Dequeue()
    { 
        front = rear = NULL;
    }

    // Push front
    void push_front(int x)
    {
        // Empty
        if(front == NULL)
        {
            front = rear = new Node(x);
            cout<<"Pushed"<<x<<" in front of deque\n";
            return;
        }
        else
        {
            Node *temp =  new Node(x);
            temp->next = front;
            front->prev =  temp;
            front = temp;
            cout<<"Pushed"<<x<<" in front of deque\n";
            return;

        }
    } 
    
    // push back
    
    void push_back(int x)
    {
        // Empty
        if(front == NULL)
        {
            front = rear = new Node(x);
            cout<<"Pushed"<<x<<" in back of deque\n";
            return;
        }
        else
        {
            Node *temp =  new Node(x);
            temp->next = front;
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout<<"Pushed"<<x<<" in back of deque\n";
            return;
        }
    }     

    // Pop front
    void pop_front()
    {
        // Empty
        if(front==NULL)
        {
            cout<<" Dequeue Underflow";
        }
        else
        {
            Node *temp  = front;
            front = front->next;
            delete temp;
            // greater than 1 node
            if(front)
            front->prev = NULL;
            //  1 node
            else
            rear = NULL;
        }
    }
    // pop back
        void pop_back()
    {
        // Empty
        if(front==NULL)
        {
            cout<<" Dequeue Underflow";
        }
        else
        {
            Node *temp  = rear;
            rear = rear->prev;
            delete temp;
            // greater than 1 node
            if(rear)
            rear->next = NULL;
            //  1 node
            else
            front = NULL;
        }
    }
    // start
    int start()
    {
        if(front==NULL)
        return -1;
        else
        return front->data;
    }
    // end
    int end()
    {
        if(front==NULL)
        return -1;
        else
        return rear->data;
    }

};

int main()
{
    Dequeue d;
    d.push_back(5);
    d.pop_front();
    cout<<d.start()<<endl;
}
```

### Implementation of Dequeue using Array:-
Same  details are needed in case of Array. Let the array be Circular because agar humara front index 0 par aur hamko phir se bola ja raha pushfront karne ke liye tab hum normal arry ke case mai opertaion perform nahi kar payenge . 
Full Condition :- Agar (rear+1)%size barabar hai front ke tob hum aur element push nahi kar sakte. 
decrement case of front :- front = (front -1 + size)%size. 
increment case of rear :- rear =  (rear + 1)%sizei 

class Dequeue :- 
1. int type ka front, rear , size aur ek arr pointer bana lo 
2. Constructor mai value ko defined karlo. 
3. IsEmpty:- agar front barabar hai -1 ke tab Dequeue empty hogi. 
4. IsFull :- Agar rear+1 mod size barabar hai front ke tab Dequeue full hogi. 
5. #### push_front :-
   1. Agar dequeue empty hai , tab front mai rear mai 0 daalo do phir arr of 0 mai x ko daal do aur return ho jao. 
   2. Agar dequeue full hai, tab return ho jao.
   3. Agar dono condition nahi hai, tab
      1. front ko decrement kar do.
      2. arr of front mai x ko dal do. 
      3. return ho jao.

6. #### push_back
    1. Agar dequeue empty hai , tab front mai rear mai 0 daalo do phir arr of 0 mai x ko daal do aur return ho jao.
    2. Agar dequeue full hai, tab return ho jao.
    3. Agar dono condition nahi hai, tab
       1. rear ko increment kar do
       2. arr of rear mai x ko daal do
       3. return ho jao. 
7. #### pop_front
   1. Agar dequeue empty hai , tab return ho jao. 
   2. Agar array mai ek he element ho means rear barabar hai front ke tab front aur rear ko -1 kardo. 
   3. Agar ye dono case nahi hai tab , front ko ek se aage bada do(front=(front+1)%size).

8. #### pop_back 
   1. Agar dequeue empty hai , tab return ho jao. 
   2. Agar array mai ek he element ho means rear barabar hai front ke tab front aur rear ko -1 kardo.
   3. rear ko decrement kardo ek se (rear = (rear-1+size)%size)

Code Implementation :- 
```
#include <iostream>
using namespace std;

class Dequeue
{
    int front, rear, size;
    int *arr;

public:
    Dequeue(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool IsEmpty()
    {
        return front == -1;
    }
    bool IsFull()
    {
        return (rear + 1) % size == front;
    }

    void push_front(int x)
    {
        // empty
        if (IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // full
        else if (IsFull())
        {
            return;
        }
        // Normal
        else
        {
            front = (front - 1 + size) % size;
            arr[front] = x;
            return;
        }
    }
    // Push Back
    void push_back(int x)
    {
        // empty
        if (IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // full
        else if (IsFull())
        {
            return;
        }
        // Normal
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
            return;
        }
    }

    void pop_back()
    {
        // empty
        if (IsEmpty)
        return;
        else
        {
            // Single element
            if (front == rear)
                front = rear = -1;
            //  greater than 1 element
            else
                rear = (rear-1+size) % size; // ek kadam pichhe
        }
    }

    int start()
    {
        if(IsEmpty())
        {
            return -1;
        }
        else arr[front] ; 
    }

    int End()
    {
        if(IsEmpty())
        {
            return -1;
        }
        else arr[rear]; 
    }
};

int main()
{
    Dequeue d(5);
    d.push_back(8);
    d.push_back(8);
    d.push_front(45);
    d.push_front(45);
    d.start();
    d.End();

}
```
### Creating Dequeue using STL
syntex :- dequeue<int> d;
Code Implementation :- 
```
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(10);
    d.push_back(10);
    d.push_front(45);
}
```

### Implementing stack and queue using deque. 
For queue we need :-  push_front and pop_back
for stack we need :- pop_back and push_back. 

### Actual Implementation of deque
ye array aur linked list dono nahi use karti hai. Bahut sare array and map are used. 

   