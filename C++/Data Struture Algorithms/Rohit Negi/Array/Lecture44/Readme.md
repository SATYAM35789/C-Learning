### Make a string Palindrome or Minimum Char to be added at front to make string palindrome
So hamko ek string diya gaya hoga, aur hamko usko palindrome mai convert karke answer dena hai. Condition: minimum character ko add karna hai ki given string ko given string palindrome ban jaaye.  

Brute Force approch :- 
Hamko pata hai ko palindrome aage ya pichhe se same he read hota hai so ham do pointer lenge jo given string ke first and end ko respectively point kar  raha hoga. So ab in pointer ko check karenge agar ye match nahi karte hai then  jisko end point kae rha hai usko aage likh do. If again not match then ab jo aayega wo jo pahle sabse aage aaya tha uske baad wali position par store hoga. If matched then start++ and end-- kardo. Ex abc, ROORSP etc
 -> Ye saari condition ke liye sahi nahi hai  like aaaotcaakr. So agar wapari condition ke according bich agar matched ho jata hai, then again mismatch us condition mai hamara intution sahi result nahi de raha hai. 

Another Brute Force Approch :- 
So pahle ham character ko sirf match and mismatch kah rahe ab pointer same rahega lakin ab bolenge kya utne portion or substring palindrome hai ki nahi. If not palindrome then last wala(end pointer), aage aa jayega, so on karo if not palindrome. If found palindrome then ruk jao, hamko answer mil chuka hai. 
- So hamko kaise pata chalega ki ye palindrome hai ki nahi. 
-> O(nsq)

Approch 
So ham baar upper wale mai he dekhe toh ye kar rahe hai ki strating se last tak palindrome hai kya, starting se last second tak palindrome hai kya , so on karte ja rahe hai.
LPP : Longest Prefix Palindrome :- Starting se kitna bada palindrome form ho sakta hai. 
So if starting se sabse bada palindrome mil ja raha hai then uske baad wale ko sabko starting mai jod do palindrome or hamko hamara answer mil jayega. 
Answer mai hamko ek int value dena hai jo bata raha hoga ki hamne kitna char ko add kiya hai so uske liye length of palindrom nikalo aur isko minus kardo size of given string se. 

Solution 
-> Apne given string ko reverse order mai note karlo ab ham ek ek karke check kare , if aisa hota hai ki given string ka kuchh portion match ho jata hai reverse string ke toh palindrom found -> prefix of string one matched with the suffix of another string(longest prefix = longest suffix) then ham yaha LPS laga sakte hai. 
1. Given string ka reverse niklo aur isko attach kardo given string ke aage
2. Phir resultant ka lps nikal lo :-> Is se hamko length mil jayega ki kitne string ka palindrome ban raha hai given string. Iske simple GivenStringSize - Jo abhi lps se mila hai = ans
Note : Reverse and Given string ke bich mai extra symbol($) add kardo(for differentiation)
  -> Calculation ko simple karne ke liye add kiye hai as if ye nahi rahega then maan lo koi bhi palindome ko agar apne is approch ko chalyenge then wrong answer milega as starting se end tak resultant string match ho jayega then lps hamko double answer dega , so bich mai symbol add kiye hai ki mismatch ho aur hamko pata chale ki string alag hai(given string and reverse)

Conclusion :- 
1. Given String
2. Reverse of giben string
3. Add extra symbol to given string
4. String mai reverse string add kardo
5. lps 
6. Original size of s - lps of last string

Code Implementation:-
```cpp
int minChar(string str)
{
    // String Reverse 
    string rev = str;
    reverse(rev.begin(),rev.end());

    int size = str.size();
    str+='$';
    str+=rev;

    // LPS
    int n= str.size();
    vector<int> lps(n,0);

    int pre=0, suf=1;

    while(suf<str.size())
    {
        // Matched
        if(str[pre]==str[suf])
        {
            lps[suf]= pre+1;
            pre++, suf++;
        }
        //  Not matched
        else
        {
            if(pre==0)
            {
                lps[suf]=0;
                suf++;
            }
            else
            {
                pre = lps[pre-1];
            }
        }
    }
    return size - lps[n-1];
}
 ```

So if ye bole character ke naam bhi batao then hamko pata hai jitna bhi ans ham return kar rahe hai utne last se charcter aage honge. And mai bhi puristring mange palindrome banane ke baad then iske ans mai jitna value utne charcter utha lo uske aage add karke original mai answer de do. 

### Circular Pattern Matching :- 
 So isme hamko do string given hongi, hamko check karke batana hai kya 2nd string present hai 1st string mai if yes then return 1 if no then return -1.  Condition : Ye hai ki string 1 circular form mai exist karta hai. Ex 1. cdeabroab 2. abcde  return 1.

Approch :- 
So ham apne given string ko ek baar aur copy karke add karde apne he given string ke aage, ab simply find karna hai ki kya hamra 2nd string exist karta hai if yes then return 1 if no then -1. 
So string matching karlo lps ke through, hamne isko pahle kiya hai. 

Variation :- 
string rotated hai hai , ham khud se bhi rotation kar sakte hai, then hamko find karna hai ki 2nd string exist karta hai ki nahi. Use same logic.

### Repeated string match
So isme hamko do string given hoga, pahli string chhoti hogi dusri string se. So isme  hamko puchha hai ki ham apni pahli string ko kitne baar repeat kare ki hamko hamari 2nd string mai pahli wali as substring mil jaaye. If multiple time repeat karne ke baad ans nahi milta then return -1. 
-> So hamko kab pata chalege ki answer possible nahi hai, aur hamko rukna hai
   1. pahle ye try karenge ki size 2nd string ke barabar ya bada hojaaye
   2. iske baad just ek baar aur repeat karenge, if isme answer nahi milta then return -1. 

Steps :- 
1. first wale string ko increse kiya jab tak wo barabar ya bada n ho jeye 2ns string ke size ke. 
2. check string present hai ki nahi as substring if not 
3. repeat once more
4. If find ans now then yes, if not then no. 

So hamko pata hai ki agar kisi string ko match hone hoga toh wo first iteration se he kuchh portion match ho raha hoga kyuki ham ek string ko baar baar repeat kar rahe hai. So if milna hoga toh mil jeyega if not then kitna bhi repeat karlo nahi milega. 

Code Implmentation 
```cpp

```

