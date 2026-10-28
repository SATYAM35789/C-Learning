### Zero sum subarray :- 
Hamko ek array diya hoga jo positive and negative , dono number ko hold kar sakta hai So hamko ye batana hai ki isme kitne subarray ho sakte hai jinka sum zero aa raha hai. or total no of subarray batao jinka sum 0 ho. Where subarray is a continous flow elements. 
Approch 1: Brute Force Method :-
Is approch mai ham kosis kar rahe hote sare possible subarray ko find karte hai jo hamara ans ho sakta hai, so ham i and j iterator le lenge i ko fixed kardo , phir j ko next se and end tak compair karke check karenge ki kya abhi tak j ka sum, i ke position ke barabar hai ki nahi .
End par pahuchne ke baad ya ans milne ke baad , phir i ko bada do phir iske next se compairsion karo and so on. 

Code part :- 
1. Ek int type ka total lelo, aur isko 0 se initialize kardo. 
2. Ek for loop le lo jo i se laker n tak chalega.
3. Ek for loop le lo jo chalega j =1 se laker n tak.
4. ek int type sum varaible jisko 0 se initialize kardo
5. ek for loop le lo jo k = i se laker k=j tak chalega
   1. sum mai sum + arr of k ki value daalte jao
6. Agar sum == 0 , aa jaye tab total ko ek se bada do. 

Time Complexity : O(ncub)

Approch 2
Code part :- 
1. Ek int type ka total lelo, aur isko 0 se initialize kardo. 
2. Ek for loop le lo jo i se laker n tak chalega.
3. ek int type sum varaible jisko 0 se initialize kardo
4. Ek for loop le lo jo chalega j =1 se laker n tak.
5. sum mai sum + arr of k ki value daalte jao
6. Agar sum == 0 , aa jaye tab total ko ek se bada do. 

Time Complexity:- O(nsq)

Approch 3 :-  Try to solve the problem order of n time. Aage pichhe aane ko no option jaha hai wahi se solution paane ki kosis karni padegi. 
Here we used the concept of prifix sum. Where prifix sum means that starting se abhi tak sum kitna hai. 
So ham isme apne starting index ke value se start karte hai aur uske next ko add karke value store kar lete hai then uske next ko apne stored value mai add kardo usko store karlo and so on till the element exist. 

Agar prefixSum agar koi value do alag position par same aa raha hai means ki second position  ke pahle ham jo bhi operation kar rahe hai us se hamare ans par koi fark nahi pad raha hai. So we can conclude from here that unke bich ka summation zero tha tabhi toh balue same mil rahai. 

So ham prifix sum ko pakdenge aur check karenge kya ye pahle aaya hai, if aaya hai then total(count) ko ek se bada do. if not then check for another prifix sum value. 
So jab bhi prifixSum nikalte hai tab ham check kar lenge li kya ye prifix sum iske pahle bhi aaya hai. 
Edge case: agar prifixSum , zero aa jata hai then aur agar check karne ke baad koi zero nahi milta tb ham apne total ko ek se badayenge. 

So hamko kaise check karenge or store kaise karenge ki apni value wapas compair kar paye ki jo present prefixSum hai wo pahle bhi aaya hai ki nahi ? And if aaya hai then kitni baar aaya hai?
Iske liye STL use kate hai, map ko use karlo. 
map< int,int>m;  :- one int for prifix sum and another int for count ki wo kitni baar aaya hai. 
- It store the value in key-value pair. 
- hamko apne edge case ko pahle daalna kyuki jab ham array mai koi element le he nahi rahe hai then means 0 hai. 

map take logn time to search.
  - ye sorted form mai data ko de deta hai
unOrdered_map take constant time on average case while serach. 
  - insertion and serach 

Code Implementation :- 
```
  // You can win a lot in life , if you are the last one to give up.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long int findSubarray(vector<long long int> &arr, int n)
{
    long long int total = 0; // Total no. of subarray , jiska sum 0 hai
    // Map : prifixSum , count
    unordered_map<long long int, long long int> m;
    long long int PrefixSum = 0;

    // Initailize by (0,1) :-  In case agar koi element nahi hai, toh means unka sum 0 hai
    // Value insert in map :- m[0] = 1;
    m[0] = 1;

    for (int i = 0; i < n; i++)
    {
        PrefixSum += arr[i];
        if (m.count(PrefixSum))
        {
            total += m[PrefixSum];  // count of prefixsum ko total mai add kardo
            m[PrefixSum]++;   // prefixSum ke count ko ek se increment kardo. 
        }
        else
        {
            m[PrefixSum] = 1;
        }
    }
    return total;
}
// Unorsered Map :- It helps to customised the index means ki ham apne according index set kar sakte hai.

int main() {
    // Example test case
    vector<long long int> arr = {0, 0, 5, 5, 0, 0};
    int n = arr.size();

    long long int result = findSubarray(arr, n);

    cout << "Total subarrays with sum 0: " << result << endl;
 
    return 0;
}
```

### Subarray Sum equals k
Is question mai hamko wo subarray find karna hai jiska sum k ke barabar aa raha hai. 
Approch 1:- Brute force Method : Same as we discussed it above but this time compair with k not with 0. 

Approch 2 :- Optimized : Using PrifixSum
Yaha par ham ye nahi find kar sakte ki, agar do prifixSum sam ho rahe hai toh apne count ko bada the ki hamko ek subarray mil gaya kyuki in same value ke difference ka sum 0 hai, ye k ke barabar nahi hai. So ham is tarah subarray nahi find kar sakte. 
Ab ham subarray is tarah find karenge, ki jo hamara prifixSum - k ka difference exist karta hai ki nahi if yes then count ko bada do if not then add it go for another one. 
Initially 0,1 ko initialize kar denge as agar koi element nahi hai then , sum =0 hoga on that case.  

