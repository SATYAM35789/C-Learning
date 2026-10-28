### Peak Index in Mountain Array :- 
So hamko ek array diya gaya hai, jisme pahle no increse kar rahe hai, phir decrese kar raha. So i want to tell you that why this problem is called the mountain , so if represent this no on, then we see the moutain like structure. So isme jo sabse peak element hai uska answer return karna hai. 

Brute Force Approch :- Linear Search
It simple as finding the maximum element in the array, we start from the linear searching and on every index we check ki kya no, abi jo maximum no. hai hamare pass us se bada hai ki chhota if bada then value update mat karo aage cahle jao usko check karo, if bada then updete it as maximum element. 

Second Approch :-  Binary Search 
Note :-  Ham Binary search waha bhi laga sakte hai, jaha hamra array do portion mai divide ho jisme pahle wo increse kar raha hai phir decrese kar raha hai. (ye increse decrese/ decrese increse/ ). 
-Binary search ka jo measure task hota hai, jisme ham sabse pahle middle ke pass jate phir dicide karte hai ki left jana hai ki right jana hai. 

Intution :- Peak he aisa ek element hai jo, jiske left and right dono side is se chhote element hai. Means peak element apne left and right dono element se bada hota hai. 

Code Part :- 
- Agar arr of mid bada hai arr of mid-1 se aur arr of mid+1 se 
  - tab answer mil chuka hai hai return kardo do mid ko
- agar arr of mid bada hai arr of mid -1 se tab 
  - hamko right side jana hai, start = mid+1
- Agar dono mai se, kuchh bhi nahi hai, means arr of mid chhota hai arr of mid-1
  - tab hamko left side move karna hai, end mid-1 daal do. 

Time Complexity :- O(logn)
Space Complexity : O(1)

Code Implementation :- 
```cpp
 Basic Code
 int peakIndexInMountainArray(vector <int> &arr)
{
    int start=0, end = arr.size()-1, mid;

    while(start<=end)
    {
        // mid = start+(end-start)/2;
        mid = end + (start-end)/2;   // Optimized line

        // Peak element
        if(arr[mid]>arr[mid-1]&& arr[mid]>arr[mid+1])
        return mid;
        // Right side Move
        else if(arr[mid]>arr[mid-1])
        start = mid+1;
        // Left side move
        end = mid-1;
    }
    return -1;
}
```

### Rotated Array :- Increse Increse Pattern Form ho raha hai
So isme hamko ek normal ascending order ka array hoga, uske different roteted forms honge like Rotate by shifting one,two, etc So inme se kisi bhi roteted form diya hoga aur bolega ki hamko sabse chhota element find karke batao. 

Brute Force Approch :- Linear search :
Ek ek karke sare element ko compair kare jo sabse chhote hoga usko return kar denge as answer. So this method take O(n) time complexity and we have the Optimized Approch 

Optimized Approch :- Binary Search 
So hamko pata hai ki jab bhi hamre koi aisa array hota hai , jisko ham do portion mai divide kar paa rahe hai, aur ye dono portion sorted hai then Binary search laga sakte hai. 

Intution :- Koi bhi element, apne left side ya right side side sorted hoga. 

So hamko kaise pata chalega ki kis side sorted hai? 
Ye ham karenge by commpairing the 1st element with mid every time, 
- Agar arr of 0 chhota hai arr of mid se then left side sorted  hai
- Agra arr of 0 bada hai arr of mid then Right side sorted hai 

Jaha se chhota side element start ho raha hai hai array mai wahi hamara ans hoga.

-So agar hamko ye pata hai ki ye left side sorted form mai iska mat lab hai ki, so hamko chhota element right side mai milega,(we confirm by making the graph representation of an array).
  => Left side sorted hai -> Right side jao

-So agar hamko pata hai ki right side sorted form mai hai then then hamko ye pata hai ki hamko chhota element right side ko he mil sakta hai.
    => Right side sorted hai -> Left  side jao 

Code Part :- 
- Agar arr of mid bada hai ya barabar hai arr of 0 ke tab (ascending order)
  - start = mid+1 (right side move)
- Agar uppar wala condition nahi hai means ki arr of mid chhota hai hai arr of 0 (Right side sorted)
  - ans = arr[mid]
  - end = mid-1

If rotation not done in the array toh kya ye logic us case mai bhi kaam karega so is case mai ye code fail marega iske liye hamko, If data already sorted so iske liye apne ans ko initialize kardo arr[o] tab answer mai kuchh nahi hoga then arr[0] he hamara answer hoga. 

Code Implementation :- 
```cpp
int findMin(vector<int> &arr)
{
    int start=0, end = arr.size()-1, ans=arr[0], mid;

    while(start<=end)
    {
        mid= start+(end-start)/2;

        // Left side sorted Array
        if(arr[mid]>=arr[0])
        start = mid+1;
       
        //  Right Side Sorted Array
        else
        {
            ans = arr[mid];
            end = mid-1;
        }
    }
    return ans;
}
```

### Search in Rotated Array :- 
So hamko ek rotated array diya gaya hoga jisme hamko koi bhi element diya gaya hoga, isme usko search karna hai. uske index dena hai. If not present then return -1. 

Brute Force Approch :- Linear search
Ek ek karke jakar search kar sakte hai ki koi element present hai ki nahi. 

