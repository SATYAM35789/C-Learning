### Merge Sort :- Divide and Merge
It is one of the sorting technique we used to sort the array in the incresing and decresing order. So this method takes the nlogn time to sort. 

Approch- 
- So pahle apne array ko divide kardo half-half mai
- phir un half half ko bhi half half mai divide kardo, till jab tak karna hai jab tak single element or jab tak wo do part mai divide ho sakta hai tabtak karo
Note :- So single element, toh sorted he hota hai. Then jisko hamne divide kiya the same order mai, merge karo which means ko do sorted array ko combined karo jiska result bhi sorted hota hai.
- Merge operation apply karo 

Merge Operation :- 
So take the example A1 : 2,3,4,5    A2: 3,4,5,6 , we need to merge this and expecting the sorted Of both A1 and A2. 

Brute Force Approch :- O(nsq)
So ham A1 and A2 ko ek array mai copy karlo aur uske baad bubble,insertion selection mai kuchh bhi laga kar sort kar le. So is tarah se We got the (n^2). 

Another Approch :- O(n)
A1 and A2 par ek pointer le lo jo starting mai unke pahle index ko point  kar raha hoga.
 - So ham pointer ke help se ek check lagao aur inme se jo chhota hai usko apne array mai copy kar lo
 - phir same array ke pointer ko ek bada do and again check karo
 - if inme koi bhi ek pointer apne array ke last mai pahuch jata hai then next arry bache hua element ko dirctly copy kardo 

Division Operation :- 
- Do pointer le lo start and end , them iska mid nikal lo 
- then uske ek portion start se mid tak and dusra portion mid+1 se end tak. 

Code Part :- 
mergeSort :-  
- ek void type ka mergeSort function bana lo, parmeter ek int arr pointer, int start and int end
- find mid, start + (end-start)/2 
- Divide into two parts :
  - mergeSort(arr,start,mid)
  - mergeSort(arr,mid+1,end)

Merge() : dono array ko merge karne ka kaam karega, parameter: arr,start,mid,end sabko pass kardo
- Creating the size of an array/vector we need while merging :-  end+start+1 
- Do pointer: left = first and right = mid+1 and index=0
- ek while loop : Condition left<=mid && right<=end
  - Agar arr of left <= hai arr of right ke then
    - temp[ index] = arr of left
  - else : temp[ index] = arr of right
- After finishing of the loop , agar hamare pass left portion mai bacha hua element hai toh usko direct copy kardo
- After finishing of the loop , agar hamare pass right portion mai bacha hua element hai toh usko direct copy kardo

- After this  we need to pass this sorted array i.e temp ko hamko jo ek portion ho sakta hai jisko hamne pahle divide kiya tha (temp ko original array mai fill kardo)
  - index =0 kardo
  - while : jab tak start greater than equal to end nahi ho jata
    - arr[ start] = temp[ index] 
    - start++ and index++ 

Code Implementation :- 
```cpp
#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int left = start, right = mid + 1, index = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++, left++;
        }
        else
        {
            temp[index] = arr[right];
            right++, index++;
        }
    }
    // Left array is not empty yet
    while(left<=mid)
    {
        temp[index] = arr[right];
        index++ , left++;
    }
    // Right array is not empty yet
    while(right<=end)
    {
        temp[index] = arr[right];
        right++, index++;
    }

    // Copy the temp in the original array
    index =0;
    while(start<=end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    // Base Case
    if (start == end)
        return;

    int mid = start + (end - start) / 2;
    // left side
    mergeSort(arr, start, mid);
    // right side
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {6, 3, 7, 5, 8, 19, 4, 3, 56, 7};
    mergeSort(arr, 0, 9);

    // Printing the Sorted Array
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}
```

Time Complexity :- 
- Dividing it in half-half => log(n) just like Binary Tree. 
  - On each level of recursive tree we 
    - left side call (1)
    - right side call (1)
    - merge function called O(n) : n + (n/2 + n/2)
    note : har level par merge karne mai n kaam lag raha hoga
    - So total level log(n) hai hamare pass. 

O(nlogn)

Space Complexity :- 
- logn + n O(n)   => temp array
   
