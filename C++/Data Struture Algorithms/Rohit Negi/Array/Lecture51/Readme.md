### Introduction To recursion :- 
Recursion : A function which calls itself again and again, until a specific condition met. 
Example :- Timer :i Birthday celebration timer :- 
5 Day left for Birthday
4 Day left for Birthday
3 Day left for Birthday
2 Day left for Birthday
1 Day left for Birthday
Hppay Birthday

So ek ladki jo roj instagram par post kar rahi hai aise, but this task given to programmer, to the same work. 
```cpp
for(int i=0;i<n;i++)
{
    cout<<i<<"days left for Birthday";
    cout<<endl;
}
cout<<"Happy BirthDay">>
```
-> Upper wale approch ko Iterative approch bolte hai, So if asked that ki if we have to solve this problem using the function only what to do? 

Brute Force Approch : So ham fun banayenge har ek day ke liye like fun5(5), fun4(4), fun3(3), fun2(2), fun1(1), and fun() respectively. 

Another approch
Ham ek he function banaye like fun(), and baar baar isko he call karle for the message execution.
```cpp
void fun3(int n)
{
    if(n==0)
    {
        cout<<"Happy Birthday";
        return ;
    }
    cout<<n<<"days left for the birthday";
    fun3(n-1);
}
```
-> So hamko pata hai ki jab koi program run hota hai stack mai memory allocate hoti hai, jaise ki function and the variable use in the function ko us specific block mai memory milti hai.
-> So sabse pahle int main call hota, aur isko specific memory milti hai, isme call kya hua function ko alag block dete hai, so pahle jis block mai hai ye bhi note karte hai usme kaha tak execute hua tha.
-> Call function execute hone ke baad, ham phir wahi usi line par chale jayenge jaha se hamne function call kiya tha. 
  - return yahi kaam karta hai, jaha se call hua tha waha par chale jao.  

Note : So agar kisi problem ko iterative way se solve kar sakte hai, then ham isko Recursive se bhi solve kar sakte hai. 
- As iterative mai bhi ham same kaam  ko baar baar karte ja rahe hote aur usme ek condition hoti hai jaha hamko rukna hota hai same hai. 

Base Case : The stopage condition in the recursive function. 

Code Implementation :- 
```cpp
 #include <iostream>
using namespace std;

void fun3(int n)
{
    cout<<n<<"days left for birthday";
}
void fun2(int n)
{
    cout<<n<<"days left for birthday";
}
void fun1(int n)
{
    cout<<n<<"days left for birthday";
}
void fun0(int n)
{
    cout<<"Happy Birthday";
}

int main()
{
    int n=5;

    // // Iterative approch
    // for(int i=0;i<n;i++)
    // cout<<i<<"days left for birthday\n";
    // cout<<"Happy Birthday\n"

    //  Using  Function :- 
    fun3(3);
    fun2(2);
    fun1(1);
    fun0(0);

    // Sirf ek function call mai, solution, iske liye defined function se uske next fun call karna hoga
}
```

Another part
```cpp
#include <iostream>
using namespace std;

void fun3(int n)
{
    cout << n << "days left for birthday";
    fun2(n-1);
}
void fun2(int n)
{
    cout << n << "days left for birthday";
    fun1(n-1);
}
void fun1(int n)
{
    cout << n << "days left for birthday";
    fun0(n-1);
}
void fun0(int n)
{
    cout << "Happy Birthday";
}

int main()
{
    int n = 5;
    // Sirf ek function call mai, solution, iske liye defined function se uske next fun call karna hoga
    fun3(3);
}
```
-> Is tarah hamko error aayega aur fun3(3); mai bol rha hai ki wo janta he nahi hai fun2(n-1) function ko.
so iske liye hamko fun2() ko upper likhna padega fun3() se. 

