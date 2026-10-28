### Introduction to String  :- 
So hamre pass different tarah ki values hoti hai jisko ham alag alag tarike se store kar-wate hai. like 1,2,3,4 inko int type mai, 1,2,3.0, 4.2,  inko float or double type mai , a, b, c, d inko char type mai Ascii value kom char ke ander store karte hai,etc

Real world Data kis kis tarah ke hote hai:-
While log-in : EmailId puchhta hai, toh ye kis tarah se store hoga. So agar email id ko single single karke character array mai store kar sakte hai. 
- if agar kisi ka naam store karwana hai then ham, size ko user se input karwa le phir usse data ko enter karwa le, phir insert/store kar de.
- chahe maximum word kitna enter ho sakta hai ye pahle define kar de ki is jayada length ka naam nahi ho sakta. 
- So jab bhi, given words(Full UserName) complete ho jaye, the uske baad null character ko store karte hai system by default kar deta hai.
  Null character : ko dekhte he compiler ruk jayega, aur further kaam nahi karna hai. So if null character nahi hota toh hamko alag se size of the words ko store karna padta. 

- char used one byte to store the data. 
- so jaha bhi null character milega uske baad wale element ko ham access or print nahi karwa paayenge.

So array ki form mai store karne ke liye we need ki hamko size batana padega , so aisa ho sakta hai ki koi word chhota hai, aur hamne pahle he size declare kar rakha hai toh us word ko same size allocate ho jayegi.
Which means kuchh memory extra hai aur wo waste ho jayenge. 
So agar aisa possible ho jaye ki jitna memory ki requirement hai, utna he memory ham use kare toh. So for this we use the String , jaha par memory dynamically allocate hoti hai. So string text form of data ko as an input le sakta hai. like Rohit. 

### String :- 
Ye array ke jaisa he ham visualize kar sakte hai, lakin yaha size nahi define karna padta hai. So for storing the ROHiT, we have the array , starting from 0 index to 5, which store  ROHIT and nullCharacter.

#### Intializing the String 
string s = "Rohit";

-> Creating the string and taking input from the user
    string S;
    cin>>S;
    cout<<S;

-> Difference b/w storing satyamMishra and satyam Mishra
So satyam mishra ko store karne ke liye we need to store  it as it is means ki space ko character manenge. according to the ascii. 
Lakin Satyam Mishra ko directly is tarah nahi store karwa sakte hai like cin>>s. Because jab bhi ham space/tab/enter dabate hai, cin samjhta hai ki isko further read karne ki zarurat nahi hai. So tab ham Satyam Mishra ko kaise le paayenge. So we have to use getline(cin , s).
- is tarah se ye sabko read kar lege aur jab ham cout karenge, the sabkuchh print ho jayega. 

-> Finding the size of the string :- 
cout<<s.size();

-> Combining two string 
s1="Satyam" , s2="Mishra" 
s3 = s1 + s2;
s3: Satyam Mishra (output).

-> String ke last mai char ko add karna 
s.push_back('p');

-> String ke last se ek character ko hata do
s.pop_back(); 

Qestion :- storing :  Hello "satyam"  mishra   as it is.
string s = "Hello "satyam" mishra";  -> ye hamko error maarega. 
So actually kya hota hai ki " jab ye sabse pahle pata hai toh read hona start hota hai, aur jab " ek aur milta hai toh lagta hai ki bas ab khatam ho gaya hai read karna. Aur baaki string rahe jayega aur hamko error mil jayega. 
So yaha ham use karte hai Escape character(\).
Need :- so agar isko(\), iske(") aage laga  de toh ye use read karna escape kar dega. 
string s = "Hello \"satyam \" mishra" ;

Agar isko \ print karwane ke liye bole tab?
string s = "\" ->  nahi
string s = "\\"
 reading \ : mujko print mat karo, mere aage wale ko direct print kardo. 

Code Implmentation :- 
```cpp

```

### Reverse the string :- 
So isme hamko given string ko reverse karna hai.

So iske liye do pointer le lo start=0 and end = n-1. So ham start++ aur end-- karte jayenge aur yaha present value ko aapas mai swap karte jayenge, ya kaam tab tk karenge jab tak start choota hai aur barabar hai end ke. 

Code Implementation :- 
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s = "Satyam";

    // Reverse String
    int start = 0, end = s.size() - 1;

    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    cout << s;

    // Calculating the length of the string or size of string
    int size = 0;
    while (s[size] == '\0')
        size++;

    cout << endl;
    cout << size << " ";

    // Checking the palindome : start aur end ko match karwayenge if matched then go and check for next, if not then return not palindrome
    string s2 = "naman";
    start = 0, end = s2.size() - 1;
    while (start < end)
    {
        if (s2[start] != s2[end])
        {
            cout << "Not a Palindrome";
            return 0;
        }
        start++, end--;
    }
    cout<<"It is a palindrome";  
}
```