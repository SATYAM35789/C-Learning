### Menmory Management
Why we need the pointer? Pointer kar he kya raha hai, address to store karta hai aur jo bhi value change or manipulate karna hota hai, using them wo permanent hota hai. So same chiz ham reference variable ke through kar sakte hai, which easy to use. 

Example 
```cpp
int  n; 
cin>>n;
int arr[n];
```

So yaha ek user se input le rahe hai aur same input ka array create kar rahe hai, So hamne pada tha ki stanadard C++ mai ye allowed nahi hota hai, but iska revalent solution hamne nikala tha vector jisme user input size ka bana paa rahe the like vector<int> hello(n);

So we have the another method jiska use karke ham, memory allocate kara paaye aur hamko error bhi n aaye. 
So hamari memory do part mai divided hoti hai :-
1. Stack:- Jaha ham systematic way mai data store karte hai, in order. Also called the static memory.
2. Heap :- Jaha jagah khali hai dikhe waha value store kardo. Also called the Dynamic memory.

-> In general stack ki size bahut kam hoti hai then heap like if we have the 4GB then stack = 8 MB and rest of them are heap. 

-> By defalut jab ham apna program run karte hai, toh wo stack mai jakar store hota. 

-> Sample Program: To understand the stack :- 
   - So pahle main() stack mai load hoga, iske saare variable same block mai memory milega.
   - the fun called in the main fun will have is function ko alag memory block milega and the variable defined in it will have the memory in the same  block jo called fun ko mila tha. 
   - After the excution of the one called funtion isko apne stack se hata denge (deallocate)
   - iske baad main function agle variable or called function or operation ko perform karega.

Why named stack?
Kyuki ye kaam he aise karta hai, pahle sabse upper wala function execute hoga phir uske niche wala then uske niche wala , jo function pahle aaya tha wo sabse last mai excute hoga. 

=> So by default ham stack he use kar rahe hai, So when to use heap and heap toh khali rah raha hai. 
So jab bhi program run ho raha hai, toh wo toh stack mai he hota hai so if kisi user ne bahut badi memory maang li jo stack, toh stack uske fulfillment kar he nahi sakta hai as uske pass, memory he nahi hai. 
Toh wo error marta hai , i.e isiliye aisa user ke through array allocate ko roka hai  :-
```cpp
int main()
{
    int  n; 
    cin>>n;
    int arr[n];
}
``` 

-> int arr[100]; :- Jab ham ye kar rahe hai toh, compile time mai bata de rahe  hai ki hamko itni int memory block chahiye. 
-> int arr[100000]; : is tarah bhi error aa sakti hai but ye error acceptable hoti hai because kyuki yaha user ko pata hota hai, and he also know that ki stack toh kam size ka hai so wo aisa nahi karega. 

Note: so badi badi process ko run hone bahut time lagta in real life so aisa nahi kar sakte program ki bich mai jakar pata chale ke hamare pass memoey he nahi hai toh isme excute nahi kar sakte. So hamko pata ho ki hamare process ko kitna resorces chahiye, tabhi process run ho.  

=> Heap mai memory kaise allocate kar sakte as wo bahut bada hai? 
So we use a keyword new, which indicates that ki ab jo bhi memory allocate hogi wo heap mai hogi. 
new : keyword used to allocate memory in the heap
new int : int ke liye heap mai memory de do. So ye address return karke deta hai jaha par memory allocate hua hai. 
-> *ptr = new int :-  So hamko address return hua hai so we need the pointer to store
int *ptr = new int; :-  So jo address return hua hai wo kis type ka hai. 

example: 
1. float *ptr1 = new float ;
2. int *p1 = new int[20];    array
-> heap mai memory dedo 20 size ka jo int type ka value store karega, iske address ko ek pointer store ho jayega jo point karega int type ka value ko
-> Jo pointer hai inko address mila hai stack mai, so isiliye taaki ham inko access kar paaye, agar inko bhi heap milta toh kaise use/ access nahi kar paate as program toh stack mai execute hota hai. 

=> So hamko pata hai ki execute hone ke baad stack se saari data automatically hat jata hai, but heap mai toh abhi bhi memory allocated hai, unko data ko delete kaise karenge, as heap apne se deallocate nahi kar sakta hai.

=> For that we have the keyword delete, int main ko fully execute hone hone ke pahle hamko allocated memory ko relese karwayenge. 
delete ptr; :- iska matlab ki ptr jisko point kar raha hai usko delete kardo,
delete ptr1;
delete [] p1; : [] isse pata chalega ki ye ek array hai isko release kardo. 

example : int *p2 = new int[n];  So yaha ham variable bhi pass kar sakte as heap mai utni space hoti hai. 
So vector ko bhi heap mai memory allocate hoti hai. So ye Stl dwara implemented hai so ye aotomatically delete bhi karwa dete hai. 

Dynamic Memory Allocation : So jab bhi memory run time par allocate karwate hai tab use dynamic memory allocation kahte hai.
Static :- So pahle se hamko pata hai ki memory kitna chahiye, so isko compile time mai pata hai ki isko kitna memory chahiye. So is tarah se stack mai memory allocate hoti hai. 

```cpp
#include<iostream>
using namespace std;

int main()
{
    //  Variable ke heap memory
    int *ptr =new int;
    *ptr = 5;  // value assign : just like we assign value normal pointer
    cout<<ptr<<endl;

    float *ptr2 = new float;
    *ptr2 = 5.6;
    cout<<ptr2<<endl;

    int n;
    cout<<"Enter the size of an array :" ;
    cin>>n;
    int * p =new int[n];

    //  value in the array
    for(int i=0;i<n;i++)
    p[i]=i+1;

    //  Print the element
    for(int i=0;i<n;i++)
    cout<<p[i]<<endl;

    //  Use delete key
    delete ptr;
    delete ptr2;
    delete []p;
}
```