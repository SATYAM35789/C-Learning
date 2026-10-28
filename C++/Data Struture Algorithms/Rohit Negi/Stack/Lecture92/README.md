### Largest Rectangle in Histogram :- 
 Largest reactangle ka area lakar hamko dena hai, Width kasise pata kar rahe hai :-  jab bhi usko next chhota mil raha hai, tab ruk jana hai any side moving(left or right).
 Length is equal to the value given .  
 Procedure :- 
 1. ek vector bana lo Right naam ka with n size. 
 2. ek vector bana lo left naam ka with n size. 
 3. ek stack bana lo st naam ka
 4. Agar stack empty nahi hai aur agar stack ka top bada hai height of i(current) se , tab
    1. Right mai stack of top ki value ki mai i ko store karwa do. 
    2. stack ko pop karwa do. 
5. Agar wapar wali condition fail hoti hai tab, stack mai push kar do i ki value ko. 
6. Agar hamara stack khali nahi hai , tab 
   1. right of stack ki top mai n ki value daal do. 
   2. stack se top value ko pop kardo.

Next smallest on left side :- isko ham dhondhate hai pichhe side se. 
1. Ek for loop chalayenge given array ke pichh se
2. Agar stack empty nahi hai aur agar stack ka top bada hai height of i(current) se , tab
    1. Left mai stack of top ki value ki mai i ko store karwa do. 
    2. stack ko pop karwa do. 
3. Agar wapar wali condition fail hoti hai tab, stack mai push kar do i ki value ko. 
4. Agar hamara stack khali nahi hai , tab 
   1. Left of stack ki top mai -1 ki value daal do. 
   2. stack se top value ko pop kardo.

Finding answer :-
1. ek ans varaible inialize karlo, 0 se
2. ek for loop chalayenge,
   1. ans mai dal do ans ka max.
   2. max ka parameter :-
     1. ans
     2. height of current position(i) multiply by Right of i - left of i -1 kardo.
3. return ans

Time and space complexity:- O(n)
Code Implementation:-
```
int largestReacangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> Right(n);
    vector<int> Left(n);
    stack<int> st;

    // Finding next smallest Right
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            Right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // Stack ko khali karo
    while (!st.empty())
    {
        Right[st.top()] = n;
        st.pop();
    }

    //  Finding next smallest left side
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            Left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // Stack ko khali karo
    while (!st.empty())
    {
        Left[st.top()] = -1;
        st.pop();
    }

    int ans = 0;
    // Area calculating
    for (int i = 0; i < n; i++)
        ans = max(ans, heights[i] * (Right[i] - Left[i] - 1));

    return ans;
}
```

Optimized Approch:- 
ham starting se he apne Right mai next smallest khoj rahe honge, jaise hamko milta hai right uske niche wala top hamara next smallest hoga. Because hum Right next smallest khoj rahe hai tab hum current se bade ko dalte ja rahe hai, uske niche wala toh us se chhota hoga. or stack mai value incresing order mai hai so us se smallest just uske niche hoga. 
1. ek ineger ans bana lo
2. ek stack bana lo st naam ka
3. Agar stack khali nahi hai aur stack ka top ki value chhiti hai , current value se tab
  1. index mai stack ka top daal do
  2. stack ko pop kar do
  3. Agar stack khali nahi hai tab
     ans mai max ki value daal do with different condition
  4. Agar khali hai tab, 
      ans mai max fn call karo, with different condition.
5. Agar upparwala condition fulfilled nahi toh, stack mai current value means index ko push kardo. 

Agar for loop ke baad stack ko khali kar rahe hai
6. Agar stack empty nahi hai toh
   1. index mai stack ki top value daal do
   2. stack ko pop kardo
   3. Agar stack empty  nahi hai toh
      1. ans mai max with non emmty condition.
   4. ans mai max empty condition. 
7. return ans

### Maximal Rectangle :- 
Ek rectangle mai 0 aur 1 ki value stored hai, usme se hamko jo sabse bada area covered hai 1 se , usko wapas karna hai. 
Procedure :- 
1. ek interger ans naam ka
2. ek integer row naam ka jisme matrix.size() store karlo
3. ek integer col naam ka matrix[0].size() store karlo
4. ek vector banao heights naam ka, col size ka , jisme 0 hoga starting mai
5. ek for loop row based 
6. ek aur uske ander col based 
7. Agar matrix current value barabar hai 0 ke
   1. height of j mai 0 daal do
8. nahi toh height mai heght + 1 dal do
9. ans mai max daal denge

Code Implementation :-
```
```


  