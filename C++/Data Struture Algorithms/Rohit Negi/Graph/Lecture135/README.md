### Cycle Detection in Undirected Graph :- 
"Graph ke problem ko solve karne ke liye, simple common sense use karo"
How we come to know that the given graph is cyclic or not ? 
Let the different vertics in the graph be the different cities. Agar ghumte ghumte wahi pahuch ja rahe hai jaha se start kiya tha tab, then we can said that there is cycle present in the graph . 

Lets Find out the solution using first method i.e DFS. 
In DFS , jo kahata hai starting node ko pakdo uske neighbour ko ek ek karke visit karke aao. and so on karte jao jab tak sare visit n ho jaye. Agar visit karte samay wapas visited node milta hai tab ham kah sakte hai ki cyclic/loop hai, graph mai. Note:- Aur privious node ko consider nahi karna hai as visited. So Parent/previous ko chod kar baaki node ko visit karna hai. Baki node mai se koi bhi visited nikala toh cycle detected. So isme jaise he sare node ko vist kar liya , so phir jaha se aaye hai waha chale jao. 

Note :-  Agar kisi node par do baar chala gaya aur wo hamra parent nahi hai, so declare it as Cyclic. And Jab bhi recursion samjhna hai toh tree generate kar diya karo. 

Requirement :- 
1. Visited Array :- Jo batayega ki koi node visit hua hai ki nahi. 
2. Parent node :- 

Jaise he cycle detect ho jata hai waise return karna start parent to parent and till starting node then finally call khatam. 

Logic steps :-
1. Parent node ko ignore kardo
2. Agar parent ke alawa koi neighnour node already visited niklta hai, then cycle detected. 
3. If not visited then visit the neighbour

Code Part :- 
1. DetectCycle() bool type ka, parameter : int node :- Current node store karega, int parent: Current ka parent konsa hai, vector int type ka adj[] array, vector bool type ka visited as reference. 
Note:- Initial node jab koi parent nahi hai toh usko -1 se show kar denge. 
2. visited of node ko 1 bana denge. 
3. Ab is node ke sare neighbour ko ek ek karke visit karna hai, so ek for loop chalayenge jo j=0 se chalega j< adj[node].size() tak
  1. Agar parent barabar hai adj[node][j] (neighbour) ke tab continue kardo (which means ki nichhe wale ko chhod or skip kardo)
  2. Agar visited node already visited hai or visited[adj[node][j]] == 1 hai tph return kardo 1 (cycle detected)
  3. Agar visited nhi hai DetectCycle() ko call kardo, agar ye return 1 karta hai or ye true hua toh return kardo yahi se return 1 kardo. 
4. Agar neighbour mai cycle nahi mailta tab return kardo 0, ki cycle present nahi hai. 

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

bool cycleDetect(int node, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;

    // Current node ke neighbour ko visit karo
    for (int j = 0; j < adj[node].size(); j++)
    {
        // Ignore the parent node
        if (parent == adj[node][j])
            continue;
        // If neighbour already visited
        if (visited[adj[node][j]] == 1)
            return 1; // Cycle mil chuka hai

        // Agar neighbour visited nahi hai than
        if (cycleDetect(adj[node][j], node, adj, visited) == 1)
            return 1;
    }

    return 0;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool> visited(v, 0);

    return cycleDetect(0, -1, adj, visited);
}

int main()
{
    int v = 5; 
    vector<int> adj[v];

    // Graph with a cycle (0-1-2-0)
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1};

    if(isCycle(v, adj)) {
        cout << "Cycle detected in the graph!" << endl;
    } else {
        cout << "No cycle found." << endl;
    }

    return 0;
}
```
Hamane abhi ek important case miss kar diya hai , Jab hamne graph pada tha tab hamko bataya gaya tha ki disconnected node bhi same graph ke part ho sakte hai means agar do ua do se jayda alag jagah node present hai graph mai toh wo bhi ek he graph mai count kiya jata hai. 

Time Complexity: O(V + 2E) -> O(V+E)  — Kyunki hum har node ek baar aur har edge ko 2 baar(ek baar visit ke liye ek baar check karne ke liye) visit kar rahe hain.
Space Complexity: O(V) — Visited array aur Recursion stack space ke liye.

So we need to add the while loop in the implementation :- 
```
bool isCycle(int v, vector<int> adj[])
{
    vector<bool> visited(v, 0);

    // Loop lagana zaroori hai taaki saare components cover ho sakein
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            if(cycleDetect(i, -1, adj, visited)==1) // return 1 aata hai then cycle detected, aur yaha se 1 ko return kar denge.
                return 1;
        }
    }
    return 0; // Pura visit karne ke baad loop n mile. 
}
```

### Cycle Detection in Undirected Graph using BFS :- 
So here treat BFS as Fire , so if starting node ko fire laga de toh pahle apane agal bagal lagayega phir wo apne agal bagal so on jab tak sare visit nahi ho jate. So agar fire jo alag alag direction mai nikle the means ki different level par ,  wo meet kar jaate hai tab bol denge cycle detected. Means agar koi node do baar visit ho jate hai apne parent ko chod kar then we call the that ki cycle detect ho gaya hai. 
Agar sare node ek baar visit hua hai toh return kardo ki cycle present nahi hai

So hamko kya ky information chahiye?
Ek queue : jisme sirf node nahi balki node aur uskeparent ko store karke rakhna padega. Kyuki sirf nodes se ham pata nahi kar payenge ki parent kon sa hai , agar ham bolte hai queue mai ji uske pahle tha wo then ham tab bhi galat ho sakte kyuki is case mai ek node multiple node se connected hota aur chance honge ki wo sibling nikale n ke parent. 
Visited Array: jo batayega ki kon sa visit hua aur kon sa nahi

Here too we three cinditions we discussed in last method :- 
Logic steps :-
1. Parent node ko ignore kardo
2. Agar parent ke alawa koi neighnour node already visited niklta hai, then cycle detected. 
3. If not visited then neighnour ko queue ke ander daal do and mark it as visited. 

Time Complexity :- O(V+2E) -> O(V+E)

Code Implementation :- 
```
```

