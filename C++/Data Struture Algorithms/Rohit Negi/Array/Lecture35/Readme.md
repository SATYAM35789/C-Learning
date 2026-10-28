### How to store 2 number in 1 position :- 
So isme hamko do number store karne hai, so ek number diya hoga jo 1 to 100(exclude) ke bich mai lie karega. So agar uska pahla number 2 hai uska baad wale number sirf 2 he dega, so ab question bol raha hai ki wo number aur wo number kitani baar aaya hai, usko store sath at particular position. 
Position = original no, occarance of original number. 

Approch :- 
So hamko given hai ki jo no hai wo 1 to 100 ke bich mai he lie karega, So range just ek bada wala no hamko lena hai hoga, Storing value = originalNumber + occanceOfOriginalNo. * just ek bada number.
ex 2+6*100. if range 1 to 99. 
So ab Hamko pata karna hai ki, jo number ham store kiye the usme se original num aur occance ka ? 
 - Original Number = StoredValue%JustBadaNum   % = remainder
 - Occance = Stored Value/justBadaNumber       /= quotant
 ex OriginalNumber= 602%2 = 2
    Occance = 602/6 = 6

Note :  Is tarah se solution nikate samay yah yaad rakhna hai ki integer overFlow ki condition n aa jaye, koi aisa no , jo integer ke category ka nahi hai. 

Example : Jab 2d array ki Row Measure order mai store hota tha in single array mai us samay, index do chiz ko store karke rakhta tha. if index = 7
- row = index/colsize
- col = index%Colsize
   example :- arr[3][4]
   row = 7/4 = 1
   col = 7%4 = 3 

### Find Missing And Repeating :- 
So isme hamko ek array diya hoga , array ka size bhi diya hoga(N) , So array number present hai 1 to N tak hone chahiye jo idle condition hai, So given array mai hamko koi ek term miss kar diya hai aur koi ek repeat ho gaya hai. So hamko missing number aur repeated number dono find karna hai. 

Brute Force Approch :- 
Repeating Number :- Iske liye ham har ek vaule ki jo array mai present uske liye traverse karte hue chack karenge kya particular number, kitni baar aaya hai. So agar kisi number ka occarnce 2 hai then iska matlab hamko repeating number mil chuka hai. O(Nsq)
Missing Number :  similarly ek ek karke, pure array mai check karenge ki kya particular number i, miss hai.Agar koi particular number , array mai nahi milta hai then we found the missing number. O(Nsq)

2nd Approch :- 
So agar ham array ko sort karde, then hamko pata hai ki nlogn time complexity mai solve ho jayega. 
Missing Number : arr[i]==i+1 
Repeating Number : Particular index par konsa number aana chahiye tha, if present Number is not equal jo number aana chahiye tha means ki ye number repeat ho raha hai.
Time Complexity : O(nlogn)

3rd Approch :- 
So hamko pata hai ki N ki value kya hai, aur jo number hai wo 1 to N ke bich mai hi lie karne wale hai, So hamne ek array bana liya jo rakhega is number ka count. So isme agar koi number present hai hamre given array mai toh count array mai waha jakar ek se bada denge.(is tarah se ek index 0, wala extra lena padega) 

So ab agar extra(size) 0 index nahi use karna chahte hai toh, givenArrayValue-1 index par apne value ko update karnge count array mai. Ex 1 ko 1-1 = 0 , so isko 0 index par update karenge count array mai. 

Note :- Ye approch ham waha laga rahe honge jaha, limited range hoga, aisa nahi ki , jamko pata nahi hai ki kitne ho skate hai. Kyuki us case mai kitne size ka array banayenge. 
Code part:- 
```cpp
vector<int> Count(N,0);
for(int i=0;i<N;i++)
count[arr[i]-1]++;
// For missing
for(int i=0;i<N;i++)
{
    if(count[i]==0)
    cout<<i+1;
    break;
}
// For Repeating
for(int i=0;i<N;i++)
{
    if(count[i]==2)
    cout<<i+1;
    break;
}
```
Time and space Complexity : O(N)

Optimized Approch :- In O(1) space Complexity
So apne given array ko ek ek karke sare element ko decrese kardo, ab is array mai traverse karo aur jo bhi value present hai us, value ke index par jakar,  value ko 1 se increse kardo  , same kaam sab saare node par jakar karenge. 
If uppar wale jaise karenge toh hamko purra gadbad answer milega, or complication bad jayega, so hamko ek position par 2 number store karwana padega, ek number jo present hai, ek us number ka count. 

So hamne saare number jo hamare array mai tha sabko ek se decrese kardiya hai toh, ab number 1 to N-1 he number present honge, so Jaise pahle N liya tha for dividing the particular number.  
- If number present hai then usparticular index par jakar, us index par jo value present hai usko add kardo 7 ke sath. 
- Original number find karne ke liye, jo bhi value present hai usko % modulas kar N ke sath we got the number
- phir iske uppar wala step karo , karte for n-1 tak
- occrance ke liye, jo number present hai ye sab karen ke baad usko / divide kardo N se.  

