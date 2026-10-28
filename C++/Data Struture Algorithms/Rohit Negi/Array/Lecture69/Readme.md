### N Bit binary Number 
Find all N Bit Binary Number having more than equal to 1 than  0 for any prefix. So hamko n ki value diya gaya hoga like N=4 So hamko char bit ke saare number print karwaane hai jisme 1 grater than equal to ho 0 se. Like 1101. 
1 -    kya 1 grater than equal to 0 hai -> yes
11     kya 1 grater than equal to 0 hai -> yes
110    kya 1 grater than equal to 0 hai -> yes
1101   kya 1 grater than equal to 0 hai -> yes

- har ek position par do value aa sakti 0 and 1 so har node par question puchhte jayenge ki yaha konsi value aa rahi . 
- last mai answer generated mai se sabko check kar lenge  ki 1 hamesha 0 se bada hona chahiye if aisa hai toh wo answer ho sakta aur aage jao and check same. 
- Jo bhi ans generated hai wo string form mai store ho rahi hongi. 

2nd Method :- 
- So hamko last mai jakar check n karna pade. 
- So we are having n=4, so 4 position's mai se har ek position par 0 and 1 mai se kuchh bhi aa sakta hai. 
- Hamko pata hai ki kisi bhi position par no. of zero jayda nahi hona chahiye no. of one se. 
- So position par check karenge kya ham 0 aur 1 mai se kisi ko rakhte hai toh if answer possible ho ja raha hai then us position par 0 aur 1 mai se value ko us position par fixed karenge. 



Code Implementation :- 
```cpp
#include <iostream>
#include <vector>
using namespace std; 

void find(int n,vector<string> &ans, string temp, int zero, int one)
{
    if(temp.size()==n)
    {
        ans.push_back(temp);
        return;
    }

//  Decresing order: So isiliye 1 ko pahle daal rahe hai 
    temp.push_back('1');
    find(n,ans,temp,zero,one+1);
    temp.pop_back();

    if(zero<one)
    {
        temp.push_back('0');
        find(n,ans,temp,zero+1,one);
        temp.pop_back();
    }   

}

vector<string> NBitBinary(int n)
{
    vector<string> ans;
    string temp;
    find(n,ans,temp,0,0);

    return ans;
}
```