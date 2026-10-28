### Slidding Window Maximum :- 
Har ek window mai batana hai ki usme maximum number kya hone wala hai, with size of k. Usko ek array ki form mai return karwa denge. 
Approch Brute force Approch:- 
 1. Ek vector bana lo ans naam ka. 
 2. Ek for loop chalayenge i zero se laker n-k tak.
    1. ek int type ka variable, INT_MIN naam ka
    2. ek for loop jo j i se laker i+k tak chalega.
       1. total ke ander max() : parameter total, nums[j] daal do
    3. ans mai push_back kardo total ko. 

Time Complexity :- O(nk)
Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n - k; i++)
    {
        int total = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            total = max(total, nums[j]);
        }
        ans.push_back(total);
    }
    return ans;
}
```
2nd Approch :- 
Agar k mai se maximum element hamko order(1) mai la sakte hai tabhi means jo sabse bada hai usko sabse aage kardo kaise chhote wale ko uske aage remove karke, tab jakar O(k) reduce O(1) mai. 
Ab iske baad First maximum ke baad jo bhi element hai usse se just wo second max ho jayega, Agar ab koi dusra element aata hai wo chhota hai abhi tak ke element se tab 3rd max ho sakta hai, agar aane wala elemeny bada hai queue ke elements se tab uske chhote wale ko remove kardenge kyuki ab wo element kabhi bada nahi ho sakta. Jo window size ke bahar ja sakte hai usko remove kardo. 

Note :  ham indexes ko store karenge. Apne queue mai to maintain the window. i-k = result. result aur usse chhote wale ko pop kardo. 

Approch:-
1. pop back the smaller element.
2. front wala window se bahar toh pop kardo
3. update your ans
Code Part :- 
1. ek deque bana lo d naam ka aur ek vector ans naam ka. 
2. Ek for loop chalayenge i zero se lakar k-1 tak. jisme
   1. Agar deque khali hai toh, d mai i ko push_back kar denge. 
   2. Agar element hai deque mai tab
     1. Agar deque empty nahi hai aur nums of i bada hai nums of d.back() se tab d.pop_back() karte jao.
     2. Agar aisa nahi hai toh, deque mai i ko push_back kardo.
3. ek for loop chalayenge k-1 se laker i< n tak,
   1. Agar deque empty nahi hai aur nums of i bada hai nums of d.back() se tab d.pop_back() karte jao.
   2. Agar aisa nahi hai toh, deque mai i ko push_back kardo.
   3. Agar deque ka front chhota hai i-k se tab deque mai popfront kardo.
   4. ans mai push_back kardo nums of d.front ko. 
4. return ans.

Note d.front() <= i - k: Yeh line sabse critical hai. Yeh ensure karti hai ki jo element window se bahar nikal chuka hai, wo deque ke front mein na bacha rahe.
Indices vs Values: Aapne deque mein indices store kiye hain, jo ki best practice hai. Isse "out of window" check karna aasaan ho jata hai.

Time Complexity :- O(n)

Code Implementation :- 
```
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> d;
    vector<int> ans;
    int n = nums.size();

    // k-1 element ko traverse karo
    for (int i = 0; i < k - 1; i++)
    {
        if (d.empty())
            d.push_back(i);
        else
        {
            while (!d.empty() && nums[i] > nums[d.back()])
                d.pop_back();

            d.push_back(i);
        }
    }
    //  k-1 se laker n-1 tak traverse karo
    for (int i = k - 1; i < n; i++)
    {
        // Remove the smaller element from the last
        while (!d.empty() && nums[i] > nums[d.back()])
            d.pop_back();

        d.push_back(i);
        // if front element is outside the window than pop it.
        if (d.front() <= i - k)
            d.pop_front();
        //  Find ans
        ans.push_back(nums[d.front()]);
    }
    return ans;
}
```

### Minimum Number of K consecutive flip bits :- 
Hmako ek array given hoga jisme 0 aur 1 element present honge, Hamko k size ka subarray lena hoga aur isme jo bhi value present hai unko flip karna hoga (flip karna means 1 mai convert karna). And we have to do the minimum no. of flip.  
Approch :- Brute Force Approch:-
Given array ko traverse karna start karenge, aue ke subaarry bana lenge k size jiske ander chack karenge if 0 than convert it into the 1 and 1 ko 0 mai convert kardo. Agar 1 present hai given array aur modified array mai to usko convert nahi karenge. 
Approch:-
1. sabse pahle 0 ko khozo
2. mil gaya tab, k size ka subarry le lo (0 position to size k tak) and do conversion procedure. 
3. -1 kab return hoga, jab hamare pass zero aur ab sub array nahi ban sakti tab. 

Code Part :- 
1. ek int lelo flip=0; naam ka. 
2. ek for loop chalayenge 0 se n tak
   1. Agar nums[i] barabar hai 0 ke, then 
     1. Agar i+k-1 >=n then return kardo -1 ko. 
     2. Ek for loop chalayenge jo j=i se chalega i+k-1 tak
        1. num of j barbar nahi hai nums of j ke
        2. flip ++ kar do
3. return ans

Time Commplexity :- O(nk)

Code Implementation :-
```
 int minBitKFlips(vector<int> &nums, int k)
{
    int flip = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            // if window doesnot exist
            if (i + k - 1 > n)
                return -1;
            // if window exist
            for (int j = i; j <= i + k - 1; j++)
            {
                nums[j] != nums[j];  // agar sabarray mai 1 hai toh usko waise he chod do.
            }
            flip++;
        }
    }
    return flip;
}
```

2nd Approch:- 
Jitna given array ka size utna ka array bana lenge aur usko 0 se initialize kardenge. Aur ab window ke size ke itna apne array ko 1 kar denege jisko initialize kar denge. Ab next jab given array mai agar 0  aata hai tab ab check karenge 1 hai flip array mai, tab ab change nahi karege. 
Note:- Har window  mai agar 0 milta hai , hai toh us sabArray mai flip kardo. 
if 1 = no of odd than 0. If 1 = no of even then 1.
If 0 = no. of odd than 1. If 0= no of even than 0. 

Time Complexity :- O(nk)

3rd Approch 
Jab bhi traverse karte hai agar hamko 0 milega,  tab us window ki kth poition tak ki index ko store kar lenge. No of flip = No of size of queue . 
Code part:- 
1. Ek queue le lenge int type ka aur ek int le lenge flip=0. 
2. ek loop le lenge jo i zero se n tak cahlega. 
   1. Agar queue empty nahi hai aur queue ka front chhota hai i then queue ko pop kardo. 
   2. Agar q.size()%2 barabar hai nums[i] ke (q.size means flip kitne baar hua hai. %2 means even or odd find karna) 
   3. queue ke ander kth position of that index ko daal do. 
   4. flip++ kar do. 
   Edge case:- Agar i+k-1 bada hai n se toh -1 return kardo. 

3. Return kardo flip  ko. 

Code Implementation :- 
