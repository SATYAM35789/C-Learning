### Introduction to stack :- 
Stack :- Ek container jo kuchh stroe karne ki capabiliyat rakhta hai. Agar is storage ke ander kuchh rakhna hai ya dalna hai toh uske liye push opertion karna padega. Agar storage se kuchh nikalna hai toh pop operation ki need padegi. So delete ya nikalne ke liye ek condition hai ki hum sirf uppar wale ko pahle nikalne hai. Yaha jo store hoga wo hoga data. 

1. Stack is a linear data structure, in which insertion and deletion are allowed at the end, called the top of stack.
2. When we define a stack as an abstract data type, then we are only interested in knowing the stack operation from user point of view. It simply mean, we are not interested in knowing the details, we only interested in what type of operation we can perform . 
Push Operation: used to insert
Pop Operation: used to delete
peek : to know the top of the element
isSize : storage mai kitna item hai
isEmpty : kya storage khali hai ki nahi

Follow Principle : LIFO :- Delete karte samay kya hota jo last mai hoga wo pahle jayega. so called LIFO. 
Ye basically char hote hai :- FIFO FILO LIFO LILO , in sab mai se se Only LIFO ko he follow karta hai. 
Note : Hypothetically What I am thinking is Agar hum Stack ko fully implement karte hai toh hum kisi aur bhi tarah like FIFO method se implement karwa le aaur waha sirf FIFO ke based rule par working ho. It may possible on the basis of use case I think so.

Not FILO :- Because hum confirmation nahi de sakte ki first wala last mai he bahar nikalega, Lakin LIFO mai de sakte hai. 

Another definition :- Stack mai jab bhi insertion ya deletion kare toh sirf last or sabse uppar wale element par ho. 

### Operations using Array :-
1. Ek size defined karenge , aur ye contigous form mai data ko store karke rakhta hai. Data fll kaise hoga, from 0 to n index ke direction mai array push hoga. Top ko aage badao , top ki jagah data push kar do. Jab hamare stack ka size 5 hai aur hum 6 element daalna chahte hai, jaha ek element extra ho gaya hai, is condition ko kahte hai stack overflow. 
2. pahle element delete hoga phir , top ko ek se decrese kar denge. Aur jab ek bhi element n bacha hai stack mai lakin hum phir bhi delete karna chahte hai , is condition ko bolte hai ki stack underflow ho gaya hai.
### Creating Stack :-
1. ek class stack bana lo
2.  ek arr pointer bana lo
3. size of the array ke liye size vaiable. 
4. aur ek top vaiable bana lenge for knowing the status of the stack
5. ek constructor jo stack ka initial size le lega , value ko initialze ke liye use karte hai
6. push operation : ek int type ka value lega , jisme
   Edge Case:- overFlow condition ko check karenge kahi top barabar toh nahi ho gaya size-1 ke. 
   1. top ko ek se increment ka denge
   2. arr[top] mai value daal denge
7. Pop Operation :- 
    EdgeCase :- under flow conition , hum check karenge ki kahi top barabar ho gaya -1 ke
    1. top ko decrement kardo
    2. and delete the element
flag variable :-  Agar stack khali hai toh falg hum 1 show karega. and flag ki value 0 hogi jab IsEmpty nahi hoga. 

Code Implementation :- 
```

```

### Stack Using Linked List :- 
Singly linked list se stack banane ke liye jo bhi operation karna chahte hai , uske liye hamko at start position par insert karna hoga. 
Steps to achive this topic :-
1. Ek class Stack naam ka. 
2. Ek pointer Top naam ka, with variavle size. 
3. contructor jis se value ko initialize karenge. 
4. push operation : ek value pass karenge. 
   1. Ek pointer banao temp naam ka jiske ander new Node ka address hoga. 
   2. temp->next mai temp daal denge
   3. top mao head dal denge.
   4. size bada do
5.Pop operation 
   1. ek temp naam ka pointer jisme top ko daal do
   2. top ko top->next se bada do
   3. temp ko delete kardo
   Edge Case Agar top null ke barabar ho tab , hum bata dege ki stack underFlow ho gaya hai
6. peek 
     1. Agar top barabar ho jaye null ke,
     2. return kardo -1 ko.
     nahi toh top->data ko return kardo. 

Code Implementation :-
```

```
Implementation of stack using STL:-
Dekho agar humko future mai koi stack ke uppar question puchhta hai toh hamko , ye pura likhne ki zarurat nahi hai, STL mai pahle se predefined stack bana hua hai ,  ham sirf use kar lenge. 
syntex : Stack<int> s ;
STL mai Stack ki implementation dequeue ke through kiya gaya hai. 

Why using stack instead of having vector?
Yes if vector is capable of doing all the stack work. Memory waste vector new momory allocate karte samay pahle uske double size ka contigous memory allocate karta phir purni wali ko deallocate karta hai. 

