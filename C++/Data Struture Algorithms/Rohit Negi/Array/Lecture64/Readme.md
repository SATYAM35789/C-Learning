### Permutation of Arrays and Strings :- 
So hamko ek array diya gaya hoga , aur hamko uske permutation print karwaane hai. like arr = {1,2,4} then {1,2,3} {1,3,2} {2,3,1} {2,1,3}, {3,1,2} {3,2,1}. And the value present in the array are distinct. 
- So we know that we have three no then there will 3!=6 permutation banenge. 

So we need the pattern by which we can solve any of the permutation. So how we going to create or find that pattern :- 
- So hamare pass is example (_ _ _)3 places hai jaha value aa sakte hai. So 1st place par 3 element aa sakte hai, 2nd 2 element aa sakte hai, and 1 place par ek he aa salta hai i.e 1st place par n value aa sakti hai, 2nd place par n-1 and 3rd place par n-2 values aa sakti hai. 
- So ham ye dekh rahe hai ek place par kon kon se number aa sakte hai, if us place koi number choose ar liye hai toh wo dobara nahi aa sakta , same next place check kar rahe hai. 
- We need to track the value ki ye number aaya hai ki nahi. 

Recursion Tree :- 
Node: Ek given array aur ek empty array initially
- So yaha hum 1st place par kon kon sa value aa sakta hai sabke liye fun call or node banayenge aur sath mai ye bhi track karenge ki us place konsi value present hai. So iske baad next place ke liye check karenge ki kon kon value aa sakta hai. 

Code Part :- 
Requirement :
arr : given array jiska permutation hamko nikalna hai
temp : array jo store karega ki konsa number include kiya hai ki nahi
visited : ye ek bool typa ka array hai jo batayega ki particular number number hamare temp ka part hai ki nahi. 
ans : ek 2d array jo ki temp ko store karega so ki ham answer print karwa paaye 

permute()
- ek for loop le lo jisme i=0 se i< visited.size() tak chalega. 
  - Agar visited[i]==0 then
    - visited[i] = 1 kardo
    - temp.push_back(arr[i])
    - permute(arr,ans,temp, visited)
    - Hamko apne visited ko wapas se 0 karna hoga nahi toh next call mai privieous place waali value pass ho jayegi. and temp mai se value ko popback karna hoga as temp is passed as refernce. i.e visited[i]=0 ,temp.pop_back()
- Base Case :-
  - if visited.size()== temp.size() then 
    - ans.push_back(temp)
    - return; 

Time Complexity :- 
- total no. of execution in the function is = n 
- total node n!
-> nn! => O(nn!)

Space Complexity :- 
O(n)

Code Implementation :- 
```cpp
#include <iostream>
#include <vector>
using namespace std;

void permut(int arr[], vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited)
{
    if(visited.size()==temp.size())
    {
        ans.push_back(temp);
        return ;
    }

    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==0)
        {
            visited[i] =1;
            temp.push_back(arr[i]);
            permut(arr,ans,temp,visited);

            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main()
{ 
    int arr[] = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(3,0);

    permut(arr,ans,temp,visited);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" "; 
        cout<<endl;
    }
}
```

=> Condtion : So ab hamko extra space temp or visited array ka use nahi kar sakte hai, ab is case mai find karke do :- 
- So in recursive tree we can say that ki har ek level ek position fixed ho jati hai. Similarly with visited too that har ek level ek visited ho jata hai. 
- so hamko arr mai he directly change karne honge, So jo bhi element aata hai level (place) mai then we say ki us element ki position fixed ho gayi hai and left element of arr are remain unvisited. 
- Note : Hamko pata hai ki ek place par different values aa sakti hai, then similarily level = place(position) and different value = nodes in that level. 
logic : Yaha swap karenge position fixed rahega. 
- Jis index par hai usko aur uske next wale ko he swap karenge kyuki uske pahle wale ki position fixed hai jo value (index pahle) hai wahi rahegi
Note : Swap same position same position ke sath bhi karenge as jo index par present hai wo bhi aa sakti hai us place par. 

Code part :- 
ek void typa ka permute function, parameter : vector< int> &arr , 2d vector ans, int index
 - ek for loop chalayenge, i=index se i< arr.size() tak
 - swap(arr[ i],arr[ index])
 - permute(arr,ans,index+1)
 - phir se pahle wale position mai daal do i.e swap(arr[ i], arr[ index])
Base case : same

Code Implementation :- 
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void permut(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if(arr.size()==index)
    {
        ans.push_back(arr);
        return ;
    }

    for(int i=0;i<arr.size();i++)
    {
        swap(arr[i],arr[index]);
        permut(arr,ans,index+1);
        swap(arr[i],arr[index]);

    }
}

int main()
{ 
    vector<int> arr(3);
    cout<<"Enter the element in array";
    for(int i=0;i<3;i++)
    cin>>arr[i];

    vector<vector<int>> ans;

    permut(arr,ans,0);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" "; 
        cout<<endl;
    }
}
```