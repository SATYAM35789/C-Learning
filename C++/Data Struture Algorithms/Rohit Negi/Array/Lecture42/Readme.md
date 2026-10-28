## KMP Algorithum : One of the hardest Algo in the DSA. 
Before going to the algo we are going to study below problem. 

### Longest Prefix Suffix :- 
Ek string diya hoga aur hamko bolega ki uska longest suffix and prefix kya ho  hoga, so pahle toh ye equal hane chahiye aur hamko in length lakar deni hai. 
prefix :- Starting se char se abhi tak
suffix : eEnd char se laker abhi tak
Condition: Ki prefix equal to suffix hone chahiye as charcter and length both wise. like A A, AA  AA ->possible , AAC CAA ->possible.
Last wala case nahi lena hai as lenge toh wo toh barabar he aayenge. like AACAA AACAA . So prefix mai purra string nahi lena hai and suffix mai bhi purra string nahi lena hai. 

Brute Force Approch :- 
Saare possible Prefix ko find out karenge and then saare suffix ko find out karenge O(nsq). Similarly saare possible suffix ko O(nsq). So ab check karenge ki jo bhi prefix and suffix nikale the if they are equal(parallely) like 1 then 2 then 3 then 4 and so on character wala. If equal then unki len ko note karlo.Compairsion->O(nsq).
- Do string ko match ho raha hai ki nahi , s1 and s2 ko directly (s1==s2) ko compair karke bata dega. 
  Time Complexity : n= size of s1 and m= size of s2 then time complexity -> O(min(n,m))

Another Approch : O(nsq)
Agar answer possible hai unka prefix barabar hoga suffix ke usme pahle character to same he rahne wala hai. So do pointer banayenge Pre and suf. Starting mai jo bhi character hoga usko ye dono pointer point kar raha hoga, so if character mila then same character ko khojenge bache hua portion mai string ke. 
If match found then pre and suf dono ek kadam aage badao and phir se match check karo, so if suffix khatam ho jaaye then hamko pata chal jayega ki itne he length ka answer possible ho sakta hai. 
- so agar prefix exist karta hoga toh prefix toh fixed hai ki wo starting char se he start hoga so sabse pahle wale character zarur le raha hoga. 

-> Agar mismatch(pre and suf ka) string aati hai then longest ko achieve karne pre ko phine se start of char se start karna hoga. And suf ko phirse update kare  ki last wali position se he start kare.
-> So hamko  toh pata hai ki, hamara prefix Starting char se start hoga so jaha jaha start char hai wahase compairsion karte hai.-> Example : AAAAD -> same concept lageyenge toh is case mai answer nahi milega.
Time Complexity : O(nsq)  -> Mismatch ke case mai aur bhi possibilty ko find kar rahe hai. 

### Another approch :- LPS
LPS table or array banane ka logic :- 
So hamko ek string diya hoga, so ham isme ek table ko fill karenge. So jitna string ka size hoga utne size ka array for karenge. The value of array batayega ki waha tak ka longest prefix and suffix kitna hai. Single element hai tab longest prefix and suffix 0 hoga kyuki wo puri string ko nahi le sakte, ab jab do element lenge tab prefix and suffix possible ho sakte hai 1 length ka but uske liye we need ki prefix suffix equal ho if not equal then 0 lenge as value in the aaray and so on. 

Code Part : to fill the array :- 
- jisko bhi prefix point kar raha hai usme +1 kareke, suffix li position par likh do. 
- Prefix and suffix initially 0 he honge, suffix ek ek karke aage badaga aur prifix kisko point kar raha hoga usko khoj raha hoga if match found then suffix mai prefix ka index+1 karke suffix mai store kardo, if again match found then pre++ and suf++ kardo and so on if not found then prefix starting of string ko point kar raha hoga and suffix ++ karte rahenge. 
  - Not match ke case mai problem aa sakti hai ki koi prefix and suffix match ho sakta hai jo substring ho main prefixSubstring ka like Prefix (s1): ABCABDABC suffix(s2): CBACBADBACBA this two are mismatch but part pre and suf are matched like  ABC = ABC (1st three are same as suffix(isko ulta likhte hai) : start from pahle C then B then A).
  - so ab mismatch mai ke case mai jis bhi character par mismatch aaya hai, us charcter ko prefix pointer se backside mai jakar khojenge if milega then ab prefix pointer pahuch jayega, waha se hamko prefix suffix ko match nahi karwana hai, bas ek ek kadam piche karenge aur charcter ko match karenge ki kya ye same hai. 
  - Longest prefix of s1 should equal to the longest suffix of s2. If got then add 1 ans store in the table

Note: If prefix and suffix are equal then ham sirf ek string mai na khoj de ki uska longest prefix wale string ko lete hai. Wo kitna hai wo hamne pahle he note karke rakha hai table mai. Value stored bata raha hai ki us index par jao, uske pahle wale utne no of char are same(utne no uske pichw matched hai)

Prefix working after misMatch :- jaha bhi misMatch hua hai prefix and suffix waha par prefix ko, just uska pahle wale index mai jo bhi value hai us index par point karwa do if 0 hai then uske pahle wale par jao and again try to find mismatch if not then so on karo if uski pahle wali valu exist nahi karti then 0 likh do suffix ki position par. Ab iske baad pahle jaise chalte raho. 

Time And Space Complexity : O(n)

Code Part :- 
- ek int type ka vector lenge, lps naam ka jiska size s.size hoga aur isko 0 se intialize kar denge.
- int type ka pre=0 and suf =1 initially. 
- while loop chalayenge aur jab tak suffix chhota hai s.size se tabtak
  - if(s[pre]==s[suf])
     - lps[suf] = pre+1 ; 
     - pre++
     - suf++
  - else
      - if(pre==0)
        - lps[suf] =0;
        - suf++
      - else  
        - pre = lps[pre-1]  : lps of pre jaha uske ek pahle wale index mai jo value hai waha chale jao.
- return lps[s.size()-1] :- last value mai jo usko as answer pass kar do. 

Code Implementation :- 
```cpp
#include <iostream>
#include <vector>
using namespace std;

int lps(string s)
{
    vector <int> lps(s.size(),0);
    int pre=0, suf=1;

    while (suf<s.size())
    {
        // Matched
        if(s[pre]==s[suf])
        {
            lps[suf]= pre+1;
            suf++;
            pre++;
        }
        //  Not matched  
        else
        {
            if(pre==0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre-1];
            }

        } 
    }
    return lps[s.size()-1];
    
}
```
