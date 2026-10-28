### Book Allocation :- 
So isme ek array diya gaya hoga soretd form mai, jisme har element represent kar rahe hai, book ko. Har ek element ek represent kar raha hai, aur uske ander ki value us book ke no. pages ko represent kar raha hai. 
Jisme hamko M ki value diya hoga. M represent karega no. of student ko. So Books ko M no. of student ke bich mai distribute karna hai.Distribution ki condition :- 
- sabhi student ko kam se kam ek book toh mile he mile
- Book ka allocation, countigous way mai hona chahiye means ki 1st / 1st , 2nd / 1st , 2nd, 3rd Is order mai de sakte hai. Na ki 1st 3rd book de diya.
- Out of all parmutation, student with most number of books get min pages :- jitne bhi tarike se ham books ko distribute kare students ke bich mai, sabse pahle uske page ko count karlo, jiska page jayda hai usko as would be answer maan , ye calculation saare possible distribution ke sath karenge. Saare possible distibution mai jiska would be answer sabse kam hoga wo answer hoga. 

General solution :
Maan lo hamare pass abhi sirf do condition fufilled karni hai, so hamare pass agar do student hai, toh ham chahyenge ki dono  ko barabar no of pages ki book mile, if aisa possible n ho then , chahenge ki uske bich ka difference kam se kam ho. So isme se jis bhi bache ke pass maximum pages hai hame, un pages ko wapas karna hai.  
Deciding ki distribution kaise karna hai?
-So ham maan lo 1 se start karte aur puchate jaate hai ki kya ye itne no. of page student ko de sakte hai?
 Maam 1 element ke no. pages de sakte but no incresing order mai so next no pichhle wale se bada hai, toh wo no dusre stude ko nahi de paayenge so ham phir capacity of student ke no. of pages ko badate jayenge, tab Aisa pahla maximum no. ka mil jaye jisme distribution of pages de dono student ko mil jaaye. 
 - So 1 se start karne ke bajaye, maximum no of pages ke values se start karte hai , distribution ko karna.Kyuki ye bhi book kisi n kisi ko milegi he so pahle he student ki capacity utani he kar dete hai. 

So basically ham sabse bade no mil ne ke baad , ek ek karke ye check kar rahe hai ki, minimum kitani capacity rahe stusents ki toh ham books ko distribute kar paaye  sabko. 

So maximum ke baad ham ek ek karke aage bad rahe hai apni condition ko match kar rahe hai, toh ye linear search jo ki brute force approch hai. 

Optimized Approch :- Binary Search  
So Iske liye max element ke baad jump ek ek karke nahi hoga, mid par jaayenge and kucch decision lenge.
So isme answer nahi milega toh ham right side ko jump kar rahe hai. If found answer then left side aur usko store kar le rahe hai. Squreroot wale problem ka concept use hoga yaha. 
End point : Maximum no of page ka allocation :- Summation of all the element or books . (collection of all no. pages)
Start point hai: Maximum element/ jis book mai sabse jayada pages hai wo 

Dostribution logic :- 
-count mai 1 ka matlab , student one ke pages ko count kar rahe hai ki , kitne pages or Books ko wo contain kar sakta hai, isme ek page naam ka variable hoga jo different books ka pages ko count kar raha hoga. Agar pages ke value bada ho jata hai mid ke tab iska matlab hai ki ab next book add nahi ho payega, we need the next student.
- Next student ke liye count ko 2 daal denge, aur pages ko phirse O se start karenge, taaki nayi book ka collection rakh paaye. 

Code Part :- 
- Do variable lenge, ek page jiske ander 0 daal denge aur ek variable lenge count jisme 1 daal denge jo represent kar raha hai student 1 ko.
- ek for loop chalayenge i =0 se i lessthan n tak
  - page +=arr[i] kar denge
  - so ab Agar page bada hai mid se tab :-
    - count++ kardo, means new student ke liye count start karo
    - page mai arr[i] daal do, ye pahle jo value thi page usko ab ke value se replace kar dega because ham yaha assign kar rahe hai, iske pahle addition opertion kar  rahe the. 
    Ab agar next book agar exist karegi toh phir se ham upperwali condition ko check karenge. 

