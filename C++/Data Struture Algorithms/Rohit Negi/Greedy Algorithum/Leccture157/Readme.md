## Greedy Algorithum :- 
It is a problem solving approch that makes a sequence of a choice, each of which looks best at that moment. This methods aims to find global optimal solution by making series of locally optimal choice. 

### Minimum no. of coins 
Hamko ek N ki value diya hoga jisko hamko achive karna hai from given different value of coin.Given, like 2000,500,200,100,50,20,10,5,2,1. So Give me the minimum no. of coin we need to achive the N. 
Example if N = 143
1st Optimal solution : 100 +20+20+2+1 = 143  5coin
2nd Optimal solution : 50 +50+20+10+10+2+1 = 143   7coins

So our answer is 1st one. 
So hamne kya kiya, N= 143 hai so hamne dekha sabse nearest konsa coin ham le sakte 200 nahi kyuki bada hai aur hamko 143 he chahiye so 100, so we have 43 left so ab 20 choose karenge, now we 23 left nearest coin jo chhota ya barabar us coin choose karenge so we choose 20, now we have 3 then chhose 2 then 1. 

Note:- So ye question to question par depened karega ki optimal solution milega ki may be that  question mai particular condition ke sahi answer de raha lakin agar condtion mai changes ho toh answer optimal n ho. 

Example same qestion :- N = 6  coin : {4,3,1}
Greedy Approch :-  So sabse nearest or baraba ko select karo, through this method : 4+1+1 = 6  3coins
Optimal solution  :-  3+3 = 6  2coins

same question tha lakin ab greedy sahi answer nahi de raha. 

Note 1. Greedy hamesha kaam nahi karega. 

Divide Approch : To find the no. of coins we need to take. 
So ham N ko apne coins se divide kar rahe hai, if divide ho pa raha hai then us coin ko select kar leneg aur jiyni baar divide ho pa raha utni baar us coin ko le lenge.

Code Implementation :- 
```
vector<int> minPartition(int n)
{
    int currency[] = {2000, 500, 100, 50, 20, 10, 5, 2, 1};
    int notes = 0, i = 0;
    vector<int> ans;
    while (n)
    {
        notes = n / currency[i];
        while (notes--)
        {
            ans.push_back(currency[i]);
        }
        n %= currency[i];
        i++;
    }
    return ans;
}
```

### Shop in candy Store :- 
So we have given the array of N size. Where N means the total no of candy and the value represent the values of candy. So question asked for to buy each candy, so minimum value or cost calculate karke batana hai. Condition: We have given the K , which says that after buying the any of one candy it can take k no. of free candy. 

Greedy approch:- 
To calculate the minimum cost :-
Sabse pahle minmim cost wali candu ko le lenge phir uske badle k no. of highest cost wali toffie le lenge and so on karte jaynege jab tak sari candy n lele. Aur apne minimum wali ke summation ko return kar denge. 

To calculate the maximum cost :-
Sabse pahle maximum cost wali candy ko le lenge phir uske badle k no. of lowest cost wali toffie le lenge and so on karte jaynege jab tak sari candy n lele. Aur apne maximum wali ke summation ko return kar denge.

Steps :- 
Array ko sort kar denge, ek pointer aage se le lenge ek pichhe se. 
To caluclate minimum cost :- Starting pointer ke value ko ans mai daalo aur apne pichhe wale pointer ko k time chala do
Base condition :- Jab end pointer front se aage nikal jeyega tab ruk jana hai. 

Code Implemenataion :-
```
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

vector<int> candyStore(int candies[], int n , int k)
{
    sort(candies, candies + n); // ascending order
    int min_amount = 0 , max_amount =0;
    int i=0 , j=n-1;

    // Calculating minimum Amount
    while (i<=j)
    {
        min_amount += candies[i];
        i++;
        j-=k;
    }

    //  Calculating Maximum amount
    i=n-1, j=0;
    while (i>=j)
    {
        max_amount += candies[i];
        i--;
        j+=k; // starting ke k elemnt ko le lo
    }

    vector<int> ans;
    ans.push_back(min_amount);
    ans.push_back(max_amount);
    return ans;
}

```

Time Complexity :- nlogn

### Assign Mice to holes :- 
M naam ka array hai jisme, Mouse present hai, aur H naam ke array mai holes. Hamko mouse ko bill ke ander daalna hai kuchh is tarike se, minimum time hamko lage inko daalne mai. 
Example :- M:{4,-4,2}  H: {4,0,5}
1. Agar bolte hai ki 4 wale ko 0 hole mai daal do so 4 unit move karna hoga 
2. Agar bolte hai ki 2 walr ko 5 mai daal do so 3 unit move karna hoga
3. Agar bolte hai ki 4 walr ko -4 mai daal do so 8 unit move karna hoga
So isme se sabse badi unit/time jitna hoga wahi answer hoga hamara. 
Note :- Waise dekha jaye toh ham - he kar rahe hai. 

