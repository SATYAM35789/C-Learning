### Cycle Detection in a Directed Graph :- 
Hamko koi directed graph dita hoga aur bol raha hoga ki kya isme koi directed graph given hai ki nahi. Lets take real life example to understand importance of these type of question :- Resources allocation by the processes. Hamre pass do process hai p1 aur p2, p1 ko r1(printer) allocated hai, and p1 is requested for r2(scanner). where as p2 ko r2(scanner) allocated hai, p2 requested for r1(printer). So isme dono p1 aur p2 ko task mila hai ki usko scane karna then print katna hai. So isme deadlock condition aa ja rahi hai. Is trah ke problem ko system ko detect karna hota hai, so ki ham apne resorces ko use kar paye.So we need free the resource.  
DeadLock Condition hone ke liye:- 
 1. Mutual Exclusion  2. Hold and Wait  3. No preemption 4. Circular loop should exist

So is problem dur karne ke liye kon use karega resources ko pahle, iske liye hamko pata hona chahiye ki Cycle detection in a directed Graph so ki ham is situation ka pata laga paye. 

Cycle Detection in a Directed Graph using DFS :- 
Using same concept we used in undirected graph :-
1. If there is node, if its neighbour is already visited and it is not a parent. 
Kya is concept ka use kar sakte hai Is problem mai :- So ham is concept ka use nahi kar sakte as we have problem that there may be situation when have both neighbour of node has same end point, so in thse case , pahle pahla neighbour visit hoga jab uske aage kuchh nahi tab wo return ho jayega then second neighboue vist hoga agar uske ending same hai then wo toh visited show hoga ye parent bhi nahi hoga, aur cycle bhi nahi ban raha on thet case we failed here. So ham sirf visited ke help se apne ans ko nahi nikal sakte. 

Lets see kon se  concept ka use kar sakte hai isko method ko solve karne ke liye :-
So agar current path mai koi node ek se jayda baar present hai then waha ham bol denge ki cycle present hai. So focus in the current path only. So hamko kaise pata chalega ki hamare current path mai cycle present nahi hai. or Hamare current path ye aur isme element repeat nahi hua hai? Ek path naam ka vertex size ka array bana lenge aur isko 0 se initialize kar denge. So jo bhi path mai aate jayenge unko 1 se increment kar dena jab tak path exist karta hai. So jab end par pahuch jayenge return karte waqat ham phir se ek decrement karte jaynge. agar wapas aate waqat koi neighbour visit nahi hai then usko visit karne ye hamara basic approch hota hai dfs ka. 
Note : 
1. So path mai next element mai jane se pahle ham check karenge ki kya ye element hamare path mai pahle se toh present nahi hai, if nahi then add it to the path and go for next if yes then cycle detected.
2. While returning 0 bana denge means unko apne path se exclude kar diye hai.  
3. path Jo info rakh raha tha usko dfs stack bhi bolte hai :- Jab recursive call lagate hai so jis bhi order mai value jati hai stack mai wo path ko he show kar rahi hoti hai. 

Code Part :- 
1. DetectCycle() bool typa ka , parameter : int type ka node, adj[] array vector int type ka, vector bool typa ka path as reference pass kardo.
2. jis bhi node se start kar reha hai usko path of node ko 1 bana do.
3. ek ek karke apne sare neighbour ko dekh rahe hai, ek for loop j=0 se j ke adj of node ke size itna chalega. 
  1. Agar path already visit ho chuka hai, path of node and j equal to 1 hai tabreturn kardo 1 which means ki cycle present hai
  2. Agar present nahi hai then call the function for that neighbour :-detectCycle(adj[node][j], adj,path) so agar ye barabar hai 1 ke then reurn kardo 1
4. jab return kar rahe honge tab is path ko 0 bana do
5. return kardo 0 which means ki cycle present nahi hai. 

So abhi ye code fullt optimized nahi means ki ye ki chances hai wo kuchh nodes ko baar baar visit kar raha hai which may increse the complexity so we need to introduce thr visited array which help us to know that ki ham is path ko visit kar chuke hai means ki path is nodes ko visit kar liye jo kisi aur path mai include tha. 

Note :- On a particular before going to visit another ask these
1. Kya ye node pahle se hamari path toh present nahi hai?
2. kya us node ko ham already visit kar chuke hai then hamko waha jane ki zarurat nahi hai. 

code part with modifiaction :- 
1. DetectCycle(), parameter : vectorbool type ka visited as reference
2. visited of node ko 1 bana do
3. Agar hamara neighbour already visited nika means visited[nide][j] barabar 1 ke tab continue kardo which means ji next iteration mai chale jao not need to go for further. 
Note :- Visited 2nd priorty rahega means pahle path wale ko chack karo then visited kyuki agar aisa nahi kiya toh ham cycle ko detect nahi kar payenge. 

Time Complexity : O(V+E)
space Complexity : O(V)

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

bool DetectCycle(int node, vector<int> adj[], vector<bool> &path, vector<bool> &visited)
{
    visited[node] = 1;
    path[node] = 1;

    // visiting neighbour one by one
    for (int j = 0; j < adj[node].size(); j++)
    {
        // if Already present in the path then retun means cycle detected
        if (path[adj[node][j]] == 1)
            return 1;

        else
        {
            // Agar node ke neighbour already visited hai means kisi aur path ka part rahe chuka hai so skip kardo
            if (visited[adj[node][j]] == 1)
                continue;

            // so if unvisited hai then call detectCycle and agar ye 1 deta hai then return kardo 1
            if (DetectCycle(adj[node][j], adj, path, visited) == 1)
                return 1;
        }
    }
    path[node] = 0;
    return 0; // cycle not present in graph
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool> path(v, 0);
    vector<bool> visited(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && DetectCycle(i, adj, path, visited))
            return 1;
    }

    return 0;
}

int main()
{
    int v = 4;
    vector<int> adj[v];

    // Directed Graph with a cycle: 0 -> 1 -> 2 -> 0
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0, 3}; // Cycle yahan hai 0->1->2->0
    
    if (isCycle(v, adj))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}
```

### Cycle Detection Using BFS :-
So hamne topological sort pad rakha hai, so topological sort ham sirf DAG ka he nikal sakte hai, Agar ham kosis kare Directed Cyclic graph ka Topological sort nikal ne ki so kya hoga, agar cyclic hai tab toh sorting nahi nikalega, is par agar kanh's algo apply kare toh kya hoga? Sodekhte hai hamko kya milta hai.
So ham Indegree find karenge , so jiski bhi indegree 0 hai usko queue mai daal do, phir usko queue se bahar nikalo, phir uske neighbour ki indegree ko ek se kam kardo. and do so on. So ham cycle mai laga rahe the so ye conclude karte hai ki jo cyclic form kar raha hoga wo kabhi ha,are ans ka part nahi hoga.(indegree 0 nahi hoga. So wo queue mai nahi jayega wo bahar nahi jayega ans mai).
Note :- DAG ke case mai agar v no of vertex hai toh utne no of count bhi milta hai hamko. DCG hai toh count != v (vertex).

Time and space same hai. 

Code Implementation :- 
```

```