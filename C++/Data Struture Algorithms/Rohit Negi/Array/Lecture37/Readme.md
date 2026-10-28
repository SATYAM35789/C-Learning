### Defanging an IP address :- 
So hamko ek ip address diya hoga is string form mai like 1.1.1.1, or 255.100.25.60 , etc so hamko return karna hai . = [.], so jaha bhi . hai waha [.], is tarah se hamko hamara answer generate karna hai. 

Approch :- 
So jab bhi hamko point milega waha [.] daal do apne answer mao phir next check karo. 

Code part :-
- ek int type ka index,jisko 0 se intialize kardo and aur ek ans string bhi create kar lena. 
- ek ek karke saare index par jaana hai, jab index chhota hai aur barabar hai address.size se tab tak loop chalta rahega. 
  - agar address of index == to '.' then 
    - ans += ans + "[.]"
  - else
    - ans = ans+ address[index];
  - index++;
return ans;

Code Implementation :- 
```cpp
string defangingIpAddr(string address)
{
    string ans;
    int index=0;

    while(index<address.size())
    {
        if(address[index]=='.')
        ans+="[.]";
        else
        ans+=address[index];

        index++;
    }
    return ans;
}
```
Time and Space Complexity : O(n)

### Check if String is rotated by 2 places :- 
So is problem hamko do string diya hoga, string 1 and string 2 so agar kya aisa ho sakta hai ki agar string1 ko do baar rotate karde toh kya wo string2 ke barabar hai ki nahi. Aur rotation clock and anti-clock wise, dono direction mai ho sakti hai. 

Approch :- 
So hamko dono string diya hoga, ab ham do string type ka varaible banayenge clockWise and anticlockWise isme string1 ko store karwa denge. 
- rotateClockwise(clockwise) :- capable to rotate one time, when string is pass to it. 
- rotateClockwise(clockwise) : kyuki do baar rotate karna hai
- agar clockwise==string2 then return 1
else
- rotateAntiClockwise(antiClockwise) : same uppar jaise he kaam karega
- rotateAntiClockwise(antiClockwise)
- agar antiClockwise == str2 then return 1
else -1 

rotateClockwise() :- So hamko ye toh pata hai ki aage se traverse karke uske next par rakh sakte as next wala data loss ho jayega so ham string ke pichhse se loop chalayenge
  - jaha last char of string ko store kar lenge and then shif karte jayenge hab 0 tak nahi pahuch jaate. 

Anti-clockWise mai, ham aisa kar sakte hai ki start se starting wale char ko store karle phir shifting wala procedure aur last mai starting wale ko add karde. 

We need to pass the string as a reference kyuki we want ki jo bhi ham change kar rahe hai wo string 1 mai ho. 

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

void rotateClockWise(string &s)
{
    char c = s.size()-1;
    int index = s.size()-2;

    while(index>=0)
    {
        s[index+1] = s[index];
        index--;
    }
    s[0]+=c;
}


void rotateAntiClockWise(string &s)
{
    char c = s[0];
    int index = 1;

    while(index<s.size())
    {
        s[index-1] = s[index];
        index++;
    }
    s[s.size()-1]+=c;
}

bool isRotate(string str1, string str2)
{
    if(str1.size()!=str2.size())
    return 0;

    string clockWise , antiClockWise;

    clockWise = str1;
    rotateClockWise(clockWise);
    rotateClockWise(clockWise);

    if(clockWise==str2)
    return 1;

    antiClockWise= str1;
    rotateAntiClockWise(antiClockWise);
    rotateAntiClockWise(antiClockWise);

    if(antiClockWise==str2)
    return 1;

    return 0;

}
```

### Check Pangram 
So hamko ek string(sentence) diya hoga jisme hamko check karke batana hai ki kya us sentence mai saare lower case le alphabate (a to z) present hai ki nahi. If present then return 1 if not then 0. 

Brute force Approch :- 
ek ek karke saare element ko check kare, sabse pahle a ko if present then break and go for next and so on till z. 

2nd Approch :- 
So ham ek array bana le 26 size ka, initiaally sabhi ke ander 0 value rakhi hua hai. a=0,b=1,c=2,d=3,,z=25.
So is tarah se ham inki indexing karwa denge, so ab jo bhi character aaye waha jao agar 0 hai toh usko 1 bana do if 1 hai toh go for another. So Ye karne ke baad ham traverse karke check kar lenge ki kya ek bhi 0 present hsi then return -1.

-> Converting or locating the index : a - 0  :- current character ki hamari array mai kon se position hai, ye pata kar rahe hai. 
index = name - 'a'
name :  koi bhi character aa sakta hai
like if a then a-a=0

Code Part :- 
- so ek vector(alpha) bana lo bool type ka , jiska size 26 hoga aur wo 0 se initilize hoga
- ek for loop i=0 se chalega aur i < sentence.size() tak jayega. 
  - index = sentence[i] - 'a'
  - alpha[index] = 1
  or (uppar dono )
  - alpha[sentence[i]-'a'] = 1
- traverse and check ki kya 0 hai ki nahi array mai if yes then return -1 if no then 1;


Code Implementation :- 
```cpp
bool checkPangram(string sentence)
{
    vector <bool> alpha(26,0);

    for(int i=0;i<sentence.size();i++)
    {
        alpha[sentence[i]-'a']=1;
    }

    for(int i=0;i<26;i++)
    {
        if(alpha[i]==0)
        return 0;
    }
    return 1;
}
```
Time Complexity : O(n)
constant time agar loop chalega O(26) = O(1)
Space Complexity : O(26) and input par space depend nahi kar raha hai. Input size kitna bhi lelo size 26 he use hoga. O(1) space complexity use hoga. 

### Sort String 
So string bhi ek 1d array jaisa he hai, so isme bhi ham, apna sorting algorithum laga sakte hai like bubble, Insert, selection,etc These algorithum take O(nsq)
Sorting in string means ki a to z, ke serial order mai, arrange karna hai. Ham taha bhi compairsion karenge as ki hamko pata hai a is smaller than b according to ascii cord. like 97 < 98. 

Solving it in the O(n):- 
So ham apne string mai jitne bhi char hai unka count nikal sakte and ek array mai store kar sakte hai, phir ek baar traverse karenge toh hamko pata chal jayega ki konsa char. kitne baar aaya hai. Then is array mai hamko jo pahle milega aur uska jitna count rahega utne baar likte chale jayenge. 
Array : store karega count from a to z where a=0, b=1,..z=25. (Indexing of character or char ki location.)

Code Part :- 
- int index = s[i] - 'a' ;
- alpha[index]++
or upper ke dono
alpha[s[i]-'a']++
ex e-a=4 -> 4th index ko ek se bada do

- char c = 'a'+i 
   Sp hamne apne array mai count store kiya hai, character ka, lakin, hamko ans mai string dena hai sorted mai so hamko apne index par count ko utni baar character ke form mai likna hai. It help in change, in the character with the help of index and 'a'.
   - a=97 if i=1
     then a+i = 98 
     ab jab ham 98 ko char ke ander daalne ki kosis karenge tab, typeCasting go jayega.  

Code Implementation :- 
```cpp
string sort(string s)
{
    vector<int> alpha(26,0);
    for(int i=0;i<s.size();i++)
    {
        alpha[s[i]-'a']++;
    }

    string ans;
    for(int i=0;i<26;i++)
    {
        char c = 'a'+i;
        while(alpha[i])
        {
            ans+=c;
            alpha[i]--;
        }
    }
    return ans;
}
```


