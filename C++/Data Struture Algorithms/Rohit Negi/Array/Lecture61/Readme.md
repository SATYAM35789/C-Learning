### Recusrion on subsquence :- 
So here we study the subsequence based question and try to find out the solution using the recursion. 

### Print all subsequence or subsets :- 
So hamko ek array diya gaya hoga and we have to print the all subsequence of the array. Subsequence or powerset, so isme ham saare element ke combination karke ke likhte hai it may be continous and nonContinous. like :- 1,2,3 :-  {{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3},{}}
- So isme dekhte hai ki ye kaise generate hua hoga , {1,2} : Iske liye ham apne given sequence mai 1 ko select kiya hai and 2 ko bhi select kiye hai lakin 3 ko select nahi kiye hai and aur bhi jo set hai wo bhi aise kuchh generate hue honge.
- Total no of subsequence : 2^n where n is the no of element in the sequence. 
  - Iska matlab hai ki har ek element ka pass do option hai ya le le ya mat le. 
  - 000 ,001, 010,011, so on , ye represent kar rahe hai kisko liya hai kisko nahi if liye hai then us se kya form ho raha hai.
  - 000 : means tin element hai hamare pass aur hamne ek bhi nahi liya -> {}

Recursive tree banao :- 
- Node : So isme ham ek sequence  ko lenge like 1,2,3 aur ek empty array jo represent karega ki agar koi element pick kiya hai then wo isme chala jayega
- so ab ek ek karke traverse karo, if taken then uska alag branch(node) if not taken then uska alag branch(node). 
- So jab ham last mai pahuch jeyenge tab ham ruk jayenge on every branch. 

Note : So recursive tree ka leaf node hamara answer de raha hoga. 

Code Part :- 
Requirement :- 
- arr[]: So ye sequence hai jiska hamko sabsubsequence nikalna hai.
- 2d vector ans :  jaya ham saare 1d form mai stored data ko store karwa rahe honge
- 1d vector temp : jaha ham apne element ko store karwa rahe honge ki wo sequence ka part hai i nahi
- index : so ki hamko pata chale ki abhi tak ham kaha aur kisko lena hai aur kisko nahi

subseq() 
- ek subSeq naam ka function, parameter int arr as pointer, int index, int n, vector< vector< int>> &ans , vector< int> temp. 
- if subSeq mai value nahi le rahe hai then simply index+1 karke call kardo i.e subSeq(arr, index+1, n, ans,temp)
- if lete hai index ko then
   - pahle usko temp mai store karwa lo, i.e temp.pushback(arr[ index])
   - Ab next waale ke liye call kardo(particular index ko lena hai ki nahi) i.e subSeq(arr,index+1,n,ans,temp)
- Base : So jab index== n then 
   - ans.push_back(temp)
   - return 

Note We can do dry run to understand the code. 

Time Complexity :- 
- Sabke liye constant time lag raha hai So total no of node ko count karlo then which is time complexity of the code
- 2^(n+1) -1 => O(2^n)

Space Complexity :- 
- ans ke ander saare sequence store honge and total no of sequence hai 2^n and the size of sequence ko worst case mai n maan lo
- temp baar baar create hoga
- O((2^n) * n) + nseq -> O((2^n) * n)


Code Implementation :- 
```cpp
#include <iostream>
#include <vector>
using namespace std;

void subSequence(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> temp)
{
    // Base Case
    if(index==n)
    {
        ans.push_back(temp);
        return ;
    }

    //  Not Include
    subSequence(arr,index+1,n,ans,temp);
    // Include
    temp.push_back(arr[index]);
    subSequence(arr,index+1,n,ans,temp);
}

int main()
{
    int arr[] = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    subSequence(arr,0,3,ans,temp);

    // Print the ans array
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";

        cout<<endl;
    }

}
```
Abhi iski space complexity O(nsq) are rahi hai isko ham kam kar sakte as bu pass int the temp as reference.
- so jab ham reference mai pass karenge toh temp ko pop bhi karna hoga after include and not inclue. i.e, temp.pop_back();
- So isme temp toh har ek call ke same he hai so temp ko khali karna hoga for the other node or function ki uski value note ho paaye temp mai
```cpp
void subSequence(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> &temp)
{
    // Base Case
    if(index==n)
    {
        ans.push_back(temp);
        return ;
    }

    subSequence(arr,index+1,n,ans,temp);
    temp.push_back(arr[index]);
    subSequence(arr,index+1,n,ans,temp);
    temp.pop_back();
}
```

