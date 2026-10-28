### Implement two stack in an Array :- 
Hamre pass ek array diya hoga us se hamko Two stack banana hai. 
1st Approch :- Hamako basic push or pop operation karna hai, Agar hum array ko do equal part mai todte hai , aur stack1 aur stack2 bana dete hai, agar ham data apne according stack mai push karte if there is  condition that one of the stack is full and second is empty then this approches fail because we have left space in another part we are unable to use that space, So we should go for the other approch.

2ND Approch:- 
Ab agar ham ek side se stack1 ko push aur pop permission de dete hai dusre side se dusre stack ko permission de dete hai then space wali problem remove ho jayegi, jisko jitna chahiye utna use kar sakta hai. 
Code Implementation:-
```
 class twoStack
{
public:
    int *arr;
    int top1, top2, size;

    twoStack(int n)
    {
        arr = new int[n];
        top1 = -1;
        top2 = n;
        size = n;
    }

    // Function to push an integer into the stack1
    void push1(int x)
    {
        // stack bara toh nahi hai
        if (top1 + 1 == top2)
            return;

        top1++;
        arr[top1] = x;
    }

    void push2(int x)
    {
        // stack bara toh nahi hai
        if (top2 - 1 == top1)
            return;

        top2--;
        arr[top2] = x;
    }
    // Function to remove an element from top of the stack1
    int pop1()
    {
        // Kahi stack khali nahi hai
        if (top1 == -1)
            return -1;

        int element = arr[top1];
        top1--;
        return element;
    }

    // Function to remove an element from top of the stack1
    int pop2()
    {
        // Kahi stack khali nahi hai
        if (top2 == size)
            return -1;

        int element = arr[top2];
        top2++;
        return element;
    }
};
```

### N Stack in AN Array :- 
1. Diveide stretegy fails here. 
2. Last problem mai hame ek aage se top1 aur ek pichhe se top2 le liya tha pichhse . Lakin yaha hum wo stretegy nahi laga sakte kyuki hum thrid top3 hoga wo kaha se access karenge.  
3. Array and linked list combination approch:- 
   Ham pass kuchh limit hai size ka, tin pointer bana lete hai top1, top2 and top3 in pointer ke help se push aur pop operation karte hai, aur apne size ko dhyan mai rakte hue ham isme pop aur push opertaion karte hai. Ye jo pointer hai , data ham linked list ke through implement  kar rahe . 

4.Uppar wali problem mai ye issue hai ki ham data linked list ke through  store kar rahe hai. Toh solution hai hau array ki index value ko ham linked list mai store kar sakte hai ab hum push aur pop operation kar skate hai. (Mapping Approch ).
Ek stack lenge jo store karega, wo index position jo hamare array mai khalai hai. Hmko pata kaise chalega ki hamara array full ho chuka hai, jab hamara stack khali ho jayega tab hamko pata chal jayega ki Hamara Array bhar chuka hai . 

Basic requirement for this question :- 
1. Ek array jo point kar raha hai, ek node type ka variable. 
2. Ek stack jo ki empty index ko store karega array size ka. 

1. Creating Node to store the index value.
  1. public mai ek int, integer naam ka and Node type ka next pointer. Node Constructor to create Node, index mai x daal do aur next ko Null kardo.
2. Creating class for N no. of stack in array. 
  1. Isme Pulic mai, int *arr jo original data ko store karega, Node type doble Top jiske pass information hogi ki kon si index ki position khali hai, aur ek stack. 
  2. Constructor create kar lo jaha hamko N diya hai no. of stack and S for the Size of the array. 
     arr = new int[s]; means mujko ek array chahiye S size ka jo Store karega int type ki value. 
     Top  = new Node *[N] : means mujko ek N size ka array jo store kar raha hai pointer ko, jo point kar raha hai Node type ke value ko.
     3. Top array ko starting mai NULL bana do.
     4. stack mai sari original array ki empty position dal rahe hai.
  3. Push Operation (int x, int m): x ek value jisko push karna hai m stack ke ander.
  4. Pop Operation (int m) : m is stack mai pop() kar do. 

  Code Implementation:- 
  ```
  
  ``` 