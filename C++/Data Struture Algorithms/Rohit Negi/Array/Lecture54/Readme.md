### Fibbonacci Series :- 
Fibonacci series start hoti 0 and 1 se ,  iska present term is equal to the sum of just privieous two term. like 0,1,2,3,5,8,13,21,... So if isme 8th term nikalna hai iske liye we need 7th and 6th terms, for 7th we 6th and 5th and so on till 3rd term. kyuki hamare function ko first and second fibonacci number pata hota hai. 
fibo(): jo bhi number pass karenge, ye function hamko us term ka value nikal kae bata dega. 

fibo = 0
fibo(1) = 1
fibo(2) = 1 + 0 or fibo(0) + fibo(1)
fibo(3) = fibo(2) + fibo(1)
fibo(4) = fibo(3) + fibo(2)

fibo(n) = fibo(n-1) + fibo(n-2)

Before writing in the code form we must analyze it that how actually this formula is working to solve the fibonacci series :- so for that take example to calulate the fibbonacci series of 4th  term using this formula :- 
fibo(4) = fibo(3) + fibo(2) -> 1 + 1 = 2
fibo(3) = fibo(2) + fibo(1) -> 0+1 = 1
fibo(2) = 1;
fibo(1) = 0; 

Conclusion :- So agar kisi bhi ek subproblem ke liye recursion relation likh le rahe hai means ki kisi bhi ek position ke liye agar uska answer nikal le rahe hai then sabko answer nikal sakte hai. 

Generating code using this mathematical expression :- 
```cpp
int fibo(n)
{
    // if(n==0)
    // return 0;
    // else if(n==1)
    // return 1;

    if(n<=1)
    return n; 

    return fibo(n-1) + fibo(n-2)
}
```

=> Recursive Tree bana sakte hai, to have understand ki pahle konsa output generate ho raha hai. Isme ham jab kisi node ko last time visit kar rahe honge then uski value ko calculate karenge and node ke branches tab tak bante jayenge jab tak hamko us node ja value nahi mil jata. 
-> last time mai isliye calculate  kar rahe hai kyuki tab ham uske pahle ke do ko traverse kar chuke aur hamko value pata hai. 

- So recusrion based koi bhi problem ho wo intution based hote as ham jo bol rahe hote hai, wahi hame karna hota hai.

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

int fibo(int n)
{
    if(n<=1)
    return n;
    
    return fibo(n-1)+ fibo(n-2);
}
```

### Nth stair Problem :- 
So hamko n diya hoga which means ki utne stairs hai, aur ham kade hai bottom par and we need to go to the top. We have condition that we can take 1 or 2 step at once a time. So total ham kitne tarike se top par pahuch sakte hai:- 
like 1f n=6 
1. 1+1+1+1+1
2. 1+1+1+2
3. 1+2+2
4. 1+1+2+1
5. 1+2+1+1
6. 2+1+1+1
7. 2+1+2
8. 2+2+1  so output = 8 -> we have 8 way to go the stairs. 

Recusrion : so we are going to solve this using recursion. So start thinking from the basic that if n =1 then ham kaise karenge aur uska output kya hoga, if n=2 then what will be the output and so on ek do aur nikalenge aise he output phir analize karenge kya koi relation ban raha hai. If recursion se solve ho sakta then koi n koi pattern form hoga he.
- so isme current position is equal the sum of previous two term. i.e f(n) = f(n-1)+f(n-2);
- so isme n=1 then ans 1 and n=2 then ans 2 ko base maan lenge. 
f(n) : total kitne tarike hai hamare pass yaha n tak pahuchne ke liye

How to solve problem we donot know the relation :- 
- start from basic (best case) mai ans kya hoga like start from input : 1 , 2 , 3 ... 
- try to find the pattern the different input uou have given and their output
- verify karlo, for some other cases. 

Code part :- 
- ek int type ka function lelo, Totalways naam ka jiska parameter ek in type ka integer hai
  - agar n chhota ya barabar aata hai 1 ke then return 1 kardo
  - else mai return Totalways(n-1)+Totalways(n-2) kardo 

Code Implementation
``` cpp
#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if(n<=1)
    return 1;

    return climbStairs(n-1) + climbStairs(n-2);
}
```

Time Exceed Limit :- Error aa raha hai
So we solve this problem using the dynamic programming. 

### GCD(greatest Comm0n Division) of 2 number :- 
So we have given a two number, aur hamko find karna wo number jo in dono number ko divide kar de aur wo number sabse bada, common division number hona chahiye. like num1=18 and num2=48 so number that divede both num are : So 1 se start karenge kya ye number jo dono ko divide kar raha hai? from 1 to smaller between num1 and num2 :- 
1 : yes, ye number dono numer ko divide kar sakta hai
2 : yes
3 : yes
4 : no , ye dono number ko divide nahi kar sakta
5 : no
6 : yes

So is tarah se iski time complexity bahut jayda ho jayegi, O(min(num1,num2)) :- Eculidian Algorithum se isko solve kar sakte . 
using that :- 
If a and b is given then next iteration mai a=b and b=a%b (mod :%(remainder)). Do this util we have the b 0.
a=18 and b=48 then (18, 48)-> (48 , 18) - > (18,12)-> (12,6) -> (6,0)
- So jab b=0 ho jayega, us waqt jo a hoga wahi hamara ans hoga. 

Code Part :- 
```cpp
void gcd(a,b)
{
    if(b==0)
    {
        cout<<a<<endl;
        return;
    }
    return (a, a%b);
}
```
