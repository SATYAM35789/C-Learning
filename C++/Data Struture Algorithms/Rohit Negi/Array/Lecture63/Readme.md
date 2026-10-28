### Perfect Sum Problem :- 
So hamko ek array diya gaya hoga jisme saare positive number he present honge. So hamko batana hai ki isme total kitne subset honge jinka addition sum ke barabar aayega. So hamko ek sum bhi diya gaya hoga. 

So agar ham saare subset generate karle aur check karle ki kiska Addition sum ke barabar aa raha hai, If aa raha hai then 1 if nahi aa raha then 0 and last mai total ko sum karde kitne 1 hai then we got the ans. 
- So yaha bhi same logic use karenge as while traversing on array we ask isko lena hai ki nahi, if ans milta then 1 return kardo and nahi toh 0 kardo aur baad sabko add kar denge. 

Recursion tree :- 
- Node : ek array and sum 
- so ab on particular value in the array wehave two option :- 
  - if Nahi Include karna hai particular value ko then is case mai index ko bada do aur sum waise ka waise he rahega. 
  - If include karna hai then if include then index++ and sum- arr[ index].
- So on every node till reached the last index of the array
-Note: And if sum is -ve aur we found the ans then we not need to create next child on that node or not need to check on the node ki ans possible hai ki nahi kyuki iske baad check karne ka koi matlab nahi rahega. 

Code Part :- 
subset()
- so ek int type ka subset le lo, parameter : int arr as pointer, int index, int sum, int n
- so left side jao and right side jao, waha se jo bhi mil raha hai unka addtion karke return kardo, i.e, return subSet(arr, index+1,n,sum) + subSet(arr, index+1,n,sum-arr[ index])
Base case :- 
 - if(sum==0) then return 1
 - if(sum<0 || index==n) then return 0.


=> Variation in question ab ham bol rahe hai ki -ve number bhi array mai ho sakte hai
Ex arr = {1,0} sum=1 is case mai hamko hamara code ans sahi nahi dega , {1,0} {1} so yaha do possible answer hai lakin hamko ek he milega we can conclude using recursive tree. wo hamko {1} case mai he answer dega according to the logic we use above. 
Note :- Yaha hamko jab ek baar ans mil gaya hai then aage bhi check karna padega as -ve or 0 bhi present ho sakta hai then aur bhi ans ho sakte hai. So hamko saare case nikalne he hai. 
Base Case :- 
  - if index == n
     - if sum==0 then return 1
     - else return 0 

Time Complexity : O(2^n)

Code Implmentation :-
```cpp
#include <iostream>
using namespace std;

int subSet(int arr[], int index, int n, int sum)
{
    if(index==n)
    return sum==0;

    return subSet(arr,index+1,n,sum) + subSet(arr,index+1,n,sum+arr[index]);
}

int main()
{
    int arr[] = {2,5,6,1};
    int sum =8; 
    cout<<subSet(arr,0,4,sum)<<endl;
}
```

### Target Sum Repeatition :- 
So hamko ek array  diya gaya hoga aur sum ki value bhi diya gaya hoga. Ye hamko bol raha hai  ki total kitne tarike is sum ko acheive karne ke liye. Jaha ham ek number ko multiple time use kar sakte hai. Subset element should be in the order. like arr = {2,3,4} then {2,3} {2,4} {2,2,3} {2,2,2} {3,3} sur bhi subset ho sakte hai lakin hamare pass answer  {2,4}  {2,2,2} {3,3} yahi wale hone. 
- Agar ham {2,4} le chuke hai then {4,2} nahi le sakte. 

Recursion tree :- 
- Node: Given array and sum hoga 
- On a paricular node we ask ke include karna hai ki nahi karna hai, But as number multiple time present ho sakte hai Means ki hamare pass sirf do he option nahi hai, toh kitne hai aur kab tak karenge isko lena hai ki nahi. 
- So yaha bhi ham same logic use karege, we take two
  - Not Include :- index ko bada aur sum ko wise he rahne do
  - Include : Is case mai index same jagah rahega as isko index multiple time use kar sakte hai but sum update ho jayega
- Jab tak sum ==0 aur sum -ve n ho jaye tab tak chalte rahe
- jab index == n ho jaye then return ho jao. 

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

int subSum(int arr[], int index, int n, int sum)
{
    if(sum==0)
    return 1;

    if(index==n || sum<0)
    return 0;

   return subSum(arr,index+1,n,sum) + subSum(arr,index,n,sum-arr[index]);
}

int main()
{
    int arr[] = {2,3,4};
    int sum =6;
    cout<<subSum(arr,0,3,sum);
}
```