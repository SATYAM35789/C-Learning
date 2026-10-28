 ### Minimum size Subarray Sum :- 
Hamko array diya gaya hoga aur hamko ek target value diya hoga , Ab hamko array mai se sabse chhota size ka subArray find karo jinka sum Target ke barabar aata hai. 

Approch :- 
1. Find all the subarray
2. jinka sum greater than equal to target
3. ab inme se sabse chhote subarray ko return kardo. O(nsq)

Approch :- 
So is approch mai ham prefixSum nikalenge aur check karenge ki kya ye target se bada ya barabar hai, jab hamko milta hai toh uska size ans mai daal lenge phir check karenge ki kya aage se ek index ko chodene ke baad or window size decrese karne ke naad hamko target achive ho pa raha hai ki nahi. if yes then window size decrese karke check kar lenge nahi toh window size mai naye index ka prefix sum dekhnge or window size ko bada lenge. 
1. Window ke size ko increse karo jab tak sum, greater than equal to target n aa jaye. 
2. Answer milne ke baad window ko decrese karnege show ki minmum size ko achieve kiya ja sake. ham choot tab tak karte jab tak sum, greater than equal to target rahta hai. 

Code Part :- 
1. Ek target le lo user se input karlo, sum ko initialze kardo 0 se aur ek total lelo lo jisko IntMax se intialize kardo.
2. Agar end chhota hai n se tab tak,
   1. Sum mai sum + nums od end daalte jao.
   2. Agar sum bada ya barabar hai target se tab 
      1. total mai min(total, end-start+1) daal do
      2. Pahle sum mai se nums of start ko - kardo phir
      3. start ek kadam bada do, start++
   3. Agar aisa nahi hai, toh end ++ kardo. 

Time complexity O(n) beacuse start or dono n he cover kar rahe hai. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int total = INT_MAX, start = 0, end = 0;
    int sum = 0, n = nums.size();

    while (end < n)
    {
        sum += nums[end];

        // Window ki length ko decrese karna
        while (sum >= target)
        {
            total = min(total, end - start + 1);
            // Removing the start value or decresing window
            sum -= nums[start];
            start++;
        }

        // window ki length ko increse karna
        end++;
    }

    return total == INT_MAX ? 0 : total;
}

int main()
{
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    int result = minSubArrayLen(target, nums);

    cout << "Minimum length of subarray with sum >= " << target << " is: " << result << endl;

    return 0;
}
```

### Minimum Window Substring :- 
Hamko do sub string diya hoga s or t naam ki, hamko minimum length ki substring dhoondhna hai, S string mai jo ko t ke sare character ko include kare. means :- ki t string ke sare character S hone chahiye agar ye continous mai nahi hai toh bhi chalega, hamko uska minimum size batana hai. 
Note  :-  
1. t ke character kisi bhi order mai present ho sakte hai, sirf character hona present hona chahiye.
2. t mai jitne bhi character present hai , utne hone chahiye kam se kam Agar A 2 hai toh array kam se kam 2 hone chahiye means character ke size same hona chaiye. 

Approch :-  Brute Force Approch :- 
1. Find all substring of s
2. match it  with string t
3. If matches then inme se sabse chhote wali hamara ans ho jayega. 
Time Complexity :- 
1. Sabko doondhne mai O(nsq)
2. match karne mai O(m*n)

Note Agar kisi question mai substring ye subarray question puchhe toh window ka concept zarur use karna.

Approch :- 
prefixSum:- abhi tak visit kiye gaye character ka collection
Isme bhi ham last approch(sliding window) ka concept use karte hai, S ke sara chareter par jao aur puchho ki kya ye prefixSum hamare ans hai ya nahi. agar nahi hai toh apne window ko badate jao, if ans milta hai uska size nikal lo, aur phir decrese karna start karenge window ko(prefixSum ke first character ko remove karna) until ans exist karta hai, if exist then uska size note karlo nahi phir se window ko increse karte jao. 
1. Window ki length ko badao jab tak t ke sare char present  n ho jaye. 
2. Window ki length ko decrese karo jabtak koi bhi ek character miss n ho jaye t se. 

Understanding Working  :- 
Deko ham ek map use kar sakte hai, jisme initially ham Apne t ke sare character ko stored karwa denge , jisme character ko 1 se initiallize karenge which shows ki hamko is character ki requirement hai. Agar requirement full filled ho jati hai then ham 1 ko 0 bana denge. So ham jaise he window ko badayenge hamko check karna hoga map mai bar bar, so ham ek Total variable le lete hai jo store karega size of t ko jo hamko find karana hai jaise total , zero hoga ham pata cal jayega ki t mil chuka hai. 

So ab ham map mai t ke char ko 1 se initialize karke rakhenge aur Total size bhi , jaise mila waise he map char ko 0 bano do aur total ko ek se increse kardo. Agar aage bade samay s mai agar koi aisa character aata hai jiska present rahna zaruri nahi hai then usko -1 se se initial karke mai map mai store karenge. 
Note:- 
1. Total decrease tab hoga jab -ve number update/add nahi honga. means is samay hamko t ka char mila hai au ham 1 se 0 kar rehe honge
2. Jaise total 0 hota hai toh ham check karenge kya ans ho sakta kya iska size minimum hai.
3. Window increse tab tak hogi hab tak total 0 ke barabar nahi hota. 
Jab ham window size ko kam kar rahe hai honge us samay aagr koi character bahar jayega toh usko + 1 se update karenge. 

Note :- 
1. 0 - not requirement :-  means ki t ka ye value hamko mil chuka hai
2. 1 - requirement :- means ki t ka ye value abhi tak nahi mila hai
3. -1 :- t mai ye value present nahi hai
4. total :-  summation of all t char, which ensures ki kitne character  abhi ,t ke achive nahi hua hai. jab total zero means t achived phir ham check karenge kya hamara minimum hai, if yes than ipdate the ans if not than window ki decrese karo jo char decrese hua usko +1 se update kardo. 

Code Part :- 
1. ek unorder_map lelo char , int type ka value store karega
2. ek for loop chalao i se laker t.size tak jisme map mai t of i , ko 1 se badakar store kar lo
3. int type ka start aur end lelo jisko 0 se initailize kardo, ans mai INT_MAX daal do m index mai -1 and n mai s,size daal do
4. Jab tak end choota hai n se, tab tak
   1. m[s[end]]; increse karte samay naya value hai toh -1 se update karna hai
   2. Agar  m[s[end]] means ye t wala char hai , map ka jo last value hai agar wo bada hai 0 se then total -- kardo 
   3. Agar total 0 ho chuka hai aur start less then equal hai end ke tab
      1. Agar ans bada hai end-start +1 se tab
         1. ans mai end-start +1 ko store karlo (size store )
         2. index mai start ko daal do. 
      2. Window ke length ko decrase hogi:- m[s[strat]]++ kardo
      3. Agar map ka start bada hai 0 se then total ko increse karo
      4. start ko aage bada do , start++
   4. end ++ kardo 

Code Implementation :- 



