### Subset Sum :- 
So hamko ek array diya gaya hoga, usme jitne bhi subset present ho sakte hai, uske sum ko return karna hai. like array = {3,4,5} -> Inka subset bhi hoga unke sum ko return karna like {3} {3,4} {3,4,5} inka sum 3, 7, 12 and so on. 
-> like {3,4} , iska ans kaise nikal rahe honge, 3 ko le lo sum mai and 4 ko bhi lelo ans mai , 5  ko mat lo ans mai => 7

Recursion tree :- 
- node : ek array aur sum le raha hoga jo initially 0 hoga 
- While traverseing or on particular on each element we asked Kya hamko isko answer mai include karna hai ki nahi.
- if yes then uska alag node banega
- if no then uska alag node banega
- and at then end all the leaf node represent our answer which we are expecting. 

OutPut  ka order janne ke liye go LRN

Code Part :- 
Requirement :- 
arr : ek array jiska sum hamko nikalna hai
index : jike help se arr ko element ko ek karke ke access karenge and ask question?
n : kaha khatam hoga search karna , basically ye array ka size hoga
sum : jisme sum ko ko calculate karenge ki kisko liye hai kisko nahi

print()
- ek void type ka print fun, parameter :- inr arr as pointer, int index, int n, int sum
- Agar include nahi karna hai then simply ek se aage bad jao, i,e print(arr,index+1,n,sum)
- Agar include karna hai then index ko ek se aage aur sum mai arr[ index] ko add kardo, i.e, print(arr,index+1,n,sum+arr[ index+1])
- Base Case :
  - if index == n ho jaye then
    - cout<<sum<<endl;
    - return ;

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

void print(int arr[], int index, int n, int sum)
{
    if(index==n)
    {
        cout<<sum<<endl;
        return;
    }

    //Not Include
    print(arr,index+1, n, sum);
    // Include
    print(arr,index+1,n,sum+arr[index]);
}

int main()
{
    int arr[] = {3,4,5};
    print(arr,0,3,0);
}
```

=> Variation apne answer ko int main mai lakar print karo
So ham ye kar sakte hai ke jo sum generate ho raha hai usko ek vector mai store kare aur us vector as refernce pass kare aur apne vector mai answer daalte jaye. 
code Implementation :- 
```cpp
#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int index, int n, int sum, vector<int> &ans )
{
    if (index == n)
    {
        ans.push_back(sum);
        return;
    }

    // Not Include
    print(arr, index + 1, n, sum,ans);
    // Include
    print(arr, index + 1, n, sum + arr[index],ans);
}

int main()
{
    int arr[] = {3, 4, 5};
    vector<int> ans;
    print(arr, 0, 3, 0,ans);
    
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}
```
Note : For practice so hamko jo bhi sum aaya hai, wo kis subset set se aaya hai uske aage likh kar print karwo output mai. 

Time Complexity :- 
- all the instruction is used take the constant time
- so we need take care that ki kitne ni of node banane waale hai. O(2^n) 

Space : 
- yaha bhi ham constant he hoga as ham as reference pass kar rahe
- so maximum size of stack used is the space complexity :- O(n)


### Target Sum :- 
Hamko ek target diya gaya hoga positive, aur ek array diya gaya hoga. So hamko batana hai kya koi array ka subset us target ke barabar ho sakta hai. Like array = {3,6,4,5} -> subset is {3,4,5} 

- So yaha bhi hamare pass, same choices hongi, kya usko le sakta hai ki nahi le sakta hai. 
- So yaha jab ham include kar rahe honge then usko target se minus kar denge, which shows ki particular element le chuke hai and we need the this target to achieve the answer. 

Recursive tree :- 
- Node : Array and the target (basic requirement)
- So yaha bhi ham ek karke element par ja rahe honge and we have the two option:-
   - Not Include : Is case mai, target same rahega and we move for the next index
   - Include : So yaha target update hoga
- So agar target barabar ho jata hai 0 ke then it shows ki we found our answer. 

Question : Is side se answer mil sakta hai ki dusre side se mil saktha. If mil sakta hai then return 1 if not then return 0. 

Code Part :- 
find()
- ek bool type ka fund fun, parameter: int arr as pointer, int index, int n, int target
- OR(||) we are using the or operator because of it usecase as agar kisibhi side(left or right) answer milta hai then hamko 1 return kar dega i.e return find(arr,index+1,n,target) || find(arr,index+1,n,target- arr[ index])
Base Case : If target==0 then return 1; 
- agar index==n || target==0 then return 0 which shows ki yaha se answer possible nahi hai. 

OR ko kasie compiler execute karta hai :- (So ye time complexity ko kam karne ka kaam karta hai)
So agar isko ek side se answer mil ja raha hai then wo dusre side ko excute or calculate he nahi karega kyuki usko pata hai agar 1 mila the dusre side kuchh bhi mile answer 1 he Hoga. 

-> Apne code part ko ek example se samajh sakte hai ki code part kaise kaam kar raha hai. 

Code Implementation :-
```cpp
#include <iostream>
using namespace std;

bool find(int arr[], int index, int n, int target)
{
    if(target==0)
    return 1;

    if(index==n|| target<0)
    return 0; 

    return find(arr,index+1,n,target) || find(arr,index+1,n,target-arr[index]);
}

int main()
{
    int arr[] = {2,4,8,7,1};
    int target = 19;
    cout<<find(arr,0,5,target);
}
```