Space Complexity : O(n)
Maximum height -> n
temp maximum -> n

###  String ka subsequence
Sp isme hamko string diya gaya hoga aur hamko bolega ki iska saare subsquence print karke bata do. Toh yaha bhi ham same logic use karenge, on each charater wo go and ask for ki isko lena hai ki nahi lena hai for making the part of the subsquence.

Code Implementation :- 
```cpp
#include <iostream>
#include <vector>
using namespace std;

void subSet(string s, int index, int n, vector<string> &ans, string temp)
{
    // Base Case
    if(index==n)
    {
        ans.push_back(temp);
        return ;
    }

    //  Not Include
    subSet(s,index+1,n,ans,temp);
    // Include
    temp.push_back(s[index]);
    subSet(s,index+1,n,ans,temp);

    //  Temp ko khali kardo return hone ke baad
    temp.pop_back();
}

int main()
{
    string s = "abc";
    vector<string> ans;
    string temp;
    subSet(s,0,s.size(),ans,temp);

    // Print the ans array
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;

}
```

### Generate Parentheses 
So hamko isme n diya hoga aur bolega ki n number ke liye valid parentheses do, like n=2 ke liye (()) or ()(). 
Approch (logic building):- 
- '(' -> left and ')' -> right so hamko pata hai ki no of left is always equal to the no. of right. So if n=3 hai then total 6 character hamare pass aayenge 3 for left and 3 for right. 
- So agar ek bhi right wale pahle aa jata hai then n=3 ke liye bhi kabhi valid string nahi ban payega So we can conclude that ki jab tak left wale nahi aa jata tab tak right wala nahi aa sakta hai. 

- no. of opening bracket is always greathen equal to no of closing bracket => if ye condition fails means ki no of closing bracket jayada hai then ham kab bhi valid parentheses nahi bana sakte hai. 

Recursion tree :- 
Ek example lo aur us se apna recursion tree banao jisme n,l,r ki intial value given hai. like n=3, l and r = 0. 
- So yaha ham ye nahi kar sakte hai particular position par do option hai hamare pass like ya toh left ya toh right, so right toh ham kebhi nahi lenge is we do so that will be generating invalid parenthesis. So ye sirf first node ke liye karenge.
- 2nd node ke baad toh right aa sakta hai as valid parentheses bhi toh banana hai. 
- We got the ans as leaf node. 

Code Part :- 
parentheses()
- Ek parentheses naam ka fun bana lo, parameter : int n, int left, int right, vector< string> &ans, string &temp.
- Left parenthesis Add karo
  - Agar left chhota hai n se then 
    - temp.push_back() kardo '(' ko
    - call karo parentheses ko jisme left+1 ho gaya hai i.e parentheses(n,left+1,right,ans.temp)
    - temp ko pop back() kardo as temp is refernce variable
- Right parentheses ko add karo
  - else if : agar right chhota hai left se then 
    - temp.push_back() kardo ')' ko
    - call karo parentheses ko jisme right+1 ho gaya hai i.e parentheses(n,left,right+1,ans.temp)
    - temp ko pop back() kardo as temp is refernce variable 
Base Case :- 
- left + right == 2*n
  -ans.push_back(temp)
  -return;

Time Complexity : O(2^n)

Code Implementation :- 
```cpp

```