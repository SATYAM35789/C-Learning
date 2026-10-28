### Bubble Sort :- Bada wala sabse pichhe
Is sorting algorthum mai ham starting ke do element ko select karte hai, aur un dono mai jo sabse bada hota hai usko swap karke piche bhej dete hai, phir next do compair karte hai, jo bda usko piche bhej do and so on karte rahte hai at end sabse bada element last mai pahuch jata hai. 

So yaha har ek round mai sabse bada element pichhe chala jayega, so jitna no. element hoga us se ek kam round honge properly sort karne ke liye. 

Internal loop logic :- 
Iske ander ham ye samjh rahe hai ki bubble sort kaise kaam karta hai, for only one round. 
- ek for loop lo jo chalega j=0 se laker j lessthan n-1 tak
- check karo ki agar arr of j bada hai arr of j+1 se then 
  - swapfunction call karo, arr[j] aur arr[j+1] ke liye

Code part :- 
- ek for loop, ko jo i= n-2  se chalega aur i=0, tak chalega. 
  - ek for loop, jo j=0 se chalega aur j=i tak chalega
     - agar arr of j bada hai arr of j+1 se then 
       - swap, arr of j and arr of j+1

Note:- Ander ka loop kaise kaam karega aur kaha tak jayega is liye, kisi basic example ko analysis kiye hai ki, har round mai koop kaha se kaha tak ja raha hai, aur unki aapas mai dependency kaise hai. 

Do dry run, to make sure that your code is generalized and able to work on any type of the input. 

Time and Space Complexity :- 
Time Complexity :- 
For different round :- 
(n-1)+ (n-2) + (n-3)+... 1 = ((n-1)n)/2 (sum of n natural no.) = n^2

Space Complexity :- Auxilary space
O(1)

Best case Time complexity :- O(n)
If the array is already sorted than jab apna round chalayenege toh ek bhi swap nahi kar rahe honge, maan lo koi insaan hai agar ek baar check kar liye ki starting se end tak usko swap nahi karna pada so dobara thodi same chiz check karega. 

So ki ye pata karne ke liye swap hua hai ki nahi uske liye ham ek variable le lenge boolean typa ka. I variable ko Internal loop ke bahar 0 se initialize karenge aur loop ke ander is variable ko 1 one bana denge taaki pata chal jaye ki swap hua hai ki nahi. 

Code Implementation :- 
```cpp

```
