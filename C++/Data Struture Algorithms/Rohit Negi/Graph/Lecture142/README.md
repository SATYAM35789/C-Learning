### Shortest Path in Directed Acyclic Graph :- 
So hamko ek directed graph diya hua hai, jisme har ek edge ke sath weight bhi associated hai, which means ki first node se second node par jane ka cost/value/distance uske weight ke barabar hai. So isme source node se har ek particular node ke liye shortest/minimum distance naikal kar batao. So ham alag alag node ahuchne ka minimum distance ko array mai store karke store karenge. 

Adjecency list kaisa dikhega?
1. Storing vertex and weight in the pair in order of vertex and weight like {1,4} : vertex=1, weight=4 . 
so hamari adjecency list :- vertex< pair < int, int>>  adj[ N]; aisa hoga. 

Approch 1 :- BFS
So Apne src node se start karenge BFS lagana jo bhi uske neighbour mai jao , agar wo visited nahi hai then uski aur privious node ke distance ko add kar lo, aur us neighbour ke jagah dist array mai store karlo. and so on karte jao not visited then mark it, queuue mai daalo, bahar nikalo,neighbour ko distance nakal store karlo and so on.
 So Ham iske pahle wale mai jab same approch Undirected graph mai laga rahe the waha ham jisko visit kar chuke the usko wapas visit nahi karte the. Iske wajah se hamko minimum distance nahi calculate kar pa rahe hai there may chances that ki agar second path use karte toh minimum distance ho sakta tha. So BFS method failed here completely. 

2nd Approch :- DFS 
So ham DFS mai kya karte hai, source se start karo pahle ek neighbour ko visit karte jao aur uske according distance bhi calculate karte jao, agar sare node cover ho gaye return back and check ke sare node cover ho gaye ki nahi, come back to source node uske dusre node ko visit karo and so on. So ham yaha bhi ruk jayenge agar node visited hua toh so only dfs se hamari problrm solve nahi ho raha hai. 

So visited wala logic se solution nahi aa para hai, ham sirf apne current path ko visit karte jayenge. So agar next node distance while traversing minimum milta hai then then usko update kardenge dist array mai. 
Note :- Agar ham apne current path par chalte rahe toh apna ans nikal sakte hai. 

So pahle ek path ko visit karlo phir dusre ko and so on jitna exist kare, is process se ans toh mil raha hai par time complexity bad ja rahi hai. As ki ham same node ko multiple time visit kar le rahe hai. So ham bol sakte hai ki ye ek ideal method nahi ho sakta. 

Approch 3rd :- Topological Sort 
So pichhle wale approch mai solution toh aa raha hai but, kuchh path ke nodes ko multiple time visit kar de rahe hai, so hamko ye try karna hai ki ham ek visit mai he apna ans nikal paaye. 
So multiple time visit karne ki zarurat kyu pad rahi thi, kyuki us path se hamko minimum distance milne laga tha particular node ke baad. 

So on particular node agar minimum distance hai tabhi aage move karna hai. So on an particular node par minimum distance calculate karne ke liye ham uske pahle ke node ke minimum distance pata hona chahiye so ki ham particular node ko calculate kar paaye. 

dist[3] = min( 6 + dist[1], 2+dist[5]) :-
dist[3] = : Node 3 par kon se value store hogi,
6+ dist[1]: 6: node 1 se node 3 ke liye weight , dist[1] : minumum distance till node 1.

(Topological sort) se pata kar sakte hai ki kis order mai ko follow karte jai tab hamko hamra solution mil jayega. So Particular node ko calculate karne ke liye jo mujpe edge daal rahe hai unko min calculate karo. 

Whenever directed Acyclic graph mai shortest path calculate karne ke liye bole tab uska toplogical sort nikalo aur us order mai min distance cakculate karlo. 

So ham topological sort calculate kar lete hai iske fo method hai 1. DFS 2. BFS
So today we apply dfs :- 
So is isme neighbour ko visit karte jayenge, aur tab tak karte rahenge jab tak exist karta hai, wapas aate samay means ki ha sare neighbour ko visit kar liye hai tab  apne node ko stack mai dalte jayenge and aisa karte jeyenga. And ek node ko dobra visit nahi karna hota hai. 
So stack mai value fill kar diye toh ek karke bahar nikalenge. Aur starting mai dist ko infinte se initilze kar denge. So source node ko bahar nikalo, dist array mai source node ki 0 he daal denge aur, 2nd node ko bahar nikalo aur compair karo Infinite aur weight mai se jo minimum hai usko update kardo dist array mai us node ke jagah and so on. so minimum distance pata karne ke liye hamko ye pata karne hoge us node par kon edge daal raha hai, iske liye pure adj ko traverse karna hoga jis se complexity bad jayegi. 

Relex edge:-
So ab pahle node ko bahar nikalenge , aur ab hamko edges ko relax karwana hai. Jaha jaha edge ja rahi , jisko bahar nikala hai us se, us edge ko relex karenge. 
Relex edge : dist[ neighbour] = min(dist[ neighbour], weight(node, neighbour)+ dist[ node])
dist[ neighbour] :- jo starting mai infinite hai
weight(node, neighbour) :- node se neighbour ka weight 
dist[ node] :- is node tak ka distance from src node.  

Code Implementation :-
```

```
Time Complexity :- 
Adjecency list : V+E
Topological sort : V+E
stack empty :- V+E  : vertex nikla aue edge ko bhi dekh rahe hai

Space Compelexity :- 
Adjecency list : V+E
Topological sort : V
stack empty :- V
Dist :  V
 