Right way :- 
```cpp
#include <iostream>
using namespace std;

void fun0(int n)
{
    cout << "Happy Birthday";
}

void fun1(int n)
{
    cout << n << "days left for birthday";
    fun0(n - 1);
}

void fun2(int n)
{
    cout << n << "days left for birthday";
    fun1(n - 1);
}

void fun3(int n)
{
    cout << n << "days left for birthday";
    fun2(n - 1);
}

int main()
{
    int n = 5;
    // Sirf ek function call mai, solution, iske liye defined function se uske next fun call karna hoga
    fun3(3);
}
```
-> Is method ka nukshaan ya hai ki agar hamko 50 din ke kiye likhna hoga toh function ko 50 baar thodi define karenge. 

Recursive method:- 
code Implementation :-
```cpp
#include <iostream>
using namespace std;
void fun3(int n)
{
    // Base Case 
    if(n==0)
    {
        cout<<"Happy Birthday\n";
        return;
    }
    cout << n << "days left for birthday";
    fun3(n - 1);
}

int main()
{
    int n = 5;
    //  Recursive Method :-
    fun3(3);
}
```

-> We have seen that jab base condition nahi de rahe the segmentation fault aa raha tha? And we have been also heared a term stack overflow. 

Stack OverFlow :- Understanding 
So when don't give the stopage condition in thr recursion function then how it will be running the stack:- 
we know that it has the limited size, : so in last example : we call the main()-> fun3(3)-> fun3(2)-> fun3(1)-> fun3(0)-> fun3(-1)... so till stack ki size khatam n ho jaaye. 
-> So stack ki size khatam hone ke baad ye error de dega as aur koi function bhi excute nahi hua hoga pura as no base condition jaha se wapas aur jaha se call kiye toh usko aage exute hone sab fun ek dusre ke excution ko rok rahe honge. 
-> Har ek function call par kuchh memory allocate ho ja rahu hogi, So last mai kisi function ko call kiya hoga aur hamare stack mai jagah he nahi thi, so we say ki stack overflow ho gaya hai. 
-> OverFlow :-  Itna data daal diya hai ki ab aur data ander nahi ja sakta. 

Visualizing the Recursion function :- For better understanding
Recursive Tree :- 
Creating Recursive Tree :- While creating a recursive tree, jab hamne sabse pahle jis bhi funtion ko call kiya hai wo hamara node function ho jayega, aur iske ander jo be instruction excute hongi wo ek branch ban jayegi, print statement ek brnach and when we call it again then it is another branch of same node, and so on till got the base condtion.
- jab base condition mil jayegi then wo bhi brnach ban jayegi, us function jisme wo execute hua hai. 

-> Analyzing the recursive tree, so that we can know the what the output may come:-
starting node se start karo, left side pahle jao ,  then right side jao and so karte jao , iske ander jo bhi print statement or arithmatic hai, unko excute karte jao. We hot the answer. 
- so jab hamko base condtion wala node milega uske baad koi node nahi hoga , uske pahle fun(node) and so on till the main node.

-> Mathmatical representation of the recursive function :- 
let the fun3() = print()
print(0) :  Happay BirthDay  -> Base Case : iske baad aur call nahi lag raha hai. Iske alwa sabme print() ki value nikalni pd rahi hai.
print(1) : 1 Day left for the birthday, Happy Birthday  or 1 Day left for the birthday, print(0)  
print(2) : 2 Day left for the birthday, print(1)  
print(3) : 3 Day left for the birthday, print(2)  
print(n) : n Day left for the birthday, print(n-1)  (that one statment)

Conclusion :- 
```cpp
void print(int n)
{if(n==0)
{
    cout<<"Happy Birthday";
    return;
}
cout<<n<<"days left for the birthday";
print(n-1);}
```

-> Isme hamko sirf apni ek statment ko handle karna tha, aur baaki ke sab apne aap solve ho jayengi and that how recursion work, ek badi problem ko subproblem mai todo, if we solve that on sub problem than we can solve the problem. 

Code Implementation :- 
1. Print  n to 1 , numbers
```cpp
#include <iostream>
using namespace std;

void print(int n)
{
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    cout<<n<<endl;
    print(n-1);
}

int main()
{
    // Print n to 1 
    int n;
    cin>>n;

    //  Iterative approch :-
    for(int i=n;i>0;i--)
    cout<<i<<endl;

    //  Recursive Approch
    print(n); 
}
```

