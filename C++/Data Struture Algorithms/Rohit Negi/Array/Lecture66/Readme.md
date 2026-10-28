### Tower of Hanoi :- 
So hamare pass 3 rods honngi aur hamko n no of disk diya gaya hoga. So the name of the rodes are source : jaha initially disk hongi, helper and destination.
 Condition :
1. ek baar mai ek he disk ko move kar sakte hai. and the top wali disk ko he move kar sakte hai. 
2. chhoti disk ke uppar badi disk nahi rakh sakte hai. 
And we need to achive the same order of disk on any one of the rode(destination), rather than the source node. 

- Ham pass source node mai disk hai so so sabse pahle hame last disk ke upper wale disks ko helper rode mai le jayenge then helper rode se destination rode par (e,g n=3).
- So when we are having less no of disks then can manually do the switches. So when the no of disks is more then it's become complicated so we need to generate some logic to solve. 

- Apne problem ko todete jao like 4 disks hai then we ask ki upper ke 3 ko kaise dusre rode move kara sakte hai. If 3 disks the we ask ki upper ke 2 ko kaise dusre rode par lekar ja sakte hai and if 2 disks then upper ke 1 disk kaise dusre rode par lekar ja sakte hai, if 1 disk then 1 disk ko kaise dusre rode par lekar ja sakte hai. 
 - Conclusion: jaise jaise ham 3 disk ko move karenge waise he 4 disks wale rode mai, upper ke 3 disk move honge. similarly jaise 2 disk ko move karenge waise he 3 disk mai upper do disk move karenge. 

Approch :- 
- Agar hamko n disk diya gaya hai then n-1 disk ko kisi bhi ek rode mai move kardo.

Code part :- 
ek void type ka TOH fun, parameter : int n, int source, int helper, int dest i.e TOH(int n, int source, int helper, int dest). Iska kaam hai ki n disk ko sorce destination par lekar chale jao.
 - Toh yaha sabse pahla kaam hai ki isko n-1 node source se helper mai lekar chale jao. TOH(n-1,source,dest,helper) -> Yaha middle ka kaam dest karega 
 - cout<<"Move disk"<< n << "from" << source << "to"<< dest ; , bata do ki nth disk, dest mai pahuch gaya hai. 
 - So ab source khali ho gaya hoga, ab hamko helper ke disk ko dest par lekar jana hai , aur yaha middle ka kaam source node karega (middle, jo abhi khali hai) TOH(n-1,helper,source,dest)

Base Case :- 
  - Agar n==1 
    - cout<<"Move disk"<<n<<"from" <<source<<""to>>dest ;

For better understanding ek example lo like 3 disk ka then is code ke help se isko solve karo. Dry and Run. 

Time Complexity : 2^n+1 -> O(2^n)
Space Complexity : - O(n)
 
Code Implementation :- 
```cpp
#include <iostream>
#include <cmath>
using namespace std;

void tohCal(int n, int source, int helper, int dest)
{
    if(n==1)
    {
        cout<<"Move disk"<<n<<"from rod"<<source<<"to rod "<<dest;
        return ;
    }
    tohCal(n-1,source,dest,helper); // source se helper wale par n-1 disk lakar jao
    cout<<"Move disk"<<n<<"from rod"<<source<<"to rod "<<dest;
    tohCal(n-1,helper,source,dest); // ab disk helper ke uppar aa gaye hai ab helper se dest ke upper bhej do disk ko

}

long long toh(int n, int from, int to, int aux)
{
    tohCal(n,from,aux,to);
    return pow(2,n)-1;
}
```