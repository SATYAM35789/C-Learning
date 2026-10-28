## Binary Search different problem :-

### First and last postion of element in the sorted array 
Incresing order :-  So incresing order mai, jo number hote hai wo repeat ho sakte hai.
strictly Incresing Order: Isme jo no hai repeat nahi ho sakte hai. 

So hamko array diya hua incresing order mai,  so isme hamko ek target value diya gaya hoga, jisme hamko batana hai ki target first occurance kaha hai aur last occurance kaha hai. So occrance ka index hamko return karna hai. 

Approch :- Brute force approch 
So ek baar aage se linear search apply karo aur first occarnce pata karlo, and ek baar linear search last se laga lo jis se last occance pata chal jayega and you find out the answer. 
Time complexity :- n +n = O(n)
-Jab target, present  nahi hai  toh -1, -1 return karenge. 

Approch 2nd :-  Binary search 
Is approch main logic wo hai jab hamko hamara target mil ja raha hai tab, ham check kar raha hai ki kya left side mai koi target value toh nahi hai n, iske liye ham present target ke index ko store kar lete hai so ki agar left side present nahi hai toh yahi answer de de if present then update wali de de. 

Similarly approch ham ek dam last occrance pata karne ke liye bhi kar rahe honge lakin ab end ko nahi balki start ko update and store kar rahe honge. 

code part :- 
First part :- First of target ko find karna
- int type ka start =0, end=n-1, mid, first=-1, last=-1 (-1 because, if target is not in the array then -1 return ho)
- ek while loop chalayenge, jo tab tak chalega tabtak start chhota aur barabar hai end ke
   - mid ko update karenge pahle , mid = start + (end-start)/2
   - if(arr[mid]==target) then
      - first mai mid daal do (storing value, target found)
      - end mai mid -1 daal do (left side check karne ke liye)
   - else if(arr[mid]<target)
     - start mai mid+1 daal do
   - else 
       end mai mid-1 daal do. 
Time complexity = logn

Second Part :- Last of target ko find karna hai
similarly all, change will be only on 
if(arr[mid]==target)
  - last = mid
  - start = mid+1 
Time complexity = logn

Overall Time Complexity = logn+ logn = 2logn = logn

Code Implementation :- 
```cpp
vector<int> searchRange(vector<int> &nums, int target)
{
    int start =0, end = nums.size() -1, first =-1, last=-1, mid;

    //  Find First
    while(start<=end)
    {
        mid = start + (end-start)/2 ;

        if(nums[mid]==target)
        {
            first = mid;
            end = mid -1; // left mai aur kahi toh target hai ki nahi
        }
        else if(nums[mid]<target)
        start = mid+1;
        else 
        end = mid-1 ; 
    }

    // Find Last
    start = 0, end = nums.size()-1 ;
    while(start<=end)
    {
        mid = start + (end-start)/2 ;

        if(nums[mid]==target)
        {
            last = mid;
            start = mid +1; // mid ke Right mai aur kahi toh target hai ki nahi
        }
        else if(nums[mid]<target)
        start = mid+1;
        else 
        end = mid-1 ; 
    }

    // Ab Hamko vector ke form mai, start aur last , jindex kp wapas karna hai. 
    vector<int> a(2);  // syntex vector<datatype> name(sizeofvector)
    a[0] = first;
    a[1] = last;

    return a; 
}
```

### Search Insert Position :- 
So is question mai hamko strictly incresing order mai value diya gaya hai, so ab hamko pata karna hai jo target agar present hai us order mai toh hamko uska index wapas karna hai. Maan lo koi aisa element hai jo us order mai nahi hai tab hamko batana hai agar wo present hota toh kis index par present hota. 

Brute Force Approch :- Linear search :- 
So isme apne target ko starting se sabse compair karte jayenge ki kya wo target ke equal hai? If not equal , so agar chhota hai toh aage he kahi aayega, if found match then return the index, we found answer. 
Is case mai jab first time bada element milega tab, samajh jayenge ki yahi uski correct postion hai. Toh output mai wo index de denge.
Time Complexity :- O(n)

Note :- So jab bhi Sorted form mai data diya gaya hai, tab bahut high chances hai ki waha binary search lag raha hoga. 

Second Approch :- Binary search 
So isme ham, directly mid par chale jayenge , aur compair karenge ki kya mid target se bada hai, if yes then left side ki aur search karna hoga, so left move karne se mid ke index ko store karwa lenge because aisa ho sakta hai ki left side sabhi element hai wo target se chhote ho, if chhote hota hai toh answer mid wala he dena padta.

Note :- Jab mid chhota hai, target se tab hamko value ko store karwane ki koi zarurat nahi hai, kyuki jo answer hone ki probability ya toh order mai mil jaye ya first badi value mile target se. 
- so jab last value of the order is smaller then the target then wo phir bolega ki right side khojo, lakin right side toh kuchh hoga he nahi so is case mai n(size of array) he hamara answer ho jeyega.
  - so index mai intially ham n ki value store kar denge so jab answer n mile tab n ko return kar de.  

Time and space Comexity :- O(logn) , O(1)

Code Implementation :- 
```cpp
int searchInsert(vector<int> &arr, int target)
{
    int start =0, end = arr.size()-1, ans = arr.size() , mid;  // ans=index
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(arr[mid]==target)
        {
            ans = mid;
            break;
        }
        else if(arr[mid]<target)
        start = mid+1; // Right side search
        else
        {
            ans = mid;
            end = mid-1;
        }
    }
    return ans;
}
```

### Squre Root of X:- 
Jo bhi target hai, uska squreroot return karna hai. 

Brute Force Approch :- Linear Search
Ham start karenge from 1 se aur uska squre nikalenge aur check karenge kya squure value barabar hai target ke if not then go for the another 2 then 3 and same check karte jayenge tab Squre barabar nahi aa jata target ke. 
So is process mai agar next squre agar target se bada aa jayega toh pichhle squreroot ke he as answer return karenge. 

Approch 2nd :Binary search (Optimized Approch)
So is approch mai ham, jo bhi target value diya hai uska mid nikal rahe hai, phir uska squre nikal rahe hai, phir jo answer aaya hai squre nikalne par usko compair kar rahe hai target se if target chhota hai then ab left side search kar rahe hai as ki ab jo squreroot hai wo ab 1 to mid-1 ke bich mai hoga and if target bada hai squre ke reseult se then (right side move) is squreroot ko store kar lenge as potenitial answer, and do the same process so on. 
Termination condition same rahega.

Code Implementation :- 
```cpp

   //  Basic 
   int mySqrt(int x)
{
    int start=0, end= x , mid, ans;

    while(start<=end)
    {
        mid = start + (end-start)/2 ;

        if(mid*mid==x)
        return mid;

        else if(mid*mid<x) // Right side move
        {
            ans = mid;
            start = mid+1;
        }
        else
         end = mid-1;
    }

    return ans;
}

//  Optimized Code
int mySqrt(int x)
{
    if(x<2)
    return x;
    int start = 0, end = x, mid, ans;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (mid==x/mid)   // equal to mid*mid==x
            return mid;

        else if (mid<x/mid) // Right side move ans mid*mid<x
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}

```

Note :- So kabhi bhi error jo hota in the online round, so hamesha error ya chhote value ke liye marega ya phir sabse badi value ke liye. 

### Kth missing integer
So hamko ek array given hai, strictly incresing order mai, so isme ham 1 se start karenge search karna check karenge kya 1 present hai array if not then found 1st missing no. and if yes then go for next and so karte kth missing vaalue ko find karenge.  