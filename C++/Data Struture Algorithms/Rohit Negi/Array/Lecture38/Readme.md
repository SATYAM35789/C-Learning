### Longest Palindrome :- 
So hamko string diya hoga, usme hamko character ko choose karna hai aur sabse bada palindeome jo us string ke character ko bana paa rahe uske  size ko as an answer dena hai.like abaccb => abccba 

Approch :- 
Palidrome pattern :- So start and last wala character same hona chahiye and then 2nd and last 2nd same hona chahiye and dono pointer ek ko he point kar rahe hai then its means ki wo same hai.

So simplly karna ye hai ki check karo ham jis bhi character mai hai kya wo string(us char ke aage wale) mai present hai, if yes then make it part of the string and if not then go and check next char.
- Is procedure ke hone ke baad bache hua jo palindrome ka part nahi hai usme se koi bhi ek char ko ham bich mai likh sakte hai, and wo bhi palindrome ka part hoga. 

Conclusion :- 
like naman - a: even, n=even and mid(m): odd
- so koi bhi character agar wo even no. of time present hai, then wo direct palindrome ka part ho jayega.
- if the char is odd no of time hai then usme jitna bhi even ho sakta hai wo direct aa jayega 1 jo bachega wo mid ke liye as cndidate ban jayega. 
or odd hai then usko odd-1 time us character ko le sakte for making the palindrome. 

Note : even -> ko directly add karo
odd -> odd-1 karke directly add karo 
- mid element tabhi aayega, jab odd mai koi bhi element present hoga. 

Condition :- Ab string mai dono lower and upper case ke character ho sakte hai. a and A ko same nahi, alag mana jayega. 

Code part :- 
- ek string s naam ki
- do vactor int type ka lower and upper jiska size 26 and ye 0 se intialize honge. 
- itrating on the string and count ko update karwa rahe honge in the vector
  - for loop lelo, jisme i=0 se i< string ke size tak chalega.
    - so how will identify that ki char lower hai ki upper, ham check kar lenge ki agar string of i bada hai 'a'(97) then wo lower mai jayega.  lower[s[i]- 'a']++
    - else, agar value chhoti hai then wo upper mai jayegi
       - upper[s[i]-'A']++
<!-- Lower vector -->
- int count = 0
- ek loop chalao, lower vector ko traverse karne ke liye, i=0 to i<26
  - agar lower of i mod(%) 2 == 0 then count mai add kardo lower[i] ko
  - else 
      count += lower[i] - 1;
Similarlly ek aur for loop for the upper vector. 

Time Complexity : O(n) + O(26) + O(26) = O(n)

Code Implementation :- 
```cpp
int longestPalindrome(string s)
{
    vector<int> lower(26,0);
    vector<int> upper(26,0);

    // Frequency Updated
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>'a')
        lower[s[i]-'a']++;

        else
        upper[s[i]-'A']++;
    }

    int count=0;
    bool odd;
    
    for(int i=0;i<26;i++)
    {
        // lower
        if(lower[i]%2==0)
        count+=lower[i];
        else
        {
            count+=lower[i]-1;
            odd=1;
        }

        //  Upper
         if(upper[i]%2==0)
        count+=upper[i];
        else
        {
            count+=upper[i]-1;
            odd=1;
        }
    }
    return count+odd;
}
```

### Sorting the sentence :- 
So isme hamko sentence diya hoga jisme bahut saare words hai, so hamko words ko sahi order mai likna hai ki pahle kon aaya phir kon aaya. So hamko keise pata chalega ki kon pahle aaya so har words ka last mai number likha hoga, jisme kon kon pahle aur kon pahle aaya, pata chal jayega. words ke position bhi given hogi. Ye no. 1-9 ke bich mai he ho skate hai. 

Approch 
- sabse pahle words ko extract karna padega, jisme ham jaanenge ki kon pahle aaya hai.  So isme ham ek string lenge temp naam ka apne given ko traverse karte jayenge jab space milega tab hamko pata chal jayega ki ek word complete ho gaya hai. Is String ka last char batayega position ko, so position par is string note kar denge. Same karte jayenge tabtak jab tak sentence khatam nahi ho jata.
- postion string lo rakhna :- So hamko pata hai ki 1-9 he string honge so utne size string type ka array le lenge aur index=position, iskee according apne value store karte jayenge. Index -> corresponding us position ki string hogi. 0 index by default kuvhh nahi store karenge. 

converting: '2' char to the int -> '2' - '0'= 2(int)

Code part :-
- so hamko string s given hai.
- Ek string type ka vector banao ans naam ka jiska size 10 hoga, aur ek string type ka temp, do int type ka count and index dono ko 0 se initialize kardo. 
- Jab tak index chhota hai s . size se tab tak
  - Agar s[index] == ' ' then 
    - int pos = temp[temp.size()-1] - '0': words ke last mai se number nikal rahe hai and converting it in the integer type. 
    - temp ke last mai se no. ko hata rahe kyuki ans mai sirf words jayenge, temp.pop_back();
    - ans of pos mai ab is temp ko daal do
    - temp.clear(); : ab temp jo pahle word tha usko remove kar dega.
    - count++ (visited one word of sentence)
  - else: 
    -temp += s[index] 
    - index++;

- Last mai simply ans vector ko traverse karlo and Jitna count ka value utna chalenge starting from the 1.
   for(int i=1;i< count;i++)
   temp += ans[i];
   temp+= ' ';
- last mai bhi space add ho jayega, so hamko space hatana hoga
   temp.pop_back();
   return temp;

Note :- Last wale word ko temp mai store karne ke liye we need to run once more as last words mai space nahi hoga, null character milega hamko. 

Code Implementation :- 
```cpp

```

