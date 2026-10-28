### Trapping Rain Water :- 
So isme hamko ek array diya gaya hoga , sorted or unsorted ho sakte hai, So jo value inke inder wo represent kar rahi hai utane height ka building. So Maan lo ki uppar se baarish ho rahi hai, so if baarish ho rahi hain then, paani kahi store hoga, so building saari, kisi solid jagah khadi hongi(base), building ke gap mai store hoga paani. So sabse pahle building ke left side aur last building ke right side paani bah jayega. So total amount of unit water batao. 

So kitna unit of water store ho sakta hai?
On a particular building  see the support you have been got from the left and right building, the min height b/w left and right building minus current building height, so aisa karte jayenge till n-1building.
-If no support then either left or right building then water on that building will be flow out. 

Brute force Approch :- 
ki har ham building pr jaye aur puchhe ki tumhare left side and right side konsa sabse bada building hai, usko laa kar do, usme jo minimum ho usko lo aur apne current buliding ki height ko minus kardo. and so on aisa karte jaaye til the last -1 building.

2nd Approch :- 
So isme ham  do array bana lenge , maxright and maxleft naam ka of same size of given array, then isme  current position ke according maxleft and maxright store karwa lenge. 
- maxleft ke liye ek for loop chalayenge i=0 se i lessthen n tak, usme max() ke through value ko apne array mai upadate karte jayenge.
- maxRight loop ko pichhe se chalayenge aur max() ka use karke maxRight array fill kar denge. 

An ek aur banayenge asn array :- 
- min(maxLeft,maxRight) -> support itna ka hai on current building
- support - current buliding height = unit of water that can be stored on that building. Is value ko answer array store karte jayenge. 

return the total sum of the answerArray. 

Time Complexity : O(n)
Space Complexity : O(n)

```cpp
vector <int> height ;
leftMax[n] , rightMax[n];

leftMax[0]=0;
for(int i=0;i<n;i++)
leftMax[i] = max(leftMax[i-1], height[i-1]);

rightMax[n-1]=0;
for(int i=n-2;i>0;i--)
{
    rightMax[i] = max(Rightmax[i+1], height[i])
}

int water =0;
for(i=0;i<n;i++)
{
    minheight = min(leftmax[i], rightMax[i]);
    if(minheight - height[i]>=0)
    water+=minheight-height[i];
}
return water
```

### Optimized Approch :-
Is approch mai time complexity same rahegi as 2nd method but space complexity ko reduce karna hai O(1).

So agar hamko kisi bhi paricular building par jaate he hamko pata chal jaaye ki uske left and right side mai sabse bada building konsa hai toh hamara kaam ho jayega. 
- so hamko left ka toh sabse bada pata chal jayega kyuki ham left side se he chal rahe hai, right ka sabse bada kaise pata chal jayega? So kya ham aisa kar sakte hai ham sirf left wale ko he use  kare  means  ki min(minLeft,maxRight) se hamesha minleft he hamesha bahar nikle. 
- So ye possible tabhi hoga jab maxRight bada hoga maxLeft se. 
- So ham sabse bada building khoj lenge toh hamari problem solve ho jayegi. for this we need to traverse the array once. 
- So ab jaha bhi maximum value present hai hamare array mai waha tak answer nikal sakte hai. kyuki waha tak toh min(leftMax, rightMax) =  leftMax he hoga

Logic :-  
leftMax = 0, initially because starting mai jo building hai unko kisi ka support  nahi hai. 
- so leftMax - current building = water unit
- so water mai agar -ve value aati substraction ke baad tab usko water mai add nahi karenge. 
- leftMax(leftMax, currentBuilding)

So max Building tak pahuch jane ke baad :-
- ab hamko ye pata hoga ki iske baad building ya toh max building ke barabar hongi ya toh max building ke sse chhoti. 
- So same logic phir se use karenge for maxRight ke liye ab(means sab ulta)
  - maxRight = 0 (for same reason)
  - maxRight - currentBuilding 
  - ye karenge, badi building -1 tak kyuki upper badi building ko include kar liye the, koi bhi pani drop nahi add hoga is building ka as no support.

