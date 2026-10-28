### String Matching Problem :- 
So hamko do string given hogi , so isme hamko chack karna hao secomde string present hai first string mai ki nahi as substring.and hamko us substring first character returb kareke dena hai. 

Brute Force Approch :- 
So isme ham second string, ko starting of first char se lakar jaha tak exist kare second string waha tak match  karwayenge and then if match then return the ans if not then second string se match karwo and so til jab tak possible hai. 
- if match then first and second dono ko aage badao and if not match then first ko aage badao and second ko pahle wali position par lekar jao. 

Code Part :- 
- n= heyStack.size() and m=needle.size()
- ek for loop chalao, i=0 se i< n-m
  - first = i and second = 0
  - while loop, jabtak second< m hai tabtak
    - agar heyStack[first]!= needle[second] ke then break;
    - else
      - first++
      - second++
  - agar second == m that means ki matching complete ho gai hai
    - return first-second
- return -1

Time Complexity : O(nm)

Another Approch :- 
So ab ham chahte hai ki kaha bhi hamko mismatch mila hai, means hamko pichhali baar ki tarah bar bar pichhe mat jaye like ham sirf ek kadam first aage bada rahe jis se time complexity bad rahi thi, chahe kuchh string match he kyu n hua ho time waste hoa tha. 
- Jaha tak apne string ko visit kar chuke hai, waha se hamko check karna hoga ki kya koi portion hai jo hamare words se match ho rha hai, so Jis string mai search ho rha hai, ye possible hai ki agar uska koi portion match ho raha hai toh wo prefix ho sakta hai second string ka. Or If match ho raha hai toh same word second string mai he uska Longest prefix and suffix exist karega (LPS table). 
- So lps table ham second string ka bana rahe honge. Aur table kaise banta hai we study in the last lecture.
  - jaha misMatch hua hai, uske just pichh wale mai jao aur jo usme value hai ab usko point karne lago if equal hai then first and second dono ko aage bada do. Ayr jaise he second string khatam hogi, we got our answer. 
Note: LPS table simply contains the count of matched prifix and suffix till that position on the same string. 
Time Complexity : O(n+m) 
O(m) : For making the lps
O(n) : for string matching

Code Part :- 
LPS Finding of the niddle(second) named string
- ek int type ka vector banayenge, lps naam ka, jiska size = niddle.size(), initially 0 se intiallized hoga.
-lpsFind(lps,needle);
- int type ka first =0 and second =0 
- ek while loop, tabtak jab second is lessthen needle.size() and first is lessthen heystack.size()
  - agar needle[second] == heystack[first] then
    - first++ 
    - second++
  - else 
    - if second == 0 hai then
      - first++
    - else 
       second = lps[second - 1]
- if second==needle.size means ki agar second pahuch gaya hoga needle.size ke barabar then
    return first-second
- else 
   return-1; 

Code Implementation 
```cpp
#include <iostream>
#include <vector>
using namespace std;

void lpsfind(vector<int> &lps, string s)
{
    vector<int> lps(s.size(), 0);
    int pre = 0, suf = 1;

    while (suf < s.size())
    {
        // Matched
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            suf++;
            pre++;
        }
        //  Not matched
        else
        {
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
}

int firstOccarnce(string heystack, string needle)
{
    vector<int> lps(needle.size(), 0);
    lpsfind(lps, needle);

    int first = 0, second = 0;

    while (first < heystack.size() && second < needle.size())
    {
        // Dono charater match
        if(heystack[first]==needle[second])
        first++, second++;

        // Dono charater not-match
        else
        {
            if(second==0)
            first++;
            else
            second=lps[second-1];
        }
    }

    // Answer exist
    if(second==needle.size())
    return first - second;
    else
    return -1;
}
```