Optimized Approch :- Binary search :
So yaha upper wala concept use kar rahe honge, mid se left side jaye ki right side jaye for the answer, ye kaise decide karenge, So array ek side se sorted hoga he hoga, isko pata karne ke liye apne arr ke first element ko mid se compair kar lenge so ki pata chale ki kis side se sorted hai. So if we search for the element , toh hamko ye pata karna hoga kya wo is range (arr[0] to arr[mid] // arr[mid] to arr[end]) aa sakta hai ki nahi. If us range mai nahi aayega toh array ke dusre portion mai khojenge. Yahi basically kar rahe honge. 

So Sorted array se pata chala gaya ki jo element ham search kar rahe hai wo, range mai ki nahi. So agar mere range mai nahi toh confirm ho jayega ki wo opposite side mai milega. 

Code Part :- 
- Agar array of mid barabar hai target ke tab
  - mid ko return kardo, as an answer
- Left side : Agar array of mid bada hai ya barabar hai array of 0 ke tab check karo ki target array of se array of mid bich mai exist karta hai ki nahi
   - agar array of start chhota hai aur barabar hai target ya array of mid bada hai  target ke tab
      - end = mid-1 kardo
   - agar wapar condtion matchnahi hota hai toh
      - start = mid+1 kardo.
-Right side :
     note Check kar rahe hai ki target, mid se end ke bichh hai toh kya karenge
     - Agar array of mid chhota hai ya barabar hai target ke aur array of end bada  hai target ke tab
        -start = mid+1
     - else: nahi toh dusre side chale jao (left side)
       - end = mid-1

Code Implementation :- 
```cpp
int search(vector <int> &arr, int target)
{
    int start =0, end=arr.size()-1, mid;

    while(start<=end)
    {
        mid = start+ (end-start)/2;

        // Found the element
        if(arr[mid]==target)
        return mid;
        // Left side sorted
        else if(arr[mid]>=arr[0])
        {
            // Checking ki target left side mai hai ki nahi
            if(arr[start]<=target&&arr[mid]>target)
            end = mid-1;
            else
            start = mid+1;
        }
        // Right side Sorted
        else
        {
            if(arr[mid]<target && arr[end]>target)
            start = mid+1;
            else
            end = mid-1;
        }
    }
    return -1;
}
```

### Kth Missing Positive Integer :- 
Ek array mai sorted order mai(ascending), hamko puchha hai ki kth missing in integer kya hai. 

Brute Force Approch :- 
Dekho positive integer start hota hai 1 se, so ham start karenge 1 se search karna kya 1 present hai ki nahi if not present apne missing count ek se bada denge, next go next to check present then go for next check directly and if not present then update the missing count, and so on. If missing count is equal to kth then return that positive number. 

Optimized Approch :- 
So Is approch mai ham ye maante hai ki, agar jitna bhi array ka size hai agar koi no miss nahi hota toh us array kon kon se number aate, that is from 1 to size of array tak hote. 
- So if present array, jo hamko question mai given hai, usme ham us ideal condition wali array ko minus karenge toh hamko jo answer milega wo us postion tak ka missing positive integer ke barabar hoga. 
- isme jo missing term hoga wo pichhla missing  term bhi include hoga. 
- ideal condtion generate karne ka formula -> arr[i]-i-1
- kth term mai lies between two missing term(in the ideal array), jaha bhi kth lies kare uske just pichhle wala missing term ko lenge jo batayega ki kitna missing no abhi tak, maan lo us se asociated index value pata chal gaya jo given array mai hoga, then +1, karne se next missing number pata chal jayega. 
- jo bhi kth hai, pata karenge uski correct postion kya hoti in ideal condtion, ham us position par chale jayenge in the given array.Is se hamko correct index pata chalega, kth missing number aata. 
- Agar koi do number hai , toh uski 1st occarance he correct position hoga. Dekho 1st occarnce he hoga kyuki , do same occarnce ke bich mai 0 missing term hoga. 

Correct index find karna, ham previous lecture mai dekh chuke hai.(insert wala)

Note :-
- So missing term jitne bhi hamko milenge, usko ek array mai store karke rakhenge, phir usme kth term ko uski correct postion par insert karenge so ki hamko correct position mil jaaye. 
or isko generate karne ke bajaye ham ye formula use kar sakte hai arr[i]-i-1

Code Part :- 
Part1 Finding the index of the kth 
-agar arr of mid -mid -1 bada hai ya barabar hai k tab
  - ans mai mid daal do
  - end mai mid -1 
- agar aisa nahi hai tab
  - start mai mid +1 kardo

Part1 mai hamko sirf answer pata chala hai, index of the kth missing positive integer
So to find out the answer :
  - ans+k, jo hamara index aaya hai wo aur kth ko add karenge toh hamko hamara positive integer mil jayega.  
  - Ye aaya hai pattern ko analysis karne ke baad, Jo kth ke baad just bada missing term wala index value usme 1 minus karenge toh , -2 karenge,- 3 karenge ans so on so hamko unke bich ka missing term milte jayega in decresing order of missing term. 

  kth misssing term = arr[index] - (arr[index]- index -1 -k+1)
                    = index +k

Note: If already sorted than, iske apne ans ko initialize karna hoga
   ans= arr.size()


Code Implementation :- 
```cpp
int findKthPositiveInteger(vector <int>&arr, int k)
{
    int start=0, end=  arr.size()-1, mid, ans= arr.size();

    while(start<=end)
    {
        mid = start + (end-start)/2;

        // left side
        if(arr[mid]-mid-1>=k)
        {
            ans = mid;
            end = mid-1;
        }
        else // Right move
        start = mid+1;
    }
    return ans+k;
}
```
