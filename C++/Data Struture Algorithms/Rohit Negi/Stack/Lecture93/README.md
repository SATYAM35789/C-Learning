### The Celebtity Problem :- 
0 Means hum nahi jante, 1 means hum jante hai. Celebrity means wo hoga jo kisko ko nahi janta lekin usko sab jante hai. 
Brute Force Approch O(nsq) :- Pahle rows find karlo jaha 0 jai sari mai, phir uske corresponding check karlo kya kya sab 1 hai means sab isko jante hai. 

Optimized Approch O(n):- Pahle do ko nikalo unse puchho kya wo ek dusre ko jante hai, if yes then pop it from the stack if no then push it back to the stack , ab same procedure follow karenge. 
Code Part :- 
1. Ek stack bana lo st naam ka.
2. Ek for loop jo given arrar ke pichhse se chalega.
3. stack mai o ko push kar denge. 
4. Agar stack ka size bada hai 1 se then,
5. ek integer bano lo (first) jisme stack ka top rahega
6. stack ke top ko pop kar do
7. ek aur integer bana lo (second) jisme stack ke top ko store kar lo
8. agar first janata hai second ko i.e (m[first][second]) aur agar second nahi janta hai first ko i.e  ![second][first] then :-
  1. Stack mai second ko push kardo.
9.agar first nahi janata hai second ko i.e ( !m[first][second]) aur agar second janta hai first ko i.e  [second][first] then :- 
   1. Stack mai first ko push kardo. 
For loop ke baahar aane ke baad
10. Agar stack empty hai, then return -1. 
11. int num mai stack ke top ko rakh lo. 
    1. Stack ko pop karlo. 
12. Note :- Verfying the the last element is Celebrity or not . 
13. Initialize row =0, col=0
Ek for loop:-
  1. rew += M[num][i]
  2. col += M[i][num]
return row==0 && col==n-1?num : -1 ;

Code Implementaion :- 
```

```