Time Complexity : N+N+N+N = 4N = O(4N) = O(N)

Code Implementation:-
```cpp
vector <int> findTwoElement(vector<int> arr, int n)
{
    //  Array ki value ko decrese karo by one
    for(int i=0;i<n;i++)
    arr[i]--;
    
    // Occarance 
    for(int i=0;i<n;i++)
    {
        // Original no niklo and waha N ko add kardo
        arr[arr[i]%n]+=n;
    }

    // Returning ans : Missing and Repwating number
    vector <int> ans(2);

    for(int i=0;i<n;i++)
    {
        // repeating
        if(arr[i]/n==2)
        ans[0] = i+1;
        else if(arr[i]/n==0) // Missing No
        ans[1]= i+1;
    }
    return ans;
}
```

### Find the Occarance of a Number :- 
So hamko ek array diya hoga, jisme n diya hoga, aur is array mai 1 to n where n is include, number present honge. So hamko batana hai ko jo no hai wo kitani baar aaya hai us array mai. 

Brute Force Approch :- 
Har ek element ko check karte jao, ek ek karke wo number kitani baar aaya hai. 

2nd Aprroch 
Ek naya array create karke, jisme ham pahle value ko ek ek se decrese kar denge and then hamne jo naya array banaya the usko 0 se initialize kiya tha ab decrese hone baad ab ham ek ek karke traverse karenge array mai jo bhi value hai usi index par jakar new array mai ek se bada denge.  Iske baad hamko answer mil jayega jo ham seimply traverse karke bata sakte hai. 

3rd Approch (without using extra space)
Is approch mai, 
- sabse pahle sare no ko ek decrese kar diya which means ki ab 1 to n-1 , no he array mai prsent honge. 
- We take the n for division purpose
- ab at every index arr[i]=value at that position , i,e arr[i]%2 karenge, ab iska jo bhi answer aayega waha jakar N add kar denge us index value mai. 
- Occarance : arr[i]/N

### Majority Element :- 
Hamko  ek array given hoga jisme hamko kuchh number diye honge, hamko us number ko output mai dena hai jo N/2 se jayda baar aaya hai. So confirm hai ki koi no zarur exist karta hoga array mai N/2 se jayda hoga. 

Brute Force Approch :- 
So ham ek ek karke element ko check karege, so jo bhi no ka occarnce bada aaya hoga , n/2 se wo number hamara anser hoga. If not then go for the next element , kyuki hamko diya hua ki koi n koi no. zarur exist karta hoga. 

Time Complexity : O(nsq)

2nd Method :- 
So isme approch mai apne array ko sort kar denge, uske baad count karlenge simply ki element kitna baar aaya hai by doing the travers.

3rd Approch :- 
So hamko pata hai ki no exist he kar raha hai, so agar ham assum kare ki koi election hai, jisme value of the array represent ki uko vote mila hai by that person(index). ex arr[2] = 3 means ki 2 ne 3 ko vote diya hai. 
Logic : 
- So hamko pata hai ki agar koi no n/2 se jayda hai, cancelling sysytem. ek ek karke , value ko camcel karna. Uske baad jo bhi no, last mai present hoga wahi hamara answer hoga. 
- Agar total no n present hai so agar koi no n/2 baar se jayda hai means ki jayda baar no present - overall present of different of different occarance. 

Code Part :- 
- hamko do variable lena hoga, candidate aur count ,so pahle , first element ko candidate bana do, aur sabse pahle count bhi 0 hoga.
- so pahle element par ab candidate hai then iska count ek se bada, agar phir candiadte aata hai then count ek se bada do and if not candidate then count ek se kam kardo.
- so agar candidate ka count 0 ho jata hai then next mai koi aur candidate aata hai then wo candidate ban jayega and so on. 

Code Implementation :- 
```cpp
int majorityElement(vector <int> &nums)
{
    int candidate, count=0, n = nums.size();

    for(int i=0;i<n;i++)
    {
        if(count==0)
        {
            count=1;
            candidate=nums[i];
        }
        else
        {
            if(candidate==nums[i])
            count++;
            else
            count--;
        }
    }
    return candidate;
}
```

#### Variation in the same question :- 
So ki maan ki gaurebtee nahi hai ki koi no isme n/2 se jayda hai, wo ho bhi sakta hai aur nahi bhi. 

Is case mai: last mai jo bhi no bacha hai hamara pass, uske liye ek baar phir traverse karenge and verify karenge ki kya ye no, n/2 se jayda hai ki nahi. 

Code Implementation :
```cpp
int majorityElement(int nums[], int n)
{
    int candidate, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            candidate = nums[i];
        }
        else
        {
            if (candidate == nums[i])
                count++;
            else
                count--;
        }
    }
    
    //  Varifing
    count =0; 
    for(int i=0;i<n;i++)
    if(nums[i]==candidate)
    count++;


    if(count>n/2)
    return candidate;

    else
    return -1;
}
```