So agar ham sare combination nikale phir ans find kare toh kaafi muski ho jayegi ye karne mai. 
So ham Dono array ko sort kar denge, phir unke dalte chale jayenge ek ke baad ek hole mai. So ham greddy ban gaye sort karne ke baad jo bhi hole jis bhi chuhe ke pass mai usko usme daal denge. 

Code Implementation :- 
```
int assignMiceHoles(int n, int M[], int H[])
{
    sort(M, M + n);
    sort(H, H + n);

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, abs(M[i] - H[i]));
    }

    return;
}
```
 
### Minimum Rotation to unlock a Circular Lock
So hamko minimum kitne Rotation lagenge lock ko unlock karne ke liye.  Lock ko ham dono taraf ghuma sakte hai. 
Ex R = 2 2 2  , D= 3 3 3    ex R :2 3 6 5 8   D: 9 2 4 0
So R se D ko achieve karna hai. 2 se 3 jane ke liye 1 bar ghumana hai. 
NOTE :- Yaha bhi ham minus he kar rahe hai (absolute) So hamesha aise answer nahi nikalega is case mai, So hamko check karna hoga ki clockwise lock ko ghumane mai kitna time lag raha hai aur anti-clock mai kitna time lag raha hai. So iske liye ham 10 - absDifference usko update karnege ans mai. 
Clockwise :- AbsDifference nikalna 
Anti-ClockWise:- 10 - AbsDifference 
ClockWise aur Anti-Clockwise mai jo bhi minimum hoga wo ans mai daal denge. 

Code Implementation :- 
```
int rotationCount(long long R, long long D)
{
    int ans = 0;
    int first, second;

    while (R)
    {
        //  Last value ko pick kar rahe hai
        first = R % 10;
        second = D % 10;
        R /= 10;
        D /= 10;

        ans += min(abs(first - second), 10 - abs(first - second));
    }
    return ans;
}
```

### N Meeting in one Room :- 
So hamare pass Start aur End, array diya gaya hai so start of i mai  jo present hai wo meeting ka starting time hai aur End of i mai jo value present hai wo End time hai value ka. So hamre pass ek he meeting room hai aur hamko sare meeting yahi karna hai. So maximum kitne meeting ko organize kar sakte hai. 

So Yaha hamre pass overlapping condition aa sakti hai, So isko nahi hone ke liye, pahle wale meeting ka end time should be chhota then starting of the next meeting. 

Greedy Approch :- 
So jo starting mai start ho rahi agar mai usko usko choose kar le rahe hai than ye khatm jab ho raha tab uske baad wali meeting choose kar le rahe hai than so on agar exist karta hai. Is tarah hamari greedy approch se optimal answer nahi mil paayega. 
So jo meeting sabse pahle khatam hogi usko select karenge, and so on till jab tak start time of meeting is greater than end time of just pahle wali meeting. 
Note : End time ko sort karenge. So ham end time ke liye greedy bante hai toh hamko optimal solution mil saktha hai. Aur End time ke basis par he start time bhi sort hona chaiye nahi toh meeting ki timing starting aur ending time change ho jayengi. 

Code Implementation :- 
```
bool comp(pair<int, int> a, pair<int, int> b)
{
    //  agar order sahi hai then waise return kardo, warna swap karke de dega
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    //  Sort it on the basis of end time ascending order
    vector<pair<int, int>> timer;
    for (int i = 0; i < n; i++)
        timer.push_back({start[i], end[i]});

    //  Sorting timer based on  end value
    sort(timer.begin(), timer.end(), comp);

    int total = 0; // kitni meeting karwa sakte hai

    int ending = -1; // end time of meeting ko store karke rakhega

    for (int i = 0; i < n; i++)
    {
        if (timer[i].first > ending) // Privious meeting end time should be less than starting of next meeting
        {
            total++;
            ending = timer[i].second;
        }
    }
    return total;
}
```

1. Comparator (comp): Aapne custom comparator sahi likha hai. a.second < b.second ensure karta hai ki ascending order mein sorting ho.
2. Pairing: vector<pair<int,int>> use karna ek smart move hai, kyunki start aur end arrays ka connection (index) bana rehna chahiye sorting ke baad bhi.
3. The Logic: timer[i].first > ending check karta hai ki kya nayi meeting purani meeting ke khatam hone ke baad shuru ho rahi hai.