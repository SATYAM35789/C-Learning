### Time and Space Complexity in the recursion :
So if we having an recursive function then how will calculating the time and space complexity of that so after this we are capable to find the any recursive function, time and space complexity. 

So if we are having the two algorithum and we need to find or select the best one then time and space complexity help in understand that one. So jo algorithum sabse kam samay aur sabse kam space lega wo algorithum best hoga. 
Time Complexity : Total time taken by an algorithum to run, as a function of its input size.
Space Complexity : Total space taken by an algorithum to run, as a function of its input size.
example 
```cpp
for(int i=0;i<n;i++)
cout<<i;
```
So har ek instruction ko karne mai ek unit maan lo like int i=0; -> 1 as pahle ham i ki value 0 kiye honge then i<n; -> 1 condition check kiye honge so on. Jitne bhi instruction or jo bhi ; is tarah khatam ho rahe hai wo ; ek unit time lega. 
So is tarah hamko kitne baar chalna hoga that is n time aur kitne istruction ko . So instruction three i,e 1. i< n;  2.i++  3. cout<< i;  and n time => 3n + 1(i=0) -> ignore constant term -> O(n)

-> Isme jo bhi variable or array create kiye honge wo hamara space complexity ka part ho jayega. 

=> Recursive function ka time and space complexity pata karne ke liye bahut sare method se hai :- Recursive tree bana le, Recursive function create karle or master theorem  se nikal le. 

Best method hota hai Recursive tree :-  
So isme jo bhi given function hai jo bhi condtion or check statment hai unko as 1 time maan lo and jo print statement unko bhi 1 maan lo .
- And agar calling ho rahi then usko ham 1 nahi maan sakte 
-While creating recursive tree jitne bhi 1 time wale milenge only 1 se represent karenge as constant term toh baad mai hata he dena anf calling wale ke liye waha jaha phir se us call ke liye apne fn ko calculate karo and so on karte jao.

example :- n =5
```cpp
void print(int n)
{
    if(n==0)  //  1
    return;

    cout<<n;  // 1
    print(n-1);  // Calling -> is call ke liye similarly excute karo
}
``` 

-> Iska pattern find karo like isme print(0) = 1 step and print(1) -> 2 and so on then print(n) -> 1+ n steps .

Recursive function (Mathematical Representation) :- 
print(n) = cout<< n , print(n-1)
T(n) = 1 + T(n-1)  => subsitution method.

Recursion tree : Ek example  ke help se recursion tree banao aur usme jitne bhi node hai unme normal instruction jinka execution time mai ham calculate kar pa rahe hai unko sirf le lo aur unko 1 lena hai(ignore karna at the end constant o toh hatana he hai)
- Ignore the calling function. 

Calculating space Complexity :- 
Uske liye stack bana lo har aur dekho ki running time mai stack kitna space le raha hai execute hone ke liye. So maximum kitna space stack le raha hai wo he hamara space ka size hoga. 
Recursive Trees : Is tree ki jitni height hoti hai agar unko sum karde toh hamko answer mil jayega
Note : yaha bhi variables ke space one count karna hai, chahe wo kitne bhi Iske alwa kuchh hai toh usko count karna hoga like array. 

### Array based recursive call :- 
Hamko given code ka time and space complexity nikalna hai :- 
```cpp
void print(int arr[], int index)   // int arr[] : pointer hai
{
    if(index==1)
    return ;
    
    cout<<arr[index];
    print(arr, index-1);
}
```

Time complexity :-
Recursive tree ke help se ek he baar mai time and space complexity dono he solve kar sakte hai:- 
Analysis :- 
- So given code kaise execute ho raha hoga, so iska main function banayenge aur dekhenge.
- Phir iska recursive tree banana start kerenge , on every fun call node create hoga
- aur jitne known istruction excute honge unko 1 maan lenge
- + call for next function (ab jo ye return karega usko add karlo)
- till the we reached the base on the having example or we habe taken in the int main function. 
- Analtzing the pattern of the recursive tree and generate general relation between the nodes or of recursive tree. 
- Generated formula, mai se constant remove kardo and we have our order. 

O(n+1) -> O(n)
- yaha array as pointer hai so ye constant space lege so ye 1 le lenge. 

Example 2nd :- 
```cpp
int Sum(vector<int> arr,int index, int n)
{
    if(index==n)
    return 0;

return arr[index] + Sum(arr, index+1, n)
}
```

O(n+2) -> O(n) => space complexity
-> isme vector naya create ho raha hai so yaha iska size n hoga, so har call par create ho raha hai 
then n+n+n+n+n.. 6n -> n

So agar vector ko as reference pass kar de toh constant space use hoga. then vector ko 1 lenge as saare different call ke liye bhi same memory lega. - Is case mai jo bhi ham change ya update karenge wo change sabko dikhega . 

### Time and space complexity of Binary Search:- 
So While analyzing we need take the worst case scenario, to make the final gereneral term. So binary search mai har ek call mai , apne search ka jo range usko 1/2 se kam karte ja rahe like n , n/2, n/4... 
O(logn)

fibonacci => O(2^n)