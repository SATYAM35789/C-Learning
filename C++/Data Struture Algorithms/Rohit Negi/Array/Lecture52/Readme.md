### Recursion problems 
So isme ham do basic problem ko solve kar rahe honge, jinko ham alag alag method se try kar rahe honge solve karne ke liye. 

### Print 1 to N :- 
So we have to print the number from 1 to N. We have learnt to print the n to 1 numbers. 

Approch 1st :  Iterative approch 
- ek for loop lenge jo i=0 se i<=n tak chalega
   - print kardo i ko

so here also we have the stoppage condition, and updating the i by 1 in each excution, we are doing so ki ham apne condition ko pahuch jaye. So ham yaha bhi ek kaam baar baar kar rahe so similarly ham isko recursion se bhi solve kar sakte hai.

2nd Approch :- 
Recursion, isme hamko ek badi problem ki chhoti sub problem mai divide karna hai then usko solve karna hai, if solved small then we solve the bigger one. 
- so problem hai 1 to n no. ko print karna 
- subproblem : 1 ko print karwana hai, 2 ko print karwana hai, ... n ko print karna hai.

subproblem ko code mai convert karna
- ye function jo bhi number daalo ge wo print kardega
```cpp
void print(int num)
{
    cout<<num<<endl;
}
```
 -> for printing the next no. we need to call this function again so that it print the number
 ```cpp
void print(int num)
{
    cout<<num<<endl;
    print(num +1);
}
```

-> So ab ye function ab next num ko print karne ke liya call karne laga hai, ab kab tak ye call karta rahega, isko rukne ke liye we need to add the base condtion so ki stack overflow or jitna kaam utna solution aa paaye.
 ```cpp 
void print(int num, int N)
{
    if(num==N)
    {
        cout<<N;
        return;
    }
    cout<<num<<endl;
    print(num +1,N);
}
```

=>Create Recursive tree for the better visualiztion of output :- 
- Node : jis bhi function call se hamara recursion start ho raha hai, uske pass jitne bhi arguments wo sab us node ka hissa ban jayenge. 
- children :- Jitna bhi instruction excute hoga wo children bante jayenge(left to right direction)
-> Traversing :-  left jao right jao so on till found the base node, uske baad saari node par jaate raho

=> Mathmatical Representation :- 
-print(num,N); where N =5, so pahle hamko ye define karna hoga ki hamara function kar kya raha hai, num se lakar N tak value print karwa do. 
print(5,N) = 5  -> Base Case
print(4,N) = 4,5 or 4,print(5,N)
print(3,N) = 3,print(4,N)
print(2,N) = 2,print(3,N)
print(1,N) = 1,print(2,N)

print(num,N) = num, print(num+1,N) -> subproblem
: print karna hai num se N tak ke value ko, iske liye pahle num print karo then num+1 se N tak value print karenge. 

```cpp
void print(int num, int N)
{
    if(num==n)
    {
        cout<<num;
        return;
    }
    cout<<num;
    print(num+1,N)
}
```

Another Approch :- Reverse order
So iske pahle ham do argument pass kar rahe the, so that ki we can compare the base condition. As we N hamko unknown hai, but iske pahle wali problem mai in last lecture we know ki hamra terimination kab hoga. 
So if asked that to solve this problem using single arguments only then what to do:- 
-So hamko pata hai n toh lena he padega as N ki value kuchh bhi ho sakti hai, So is argument ko lenge and we know ki hamko 1 se start karna so ham sirf n ko lenge then waha se n-1 call karenge, then n-2 ko and so on till 1 tak just like we do to print the value last question.
- so jab wapas ja rahe honge tab ham print krwa rahe honge. 

```cpp
void print (int num)
{
    if(num==1)
    {
        cout<<num<<endl;
        return;
    }
    print(num-1);
    cout<<num;
}
```
- So hamko pata hai hamko 1 to N print karna hai, so ham do approch le sakta hai,as ek mai ham pahle print karwaye baad mai call kare, dusra jisme pahle pahle call then then print kare-> isme base condition achieve karne ke baad he apne excution ko print karwa paayenge so yaha call karte he jayenge. So 1 to N print kar rahe honge wapas aate samay.
Reverse order :- N to 1 ja rahe but print 1 to N kar  rahe hai so isiliye reverse order. 

Mathematical Representation :- 
1 to N print karna hai, Base case = 1 hai aur pahle 1 ko then 2 ko and so on till n tak value print kar rahe hai.
print(n) : 1 se lakar n tak value ko print kardo like print(1) :  1 se 1 tak print kardo, print(2) is 2 tak value priny kardo

