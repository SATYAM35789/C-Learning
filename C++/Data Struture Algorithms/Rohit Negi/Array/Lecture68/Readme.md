### Rate in Maze 
So here we see the use of recursion in 2D array. So hamko ek 2d array diya gaya hoga, jisme ek initial value diya hoga jaha rat khada hoga aur ek final value(goal) jaha rat ko jana hai so hamko batana hai ki aise kitne tarike hai goal tak pahuchane ke liye. The matrix has n of rows and cols. 

- Rat charo direction mai ja sakta hai which are up-down , left-right. So hamko saare unique path ko print karwana hai. 
- 2D array mai 0 aur 1 present hai , where 0 means ki waha nahi ja sakte wo block hai. 

Approch :- 
- So apne initial point ke neighbour mai jaha jaha 1 hai waha waha ham ja sakte hai, waha se kisi bhi ek ek jagah chale jao phir unke bagal mai jaha 1 hoga waha ja sakte hai. 
- Jo hamre path ka part ban chuka hai waha nahi ja sakte. So ham present mai jaha hai waha se toh pata kar sakte hai ki iske pichh nahi ja sakte lakin , present element ke aur pahle walo ko kaise pata chalega ki ham waha ja chuke hai ki nahi. so we need to track. So hamko same size ka array ka need hoga. 
- While traversing ham kaha kaha nahi ja sakte :- 
   1. Matrix ke bahar nahi ja sakte  2. 0 wale block hai, waha nahi ja sakta 3. Already visited path pe nahi ja sakta
- So goal par pahuchane ke baad, Jo bhi path milega usko store karke rakh denge.
- phir  hamko aur bhi path ko pata karna hai then ham goal se ek kadam pichhe aayenge aur goal ko wapas se 0 bana denge which means ki isko visit kar sakte hai.
- So ye kaam ham karte rahenge and this technique is called the Backtrack method. So jab ham apne goal ke pichle position ko explore kar chuke hai then pichhe jaate raho. 

Code Part :- 
up = i-1,j       -> i-1,j+0  -> (-1,0)
down = i+1,j     -> i+1,j+0  -> (1,0)
left = i,j-1     -> i+0,j-1  -> (0,-1)
Right - i, j+1   -> i+0, j+1 -> (0,1)
Goal State (Always) : i=n-1 aur j=n-1 

Total() :- 
ek void type ka Total fun, parameter 2d vector matrix aur visited as reference, 1d vector ans , string path, int i,j, n .
- Agar i==n-1 and j==n-1 ho jata hai then 
  - ans.pushback(path)
  - return ;
- Sabse pahle jaha initially khade usko visited mark karo, i.e visited[i][j] 
- So ab present mai jaha khade waha se kaha ja sakte hai, upper tin condition jaha satisfied karengi waha ja sakte hai :- 
   1. validity : Means ki up down left right opertion perform karna hai sirf. Matrix ke ander hai ki nahi
   2. visited : Kya ham pahle visit kar chuke hai ki nahi?
   3. matrix :- Matrix mai rasta block to hani hai n (matrix mai 0 waale block hai)
    up ke case mai :- 
    if(valid(i-1,j,n)&&matrix[i-1][j]&&!visited[i-1][j]) :- aise he saare case mai check karenge. 
      - ans.push_back("U")
      - Total(matrix,i-1,j,n,path,ans,visited);
      - path.popback() : another option try kar rahe hai same path se
- So we have created another logic so ki hamko har case mai same code ko repeat n karna pade. 
- visited[i][j] = 0 :- so wapas jaa rahe toh current wale ko 0 bana do so ki dusre path ke through bhi access kar paaye is position ko. 

Valid()
return i>=0 && j>=0 && i< n && j <n ;

Time Complexity :- 
Nsq total element hai 2d array mai. And har ek element ke pass 3 direction hai ghumne ke liye so total time complexity. 
3^Nsq. 

Code Implementation :- 
```cpp

```
