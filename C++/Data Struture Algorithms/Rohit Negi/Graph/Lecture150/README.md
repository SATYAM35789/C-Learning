### Minimum Spanning Tree :- 
Saanning Tree : It is a subset of Edges of a graph that forms a tree, when every node of a graph is a part of tree. 
Tree Definition:- 
 1. node : n, edges : n-1
 2. No cycle
 3. All the nodes should be connected.

So hamare pass graph hoga jisme se kuchh node select karna hai, so isme so  sare ki sari node hona chahiye aur sari nodes connected hona chahiye aur cycle nahi hona chahiye. Or Us Graph se tree bana lo jo tree ki definition ko follow kar raha ho, isko bolte hai spanning tree. 

Minimum spanning tree :- 
Weight with spanning tree having the minimum total cost , is called the Minimum spanning tree. 
So Ek weighted graph se bahut sarre spanning tree ban sakte hai, so un sab mai se jiska sabse kam weight ka summation hoga wo hamara minimum spanning tree of that graph.

Advantages of the minimum spanning :- 
Railway line connectivity in different city :- Delhi-Up-Mp-Uk are the graph with having 5,4,3,2 weight respectively. So hamre pass issue hai ki hamko railway lines bichhna hai hamre pass budget kam hai so hamko sare city ko conect be karna hai aur kam se kam kharacha karna hai. So we use MST Sare connected bhi rahenge aur cost bhi kam lagegi. 

Approch :- So pahle approch ye ho sakya hai ki ham apne graph ka sare spanning tree banaye aur unke sare ke cost calculate kare, unme se jo chhota hai usko select karle. 

So we have two Algorithms to find out the minimum spanning tree. 
1. Prim's Algorithum 
2. Kruskal's Algorithum 

### Prim's Algorithum :- 
Kisi bhi ek node ko pakdo apne graph ka, uske neighbour mai jo sabse chhota hai , aur wo visited nahi hai, then select that neighbour and go to that node and so on till all node are visited. 
Agar edge ko connect karte se cycle form ho sakta hai then us edge co ennect nahi karna hai basically jo hamne tree ka definition bataya tha wo satisfied hona chahiye. 

Example :- 
Ek 8 node ka graph hai hamare pass, jisme hamne node/vertex as station treat kar rahe hai, edges ko as track. Yaha inke weight bhi diys gaye hai. Kisi bhi ek node ko pakdo, uske neighbour mai jo sabse chhota hai usko pakdo aur waha chale jao and so on karte jao, while doing this satisfied the tree conditions. We got our MST. So edge connect karte samay agar loop form ho  raha hai then pichhe chale jao aur phir waha check karo ki loop hai ki nahi if nahi then connect karlo if yes then go back.

Pseudo Code :- 
1. Ek array MSt jo batayega ki kon kon se node, spanning tree ke part ban chuke hai, Isko array ko 0 se initiallize kar denge, Aur jo MST ka part bante jayega usko 1 marke karte jayenge. 
2. So hamko min heap/priority queue ki zarurat padegi kyuki hamko minimum weight ko he select karna hai. 
3. Isme Kya kya puchha ja sakta hai :- 
   1. Minimum spanning tree ka cost kya hoga?
   2. Apne Minimum tree ko draw karo. 

   MinHeap :- weight,node,parent store karke rakhega. (0,0,-1) se initialize karenge start mai. 
   Parent Array :- aur apne parent ko store karte jayenge. 
   variable: cost ,Draw MST.

   So min heap se element/pair ko bahar nikalo , check karo ki MST ka part hai hai ki nahi, agar part nahi hai toh usko part bana lo and agar part nahi hai toh usko ignore kardo, aur uske  parent ko note karlo parent array mai. 
   Parent wo banega jo sabse pahle bahar niklega heap se.So jab tak priority queue khali nahi ho jata hamara code chalta jayega. 
   
   Why we need Parent ? 
   Ham sirf parent ko dekh kar he apne tree ko draw kar sakte hai. value : represent kaha se index: represent kaha ja rahi hai edge. 

Note :- Graph should be connected kyuki tree mai sare modes hote aur wo connected hote so agar graph connected nahi rahega toh spaning tree bhi conected ahi rahega aur n nodes or total nodes cover nahi kar payenge. 

Code Implementation
``` cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int spanningTree(int v, vector<vector<int>> adj[])
{
    // Priority Queue :- Min Heap
    // wt , node, parent
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> IsMst(v, 0);
    vector<int> parent(v); // Not Necessary :-  Agar Spannig Tree ko DRAW karne mai use hota hai

    int cost = 0;
    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;

        // MST ka part nahi hai,
        if (!IsMst[node])
        {
            IsMst[node] = 1;
            cost += wt;
            parent[node] = par;
            pq.pop();

            // Visiting neighbour
            for (int j = 0; j < adj[node].size(); j++)
            {
                if (!IsMst[adj[node][j][0]])
                {
                    pq.push({adj[node][j][1], {adj[node][j][0], node}}); // weight , node , parent
                }
            }
        }
    }
    return cost;
}

int main()
{
    int V = 5; // Total nodes
    vector<vector<int>> adj[V];

    // Graph edges based on {neighbor, weight}
    // Edge: 0-1 (weight 2), 0-3 (weight 6)
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});

    // Edge: 1-0 (2), 1-2 (3), 1-3 (8), 1-4 (5)
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});

    // Edge: 2-1 (3), 2-4 (7)
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});

    // Edge: 3-0 (6), 3-1 (8)
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});

    // Edge: 4-1 (5), 4-2 (7)
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    // Function call
    int totalMSTWeight = spanningTree(V, adj);

    cout << "The Minimum Spanning Tree weight is: " << totalMSTWeight << endl;

    return 0;
}


```

Space Complexity :- 
Priority Queue :- Approximately  E no of edges se hamara node connect jo sakta hai, aur aise v no. of nodes ho sakte hai hamare pass. And we were doig push and pop operation :- ElogE + ElogE respectively. LogE push karne ka which is maximum size of push element in pq. 
ElogE =  ElogV  {where E=vsq in the case of Complete Graph . so Elogvsq = ELogV}
 

