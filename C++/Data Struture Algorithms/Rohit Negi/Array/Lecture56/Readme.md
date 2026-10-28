### Recursion in Strings 
So isme ham dekhenge ki ham recursion ka concept kaise laga sakte hai string mai. 

### Check Palindrome 
So hamko ek string diya joga aur hamko batana hai ki ye palindrome hai ki nahi , palindrome ek string hota hai jo aage aur pichhe se dono taraf se same hota hai on reading like naman, mom, etc 
- isko ham two pinter ke help se kar sakte hai. 
code part :- 
```cpp
bool checkpal(string str, int start, int end)
{
    if(start>=end)
    return 1;

    if(str[start]!=str[end])
    return 0;

    return checkpal(str, start+1, end-1);
}
```

Recursive tree with an example naman

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

bool checkpal(string str, int start, int end)
{
    //  base case
    if(start>=end)
    return 1; 

    if(str[start]!=str[end])
    return 0;
    return checkpal(str,start+1,end-1);
}

int main()
{
    //  Check palindrome 
    string str = "naman";
    cout<<checkpal(str,0,4)<<endl;
}
```

### Count Vowels :- 
So hamko ek string given hongi aur hamko batana hai usme kitne vowels present hai. like amanos => 3 , Rohit => 2 . And the given string inn this question are lower case alphabates.  

Recursion 
- So given string ko 0 se start karenge aur puchhenge kya tum vowels ho, aur bata do ki mere aage wale mai kitne aur vowels hai. 
- jab string khatam ho jayegi tab ham 0 return kar denge, which sign ki iske aage ek bhi vowels present nahi hai. 
Note : ham pichhe se bhi apne string mai traverse kar sakte aur same question puchhenge jis hamko hamara base case pata hoga aur hamko extra parameter pass karne ki zarurat nahi padegi. 

code part :- 
- ek int type ka count function hai, parameter : string type ka str aur int type ka index
  - agar string ka index barabara aata hai a/e/i/o/u mai se kiso ke tab return 1 kardo aur call kardo index ke pahle koi vowels hai ki nahi. 
  - if index par jo value hai wo vowel nahi then mere aage wale ko call kardo i.e return count(str,index-1);
  Base Case :- If index == -1 then return 0

Note : recursion mai hamesha pichhe se calculation is liye karte hai kyuki ham isme hamesha constant ki taraf aana pasand karte as other case like this n or end kuchh bhi ho sakta hai so ek extra parameter lena padega. 

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

int count(string str, int index)
{
    // Base Case
    if(index==-1)
    return 0;

    if(str[index]=='a'||str[index]=='e'||str[index]=='i'||str[index]=='o'||str[index]=='u')
    return 1 + count(str,index-1);

    else
    return count(str,index-1);
}

int main()
{
    //  Count vowels 
    string str = "satyam" ; 
    cout<<count(str,5)<<endl;
}
```

### Reverse String 
So hamko ek string diya gaya usko reverse karke dena hai, so ham two pointer ke help se easily reverse kar sakte hai start++ and end-- karo swap kardo so karte jao jab tak start bada ya barabar nahi ho jata end se. 

Code Part :- 
-ek reverse naam ka function hoga jiske ander ham ek string aur do int type ke start aur end pass kar rahe honge. Is function ka basic kaam ye hai ki jo bhi string usma jaha bhi start aur end point kar rahe hai unko swap karke de dega or reverse karke de dega.
  - swap procedure using three variable
  - After swaping ham next character, string ka reverse karne ke liye call kar denge
  - base case : when start is greater than equal to end
  - so ham chahte hai ke ham reverse function mai jo kar rahe hai wo changes ham apne string mai bhi dikhe for that we need to pass the string by the address. 

Code Implementation :- 
```cpp
#include <iostream>
using namespace std;

void reverse(string &str, int start, int end)
{
    // Base case
    if(start>=end)
    return;

    char c = str[start];
    str[start] = str[end];
    str[end] = c;
    reverse(str, start+1, end-1);
}

int main()
{
    // Reverse a string
    string str = "satyam";
    reverse(str,0,5);
    cout<<str<<endl;
}
```

### Lower Case to UpperCase 
So hamko lowercase mai string siya gaya hoga and we need to change it in the uppercase. So hamk kaise change kar rahe honge ex let char c = 'A' + 'r'-'a'; 
r : character which we want change in the upper so for that we are substracting 'a' from 'r' so ki we find out what is the difference between the ascii code from a 
- then we adding this difference to the 'A' so ki hamko upper mai 'r' mil jaye
Note: Hamko pata hai ki jitna differnce r ka a se hai utna he difference A sur R mai hoga. 

LowerToUpper naam ka function hai jiska kaam hai ki character of string ko uppermai kar de.

Code Implementation :- 
```cpp
#include<iostream>
using namespace std;

void lowerToUpper(string &str, int index)
{
    if(index==-1);
    return ;
    
    str[index ] = 'A' + str[index] - 'a';
    lowerToUpper(str, index-1); 
}

int main()
{
    // Lower to upper
    string str = "rohit" ;
    lowerToUpper(str, 4);
}
```