### SubArray Sums Divisible by k :-
So Ye question bol raha hai ki total kitne subarray hai , jinka agar hum sum kare toh wo divide ho pa raha hai k se. 
1. Approch :- Brute Force method :- O(nsq)
Find the all the subarray, phir unks dum find karo, then Divide karo k se if ho ja raha hai then count ko bada do.

2. Approch second :-  PrefixSum - Remainder based
Is question mai prefixSum ko calculate karenge aur check karenge ki kya prifixSum minus any no. divisible by k is present in the array or not like if k =7 then (prefixSum - 7,14,21,28, etc). 
Lakin ham kab tak check karte rahenge, means hamko kab rukna hai check karna. So iske liye hamko pata hai ki jo no, 7 se divisible hai unka remainder zero jo same hota hai unse jo divisible hai 7 se. kuchh no aise bhi ho sakte hai jinka remainder 1 or 2 or 3 etc. Agar hamko  prefixSum milte hai jinka remainder same aa raha hai toh Agar present prefixSum jiska prefixSum ka remainder same ho agar uska difference nikalte hai toh wo divisible k se hoga. 
If array mai -ve or +ve dono value diya hai , then prefixSum bhi -ve or +ve ho sakte hai then agar -ve ka remainder nikalenge toh kya aayega is case mai wo different compiler based hota hai wo kya answer dega ki -3/7 = -3, +4. Cout karke check kar lenge. 
Different way to represent the number :- 
   1. -3 : 7*0 = -3 -> remainder
      -3 : 7*-1 = +4
Note :- Jab prefixSum ka remainder -ve aa raha hai usko bhi +ve mai stare karwayenge by adding the k in the negative. 


Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    unordered_map<int, int> m; // remainder with their count
    m[0] = 1;
    int prefixSum = 0, rem, total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        rem = prefixSum % k;

        if (rem < 0) // If remainder -ve aata hai
            rem = k + rem;

        if (m.count(rem))
        {
            total += m[rem];
            m[rem]++;
        }
        else
            m[rem] = 1;
    }

    return total;
}
int main()
{
    int n, k;

    cout << "Array ka size (n) enter karein: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Array ke elements enter karein: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Divisor (k) enter karein: ";
    cin >> k;

    int result = subarraysDivByK(nums, k);
    cout << "Total subarrays divisible by " << k << " are: " << result << endl;

    return 0;
}
```

### Subarray Product less than k :-
So is question mai hamko Ek array diya hoga jisme hamko find karna hai wo sabArray jiska product k ke se less than aa raha hai, uska count batana hai aise kitne subArray possible hai. 

Brute Force Approch:-
1. Find All subarray
2. product find karo
3. And check if product < k then count ko ++ kardo. 

This approch take O(nsq)

Approch 2nd :- 
Ab tak jaise kar rahe the wahi approch laga kar dekhte hai, prefixSum as hamko koi fayda n ho kyuki ye toh product puchha hai, lets's see :-  So yaha ham preMultiplier method laga rahe hai, this is not good method as it give the int overflow or long long overflow too. 

So jab ham product nikal rahe honge using preMultiplier tab ham check kar rahe honge kya product k se chhota hai if then go for the next element product, but if product bada aata hai then ham apne window ko chhota karna start kar denge. 
Jab ham product mai next element ka product nikal rahe honge tab ham ye bhi dhyan rakhenege ki agar unka product chhota hai then ham jitne abhi tak ka size hai subarray ka utne se size ko badayenge. because agar product k se chhota hai , toh element singly bhi toh chhota he hoga and aur bhi combination's ban sakte hai.
Do jab product bada aa jaye k se then ? (subarray ko chhota karna)
then ham subarray ke 1st element ko remove kar denge aur apne product ko us element se dive kar denge then phir check kar lenge ki k chhota hai or bada. 

Note :- Apne subarray ke size badate rahne when product is smaller than k and vice-versa when k is bigger than product. 

Code Implementation :- 
```

```