Code Implementation :-
```cpp
int trap(vector<int> height)
{
    int n = height.size();
    int leftMax = 0, rightMax =0, maxHeight = height[0], index=0, water=0;

    //  Max Height of the building
    for(int i=1;i<n;i++)
    {
        if(maxHeight<height[i])
        {
            maxHeight = height[i];
            index = i;
        }
    }
    // Left part
    for(int i=0;i<index;i++)
    {
        if(leftMax>height[i])
        water+=leftMax - height[i];
        else
        leftMax = height[i]; // updating leftMax
    }

    //  Right Part
    for(int i=n-1;i>index;i--)
    {
        if(rightMax>height[i])
        water+=rightMax - height[i];
        else
        rightMax = height[i]; // updating rightMax
    }

    return water;
}
```

4th method :- 
Iske pahle method mai hamne, Do baar traverse kiya tha , one for finding the maximum element and one for the calculating the water. So if the Interviewer asked to solve this question in the single traverse then what to do? 
So jab bhi mutiple traverse mai answer nikal rahe hai hamko bole ko single traverse nikalne ke liye then we know ki two pointer ka concept he sirf answer nikal de sakta hai. 
Hint - ek pointer starting mai rahega aur ek pointer end mai. Find the answer as an Homework. 

### 3 Sum 
So hamko ek array diya hoga, usme kuch no present(generally unsorted), aur X diya hoga. Hamko batana hai ki kya array mai se koi tin no. add kare toh wo X ke barabar aa sakta hai, if answer possible then return  1 and if no then return answer no or 0.

Brute Force Approch :- 
- So hamko tin no. chaihiye for the sum to verify ki wo X ke equal ki nahi so we need the three loop. 
  - i=0 se start hoga aur i less than i-2 tak chalega
  - j=i+1 se start hoga aur j less than n-1 tak chalega
  - k = j+1 se chalega aur j lessthan n tak chalega
     - agar arr[i]+arr[j]+arr[k]==X then return 1. 
- return 0;
Time Complexity : O(ncub)

2nd Approch :- 
- Isme sabse pahle apne array ko sort kar denge. 
- So sort karne se ye fayda hai ki ham binary search laga sakte hai
working :- 
A+B+C= X
C = X-A-B
so see ko binary search ke help se search karenge.  
Time Complexity : O(nsqlogn)

```cpp 
for(int i=0;i<n-2;i++)
{
    for(int j=i+1;j<n-1;j++)
    {
        find = X - arr[i]-arr[j];
        start= j+1; end = n-1;
        Binart Search Algorithum
    }
}
```

3rd Aprroch :- 
- So isme sabse pahle X minus current position karenge so uska jo bhi answer aaya hai usko result variable mai store kar lenge. 
- ab check karenge ki kya koi do no/element ka sum result ke barabar aa raha hai ki nahi.
- if ans bada aa raha hai aur we expect ans kam aaye then end ko -- kar denge
- if ans chhota aa raha hai aur we expect ki answer aur bada ho then start ++ kar denge

Note so :  2 sum wala concept use kar rahe hai or 3 sum ko 2 sum mai convert kar deye hai.
```cpp 
bool find3Numbers(int arr[], int n, int x)
{
    //  Sort the given array : Bubble Sort
    for(int i=n-2;i>=0;i++)
    for(int j=0;j<=i;j++)
    if(arr[j]>arr[j-1])
    swap(arr[j], arr[j+1]);

    for (int i = 0; i < n - 2; i++) // Choosing the first element
    {
        int ans = x - arr[i];
        int start = i - 1, end = n - 1;
        while (start < end)
        {
            if (arr[start] + arr[end] == ans)
                return 1;
            else if (arr[start] + arr[end] > ans)
                end--;
            else
                start++;
        }
    }
    return 0;
}
```
 