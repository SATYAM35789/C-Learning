### Next Greater Element Right :-
Hamare pass ek array hogi integer type ki , har element par check karna hai ki uska nearest grater konsa hai usko store kar lenge at end jab humare pass koi nearest grater nahi hai toh -1 kar denge. Ab jo bhi hamne store kiya hai usko wapas kar denge.
Applying Brute force Approch:- jis bhi element ka next greater khoj rahe uske aage se sabhi element ko check karenge ki kya ye greater hai if yes then update it in new storage and move to next element and do so on.
1. ek vector banayenge , ans naam ka jo n size jiske ander initially -1 daal denge. 
2. ek nested loop create karenge , i and j ki help se 
   1. agar a[j] bada hai arr[i] se tab, ans[i] mai arr[j] ki value daal do, phir loop se bahar aa jao. 
Time complexity: O(nsq)

Code Implementation :- 
```
// Brute Force approch
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}
```
2nd Approch :- pahle element ko uthao aur check karo ki uske next element us se bada hai, Agar bada hai toh ans mai uski index daal do, warna pahle element ko add ka stack mai, same with next element. 
Note :  Hum index isiliye daal rahe taaki humko pata rahe ki jo value jo badi hai usko kis position par daal na ya rakhna hai. 
2. Stack mai calue hamesha decreseing order mai he hoga.  
Procedure :- 
1.  ek stack banayenge st naam ka
2. ek vector banayenge arr naam ka jo n size ka hoga aur usme -1 daal denge sabme.
3. Ek for loop , jab tak given khatam n ho jaye.
4. Agar stack empty nahi hai toh,
   1. Tab check karenge ki kya jo stack ka top element hai wo chhota hai , arr ke present index value ka aur kahi stack khali  toh nahi hai
     1. stack ke top jo position daali hai waha arr of present ki value dal denge. 
     2. stack ko pop kar denge. 
   2. Agar wapar wali condition fulfilled nahi hai toh, stack mai push() kar do.
Time ans space Complexity :- O(n)

Code Implementation :- 
```
// Optimized version of the problem.
vector<long long> nextLargerElement(vector<long long> & arr, int n)
{
    vector<long long> ans(n, -1);
    stack<int> st;

    for( int i=0;i<n;i++)
    {
        while( !st.top() && arr[i] > arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
```
3rd Approch :- Ham apne data ko pichh se bhi dal sakte hai stack ke andar, Pahle data ko daal stack ke ander , har index par jane ke kya ye kisi ka greatest integer ho sakta ha kisi ka, then push it in the stack otherwise pop it.
Procedure :- 
1.  Pahle do step same hai, Ek for loop banayenge jisko pichhe se chalayenge .
2.  Ab hum check karenge ki kya stack empty hai aur kya stack ka top ki value chhoti hai arr[i] se. 
    tab stack ko pop kardo
3. other wise Agar stack khali nahi hai, tab ans[i] mai stack ke top jo value usko daal do
4. Iske bahar aane ke bad stack mai push kardo index.
Not easy to understand it easily:- 
Code Implementation :-
```
// Optimized version of the problem from back side .
vector<long long> nextLargerElement(vector<long long> &arr, int n)
{
    vector<long long> ans(n, -1);
    stack<int> st;

    for (int i = n; i < 0; i--)
    {
        while (!st.top() && arr[st.top()] < arr[i])  // if yes than it cannot be next greatest
        st.pop();
        
        if(!st.empty())
        ans[i] = arr[st.top()];
        st.push(i);
    }
    return ans;
}
```

### Next Smaller Element :-
 Agar element chhota milta hai, tab chhote wale element ko top of stack ke position ke jagah daal do and do agar nahi ,ilta hai toh push karte jayo stack mai.
 Procedure:-
 1. Ek stack le lenge st naam ka. 
 2. Ek vector le lenge ans naam ko jo n size ka hoga , jisme -1 hoga har jagah. 
 3. ek for loop chalayenge n tak
 4. Agar stack empty nahi hai aur stack ka top ki value badi hai arr[i] se tab
    1. ans of stack ki value mai arr of i ki value daal do. 
    2. stack ko pop kardo. 
5. Nahi toh stack mai push kardo. 

Code Implementation :- 
```
// Next smaller Element
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

```

### Smallest Number on left :- 
Prcedure :-
1. 2nd step tak uppar jaise he hai
2. ek for loop chalayenge arr ke pichhe se
3. Agar stack empty hai aur stack ka top ka value bada hai arr of i se toh
   1. ans of stack ki top ki jagah ans of i ko dal do
   2. aur stack ko pop kardo
4. nahi hai toh stack mai push kar do value ko. 
5. return statement likh do. 

Code Implementation :- 
```

```

### Next Greater Element 2 :
Is problem mai hum apne array circular jaisa  manege, Ek baar tavarse karne ke baad , jis bhi index or value -1 hai usko ek baar phir conition se match karwayenge . 
1st Approch:- Given array ka double bar , ek new array mai store kar lenge.  Aur apna condition apply kar lenge. 
2nd Approch :- Hamko double size ka array lene ki bhi zarurat nahi hai bas apne array mai i%n kar denge. 

Code Implementation :- 
```
// Next Greater Element 2
vector<long long> nextLargerElement(vector<long long> &arr, int n)
{
    vector<long long> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        while (!st.empty() && arr[i % n] > arr[st.top()])
        {
            ans[st.top()] = arr[i % n];
            st.pop();
        }
        if (i < n)
            st.push(i);
    }
    return ans;
}
```

### Stock Span Problem :- 
Problem : mere left side mai kitne aise hai consecutive jo chhote hai ya barbar hai.
Ab ek array mai traverse karte samay , hun ye check karenge ki, uske left mai kitne us se chhoti ya barabar hai. wo kitne hai, top mai jo index hai usko minus kardo jo bhi greatest value mili hai stack ke top ki value se(i).   
Procedure :- 
1. ek stack bana lo st naam ka
2. ek vector bana lo int type ka jisme 1 store rahega. 
3. ek for loop chalenge given array par pichh se
4. Ab check karenge ki stack empty nahi hai n aur agar Price of i bada hai price of stack ke top se 
    1. ans of stack ke top mai stack ke top minus i ko dal do
    2. stack ko pop kar do
5. Agar condition nahi follow hota hai toh stack mai value push kardo. 
Edge case :- 
1. Agar stack khali nahi hai tab 
  1. ans of stack ke top mai stack ka top + 1 daal do.
  2. stack ka pop kardo
2. Return the stack. 