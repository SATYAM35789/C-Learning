### Insertion sort :-  Sabse check karo, and insert it to its correct position. 

To understand the insertion sort taking the example that ki tum ek juwari ho, wo apne card ko kaise kisi order like ascending order mai karte hai. So wo koi ek card uthate hai, phir next card ko uthate phir check karte hai jo next card hai wo pahle card se chhota hai ki bada if chhota then left side laga dete hai if bada then right side laga dete hai, so yahi insertion sort ka basic logic hai. 
So basically agar koi next card bhi aayega tab ham usko un sab se compair karenge similarly to get the correct postion. 

Insertion sort mai pahle element ko already sorted maan ke chalte hai ki wo apne correct position par hai,
compairsion next element se start karte hai. So round 1 mai sirf next element se compair karte hai, uske baad wo do postion tak sort mil jata hai, phir next element ke liye compairsion dono element se karte hai and so on aise he compairsion karte hai. 

Note : Isme jo next element hai jisko ham sabse compair kar rahe hai, wo tab tak aage badate jayega tab tak usko bada element mil raha hai, if chhota element milega toh next elemet ko rok denge aur next element apne correct position par ja chuka hoga. 

Internal loop :- 
Isme ham basic logic (concept) build kar rahe hai, sirf single round ke liye Insertion sort kaise kaam karta hai. 
So isme scenario maan kar chal rahe hai ki koi array jo pura sorted hai sirf last ek element sort nahi usko, correct postion par lana hai.
- ek for loop lo, jisme j, n-1 se chalega aur j lessthan 0 tak chalega.(agar lessthan equal to hota toh segmentation fault aa sakta tha. (Bubble sort mai bhi sakta hai))
  - Agar arr[j] chhota hai arr of j-1 se then 
    -swap kar denge arr of j aur array of  j-1 ko 
  - Agar aisa nahi hai then loop ko break kardo. 

Code Part :- 
- ek for loop lo, jisme i=1 se start hoga aur i lessthan n tak chalega 
  - ek for loop lo, jisme j =1 se chalega aur tab tak chalega tab tak j bada hai 0 se
    - agar arr of j chhota hai arr of j-1 se then 
       swap kardo arr of j aur arr of j-1 ko
    - agar aisa nahi hai toh break kardo


Space complexity :- O(1)
Time Complexity :- kitna bar execution ho raha hai
1+2+3....+n-1 time = (n(n-1))/2 = O(n^2)

Best case :- If already sorted hai, toh time complexity kitnai hogi
So kam se kam n-1 compairsion karne padenge as ki agar sare sorted hai toh swap nahi karna hoga.  O(n)

Avg case = Sum of all cases/ Total cases  O(nsq)

Code Implementation :- 
```cpp

```