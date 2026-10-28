### Permutation 2 :- 
So yaha hamko ek array given hoga aur yaha duplicates array present ho sakte hai, total kitne permutation honge hamko output mai lakar dena hai. Aur hamko diya gaya hai ki number in array kis range mai lie karenge. So hamko yaha duplicates bhi diya hai jitne duplicate unko count karlo, and total element count karlo uske total element factorial divided by duplicates factorial utne hamare output generate honge. 
like arr = {1,1,2} then 3!/2! = 3 then outputs are {1,1,2} {1,2,1} {2,1,1}

- So iske pahle ham ye karte the ki jaha index hai waha se uske aage wale aur usko ko swap kardo and call kardo fun next. So yaha hamko agar duplicate value hoga then hamko  duplicate number ke liye function bhi call hoga jiska answer same he aayega then isko eliminate kaise kare ki duplicate ke function call n ho. 

-Logic 1: Iske liye ye karle ke Is logic ke sath answer create kare usko answer mai store kare aur usme uniqe value ko utha le aur output mai de de. 
- Logic 2: So jis bhi index par hai, agar  uske aage wale index par bhi same value present hai jo index par hai then swap mat karo aur usko aage  chale jao and check same if value are same then go for next check if different then make swap and call for the next function

Recursive tree :- 
- Used logic 2 for the recursive tree.
- Node : Given array and index 
- Swap karo :
   - Khudko khud ke sath
   - khudke aage wale ko if we present element se alag hai
- call for the fun : which means ki position fixed kardo and next index par chale jao

Note :-  So hamko ye yaad bhi karna hoga ki value pahle aa chuki hai ki nahi meand we need to track the values. So we have the range given in the question let's take -10 to 10 by default. We need the 21 size ka array jo batayega ki wo number aa chuka hai ki nahi aa chuka hai. 
- Is bool array mai mark kaise kar rahe honge, hamko kaise pata chalega ki hamari index par jo value hai wo kaha hai bool array mai . So we know that we have 21 size array then if index value is 1 then its position in the bool array is 10 + 1 = 11. 

Code Part :- 
permute()
ek void type ka permute fun, parameter, 1d vector arr, 2d vector ans int index. 
- ek vector banao bool typa ka jiska naam use hoga, 21 size ka. 
- ek for loop chalao i=index se i< arr.size() tak
  - if(use[arr[i]+10]==0)
    - swap kardo arr[ index] ko arr[ i] ke sath
    - permute(arr,ans,index+1)
    - phir se swap kardo
    - use[arr[i]+10] = 1 bana do.
Base Case : 
   - If index== arr.size()
      - ans.push_back(arr)
      - return ; 

Time Complexity :- 

Code Implementation :- 
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void permute(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    vector<bool> use(21, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (use[arr[i] + 10] == 0)
        {
            swap(arr[i], arr[index]);
            permute(arr, ans, index + 1);
            swap(arr[i], arr[index]);
            use[arr[i] + 10] = 1;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &arr)
{
    vector<vector<int>> ans;
    permute(arr, ans, 0);
}
```

### Ways to Sum N 
So hamko ek array diya gaya hoga jisme positive number present hoga and har number alag hoga. Aur hamko ek sum ki value diya gaya hoga. So hamko batana hai ki ham kitne tarike aisa bana sakte hai apne array se jisse sum achive  ho jaye. Here order's matters. like arr = {1,5,6} then output: {1,1,1,1,1,1,1} {1,1,5} {1,6} order matters means if we find out ans with {1,1,5} then {1,5,1} and {5,1,1} se bhi mikal sakte hai. So inko bhi count  karke answer mai dena hai. 

Recursive tree :- 
- Node: Given array , ans lenge
- Yaha ham ye kar rahe honge ki kya ham isko le sakte hai, if le sakte hai then ans ko update karo next node par bhi ham sabko le sajte hai untill sum==0 or negative. 
Note yaha ek value multiple time bhi aa sakta hai , so multiple times ham call bhi kar sakte hai. Logically ham koi position fixed nahi kar rahe hai bas apne index ko aage nahi bada rahe hai lakin swaping kar de rahe hai, conclusion hai ki ham baar baar same no. of calls kar rahe untill it reached to base case. 


Code Part :- 
way()
ek int type ka way fun, parameter: int arr as pointer, int m, int sum
- ek ans variable initially 0 se initialize kardo
- so ek for loop lenge which represent ki ham, har ek node se baar same calls kar rahe hai. so ye i=0 se i< m tak chalega. 
   - ans+= way(arr,m, sum-arr[ i]);
- return ans; 
- Base Case :
   if sum == 0 then return 1
   if sum< 0 then return 0; 

Code Implementation :- 