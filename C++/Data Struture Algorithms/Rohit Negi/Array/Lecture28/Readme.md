## Two pointer in C++
In problems ke help se jaanenge ki two pointer kya hota hai, aur is se problem kaise asaani se solve ho jati hai. 

### Segregate 0 AND 1 :- 
so hamko ek array diya hai jisme 0 aur 1 hai. So hamko sare 0 ko ek side(left) karna hai aur saare 1 ek side(right) karna hai. 

Brute Force Approch :- So ham apne is array ko sort kar denge, toh hamko hamara answer mil jayega. So ham sorting algorithum ka use karke karenge toh O(nsq) time complexity aayegi. 

2nd Approch :- 
So if ye array hamko vector ke form mai diya hoga toh ham isko. sort(arr.begin(),arr.end()). So if  vector nahi hai than ham ek vector create kar sakte hai , aur us array ko copy kar denge. Iski Time complexity hoti hai nlog(n). Sort using the heap,insertion and quick sort ka mixture ka koi algorithum hai, us se karta hai usko janne ke zaryurat bhi nahi hai. 

3rd Approch :- 
So hamko is problem pahle 0 ki likhna hai and then 1 ko likhna hai. So Agar ham do variable le le count0 and count1 , initially ye zero honge, ye variable count 0 and 1 ko store karenge. So if count karle ki isme count 0 and 1 kitne hai tab hamari problem solve ho jayegi. So ham ek baar traverse karte jayenge aur 0 hoga toh count0++ and 1 hoga toh count1++ kar denge jis se ye kitne unka no. pata chal jayega. 

Time Complexity : n+n+n = O(n)
Code Implementation :- 
```cpp
int count0=0 , count1=0;
for(int i=0;i<n;i++)
{
    if(arr[i]==0)
    count0++;
    else
    count1++;
}
for(int i=0;i<count0;i++)
arr[i]=0;
for(int i=count0;i<n;i++)
arr[i]=1;
```

4th method : 
So is method mai time Complexity ko optimized karne ki baat nahi kar rahe hai, ham chahte hai ki ek he traversal mai, apna answer nikal de. 
So isme do varaible lenge ek start naam ko jo starting of array ke element ko point kar raha hoga aur ek end jo array ke end ko point kar raha hoga,
- If start wala index par 1 hai aur end wale par 0, then ham samjh jayenge ki 1 ko last mai hona chahiye so isko swap karenge end se if wo 0 ko point kar raha hoga toh.swap hone ke baad start++ and end-- kar denge. 
- if start jisko point kar raha hai wo 0 hai, it means ki wo sahi position par hai so start++ kar denge. 
- if end jisko point kar raha hai wo 1 hai then it means ki wo sahi position par  hai then end-- kar denge.
- Break condition: so if start greater then or equal to end. 

- Jo hamne kiya isko bolte hai two pointer ek start ko point kar raha hai aur ek end aur ye ek dusre ke taraf aa rahe hai. 

Time Complexity :- O(n)

Code Implementation :- 
```cpp
void segregate0and1(int arr[], int n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        if (arr[start] == 0)
            start++;
        else
        {
            if (arr[end] == 0)
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
            else
                end--;
        }
    }
}
```

### Two Sum :- 
So hamko ek array given hai sorted form mai, So isme hamko ek target value diya hoga, hamko batana hai ki kya koi bhi do element ka sum target ke barabar aa sakta hai ki nahi hai, ye hamko batana hai.  

Brute Force Approch :-
Is approch mai, ek karke sare element ke sum ko check karenge ki wo target ke equal hai ki nahi hai, if equal aa jate hai then ham aage compair karna chod denge. With the help of two loop. (inner loop).
So innerloop ke ek kadam aage se chalayenge (i+1)se.

```cpp
vector <int> ans;
for(i=0;i<n-1:i++)
for(j=i+1;j<n;j++)
{
    if(arr[i]+arr[j]==target)
    {
         ans.pushback(arr[i]);
         ans.pushback(arr[j]);
         break;
    }
}
```
Time Complexity : O(nsq)

2nd Method :- 
So dekho hamko 1st element pata hai aur target bhi , let the 2nd element be x then x = target -first element. Ex if first element= 2, target is 22, then second element = 22-2=20. So ab agar ham ye check karle ki 20 hamare array mai present hai  ki nahi, toh hamko pata chal jayega ki hamara ans exist karta hai ki nahi. So hamko sorted order mai answer diya hai, then ham Binary search laga sakte for searching the x element. 

```cpp
for(i=0;i<n-1;i++)
{
    x= Target- arr[i];

    start = i+1;
    end = n-1;

    // Binary serach algo: If found then break the loop and return ans if not then go for next round
}
```

3rd Approch :- Two pointer 
So isme do variable lenge, start and end aur inko, start ko starting element par rakh denge and end ko last element of the array par rakh denge. 
- start aur end ko ko check karenge if wo target ke barabar nahi hai then start++ ya end-- kar denge.if hai then unko index ki value ko return kardo as in vector form mai. 
- so jab bhi unka summation karene par target se bada aa raha hai, it means ko hamko decrese karna hai taaki solution ke pass pahuche so isme end ko  decrese karenge and vice-versa
- Array sorted order mai hai, means ko start aage badega toh vaule ko increse karega and end chalega toh value decrese hogi. 

