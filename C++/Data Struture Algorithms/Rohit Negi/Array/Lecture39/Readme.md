### Soot vowel in a string :- 
So hamko ek string diya hoga jisme kuchh vowel honge hamko inko sort karna hai, So ham inko unke ascii ke according incresing order mai laga denge by default. Ex s="leetCode" vowels eeoe->eeeo -> ans=leetcedo . 
So ham string mai se vowls nikal rahe hai phir unko sort kar rahe hai, phir same position par jakar vowels ko store kar jo hamne sort kuya tha in the same order. 
Condtion : lowerCase and Uppercase dono alphabate ho sakte hai and where, a != A.
Ex : s=lEetcOde -> vowels-> EeOe-> EOee(sorted wala) -> ans = lEOtcede

Steps:
1. Select the vowels and then Sort the vowels
2. Insert the Vowels at right position.


Code Part :- 
- Do vector lenge int type ka, lower and upper of size 26 and 0, iske ander ham vowels ka sirf count rakhenge and given string s. 
- ek for loop lenge, i=0 se i< s . size tak chalega
  - if s[i]==a/e/i/o/u tab 
      -lower[s[i]-'a']++;
      - s[i] = '#'
    
  else if s[i]==A/E/I/O/U/ tab 
      -upper[s[i]-'A']++;
      -s[i] = '#'

// Sort
- ek string le lo ans naam ka jo sorted vowels ko store karega.
- ek for loop chalo from i=0 se i<26 tak  // upper Case:-
  - char c = 'A'+i
  - Jab tak upper[i] exist karta hai tab tak
    - ans+=c;
    - upper[i]--;

- ek for loop chalo from i=0 se i<26 tak  // Lower Case:-
  - char c = 'a'+i
  - Jab tak lower[i] exist karta hai tab tak
    - ans+=c;
    - lower[i]--;

Note : Ab hamare pass ek ans variable aa gaya hoga jisme sorted string present hoga. 

- Now original string mai traverse karenge, aur jaha vowel present hoga, ans[i] ko store kar lenge aur ans[i]++ bhi kar denge.

Note: So ab ham iske liye hamko 10 condition phir se likh rahe honge isko avoid karne ke liye jab ham pahli baar apne string par traverse kiye the usi samay jab hamko vowel mila tha tab uske jagah # ko store kar denge.

code Implementation :- 
```cpp
string sortVowels(string s)
{
    vector <int> lower(26,0);
    vector <int> upper(26,0);

    // Count of vowels in lower and upper
    for(int i=0;i<s.size();i++)
    {
        // lowerCase : a,e,i,o,u
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            lower[s[i]-'a']++;
            s[i]='#'; // Jab ham dobara traverse kare toh pata chal jaue ki yaha vowel tha
        }

        // UpperCase : A,E,I,O,U
        else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        {
            upper[s[i]-'A']++;
            s[i]= '#';
        }
    }

// Storing the vowels in order in ans
    string ans;
    //Part1-> upper: kyuki ye chhota hota hai
    for(int i=0;i<26;i++)
    {
        char c = 'A'+i;
        while(upper[i])
        {
            ans+=c;
            upper[i]--;
        }
    }
    // Part2: lower 
    for(int i=0;i<26;i++)
    {
        char c = 'a'+i;
        while(lower[i])
        {
            ans+=c;
            lower[i]--;
        }
    }

    // Original String ke ander, vowels ko insert karwana hai
     int first=0 , second = 0; // Second points the ans string ko 
     while(second<ans.size())
     {
        if(s[first]=='a')
        {
            s[first]= ans[second];
            second++;
        }
        first++;
     }

     return s;
}
```

### Add String :- 
So hamko agar koi bahut bada no diya hua hai diya hai toh ham usko kaise store karwa sakte hai, int type ka 32 bits , and long long 64 aur max to max ham 128 bits ko store arwa sakte hai. So inko store karne ke liye we use the string. 
H/w : Big Int (DataType)

So ham jab pahle factorial nikal rahe the chhote no ka answer aa ja raha tha lakin bade no ke liye int overflow aa ja raha tha. So usko handle karne ke liye we have the string, jo bhi intermediate resukt aate hai unko string ke anser store karte hai. 

Discussing the given problem so ki factorial wala bhi samjh aa jaaye. 
So we have given two string jisme no. stored hai(0-9). ex num1 = "26583" , num2 = "698" ans= 27281

Approch :-  Jaise manually ham karte hai addition pahle last wale ko add karo uske carry ko next mai and so on. 
Addition :- '3'+'8' = 51+56 = 107
But substraction ka case mai barabar kaam karta hai like '8' - '3' = 5 kyuki pahle ascii value puchhi jati hai, 56 - 51=5
So Addtion karne ke liye pahle apne char ko int mai change karenge like : '3' - '0' = 3 and '8'-'0'= 8 ab   3+8=11 ho jayega. 
Note : Substraction tab tak karenge jab tak, dono string mai se koi -1 ke equal na aa jaaye. And we have assumed that num1 ka size greater than num2. 

Code Part :- 
- do int lenge index1 and index2 ko jo store kar raha hai num1.size()-1 and num2.size()-1 ko respectviely. 
- string type ka ans lenge jo dono string ka answer  store kar raha hoga
- int type ka carry=0 lenge, aur ek sum jo ki summation of the two char ko store karega. 
- jab tak index2 bada hai ya barabar 0 ke tab tak(kyuki pahle index2 khatam hoga as Num2 chhota hai)
  - sum = (num1[index]-'0')+ (num[index]-'0')+ carry ;
  - carry = sum/10;
  - char c = 'a' + sum%10;
  - ans+=c;
  -index2-- , index1--;
- loop ke khatm hone ke baad agar index1 bacha hai, jabtak index1>=0 tab tak
  sum = num1[index1]-'0' + carry;
  carry = sum/10;
  char c = 'a' + sum%10;
  ans+=c;
  index1--;

EdgeCase :- Add karte karte sabse aage aaye aur uska bhi carry aa gaya toh hamra loop nahi chalega as index1 -1 ho chuka hoga so :-
  - if(carry)
     ans+='1';
- reverse string ans with reverse()

Code Implementation :- 
```cpp
string add(string num1 , string num2)
{
    string ans;
    int index1 = num1.size()-1, index2 = num2.size()-1;
    int sum, carry=0;

    // Summation till index2>0
    while(index2>0)
    {
        sum = (num1[index1]- '0') + (num2[index2]- '0') + carry;
        carry = sum/10;
        char c='0' + sum%10;
        ans+=c;
        index1--;
        index2--;
    }
    // Agar index1 abhi bacha hua then
    while(index1>0)
    {
        sum = (num1[index1]- '0') + carry;
        carry = sum/10;
        char c='0' + sum%10;
        ans+=c;
        index1--;
    }

    // Agar carry abhi bacha hua or if last addition mai carry hota hai
    if(carry)
    ans+='1';

    reverse(ans.begin(),ans.end());

    return ans;
}

string addStrings(string num1, string num2)
{
    if(num1.size()<num2.size())
    return add(num2, num1);  // jo bada hai wo pahle pass karenge
    else
    return add(num1,num2);  // same
}
```
