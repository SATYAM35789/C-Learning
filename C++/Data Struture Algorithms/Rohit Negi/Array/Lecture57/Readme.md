### Recursion in Linear Search :- 
So isme hamko ek array diya gaya hoga, x diya hoga. Hamko batanaa hai ki kya x array mai present hai ki nahi if yes then return 1 if no then return 0. 
Recursion :- So hamna kya kar rahe honge, so kya x, array of 0 par present hai if not then go for the next index value for search or checking the element is present or not. So if found that element then wahi se return ho jao and send message to jaha se call hua tha ki present hai. 
- If khojte khojte last mai pahuch gaye aur element array ka khatam ho gaya then ham bol denge , jaha se call kiya gaya tha ki nahi present hai. 

Code part :- 
-ek bool typa ka, linearSearch naam ka ek function le lo jiske parameter hai : ek array aur ek int type ka X, int type ka index
  - if arr of index is equal to the x then return 1 kardo. 
  - go for the search for next index i,e return linearSearch(arr,X,index+1)
  - Base Case :- index == N then return 0 so we need to pass the n also in the function. 

Code Implementation :- 
```cpp
#include <iostream>
using namespace std; 

bool linearSearch(int arr[], int x , int index, int n)
{
    // Base case
    if(index==n)
    return 0;

    if(arr[index]==x)
    return 1;

    return linearSearch(arr,x,index+1,n);
}

int main()
{
    int arr[] = {2,4,5,7,43,56};
    int x = 7;
    cout<<linearSearch(arr,x,0,6); 
}
```

### Binary Search   
It is searching technique which works on the sorted data. Non-decresing means same or incresing lakin ye ghat nahi rahe honge. Non-incresing means ye bad nahi raha hai, so ye ya phir same hai ya phir ghat raha hoga. So hamko ek array diya gaya hoga incresing order mai. 
Binary search :- 
- so isme pahle start jo starting of array ko point kar raha hoga and end last element of the array ko point kar raha hoga.
- Phir iska ham mid nikalenge which is (start + mid)/2 
- ab arr of mid agar hamare target ke barabar hai toh answer de do
- if arr of mid chhota hai x se then start ko update kardo and right side jao
- agar arr of mid x se bada then end ko update kardo (left side) and so on kartejao
- Base case : start>end then return ho jao 

mid = (start+end)/2 
 - is tarah se likhne se int overflow ki condition aa sakti hai like int type, maximum kitna value store kar sakt hai that is 2^32 -1 so if start and end ki value dono yahi hua toh then ab ham jo value hamko milega usko toh int type store nahi kar paayenge so :- 
- start+ (end-start)/2 karene is tarah se likhenge. 

Code Implementation :- 
```cpp
 #include <iostream>
using namespace std;

bool BinarySearch(int arr[], int start, int end, int x)
{
    // Base case
    if(start>end)
    return 0; 

    int mid = start + (end-start)/2;
    if(arr[mid]==x)
    return 1;
    else if(arr[mid]<x)
    return BinarySearch(arr, mid+1,end,x);
    else
    return BinarySearch(arr, start,mid-1,x);

}

int main()
{
    int arr[] = {22,32,34,56,78,88};
    int x =56;
    cout<<BinarySearch(arr,0,5,x);
}
```
Note : Variation :- so same approc ko for decresing order ke liye karo.