Note : Is approch ko ham sirf sorted array mai he laga sakte hai. 

Two pointer kyu kaam kiya:- 
Cases ko udate chale jaye kaise, as so if ham arr ka starting aur array ka end target se bada aa raha then it means ki ab start se end tak koi bhi value rakhe tab hamko value badi de milegi as ki starting index jo hamne rakha hai uske baad toh sari us se badi value he hai, So hamko apne end ko ek se kam karna hoga uske liye bhi same condition rakhenge and wise versa if target se chhoti aaye, then start++ karenge. 

Elimination method :- aise possibilites ko hatana jis se answer ki possibility nahi hai. 

Code Implementation :- 
```cpp
vector <int> twoSum(vector<int> & numbers, int target)
{
    vector <int> ans;
    int start=0, end=numbers.size()-1;

    while(start<end)
    {
        if(numbers[start]+numbers[end]==target)
        {
            ans.push_back(start+1); // I baased index and initially we have taken start=0
            ans.push_back(end+1);
            return ans;
        }
        else if(numbers[start]+numbers[end]<target)
        start++;
        else
        end--;
    }
    return ans; 
}
```

### Pair with given difference :- 
So ab hamko ek array diya gaya hoga, ab ek difference(target) diya gaya hoga, ab hamko do element ka agar difference iske barabar aata hai toh hame iske value ko vector mai store karwake wapas karna hai. 

Brute force approch:- 
Ham do loop ka use kare aur ek ek karke minus kare, if answer milta hai toh return karde nahi toh empty vector he return kar denge. 
Time Complexity : O(nsq).

So intution aa raha hoga ye problem two sum jaise hai, so hamko isko sort karna hoga ek isko optimized karne ke liye. 

2nd Method
Same approch yaha bhi use kar sakte hai jo iske pahle question mai kiye the. A-B = Difference, ex A-B=Diff
A= Diff+B.
If B = arr[i] say 2 and diff = 45
so A = 45 +2 = 47
Ab agar arr[i+1] se arr[n-1] ke bich mai, 47 exist karta hai then ans exist karta hai. N
If not exist then arr[i]++ karke, phir se A  ki value nikalo and phir answer find karo son karte jao until  found the answer. 
Time Complexity : nlog(n)

3rd Optimized Approch :- Two pointer
Isme jab ham A-B karenge toh , result kaisa bhi ho dono he case mai value decrese ho rahi hai hai, means ya phir start ko aage badaye ya end ko -- kare , inka result dono he case jo present result hai usse kam he aayega. So start air end ko ham pahle ke jaise , array ke starting and array ke ending mai nahi rakh sakte pahle wale ke jaise. 
- As jab dono he case mai, agar decrese ho rahe hai tab ye nahi bata paayenge ki kidhar jane se ans ke chance jayda hai ye decide nahi kar paayenge. 

 So start aur end ko waha rakhenge, jaha result nikale toh increse and decrese ke factor involve ho. 
 start = array of starting(0 index)
 end = array of ending(0+1 index) par or just uske aage. 
- is case mai jab apne difference ko badane ke end  ko ek se badayenge kyuki difference tabhi bad sakta hai start(B) kam ho jaaye ya A(end) bad jaaye. So abhi A toh start mai he hai so wo toh kam nahi ho sakta so B (end) ko bada sakte hai. 
- Jab hamko result bada aa raha hoga aur hamko kam karna hai then start ko aage badayenge.
- jab hamko result chhota aa raha hai target se then ham end ko badayenge. 

Time Complexity : O(n)

Why we start the start and end like this not like we do in Two sum ? 
So ab koi bhi problem ho, pahle start and end waise he likh do and hamko pata hai hamko start aur end ko koi direction batani padegi. 

Condition :- Start aur end ko koi bhi direction lakin, aisa ho ek case mai value increse ho dusri case value decrese ho. Means ki start aur end ke sath  koi bhi operation perform kar rahe hai, so agar start ko bada ya ghata rahe hai toh value increse ya decrese ho and same in case of  end. So if start badayega value ko end kam karna chahiye value ko ya phir iska vice versa bhi ho sakta hai. 

Start :-
- Increse :- 
- decrese :- 
End :-
 - Increse :-
 - decrese :-

 Note : If start increase karega toh end ko decrese karna he hoga and vice versa also possible. 

Code Implementation :- 
```cpp
 int solve(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int start=0, end=1, n=arr.size();

    // Edge case : 
    if(target<0)
     target = target+-1; 
    while(end<n)
    {
        // substraction equal to target
        if(arr[end]-arr[start]==target)
        return 1;

        // Substraction is lessthan target
        else if(arr[end]-arr[start]<target)
        end++;
        else
        start++;

        //Edge case 
        if(start==end)
        end++;
    }
    return 0; 
}
```

### Pair with given Product
