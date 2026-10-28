### Introduction to Graph :- 
Example:-
1. Visiting Single Girlfriend in HP through different states like Up, punjab, haryana, rajesthan, Delhi(Jaha tum rahte ho).Calculate shortest path.
2. Now you are playboy and having girlfriend in all the states mention here hp, Up, punjab, haryana, rajesthan, Delhi(Jaha tum rahte ho).Calculate shortest path, har state ke liye shortest path mil gaya hai. 

How the google maps finding the soretest path?
Jaise ham kisi problem ko solve karte hai waise he koi computer device bhi problem ko solve karta hai. 

Railway track problem ? 
Suppose you the rail minister of the India? And you have minimum amount of sources are avaialable and you have connect these cites with minimum expanse  different states are Del,up,pun,wb,Mp,Mumbai, Goa. Different distance are given means edges ki value di gai hai. So calculate the miminum distance which connect all the states. 

Graph :- Graph se chizo visualize karna easy ho jata hai jiske help se data easily understandable and extra details bhi mil jata hai. 
- heat and trial jaldi se kar payenge. 

Example :- 
FaceBook Network(friend suggestions) :- Kisi graph agar node directly attached hai toh friend hai if not directly then not friend.  
friend suggestions :- mai kisi se directly connected hu, wo jisse directly connected hoga jisse mai nahi uska suggestionmujko dikhyega. 

Edge :- Relationship blw two nodes ko batati hai. 
Nodes = verteces

Definition :- Graph is a non-linear data structure consisting of vertices and edges. 
linear :- kyu iske data ki one by one kerke stored or access karte hai. like :- Array,LL, Stack, Queue. 
Non- linear :-  jisko ham ek ke baad ek store or access nahi kar sakte

Example :- 1993 mai us ek dukaan hoti thi , unhone ye chiz notice kiya ki har friday ko jo log bear le rahe wo diaper bhi le rahe , kaafi pata karne ke baad unko pata chala ki jo asia kar raha friday ko log weekend hota tha aur new married couple the jinke chhote bache the , so bahar nahi jana chahte the wo ghar enjoy karna chahte the, so ab is se store ke malik ne sales ko badane ke liye bear or diaper ka section bagal mai kar diya. 

### Different types of graph :- 
1. Undirected Graph :-
  - without direction edges
  - yaha both direction mai move kar sakte hai
  ex 1. friend duggestion on social media. lakin yaha agar follow aa jaye toh wo directed graph ho sakta hai. 

2. Directed Graph :-
  - with direction edge
  ex Rohit follow mohit then Rohit to mohit(arrow) and if Mohit not follow Rohit then no direction from mohit to rohit. 
  ex :- calculating minimum distance of differnet (single way)

3. Cyclic Graph :- 
   - ek node shuru hokar wapas aa jana wahi par. 
   - So kisi bhi graph mai agar koi bhi cycle present hai then wo cyclic graph hai. 
   - ye bhi do tarah ke ho sakte hai 
      1. Directed cyclic graph  2. Undirected cyclic graph
4. Acyclic Graph :- 
   - jisme cycle present nahi hai
   - ye bhi do tarah ke ho sakte hai 
      1. Directed Acyclic graph  2. Undirected Acyclic graph 

5. Connected Graph :-
   - kisi bhi nodes se kisi bhi dusre node par ja sakte hai
   - ex normal koi bhi directed or undirected graph le lo single same graph mao kahi bhi ja sakte hai

6. DisConnected Graph :- 
   - kisi node se durse node par nahi ja sakte
   - ex normal koi bhi directed or undirected graph le lo do ek graph ek node pakdo dusre graph ek node pakdo if ask to go then this is undirected graph . 
   - single directed graph ek disconnected graph hota hai. lakin single cyclic graph connected ka example ho sakta hai. 

7. Complete Graph :- 
   - jab har ek nodes se directly durse nodes , par ja sakte hai then ye complete graph hoga. 
   - Complete graph mai kitne edges ho sakte hai :- 
      1. nC2 =( n*(n-1))/2 where n is no vertices in the graph. 

8. Wighted Graph :- 
   - edge with value it may be directed or undirected
9. Unwighted Graph :- 
   - edge ke sath koi value nahi diya hita. 

So hamko pata hai ki agar kisi bhi chiz ko store karwana hai Aone device ke ander toh hamare pass do data structure hai Array(data ko ek sath rako do) or LL(ya data ko alag alag rakh do). 


   