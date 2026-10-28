### Shortest Path in Undirected Grapg :- 
Hamko ek graph diya hoga aur ek source node diya hoga, So hamko source se shorted distance nikalna hai har ek dusre node ke liye. So isko solve karne ke liye hamre pass kya method's hai? Hamko traverse karna hoga :- BFS OR DFS 
Note :-  Graph Disconnected ho bhi sakte hai. 

BFS method :- 
So is method mai source se start karenge BFS traversing, So pahle uske agal bagal, phir uske agal bagal ghumte jayenge, jinki visit kar liya hai us neighbour ko dobara visit nahi karenege, on traversing on each level we increse the distance by 1.  

So ham ek Dist naam ka array le lenge , jo source se specific node ki shortest distance ko store karke rakhega aur is vector ko -1 se initialize kar denge. Aur ek visited array le lenge aur isko 0 se intiallize kar denge. 
Agar koi disconnected hai means ki wo source se connected nahi hai then hum uske liye -1 le lenge. 

So source node se start karo, mark this node as visited and  dist vector source node ke jagah 0 se update kardo as same node distance same node se 0 hoga, phir uske neighbour wale ko visited mark karo and
distance calculate karo previous node distance + 1(neighbour node or next level).  and do so on. 
i.e, dist[ neighbour] = dist[ node] +1;

steps :- 
1. Source node se start karo
2. uske neighbour ko check karo, if not visited
3. mark it visited and push that neighbour in the queue
4. update distance i.e dist[ neighbour] = dist[ node] +1;

Code Implementation :- 
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)  // M : no of edges
{
    // adjecency list create karna 
    vector<int> adj[N];

    for(int i=0;i<M;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // Array dist
    vector<int> dist(N,-1);
    vector<bool> visited(N,0);

    queue<int>q;
    q.push(src);
    dist[src]=0; 
    visited[src] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        // Look at all the neighbour
        for(int j=0; adj[node].size();j++)
        {
            // Agar node visited hai toh usko chod do, kuchh nahi karna hai
            if(visited[adj[node][j]])
            continue;

            visited[adj[node][j]] =1;
            q.push(adj[node][j]);
            dist[adj[node][j]] = dist[node]+1; 
        }
    }

    return dist; 
}
```
Time Complexity :- 
BFS Operation : O(V+E)
Adjecency List : O(V+E)

Space Complexity:-
Adjecency list :O(v+E)
dist : O(V)
visite :(V)
Queue : O(V)


### Using DFS :- 
So Ab DFS se is problem ko solve karne ki kosis karte hai, So source node se start karo aur kisi ek neighbour ko pakdo aur ek se increment karo dist ko, and tab tak visit karte jao tab sare node visit nahi ho jate, agar neighnour ke sare node visit ho ja rahe hai then , apne pichhle par aao, usko check karo kya visited hai if no then visit that neighbour , if yes then come back and so on. 
So we conclude that ki simple dfs se hamara ans nahi aa sakta so hamko kuchh extra karna hoga. 
So ham apne source par wapas aane ke baad , Dusre raste ko bhi explore kare , apne ans ko update karte jaye. So ye karne, ham multiple times apne node aur edge ko cover kar rahe haidi different path ko explore karne ke liye jis se complexity bad jayengi. 
So that's why we not preferred to apply dfs as uske use se complexity bad jati hai whereas we can find out the ans with it. 

### So same graph mai puchhe ki source se destination ka shortest path batao
So isme shortest path kon kon se node ko connect kiya hai, usko bhi batana hai. 
So iske pahle mai BFS laga rahe the shortest path find karne ke liye jaise he hamko hamara destination mila ham ruk jeynege, lakin ab toh hamko sirf shortest distance mila hai pah nahi? Iske liye apne node ek aur information store karwa ke rakhenge, uske parent ko. 
So ab destnation node milne ke baad uske parent aur uske parent ko store karte jayenge till source aur sare parent ans mai store karte jayenge , so ab reverse order mai path mil jayega, then apne path ko reverse karke ans mai store kar lenge. aur return kar denge. 

Steps :- 
1. Minimum distance find karo destination node ka
2. destination node se uske parent par jao aur usko store karlo array mai
3. till src node tak 
4. apne array ko reverse karke ans dedo. 


dist = parent array :- parent kon hai batyega , -1 se intilize kar dena
visited array :- visited hai ki nahi information ko batayega, 0 se initialize kar dena

So sorce node se start karo usko queue mai daalo, bahar nikalo, aur uske neighbour ko visited mark karo if not marked as visited, neighbour ke parent ko store karlo in parent array and do so on till got the destination node. So agar sare node visited ho gaye hai then hamko hamara parent array mil chuka hai. 
Parenet :- Agar koi node visit nahi hua hai , aur aap usko visit kar rahe hai, then aap uske parent honge. 
Node :- Jiska parent -1 hai means uska koi parent nahi hai aue wo src node hai. 
Reverse karte samay ask question :- mera parent kon hai, phir isme jo valuue hai waha chale jao ask same till got -1. (parent array).

Code Implementation :- 
```

```
