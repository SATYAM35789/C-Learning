### Longest Substring without Repeating char
So hamko ek string diya hoga aur hamko usme se longest substring dhoondna hai, jisme koi bhi character repeat nahi ho raha ho. So hamko uski legth ko answer mai lakar dena hai. So substring : means ki continous part of a string. So hamko substring dhondna hai jiske character uniq ho. 

Brute Force Approch :- 
Saari sub string ko dhoondh lo, isme se sabse badi wali substring hamara jo unique hoga wo, ans hoga. 
- isme sabse pahle 1 length ki substring nikalenge and then two length ki substring ko nikalenge and then 3 length ki and so on, nikalte jayenge. 
- unme se jo sabse bada unique hoga wo hamara anse hoga. So unique milta hai saare lenth ko ek ek karke check karenge pahle 1 then 2 and so on. So isme jo sabse bada unique milete rahenge usko usko update karte rahenge length mai.Final mai sabko dekhne ke baad length mai jo hoga usko wapas kar denge. 
-Time Complexity :- O(Ncube)

2nd Approch :- 
-Starting of char se start karenge check karna and accordingly length ko update karenge if bada milta hai length, so isme starting char ko lenge pahle then uske next char ko lenge aur check karenge kya ye unique hai aur hamare ans ka part ho sakta hai if yes then include if no then stop for next searching, ab 2nd char se phir se start karo and again possibility dekho and so on karte jao. 
- Time Complexity : O(nsq)

3rd Approch : O(n) :- Sliding Window Protocol 
- Basic Logic :- So starting se ye puchte jayenge ki kya hamara ye answer ka part ho sakta hai ki nahi if yes then include the character and go for the next character and ask same question, and if answer ka part nahi ho sakta hai then starting mai jo charcter hoga ans ka usko exclude or remove kardo. And so on til we reached the end.

Steps :-  
- startung mai length =0 kar dengen and do pointer first and end le lenge jo ki strat element ko point karenge starting mai. 
- so hamko kasie pata chalega ki character pahle aa chuka hai ki nahi, so we know ki character limited he hote hai so amy type of character may be in string like char,symbol,num,etc So they 256 So we maintain here yaha se pata kerenge ki element do baar aaya hai toh sliding window ko kam karte raho.
 - kya char repeat ho raha hai if not then us char ko 1 bana do with the end pointer. 
 - if repeat then first pointer ko aage bada do ye usko 0 bana dega , tab tak hamko repeat char nahi milta. 

Note :  count[s[second]]-> we are writing directly because we have taken it 256 size of an array.
Code Part:- 
- string s hamko given hoga
- bool type ka vector banayenge, count naam ka, size=256 and intilly value=0
- int type ka variable, first=0, second=0, len=0;
- ek while loop chalayenge, jab tak second<s.size() ; 
  - ek while loop, jab tak count[s[second]] exist karta hai -> Repeated
    - count[first]=0;
    - count++ kardo
  - Not repeated:-
  - count[s[second]]=1;
  - len = max(len,second-first+1)
  -second++;

Code Implementation :- 
```cpp
int lenthOfLongestSubstring(string s)
{
    vector<bool> count(256, 0);
    int first = 0, second = 0, len = 0;
    while (second < s.size())
    {
        // Repeated character
        while (count[s[second]])
        {
            count[s[first]] == 0;
            first++;
        }

        count[s[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }

    return len;
}
```

### Smallest Distinct Window
Hamko ek string given hogi, jisme sabse chhoti window, waps karna hai, jisme sare character present ho jo hamare original string mai present hai. So hamko sabse chhoti substring doondhna hai jisme ye saare char present ho. Kam se kam ek baar present ho. 

Brute Force Approch :- 
So lets we have the three distint char so donot need to check for the 1 and 2 size of char, so we directly start checking from the group of three char, if not found distinct then go for next and remove the first one. Check ek karke saare gropu ki kya wo answer ho sakta hai.Agar nahi milta then ham char char ka group banakar usme check karte and so on karte rahe rahenge. 
Time Complexity : O(ncube)

2nd Approch :- similar

3rd Approch : Slidding Window Protocol
So har ek char ke pass pahuchte he ham puchhenge ki kya hamara ye ans ho sakta hai, if no then apne window size ko badate raho if answer possible ho gaya then apne window ko ek se kam karte rahenge and check karenge kya hamara ans abhi bhi possible if yes then same task karo if no then also same task karo till reach the last char of string. 
- Assumption : So length ko initially given string ka size ke barabar hoga as usme toh saare string present he hoga, so if us se chhota milta hai length jo answer ho sakta, phir len ko update kar denge with min().
- Any type of char can possible like alphabate, symbol,number,etc 256 Ascii. 
Steps :-
1. Finding the unique character present in the string.
2. After that we need to find the length(substring) jo apne ander sabhi char ko contain kare

Note : While traversing jab bhi kisi char ko first time dekhenge tabhi ham apne distinctCount ko ek se kam karenge. Till distinct becomes 0.-> length ko update kardo. 
- And if distinct variable 0 then we  decresing the window aur jo bhi char first mai hoga usko ek se bada denge. Distinct variable tabhi ek badega jab kisi char ka count 0 ho jayega. 
- distinctVariable(diff) agar 0 nahi hai that means ki window ki size badao for including the character and if the window ki size is 0 then window ki size kam karo for finding the smallest possible answer. 

Code Implementation :- 
```cpp
int findSubstring(string s)
{
    vector <int> count(256,0);
    int first=0,second=0, len = s.size(), dif=0;

    // Calculate all the unique character
    while(first<s.size())
    {
        if(count[s[first]]==0)
        dif++;

        count[s[first]]++;
        first++;
    };

    for(int i=0;i<256;i++)
    count[i]=0;

    first=0;

    while(second <s.size())
    {
        //Increse Window : dif exist karta hai
        while(dif && second<s.size())
        {
            if(count[s[second]]==0)
            dif--;

            count[s[second]]++;
            second++;
        }
        len = min(len,second-first); // findout ki yaha +1 kyu nahi kiya
        
        //decrese Window : tab tak dif=0 hai
        while (dif!=1)
        {
            len = min(len,second-first);
            count[s[first]]--;

            if(count[s[first]]==0)
            dif++;

            first++;
        }
        
        return len;
    }
}
```