print(1)=1
print(2) = 1, 2 or print(1), 2
print(3) =  print(2), 3
print(4) =  print(3), 4
print(num) =  print(num-1), num


```cpp
void print (int num)
{
    if(num==1)
    {
        cout<<num<<endl;
        return;
    }
    print(num-1);
    cout<<num;
}
```

Code Implementation :- 
1st Method :- 
```cpp
#include <iostream>
using namespace std; 

void print(int num, int N)
{
    if(num==N)
    {
        cout<<N<<endl;
    }
    cout<<num<<endl;
    print(num+1,N);
}

int main()
{
    //  Print number from 1 to N 
    int N;
    cin>>N;
    print(1,N);
}
```
2nd Method :- 
```cpp
#include <iostream>
using namespace std;

void print( int N)
{
    if(N==1)
    {
        cout<<1<<endl;
        return;
    }
  
    print(N-1);
    cout <<N<< endl;
}

int main()
{
    //  Print number from 1 to N
    int N;
    cin >> N;
    print(N);
}
```

### Print 1 to N (Even Number)
Solving this question using the recursion: so isme ham sabse bade problem yaani print 1 to N even number ko subproblem mai todenge like 1 to n ke bich kya kya number print karwane hai 2,4,6..n on the addition of two.
printEven( num) : Is function koi bhi no pass karo agar even hai toh ye number usko print kar dega or is function ka kaam hai even number print karna.
printEven(num+2) : ye call kar rahe hai, next even no ko print karne ke liye ye karte rahenge jab tak n even no nahi print hota. 
- Yaha ham 2 se start kar rahe hai aur N tak ke even number print karenge, next even number print karne ke iske pahle wale even number + 2 kar de rahe hai. 

```cpp
printEven(int num,int N)
{
    if(num>N)
    return;
    cout<<num<<endl;
    printEven(num+2,N);
}
```

- For Debugging the code made the recursivr tree.

Another Approch :- Passing only onr arguments :- 
So too understand ki kis argument ki requirement hai iske liye hamko alag alag case try karne honge ki uske baad ham decide kar payenge ki konsi factor change ho raha hai, jo change ho raha hoga usko pass karna he hoga. 
-Ek wo num jaha se case start ho raha hai, aur jaha tak ja raha. If inko reverse mai karenge toh hamko pata chalega ki sab 2 par he jakar khatam ho raha hai, so isme se ending toh fixed ho gaya, we need to pass ki start kaha se hoga. 
- So yaha ham return karte waqt print kar rahe honge.
```cpp
printEven(int N)
{
    printEven(N-2); 
    cout<<N<<endl;
}
```
- ye function even number print karega
- lakin printEven(N-2); ye bol raha ki N print karne se pahle, mere se pahle wale even ko print karwa do. 

```cpp
printEven(int N)
{
    //  Base Case
    if(N==2)
    {
        cout<<n;
        return;
    }
    printEven(N-2); 
    cout<<N<<endl;
}
```
Base Case : so kab tak ham ye karenge ki mere se pahle walo ko print kardo, kabhi toh num ko print karna hoga , so wo case hoga base case.

Edge Case :- Agar N yaha odd hua toh ye toh saare odd ko print karwane lagega so iske liye starting mai check laga denge. if odd then decrese by one then call the function.

Represenation 
1. Recursive tree 
2. Mathematical Representation
print(n):2 se lekar n tak even number print kardo

print(2): 2
print(4) : print(2), 4
print(6) : print(4), 6
print(8) : print(6), 8

print(n) : print(n-2), n

Code Implementation :- 
1st Approch
```cpp
void printEven(int num, int N)
{
    if(num==N)
    {
        cout<<N<<endl;
        return;
    }
    cout<<num<<endl;
    printEven(num+2,N);
}

int main()
{
    // Print even number from 1to N
    int N;
    cin>>N;
    if(N%2==1)
    N--;

    printEven(2,N);
}
```

2nd Approch
```cpp
#include <iostream>
using namespace std;

void printEven(int N)
{
    if(N==2)
    {
        cout<<N<<endl;
        return;
    }

    printEven(N-2);
    cout<<N<<endl;
}

int main()
{
    // Print even number from 1to N
    int N;
    cin>>N;
    if(N%2==1)
    N--;

    printEven(N);
}
```