### Agressive cow : (min)max
Is problem mai hamko ek array diya gaya hoga, jisme jo array ki element hai wo, stall ko represent kar raha hai. Stall- jaha ham cow ko bandh sakte hai. So hamare pass k no of cow hai, jinko in stall mai bandhna ha. Ham kaise bandh sakte hai?
- Minimum distance between any two of them is maximum possible. 
Jo value hai, array ke aner wo represent kar rahi hai, distance b/w the stall or element. 
- dekho bahut sare tarike honge inko baandne ke liye, maan kisi sabko serial order of stall mai, coe ko bandh diye, so ab inme sabse kam distance do cow ke bich ki as a possible answer lenge. Hence minimum distance b/w any two of them  mai se jo sabse maximum wala he hamara answer hoga. 

Brute Force Approch :- 
Is approch mai, ham starting mai , ham sabhi cow ko minimum 1 distance par bandhyenge, so jis stall ki distance 1 se jayda hogi toh ham cow waha bandh payenge kyuki minimum distance 1 hai, toh jayda toh ho he sakta hai. So is se ham apne la pa rahe hai, lakin hamko puchha hai ki, distance maximum hona chahiye, distance ko aur badayenge aur check karenge kya ab ham bandh sakte hai, and do so on till found the answer.

Optimized Approch :- Binary Search 
Binary search kisse lagega, so hamko pata hai ki 1 se start hokar end tak ja raha hai, aur jo hamara answer hoga uske left side wale sare answer nikal paa rahe honge, aur uske right side wale answer nahi nikal pa rahe honge, 
So jaha answer mil ja raha hai waha ham right side move karne ke kosis karenge if answer nahi mil raha hai then left side move karenge aur ham yahi toh karte hai binary serach mai. SqureRoot mai ham yahi kar rahe the. So wahi conecpt use karenge. 
Note: Jab hamare pass ek line hai, aur hamko lag raha hai ki hamara answer nikal sakta hai, nikal sakta phir answer nikal gaya, phir uske baad answer nahi nikal raha hai, so yaha ham left right ja sakte hai.
end : is the difference b/w the Highest No.(maximum value) and lowest No. (minimum value) 
start : lowest No. in the array 

Note :- Is question mai diya hai ki, jo element hai sorted order mai nahi bhi ho sakte hai. So if not sorted then sort the array.   

Code Part :-          
- Do variablr banao ek int type ka count, jo ki batayega ki kitni cow ko stall mil chuki hai, aur ek int type ka pos(position), ye batayega ki konsa stall hai . 
- ek for loop lenge, jo i=0 se chalega aur i lessthan n tak chaliye.
  - Ab agar pos + mid is lessthan or equal to stall of i , then 
    - count++ kardo
    - pos mai stalls[i] ko store karlo

- Agar count lessthan k, which means ki hamne distance jayda le li hai , hamko distancee kam karne ki zarurat hai.
  - end = mid-1
else mai
   - ans = mid
   - start+1 

Code Implementation 
```cpp
int solve(int n, int k, vector<int> &stalls)
{
    int start=1, end, mid,ans;

    // Sort the vector in ascending order
    sort(stalls.begin(), stalls.end());

    end = stalls[n-1] - stalls[0];

    while(start<=end)
    {
        mid = start+(end-start)/2;
        int count =1 , pos = stalls[0];
        for(int i=1;i<n;i++)
        {
            if(pos+mid<=stalls[i])
            {
                count++;
                pos = stalls[i];
            }
        }

        if(count<k)
        end = mid-1;
        else
        ans = mid;
        start =  mid+1;
    }

    return ans;
}
```

### KOKO Eating Banana :-
Hamko ek array diya gaya hai, jisme har el element, pile ko represent kar rahi hai. So har value present in the array reprent the no. of bananna in the pile. KOKO have H no. of hours to eat that bananna. So hamko ye nikalna hai ki KOkO har ghante kitna bananna khayega toh, kela khatam kar dega. KOKO araam se khana chata hai aur wo sab khana bhi chahta in given time. 
So minimum no of bananna batao ki jitna wo khayega in a Hour so ki wo purra khatam kar de. 

Let's say ki koko decide to eat 3 bananna in hour, so wo kisi ko bji pahle choose kar sakta hai khane ke liye.
- jabtak apne pile ke saare bananna khatam n karde, tabtak dusra pile ka bananna nahi kha sakte hai. means ki agar extra bananna ho gaya toh wo next hour mai sirf un extra bananna ko he khayega. 

Brute Force Appproch :- 
So maan lo koko 1 bananna kha raha hai 1 hour mai, then wo sirf kucch no of bananna kha paayega baake saare bach jayenge. So next wo 2 kela khayega in a hour aur aise he badate jayenge, jab tak saare kela nahi kha leta in H time , starting pahle he case jab wo saare kela kha lega tab ham answer khatam kar denge. Kyuki question mai bola hai ki minimum kitne bananna koko khane honge. 

Optimized Appproch :- Binary Search 
end :- maximum value of the array end point hoga, maximum itne ham kha sakte hai 1 ghante mai so is se jayda kha he nahi paayenge. 
-starting(minimum speed) :- Total bananna/H , kyuki is se kam ham kabhi bhi H ke ander saare bananna nahi kha sakte. 
So if koko H ke ander kha pa raha means ki answer possible hai, then usko store kar lenge and check karenge ki kya aur bhi possible solution hai kya so is question mai ye left side aayega for more solution. 
And if answer not possible hai then right side move karenge. 

Code Part :- 
```cpp
int minEatingSpeed(vector<int> &piles, int h)
{
    int start =0, end=0, mid, ans, n=piles.size();
    long long sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=piles[i];
        end = max(end,piles[i]);
    }
    start=sum/h;
    
    while(start<=end)
    {
        mid = start +(end-start)/2;
        // Mid amount of bananna to consume in one hours

        // Calculating time , mid amount time need in one hours, then sabko khane mai kitna time?
        int total_time=0;
        for(int i=0;i<n;i++)
        {
            total_time+=piles[i]/mid;
            if(piles[i]%mid)  // point mai answer aayega toh ek se bada do
            total_time++;
        }

        if(total_time>h)
        {
            // then ki hamko aur kela khana hai, so right side move karo
            // Jayda time lag raha hai means ki ham kam kela kha rahe hai, no of kela khanna badana hoga
            start = mid+1;
        }
        else
        {
            ans = mid;
            end = mid-1;
        }
    }
    return ans;
}
```

Note: Yaha start ki 0 hone ke probabilty hai kyu ki start mai sum/h kar rahe hai so if sum chhota hai, then 0 ho sakta hai, End nahi ho sakta kyuki ham isme maximum value he le rahe hai. jo 1 se 10^4 ke bich mai hai. 


