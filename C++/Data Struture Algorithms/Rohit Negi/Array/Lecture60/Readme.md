### Quick Sort 
So ye bhi ek sorting technique hai. So isme hamko ek unsorted array diya gaya hoga and we have to sort. So this is Optimized Approch then the technique we study till now. 
Pivot Element : kisi bhi ek element ko pakdo usko uski correct postion mai jakar rakh do us array mai. like 6,3,2,4 let if we take the 4 as pivot then what will the correct position of the element when it is sorted in ascending order so output : 6,3,4,2

Approch :- 
- pivot : Ham apne case mai hamare array mai jo last mai present value hai usko he pivot lenge
- So ab find karenge ki hamare pivot element se kitne usse chhote hai ya barabar hai, if we find that then we can say that ki correct postion iske baad wala he hoga. 
- pivot ko sahi postion par daalne ke baad pivot se chhote wale uske left side and bade element pivot ke right side daal denge
- so pivot ke left side wala ek array maan lo and dusre side wala ek array means ki do part mai hamara array divide ho gaya hai. 
- Ab same procedure phir left and right side lagao
- So if ek he element present hoga then we can say that ki sorted hai aur apni correct postion par hai. 

Code Part :- 
quickSort()
- ek quickSort naam ka ek function, parameter int arr as pointer, int start, int end
- ek int type ka pivot element create kar jisme ek fun partition() naam ka wo pivot element kp sahi position par pahucha dega hamare array mai then return the index of pivot. 
- call for left side of pivot i,e quickSort(arr,start,pivot-1)
- call for right side of pivot i,e quickSort(arr, pivot+1,end)
- Base Case : start > end :- Isko detailing mai samjhne ke liye recursion tree mai jao and dekho kis condtion mai aage call nahi kar sakte -> on each level see the start and end. 

Logic: Ki ham pivot element ko kaise sahi position par la rahe hai
- Iske liye apne array mai last wale ko pivot maane hai so start se start karenge array ke, traversing kar rahe honge during that we check on every element if the present element is smaller and equal to pivot then temp array mai update karte jao, if aisa karte karte ham last of array mai pahuch jate  hai then we say ki pivot elemet ko daal do ab, iske isse bade sare element aa jayenge or bache hua saare element ko likh do. 
- So we are creating the extra array now we can solve without using that 
  - create extra pointer pos
  - ab agar chhota ya barabar element milta hai then us element ko apne pos pointer wale element se swap kardo and pos++ and start++ 
  - jab tak ham end mai nahi pahu jate aisa karte raho So is procedure mai ham apne pivot element ko apne position par la denge aur pivit ke pahle wale isse chhote honge and right side wale is bade ye bhi ho jayega. 

Partition(): Easy hai code iska dekh kar understand kar sakte hai. 

Code Implementation :-
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pos = start;
    for(int i=0;i<=end;i++)
    {
        if(arr[i]<=arr[end])
        {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
}

void quickSort(int arr[], int start, int end)
{
    //  Base Case
    if(start>end)
    return ;

    int pivot = partition(arr,start,end);
    // Left side
    quickSort(arr,start,pivot-1);
    // Right Side
    quickSort(arr,pivot+1,end);

}

int main()
{
    int arr[] = {9,7,8,6,5,44,3,2,24,5};
    quickSort(arr,0,9);

    for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
}
```

Time Complexity :- 
- So correct postion tak jaane ke liye we take n time
- har level par O(n) he lag raha as n+(n/2+n/2)+(n/4+n/4+n/4+n/4)...
- total no. of level is O(logn)
So final nlogn  -> Average Case

Space Complexity :- logn -> height of a tree

Note :- WorstCase : O(nsq) and n, time and space respectively
- isme worst case mai jo height hai tree ki wo n ho jaati hai, isiliye nsq timecomplexity ho jati hai. 

So quick sort bahtar hai merge sort se as it take logn space to sort but time complexity same hoti hai. So quick sort best when the given question is not in desending order and incresing order which is worst case. 
- so agar data already sorted hai then worst case hoga. 
- quick sort kuchh he cases ke liye worst case mai jata hai, nahi toh mostly ye average case mai he hota hai. 
