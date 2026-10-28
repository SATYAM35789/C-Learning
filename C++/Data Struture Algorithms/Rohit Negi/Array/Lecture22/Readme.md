### Binary Search  Algorithum :- 
To apply the Binary search , the data sholud be in sorted. So it may be ascending order or descending order. 

So how binary search devlop?
It comes from the real world problem searching word in the dictionary. 

How Binary search works?
Koi word ya value hoga usko ham search kar rahe honge, dirctly mid wale value par jayenge aur usko compair karenge jo bhi value ham khoj rahe honge us se agar mid value chhota hai, jisko ham khoj rahe hai us se then right side ke portion mai khojenge if khojne wala value chhota hai then left side khojenge. and so on karte jayenge tab tak mil nahi  jayega. 

Finding middle element :- 
(starting index - Ending Index) /2

Code Part :- 
start :-  store the starting index of the array
end :- store the ending index of the array
Step1:- Mid = ( start+End)/2
Step2:- If(arr of mid == key) -> founnd the answer. 
stpe3:- else  if(arr of mid is smallerthan key)
          -then we try to find the element on right side of the mid, so in this case :
            - start mai mid ke index  daal denge
                 start = mid +1
step4:- else :- arr of mid bada hai key se then 
          - try to find the element on the left side of the mid and update the mid with end
               end = mid -1

So agar koi aisa value khoj rahe hai jo present he nahi hai, toh usko kiase pata karenge, kab rukenge khona ya uske liye break condition kya hoga, so jabtak start chhota aur barabar hai end ke tab tak upper wala kaam karte rahenge. 
Or :- agar end chhota ho jeyega start se tab ruk jana hai, search karna.  

Time Complexity :- 
N/2^0 + N/2^1 + N/2^2 + .... + N/2^k 
-> N = 2^k -> logN = log2^k = klog2
-> k = logN/log2 = logN O(logn)

Code Implementation :- 
```cpp

```