-Agar count barabar hai ya lessthan M ke tab 
  - ans=mid  (storing)
  - end=mid-1 
- Agar aisa nahi hai, 
  - start = mid+1

Count : Hamko ye pata chalega ki distribution sahi hua hai ki nahi. 
Note :- lessthan M means ki kam no of students ko he book distribute hua hai. So conlusion ye hai jo chiz tin bachho mai baat sakte hai usko ham 4 bachhe mi bhi bsst sakte hai
-Iska opposite exist nahi karega kyuki wo capicity se exceed kar jayega , jiske wajah se next student ki zarurat pade ya phir apne capacity ko bada de. 

Time Complecity : O(nlogn)

Code Implementation :- 
```cpp
int findPages(int arr[], int N, int M)
{
    if(M>N)
    return -1;

    int start=0, end=0, mid, ans;
    for(int i=0;i<N;i++)
    {
        start = max(start, arr[i]);
        end+=arr[i];
    }

    while(start<=end)
    {
        mid = start + (end-start)/2;

        int pages=0, count=1;
        for(int i=0;i<N;i++) // Page Allocating
        {
            pages+=arr[i];
            if(pages>mid)
            {
                count++;
                pages=arr[i];
            }
        }

        if(count<=M)
        {
            ans = mid;
            end = mid-1;
        }
        else
        start = mid+1;
    }
}
```

### Painter Partition Problem :- 
Hamko ek array diya gaya hai, aur har ek element ek wall ko represent kar raha hai. Jo bhi value present hai, wo us wall ki length hai. Ab hamko wall ko print karwani hai, aur hamare pass k no. of pinter hai for the printing the walls. 1 length = 1 unit, So hamko inko kaam allocate karna hai in contigous form mai. So minimum kitne time mai kaam complete ho jayega.
- So saare ek saath kaam start kar sakte hai, bas condition ye hai ki contihous form mai allocation hoga. 

Brute Force Approch :- Linear search :-
Maximum element choose karo, aur eke ek karke aage badte jao check karo ki capacity badane se kya koi aur wall allocate ho sakti hai kisi painter ko. Jitna capacity hoga utna time lagega. 

Optimized Approch :- Binary search
Similar approch lenge.
Start and End lenge jaise pahle liya tha. 

Note :- Jab bhi contigous aur phir maximum ya minimum puchh raha hoga toh waha Binary serach lagega. 

Same Logic as before
Code Implementation :- 
```cpp
long long minTime(int arr[], int n , int k)
{
    long long start=0, end=0, mid, ans;
    for(int i=0;i<n;i++)
    {
        if(start<arr[i])
        {
            start = arr[i];
            end+=arr[i];
        }
    }

    while(start<=end)
    {
        mid = start + (end-start)/2;

        long long pages=0, count=1;
        for(int i=0;i<n;i++) // Page Allocating
        {
            pages+=arr[i];
            if(pages>mid)
            {
                count++;
                pages=arr[i];
            }
        }

        if(count<=k)
        {
            ans = mid;
            end = mid-1;
        }
        else
        start = mid+1;
    }
}
```

### Ship Packages :- 
Hamare paas kuchh Packages hai, unko kahi bhejna hai. So hamare pass ek array diya gaya hai, jiske element represent kar rahe hai, package ko. Aur jo value hai element mai wo represent kar raha hai weight ko. 
Contigous form mai he packages ko send kar sakte hai. Toh minmum weight is ship ki kitani hogi. ki inko ham apne give timeline mai deliver kar paaye. So minmum weight capacity kitni wo ki ship in sabhi packages ko 3 din ke ander bhej de. 
- So ham kitne bhi package bhej sakte hai, kakin ye dhyan mai rahe ki, minimum capacity ho. 

Brute Force same logic

Optimized Approch same logic :- 
Same tarike se start and end nikalenge. 
