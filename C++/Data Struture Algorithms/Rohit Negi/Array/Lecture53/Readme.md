## Recursion : Different problems
### Factorial :- 
5! = 5 * 4 * 3 * 2 * 1

Approch 1st : Iterative method :- 
fact=1
for(int i=0;i<=5;i++)
fact*=i;

- yaha ham same kaam kar rahe hai ,i,e :- fact*=i;
- ye kaam kab tak karna hai, iska base condition bhi diya hai :i<=5
So is problem ko ham recursion ke help se kar sakte hai.

Recursion :- 
So example se understand karte hai hamko factorial of  5 nikalo, then factorial of 4 then factorial of 3 and son till the factorial of 1. Aur fact of 1 hamara base condition hoga. 

fact(): fact() function hamko jo bhi number pass karenge waha tak ka factorial la kar de raha hai. 

fact(1) : 1  -> Base condition : as yaha hame kisi bhi function ki zarurat nahi isko calculate karne ke liye.
fact(2) : 2*fact(1)
fact(3) : 3*fact(2)
fact(4) : 4*fact(3)

fact(n) : n*fact(n-1)  ->Subproblem jisko solve karenge toh lagbhag saare subproblem solve ho jayengi 

Code Mai convert karna:- 
- Subproblem ko representing in the code
- Base Condition
```cpp
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
   return n*fact(n-1);   
}
```
So base condition mai hamko 1 return karna he pad raha hai, for the calculation, so is se ue conclusion hoga hamara function ka type bhi ek int hona chahiye. 
return : jaha se bhi function call hua tha waha par, n*fact(n-1) iske answer ko de do. 

Note :- Iska ham execution ko ham show kar sakte as
1. Stack wise block mai
2. Alag-alag dibba bana kar : jis ek dibba represnt karega ek call function ko-> us call mai jo instrion hobgi unko excute karega, if another fun call then alag dibba bana aur pichhle dibbe se is dibbe par arrow or point karo jo bateyega ki iske baad kis function ko call liye hai.
- return karte waqt arrow point karega usko jaha se call hua tha , so jaha jaha return jayega waha arrow banta rahega. 

=> We can create a recursive tree also to understand, how the output is generated using the recursive fn. 

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

int fact(int n)
{
    if(n==1 || n==0)  // Only agar 0 ke chack kare tab bhi hamara code perfectly kaam karega. 
    return 1;

    return n*fact(n-1);
}

int main()
{
    //  Factorial of a number n 
    int n;
    n=5;
    if(n<0)
    {
        cout<<"Fcatorial is not possible";
        return 0;
    }

    cout<<fact(n);
}
```

### Sum N number
So isme hamko n diya hoga, isme hamko sum of N natural no. nikalkar answer mai dena hai. 

Iterative Approch :- 
sum =0 ;  when n=5
for(int i=0;i<5;i++)
sum+=i;

Recursive approch :- 
So isme maan lo n=6 hai , 6 ko add kardo, 5 ko add kardo m 4 ko add kardo so on till 1 tak karte jao. so 1 base condition ho jayegi. 
sum() : iske ander jo bhi no pass karenge, ye waha tak ka number lakar de dega. 

sum(1) = 1  -> base condition : as yaha hamko koi sum() call nahi krna hai.
sum(2) = 2+1 or 2+sum(1)
sum(3) = 3 + sum(2)
sum(4) = 4 + sum(3)

sum(n) = n + sum(n-1)  -> sub problem of big problem
Note : Jo bhi formula nikal rahe hai us par kisi bhi case ko lekar check kar sakte hai kya is formule se answer generate bhi ho raha hai ki nahi. 
-> n ko pass karo assuming any no then us formule mai rakho and so on karte jao jab tak base case nahi milta, jab base case milega uske baad wo function return karte rahenge apne function ko jaha se unhe call kiya gaya tha. 

code part :- 
```cpp
sum(n)
{
    // Base Case
    if(n==1)
    return 1;
    //  sub-problem
   return n+sum(n-1)
}
```

-> Same excution box bana kar inke check kar sakte hai inke working ko. so isme example ke sath execute karenge function(using code part), so ki dekh paaye ki kaise kaam kar raha hai. 
 - har ek box or block ek subproblem ko  represent kar raha hai or ek call function mai kya ho raha. 

Code implementation :- 
```cpp
int sum(int n) 
{
    if(n==1)
    return 1;

    return n+sum(n-1);
}

int main()
{
    //  Sum of first n natural number
    int n=6;
    cout<<sum(n)<<endl;
}
```

### Power of 2 :- 
So hamko n diya hoga aur bolega ki, utna power 2 calulate karo. like if n=5, then 2^5 => 2X2X2X2X2 = 32
Recursion :-  So recursion se karne ke liye hamko pata hai ki, 2 ko multiply karo, phir 2 se karo, and phir do se multiply and so karte jayo jab n barabar ho jaye 1 ke. 
Base Case :  when we have n == 1, waha ruk jao call karna. 

power() : isme do parameter honge ek 2 aur ek n jo batayega ki 2 ko kitni baar multiply karna hai. So ye function hamko jo bhi n ki value hai, waha tak ka power de dega. 

pow(2,1) = 2  => Base Case
pow(2,2) = 2 x 2 or 2 x pow(2,1)
pow(2,3) = 2 x pow(2,2)
pow(2,4) = 2 x pow(2,3)

pow(2,n) = 2 x pow(2,n-1)  => Subproblem

Note : Apne genetate kiye gaye mathematical expression ko ek example lekar verify karoge toh aur behtar iski working ko samjh paaoge. 

General formula = 2^n = 2 * 2^(n-1)
Generating code part for subproblem :- 
```cpp
int pow(2,n)
{
    // Base Case 
    if(n==1)
    return 2;

    //  Sub problem 
    return 2*pow(2,n-1);
}
```
Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

int pow(int num , int n)
{
    //  Edge Case :- agar user n= 0 daalo toh 
    if(n==0)
    return 1;
    //  Base Case :- Edge case handle karne ke baad agar Base case hata de toh bhi code perfectly kaam karega
    // if(n==1)
    // return 2;

    return 
    num * pow(num, n-1);
}

int main()
{
    //  power of n
    int n;
    n=5;
    cout<<pow(2,n);
}
```

### Sum of square of N natural  number :- 
So hamko ek value diya hoga n , so hamko n tak ke saare no ka square karke unka summation karna hai. like if n=2 then 1^2 + 2^2 + 3^2+ 4^2  = 30

Recusion:-
So agar hamko is recursion ke liye bole toh hame pahle 4 ka squre nikalna hoga then 3 ka, then 2 ka then 1 ka. So hamko aisa function chahihe jisme , jo bhi num daale wo uska squre karke de de aur ham usko add kar denge.  

sqSum(1) = 2^1 = 1  -> Base Case
sqSum(2) = 2^2 + 1^2 or 2 *2 + sqSum(1)
sqSum(3) =  3^2 + sqSum(2) -> 3^2 = 3 * 3
sqSum(4) =  4^2 + sqSum(3)  -> 4^2 = 4 * 4 
sqSum(5) =  5 * 5 + sqSum(4)

sqSum(n) =  n*n + sqSum(n-1) => SubProblem

Generating Code part :- 
```cpp
sqsum(int n)
{
    if(n==1)
    return 1;

    return n*n + sqSum(n-1) ;
}
```
