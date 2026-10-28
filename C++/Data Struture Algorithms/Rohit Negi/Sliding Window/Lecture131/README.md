### Length of Longest subarray with almost k frequency :-
Hamko length dhoondna hai longest subarray ki jisme kisi bhi element ko jo frequency hai , wo atmost k hoga. Atmost :- jada se jyda k ho sakta hai frequency but k se jyda nahi chalega. 

Approch :- 
1. Sare subArray ko find karo
2. check karo jo valid hai
3. unme se jiski length sabse badi hogi usko ans de dedo. 

Approch
So ham apne first element se start karenge aur puchhenge kya tum valid ho means ki kya tumhari frequency atmost k hai, if yes than next elemet ko include karo ask same question if valid then increse the frequncy with one so on till it valid. 
Jaise he unvalid check aata hai then ham apne windo decrease karna start kar denge means is case mai -- kar denge start wale ke frequency ko. jab tak unvalid hoga, tab atak window ko decrese karte jayenge. 
Note:-  Jis ka bhi count bada rahe ham sirf isko check kar lenge kya ye valid hai, so isse hamara kaam ho jayenga. 

Code part :- 
1. Ek unordered_map le lo int int type ka jo ki count of occarnce ko store karega. 
2. int type ka strat , end , len le o inko 0 se initialize kardo
3. Agar n chhota hai end se tab tak 
   1. count mai jo nums of end hai usko ek se bada do.
   2. Agar count jo nums of end hai wo bada hai k se than
      1. count mai jo nums of start hai usko ek se kam kar do(window decrese)
      2. start ko ++ kardo
   3. len mai max ko call kardo jiske ander len aur end-start+1 kardo. 
   4. end ++ kardo (window ko increse karna )
4. return the length

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxSubarrayLength(vector<int> &nums, int k)
{
    int len = 0;
    unordered_map<int, int> count;

    int start = 0, end = 0, n = nums.size();

    while (end < n)
    {
        count[nums[end]]++;
        while (count[nums[end]] > k) // yaha nums of  end par ruke hue hai check kar rahe hai ki kya count mai nums of end wo abhi bada hai k se, jab tak bada tab tak window decrease hota jayenge
        {
            count[nums[start]]--;
            start++;
        }
        len = max(len, end - start + 1);
        end++;
    }
    return len;
}

int main()
{
    // Example: {1, 2, 3, 1, 2, 3, 1, 2}, k = 2
    // Expected output: 6 (Subarray: {1, 2, 3, 1, 2, 3} where freq <= 2)
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    cout << "Maximum length of subarray is: " << maxSubarrayLength(nums, k) << endl;

    return 0;
}

