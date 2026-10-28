### Euler Path :- It is path in graph that visit every edge exactly once.
So Isko samjhne ke liye ek case study use karte hai, so maan lo ki tum kuda uthane wale insaan aur tumhara jiwanyapan usi se hota hai, so tum try karoge ki tum jayada se jayda ek baar mai utha le aur time waste na ho means ki ek raste ek baar he jaye aue waha ka sara kuda utha le next raste par so ki, jayda raste par ja sake aur hamara content bhi thik ho , time waste n ho. 

This is what Eular path says apne node ko sirf ek baar he visit karo, graph mai. So if this type of path exist in a graph then we say's ki eular path exist karta hai. Euler -> E for edges remember it Eular hamesha edge ki baat karta hai.

Note :- Every garph cannot have the Euler path.

### Eular Circuit :- Cycle = Close
Sare edges ko exactly once time visit karna hoga aur hamara starting point aur ending point same hona chahiye, isko bolte hai Eular circuit. So Agar eular circuit exist karta hai than ham kisi bhi nodes se start kare tabh bhi condition exist karta hai whereas in eular path Aisa nahi hota hai. 

Eular ne kabhi bhi vertex ki baat nahi kiya hai, hamko sirf edges visit karana, so in case of disconnected graph we can say that there is Eular path and Eular circuit dono exist kar sakte hai.

How implement this :- 
1. All edges should be visited exactly once. 
2. Start == end. 

We are noticing in the Euler circuit that the degree of the vertex is even. Then their can be euler circuit. Different pattern ko analysis karo by taking the Euler circuit(kyu ye Euler cicuit hai, degree) and non Eular Circuit(aur ye kyu nahi hai, aur kaise bam sakta hai,(degree)). 

Let understand it in more detail, ek starting node hai, so yeha se ek node nikalegi, othernode ko visit karne ke liye, aur agar Eular cicuit hai, then ek edge andar bhi aa rahi hogi. So eular circuit even ho jati hai. 

So the graph should satisfy this condition to be Eular circuit :-
1. The dgree of every node should be even. 
2. All the node should be visited or All edges should be part of the single component. Or
All the non-zero node/vertex should be connected.

Note :- Maan lo ki hamre do disconnected graph hai jinki dgree even hai, tab bhi ham inko Eular circuit nahi bol sakte kyuki agar ek graph ko visit karenge toh dusre graph ko visit nahi kar payenge. or Agar do disconnected graph hai ek even degree hai aur dusra graph mai 0 degree hai then wo Eular circuit ho sakta hai. (0 degree means single node)
2. Degree means :- No. of edges connected eith the particular node. 

Eular Path:-
Art of noticing graph and then making the conlcusion :- 
Eular Graph mai koi 2 or 0 node exist kar sakte hai, jinki degree odd ho aur baki sab ki even hogi. 
Condition to be the Eular Path :- 
1. Zero or Two node can have odd degree and remaining node shoule have even degree. 
2. All non-zero degree should be connected .  Or All the edges should be the part of the 1 component. 


So Eular circuit jiski degree even hoti hai, lakin ye Eular path bhi toh hota  hai isiliye graoh ho sakte  jisme ek bhi node odd na ho , aur sare even degree ho, so call eular path.  

Steps :- 
1. Find the degree of each node
2. Degree of any node is odd , not a Eular circuit. 
3. If even degree
4. We to check that ki sab ke sab connected hai ek sath ki nahi, so Ek visited array le lenge, intialy 0 se initialize kardo, which means ki abhi tak visit nahi hua hai. Apply dfs or bfs from non zero degree

Visitied array :- Ye store karega information ki konsa node visited hai aur konsa nahi, 
Degree array :- Jaha sabki degree ko store karke rakha gaya hai.

Edge Case
1. So ab ham check karenge ki, kya koi aisa node hai jiska degree exist karta hai but wo visited nahi hai so we declare ki Ye Eular Circuit nahi hai.  
2. Jinko degree 0 hai unko dekhne ki zarurat nahi means ki wo unvisited hai tab bhi ok hai. 

Eular Path :-
Is case mai same rahega bas yaha koi do node ko permit de denge kisi 2 wo odd  mai rah sakta hai. 

Note :- If euler circuit than it is also Eular Path but Eular Path can not be the Eular circuit. 
EP :- All the edges should be visited.
EC :- All the edges should be visited && (Start==End).

Real Life Use Case :- Search it into the Google for more. 
Gaadi wala kachra uthane aata hai then wo bhi toh chahega ki uska kam se kam petrol kharacha ho.

Relatable Algorithum :-  Kosaraju's Algorithm

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}

int isEularCircuit(int v, vector<int> adj[])
{
    // Calulating degree
    vector<int> Deg(v, 0);
    int oddDeg = 0; // No. of nodes having odd degree
    for (int i = 0; i < v; i++)
    {
        Deg[i] = adj[i].size();
        if (Deg[i] % 2 == 1)
            oddDeg++;
    }
    // Edge Case
    if (oddDeg != 2 && oddDeg != 0) // 1,3,4,5,6
        return 0;                   // Not a Euler Path and Not a Euler Circuit

    // All non-zero node should be connected.
    vector<bool> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (Deg[i]) // Agar is index par degree exist karti hai then apply DFS
        {
            DFS(i, adj, visited);
            break;
        }
    }

    //  If non zero degree is still not visited then, it is not euler path or circuit.
    // Agar Degree 0, then ignore that node, unke pass edge nahi hai
    for (int i = 0; i < v; i++)
    {
        if (Deg[i] && !visited[i])
            return 0;
    }
    // Euler ckt : 2
    //  Euler Path : 1

    if (oddDeg == 0)
        return 2;

    else
        return 1;
}

int main()
{
    int V = 5;
    vector<int> adj[V];

    // Example: A simple House shape graph (Eulerian Path exists)
    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1, 4};
    adj[3] = {1, 4};
    adj[4] = {2, 3};

    int res = isEularCircuit(V, adj);
    if (res == 0)
        cout << "Neither Euler Path nor Circuit";
    else if (res == 1)
        cout << "Eulerian Path Found";
    else
        cout << "Eulerian Circuit Found";

    return 0;
}
```

Time Complexity :- DFS O(V+E)
Space Complexity :- V

So agar question mai hamko path bhi puchh le ki hamko batao ki konsa path hai Eular ckt or Path ko toh usko is time complexity mai nahi kar payenge. 
