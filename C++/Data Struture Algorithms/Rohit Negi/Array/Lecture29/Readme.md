### Prefix and Suffix :- 
Prefix : Jo starting se suru ho raha hai. 
Suffix : Jo ending se suru ho raha hai. 
prefixSum :- starting se abhi tak ka sum at a pariticular index. 
-So if someone ask for the prefixsum then hamko ek array nikalna banana hoga same size ko aur usme for loop ke help se present value tak ka sum karte jayenge.
Code Part :-

```cpp
vector <int> prefix(n);
prefix[0]=arr[0];
for(int i=1; i<n;i++)
{
    prefix[i]=prefix[i-1]+arr[i];
}
``` 
SuffixSum :- Jo prefixsum ka ulta hota hai, isme ham pichhe se present value tak ka summation rakhte hai.  

SubArray : Array ka kuchh part jo jiske element countigous hone chahiye. As in a original array.
If array ka size n hai then :- 
1 size ka : n subarray banega
2 size ka : n-1 subarray banega
3 size ka : n-2 subarray banega
...
n size ka : 1 subarray banega

So with the help of loop we have to print the all the subarray of the array, pahle one wala then , phir two wala, then so on. 

### Divide array in 2 Subarray with equal sum
So hamko ek array diya hoga, hamko unko do sabarray mai divide karna , aur in dono subarray ka sum barabar hone chahiye. So if aisa possible hai, then yes print kardo and if not possible then no print kardo. 

Brute Force Approch :- 
So isme ham pahle ek element ko alag karenge and check karenge kya in dono ke part barabar hai, if not then pahle element and dusre element ka sum bache hue array element se karenge, if not same then same procedure ab 3 element ko lo and other element and do so on till found the ans. 

Code Part :- 
n-1 : because ki last element par ja kar thodi cut karenge / divide karenge (for the 1st part and 2nd  part)
```cpp
for(int i=0;i<n-1;i++)
{
    int sum1=0; sum2=0
    for(j=0;j<=i;j++)
    sum1+=arr[j];
    for(j=i+1;j<n;j++)
    sum2+=arr[j];
    if (sum1==sum2)
    return 1;
}
return 0;
```
Time Complexity : O(nsq)

2nd Approch :- 
- So sabse pahle given no. of array ka TotalSum nikal lo. 
So starting se abhi tak ka sum nikal sakte hai, lakin current position se n tak ka sum kaise nikalega. So uske liye TotalSum - start to current position sum. 
- iske baad starting to current aur current to end tak ka sum ko compair kar lenge if not equal then i(currentposition) ko ++ kar denge. 
- so if found equal then it means ki arrau ko do part mai divide kar sakte hai. 

Code Part :- 
- ek int type ka TotalSum jisme array ki sare element ka Sum isme store karenge, isle liye ek for loop lagayenge ek ek karke saare element ko TotalSum mai store kar lenge. 
- ek prefixSum lenge jisme, current position tak ka sum rahega. 
- ek for loop chalayenge from i=0 se lekar i lessthan n-1 tak for the same reason 
  - prefixSum+=arr[i];
  - current(current+1) se n tak ka sum = TotalSum-PrefixSum(ans=TotalSum-prefixSum)
  - agar answer barabar aata hai prefix ke tab return 1 kardo. 
- return kardo 0 , answer not found yet

Time Complexity :- O(n)

Code Implementation :- 
```cpp
bool divide(vector <int>arr)
{
    int  prefixSum=0, totalSum=0 , n=arr.size();
    // Total Sum
    for(int i=0;i<n;i++)
    totalSum+=arr[i] ;

    for(int i=0;i<n-1;i++)
    {
        prefixSum+=arr[i]; 
        int ans = totalSum- prefixSum; // RightSubarray ka sum
        if(ans==totalSum)
        return 1;
    }
    return 0; 
}

int main()
{
    int n;
    cout << "Enter the size of an array :";
    cin >> n;
    vector<int> v(n);

    cout<<"Enter the element in the array :" ;
    for (int i = 0; i < n; i++)
    cin >> v[i];

    cout<<divide(v);
}
```

### Largest Sum Contigous SubArray :- 
So hamko ek array diya gaya hoga, uske bahut saare subarray banenge, un sabhi sab array ka kuchh Sum hoga, usme jo sabse bada Sum hoga wo return karna hai, as an answer. 

So hamko ek homework mila tha ki, Hamko saare subarray ko print karna hai ek given array ka, Brute force approch se, O(ncube). 

