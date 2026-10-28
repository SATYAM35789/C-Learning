### Queue :- (ek line ko lagwana )
Queue is a linear data structure which follow the fifo principle to their Operations. Ex Whatsapp messages when person is offline and sender some message then this messages will store in the Queue at th server until person see the message or internet connection 2 When open different apps in the phone or pc then the processor do the same work in the Queue formed to open the apps.

Operation of Queue :- 
1. Push operation :- push karte samay value pichh se add hogi.
2. Pop operation : - pop aage se hoga. 
3. Front operation :- front par konsa element hai
4. Rare Op :- Last element konsa hai. 
4. isFull :- Hamara queue bhara hai?
5. isEmpty :- kya kyu khali hai?

Note Jab bhi hamara front rare se agge chala jayega means ki hamre pass koi bhi elemnt exist nahi karta hai. Agar aisa hota hai then front aur rare dono ko update kar do. 
2. Ham array ke case value ko aage nahi bada rahe hai kyuki time complexity bad jayegi, we just want implement the queue and generate the undersanding. 

1. empty condition :- Agar front barabar ho jata hai -1 ke 
2. full condition:- Agar rear barabar ho jata hai size-1 ke 

Note:- Jab bhi ham value push kar rahe tab hamko check karna padta hai ki array khali hai ki nahi. IsEmpty fun se check kar lete hai ki hamara array khali kyuki front , -1 ke barabar hai lakin 2 value aa jane ke baad , ye condition fail ho jayegi. so we need to verify again then we use !IsFull. 

Pop():-
1. Kahi hamra queue empty toh nahi hai, if empty then show the message. 
2. Front ko ek kadam aage bada do.
3. Edge Case :- When font equal the rear, front and rear ko wapas se update kar do. 

Start()
1. Agar queue khali toh bol denge queue is empty and show message.
2. return kardo jo arr ke front ko 

Code Implementaion:-
```
// Implement queue using Array
class Queue
{
    int *arr;
    int front, rear, size;

public:
    Queue(int n)
    {
        arr = new int(n);
        size = n;
        front = rear = -1;
    }

    // Queue is empty or not
    bool IsEmpty()
    {
        return front == -1;
    }

    // Queue is Full or not
    bool IsFull()
    {
        return rear == size - 1;
    }

    // Push element into the queue, end
    void push(int x)
    {
        // Empty
        if (IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // Full
        else if (IsFull())
        {
            cout << "Queue is overflow\n";
            return;
        }
        // Insert
        else
        {
            rear = rear + 1;
            arr[rear] = x;
        }
    }

    // Pop element, starting
    void pop()
    {
        // Empty
        if (IsEmpty())
        {
            cout << "Queue UnderFlow\n";
            return;
        }
        // If not empty, than pop the element
        else
        {
            if (front == rear)
                front = rear = -1;
            else
                front = front + 1;
        }
    }

    // Starting mai konsa element rakha hua hai
    int start()
    {
        if (IsEmpty())
        {
            cout << " Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
};
```

Why this method of using is not suggested?
Space ka utilization nahi kar pa rahe so is problem ka solution Circular Queue. Means given array ko circle ki tarah treat karo. 
If this condition match then it act as a circular queue :- (rear+1)%size == front, than hum push operationnahi kar sakte.
Increment and Decrement in Circular Queue :- front = (front +1)%size; rear= (rear+1)%size;

Code Implementation :-
```
// Implement queue using Circular Array, circular queue.
class Queue
{
    int *arr;
    int front, rear, size;

public:
    Queue(int n)
    {
        arr = new int(n);
        size = n;
        front = rear = -1;
    }

    // Queue is empty or not
    bool IsEmpty()
    {
        return front == -1;
    }

    // Queue is Full or not
    bool IsFull()
    {
        return (rear + 1) % size == front;
    }

    // Push element into the queue, end
    void push(int x)
    {
        // Empty
        if (IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // Full
        else if (IsFull())
        {
            cout << "Queue is overflow\n";
            return;
        }
        // Insert
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    // Pop element, starting
    void pop()
    {
        // Empty
        if (IsEmpty())
        {
            cout << "Queue UnderFlow\n";
            return;
        }
        // If not empty, than pop the element
        else
        {
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % size;
        }
    }

    // Starting mai konsa element rakha hua hai
    int start()
    {
        if (IsEmpty())
        {
            cout << " Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
};
```

### Imlementation using Linked list :- 
Same everything but ab hamko linked list ke through Implement karna hai. 
1. Creating a node structue. public mai data , next pointer ko initialize kardo aur constructor ki help se usko define kar do. 
2. Queue ko implement karwa dete: -
  1. We need two pointer front and rear, Queue ke constructor mai value ko definedd kardo. 
  2. push() 
  3. pop() 

Code Implementation:-
```
// Queue using linked list
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

class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Queue is empty or not
    bool IsEmpty()
    {
        return front == NULL;
    }

    // Push element into the queue
    void push(int x)
    {
        // Empty
        if (IsEmpty())
        {
            front = rear = new Node(x);
            return;
        }
        // Empty na ho
        else
        {
            rear->next = new Node(x);
            rear = rear->next;
        }
    }

    void pop()
    {
        if(IsEmpty())
        {
            cout<<" Queue underflow\n";
            return;
        }
        else 
        {
            Node * temp = front;
            front = front->next;
            delete temp;
        }
    }

    int start()
    {
        if(IsEmpty)
        {
            cout<<" Queuue is empty";
            return -1;
        }
        else
        return front->data;
    }
};
```

### Queue in Standard template Library :- 
Dekho  queue pahle se implement kar diya gaya standard template library mai so future agar koi problem aati hai tab hamko queue ko implement karne ki zarurat nahi ba s hamko use karna hai usko. Use karene queue ki sari functioanality ko hum use kar sakte hai.  
 