```

### Count Subarray where max element appear at least k times 
So hamko ek array diya gaya jisme se hamko wo subarray ka count return karna hai jisme jo max element hai wo kam se kam k time aaya ho, k se jayda ho sakta hai lakin k se kam nahi hona chahiye.

Approch :- 
1. Sare subarray ko count karlo
2. usme jo bhi bada element hai agar wo k times ya k se jyda baar hai toh, 
3. usko us sab array ko count karke ans bana do 

Approch :- 
So isme sare elements sawal karte jayenge ki kya is ye valid hai means ki iska max element k times present hai if nahi then next element par chale jao , lakin k times present hai than uske agge ham jine bhe aage chale wo sab valid karenge hamre hamare so ham uske baad ke sare present element ko count kar lenge wahi hamara ans hoga. or jaha hamko first valid mila hai us index ko size of array se minus karte hai tab bhi total count mil jayega. 
Count ke milne ke baad ab aage se decrese karna start karenge , aur check karenge ki ya valid hai ki nahi if valid count ko ek se bada do. and again ham size wala step karle. and do so on. 
Ab max element ki count decease hota hai ab window ko badana start kearenge. Ab phir validity ko check karenge. 
Note :- jab hamko k ko satisfied karne wala sub array mil jata hai wahi ruk jao , aur window ko decrese karte jao validity chack karo.

1. window ke  size ko tab tak badate jayenge tab tak max element barabar n ho jaye k ke. 
2. jab count ka size k ke barabar ho gaya toh window ko decrese karna shuru kardo tab tak count kam nahi ho jata  k se. 

Code Part :- 
1. int type ka start,end ,count, total le lo inko 0 se initialize kardo aur ek maxElemnt le lo
2. agar n chhota hai n se tab tak , 
   1. Agar nums of end barabar hai maxElement ke tab tak 
      1.count ++ karte jao. 
      2. Agar count barabar hai k ke tab, (window  decrese)
        1. total ke ander add kardo n-end ko.
        2. Agar nums of start barabar hai maxElement ke tab tak ,
           1. count ko decrese kardo, count--
        3. Agar aisa nahi hai toh , count ko ++ kardo
      3. end ko ++ kardo. 
3. return total. 

Note:- we donot need  unorder_map as hamko MaxElement ka he count store karke ke rakhna hai

Code ke analysis ke factors :-
1. Logic
2. Complexity
3. Correctness
4. sujhaav 


Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

long long countSubarrays(vector<int> &nums, int k)
{
    int maxElement = 0, n = nums.size();
    for (int i = 0; i < n; i++)
        maxElement = max(maxElement, nums[i]); // max element ko store kar raha hai

    long long total = 0;
    int count = 0, start = 0, end = 0;

    while (end < n)
    {
        // increse the window length until , maxElement is equal to k
        if (nums[end] == maxElement)
            count++;
        // Agar count barabar ho gaya k ke tab tak
        while (count == k)
        {
            // window ko kam karna hai
            total += n - end;
            if (nums[start] == maxElement)
                count--;

            start++;
        }
        end++;
    }
    return total;
}
int main()
{
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;

    cout << "Count of subarrays: " << countSubarrays(nums, k) << endl;
    // Example: {1,3,2,3,3} ke liye result 3 aayega ({1,3,2,3}, {1,3,2,3,3}, {3,2,3,3})

    return 0;
}
```

### SubArray with k different Integer :- 
Hamko ek array diya hoga aur bol raha hoga ki , jo return kar raha hoga good numbers of subarray ke count ko. Good Subarray: jisme exactly k diffferent integers present ho. If k is =2 then isme do then agar isme 2 he different no present hai so ye good Subarray hoga like [ 2,1,2] isme do different integer hai, and [ 1,2,1,3] nahi hai because isme 3 different integer hai , etc

Approch :- 
1. Sare subarray ko find karlo
2. aur check karlo ki different integer konse hai, usme
3. if satisfied then usko count karke de do. 


Approch 2nd :- 
Start se start karo puchho ki kya ye good subarray hai if not then window ke size ko increse kardo if mil valid good subarray mil jata hai tab kya karenge, is case ke baad agar window ko decrese karenge tab bhi ham kisi n kisi good array chhut sakta hai agar increse karenge windo tabh bhi koi good arrar miss ho sakta hai, so ab kta kare?
So kab window ko decrease aur increse karenge ? 
Try to find :- Total no of subarray where atlest k different integer are present ?
If k =2 , then hamko total no. of subarray ko batana hoga jo do different ua do se jayda different subarray present ho. 
If k=3 , sam nikal lenge
So agar ba k=2 minus k=3  karte then hamko extactly k=2 mil jayega. 
or
Atleast(2) : sub(2),sub(3),sub(4),sub(5)
Atleast(3) : sub(3),sub(4),sub(5)
Atleast(2) - Atleast(3)= sub(2)

Note :- jaise isme atleat concept laga rahe hai waise agar atmost lagaye tab bhi solution find kar sakte hai. 
Atmost(2) = sub(0) , sub(1), sub(2)
Atmost(1) = sub(0) , sub(1)
Atmost(2) - Atmost(1) = sub(2) :- exactly 2 wale 

Code Implementation :- 
```

```