Brute Force Approch :- 
So isme pahle 1 size ka subarray nikalenge, usme jo sabse bada hoga wo hamra possible solution hoga, similarly 2 size ka, 3 size ka so on till n-1 size tak, so in sab mai se jiska sum sabse bada hoga wo hamara answer hoga. 
- or Simply ek given array ka saare subarray ka sum nikalna hai, jis bhi subArray ka sum sabse bada hoga usko as a answer maan lenge. 


2nd Method :
So is approch mai, if array = {4,-6,2,8} , index are 0,1,2,3
- {0}, {0,1}, {0,1,2}, {0,1,2,3}  -> prefix sum -> usme jo sabse bada hai = possiblr ans
- {1}, {1,2}, {1,2,3} -> prefix sum -> unme jo sabse bada = possible ans
- {2}, {2,3}   -> similarly
- {3} -> similarly

In upper wale combination, mai se koi ek hamara answer hoha. 
- saare possible answer mai jo sabse bada hai, wo hamara answer hoga.

Code Part :- 
```cpp
maxi = INT_MIN;
for(int i=0;i<n;i++)
{
    prefixSum=0;
    for(int j=i; j<n;j++)
    {
        prefixSum += arr[i];
        maxi = max(maxi,prefixSum)
    }
}
return maxi;
```

### Kadan's Algorithum :- 3rd Approch : O(n)
So is approch mai do variable lenge, prefixSum and Maxi, jaha prefixSum, apne current position tak ka sum store karega, aur maxi store karega maximum of prefixSum and maxi(initially Int_min). So isme ye maan ke chalenge ki jaha hamko prefix sum ka sum -ve milta hai, waha ke prefixSum ko ham 0 maan lenge. 
Is approch ko Kadan's Algorithum bhi kahte hai.
So Simply hamko toh largest sum find karna tha. So yaha ye algorithum bolta hai ki jab bhi prefix 0 dikh jaye then prefixSum ko 0 bana do. 

So hamko aisa kyu karna hai? 
Kyuki max function mai daalenge toh wo prefix sum aur iske maxi mai se bada lega , so wo prefixSum automatically remove ho jayega so ham usko 0 bhi maan sakte hai. 
Why 0 bana do?
- so as subarray want to join an other subarray to give the maximum, so Agar subarray jud raha aur wo -ve ho raha hai then subarray  aisa kyu chahenge, so us subarray ko Summation ko 0 maante as ki us subarray ke hone se usko koi impact n pade.(value kam n ho)

```cpp
long long maxSubarray(int arr[], int n)
{
    long long maxi=INT_MIN, prefixSum = 0;

    for(int i=0;i<n;i++)
    {
        prefixSum +=arr[i];
        maxi = max(prefixSum, maxi);
        if(prefixSum<0)
        prefixSum=0;
    }
    return maxi;
}
```

### Maximum Difference between two element
So isme hamko ek array diya gaya hoga, aur hamko isme se maximum difference batana hai. Condition ye hai ki current position par jo element hai wo apne right ke element se minus hoga. 
So if ye simple array hota then ham isme sabse chhota element khojte and phir sabse bada element khojte phir unko minus kar lete. Lakin yaha current element ko as smaller element and right side of the current element mai jo bada hoga, uska differnce he hamra as possible answer hoga. 

Brute Force Approch : O(nsq)
- current posotion, starting se bada element milta hai right side then unka differnce nikal lo. So aur koi hoga toh usko max() ka use karke abhi tak ka maximum differnce aur jo abhi just aaya hai usme jo bada hoga usko , store kar lenge ans mai and so on karte jayenge. 

``` cpp
int ans = INT_MIN;
for(int i=0;i<n-1;i++)
{
    for(int j=i+1;j<n;j++)
    {
        ans = max(ans, arr[j]-arr[i]); 
    }
}
```

optimized Approch :- 
So if hamko, pata chal jata ki current element ke right side konsa sabse bada element hai. Then ham directly us se differnce nikal lete. For this hamko suffixMax ka use karna padega. 
Suffix max :- current postion se(exclude) end tak mai jitne bhi number hai unme abhi tak maximum element ko store karke rakhe rahega. 
So Apne se ek baad wale ko current element check karle ki uska suffixMax kitna hai then wo directly difference nikal sakta hai. So ek array mai saare ke suffixMax ko store kar lenge. 

So sare difference nikalte jayenge unme se jo bada aate jayega max() ke help se current maxdifference aur jo maxi jo pahle se bada hai usko daal ke maximum nikalte jayenge. 

3rd Optimized Approch :- 
- last of array suffixMax(sameElementhoga)
- apna loop last n-1 se chalayenge 
- so ab differnce niaklenge aur max()se maximum ko update kar rahe honge
- loop ko ek aur kam karne se pahle apne suffixMax ko update karenge with max() , present suffix aur arr[i] jaha abhi loop hai usme se kon bada hai. 


