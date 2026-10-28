### Kruskal Algorithum :- used to find the Minimum Spanning Tree 

General Approch :- 
1. Sare nodes ko note kar lete apne copy par
2. ab us nodes/track ko coonect karenege jiska cost sabse kam hoga. 
3. Aise node ko connect karte jayenge jab tak sare node connect nahi ho jate bas is baat ka dhyaan rakhenge ki loop na form kar raha ho. 

So ham yaha apply kar rahe hai Greedy Approch, so ham yaya us edge ko uthayenge jo jiska cost sabse  kam hoga aur loop nahi form kar raha hoga. 

How we come to know that ki loop ban raha hai ki nahi ? 
So jis bhi edges ko select kar rahe hai, wo jine do node ke bichh mai conect hone wale hai, us se pahle ham ye check karenge ki wo dono connected hai ki nahi? Not conneceted then connect them. 
Agar do node connected nahi hai then ham check karenge ki kya ham pahle node se dusre node par ja sakte by any path. So ham dusre node par ja sakte hai then connect nahi karenge kyuki hamko pata hai agar connect kar denge toh loop ban jayega. 

So Isko ham BFS or DFS kisi se bhi kar sakte hai, two node hai so, pahle node se dusre node par ja sakte hai ki nahi, if nahi then connect it and if yes then ignore the edge. So is tarah karne mai ek node ki connectivity check karne mai hamko O(n) time. So is there is a way exist to solve it in O(1) time. 

So Yaha introduction hota hai Disjoint set ka. So isme Different set hota hai hamre pass between ki connected wale node ka ek set aur dusre discoonected or small conected ka ek set, So ab Do node ko check karne ke liye, Agar dono node same set ke part honge tab connect nahi karenge, if different node ke part hai then connect them. 

Disjoint set kaise jud rahe hai aapas mai after the connecetivity of two nods.
1. Start mai sabhi nodes ko maan lenge ki ye alag alag set mai hai, Iske liye ham ek array le lenge V aize ka aur sare array mai unke he index value ko store karwa lenge. 
2. Ab apne minimum edge ko uthayenge , unko agar dono node ka set ka value differet hai means differet set ke hai ye nodes aur connect ho sakte hai, then connect them, un dono connected nodes ke value ko same kar denge, so we can know ke ye same set ke part hai or wo dono ab as single unit treat ho rahe hai. So on karte jao until two node are different or all node are conneceted. 

Note : Is procedure mai jab nearly graph connect ho rahe honge then tab set bade ho gaye honge so ab inko connect karne ke liye kisi ek set ki dusre set ki value ko same karna hoga, isme bhi complexity O(n) time chale ja rahi hai. So isme hamko optimized karna hoga. 

Ham Disjoint set ke help se kaise solve kar sakte hai taaki O(n) time na lage?
We have two method/ approch :- 
1. Union by rank
2. Union by size

1. Union by rank
We have Some edges like (0,1),(1,2),(3,4),(5,6),(7,8),(3,6). We Create an  array of Name Parent of v size ka.parent hamko batayega ki ham kis set mai hai. So parent array mai uski value mai uske index value ko he store karwa lenge,  And Rank array bana lenge of size V. Rank ka kaam hai ki kis set ko kis set se merge kare. Rank as Height bhi maan sakte hai. 
We do work in 3 steps :- 
1. Find the ultimate parent of u and v.
2. Find the rank of the ultimate parent(Pu & Pv)
3. Merge the smaller set into larger set -> on the basis of rank. 

Agar ultimate parent of two node ki value different hai then merge kar sakte hai , So ab decide karna hai ki node1 ko node2 se merge karna hai ki node2 ko node1 se? So Agar ab agar dono node ki value same hai then kisi ko bhi kisi se merge kar sakte hai, Agar node1 to node2 connect kiye hai then parent of node 2 mai node1 ko daal denge. Aur Rank of node1 ko ek se bada denge. and so on.
Note : Agar rank same rank hai then kisi ko bhi kisi ke sath merge kardo and rank of node1 ko bada do and differet in rank hai then merge it on the same level aur hamre rank ko nahi badna hai. 

So hamko kaise patachalega ki parent same set mai hai?
So agar ek vertex se edge nikal kar dusri par ja rahi hai then ham vertex ka ultimate parent ko check karenge  agar dono ke parent same hai the the same set ke hai. Ultimate parenet means ki set ka sabse top wala element jo hai wo. 

Two major operations :- 
1. Find parent
2. Union by rank

Path Compression :-  Parent ko joining karte samay, baar baar same path ko choose n karna pade iske liye parent ko find karne ke liye iske liye jo naya set aa raha usko directly parent se connect karte hai. Means ki ek parent node se sabko directly add karne ki kosis kar rahe hote hai.  

Rank ko hamne bola li ye height jaisa ho sakta hai lakin ye one nahi hai, kyu?

Why merge smaller set to bigger?
kyuki no. of nodes ka count increse na ho. 

2. Union By size :- 
Sab same rahega bas is baar ham different set ke size ko store kar rahe honge, size array mai. Chhote wale ko bade mai merge karenge. 

Code part : Disjoint set

Phase 1:- Find Parent
1. findParent() int type ka, parameter : vector int type ka parent aur ek int type ka u.
2. Agar u barabar parent of u ke tab return kardo u ko
3. Agar barabar nahi hai toh, FindParent(parent[u],parent) call kardo ,
Ab 3rd wale ko path compression karne ke liye, 3rd wale ko parent of u mai store karwa lo aur return kardo, jaha call hua hai. 

phase 2:- Union By Rank  
1. UnionByRank() void type ka, Parameter : int type ka u and v , vector int type ka parent aur rank.
2. int pu = findParent(u,parent)
3. int pv = findParent(v,parent)
4. Agar rank[pu] bada hai rank[pv] se
   1. parent of Pv mai Pu daal do
5. Agar rank of Pu Chhota aata hai rank of Pv se
   1. parent of Pu mai Pv daal do.
6. Agar Pu aur Pv barabar hai then kisi ko bhi kisi ka parent bana do
   1. parent of Pv mai Pu daal do  

Krushkal's Algorithum :- 
Yaha ek karke sorted order mai edges ko nikalna hai so we used PQ -> min heap.
1. Insert all edges in the PQ. 
   pair<int, pair<int, int>> : weight , u and v

Code Implementation :- 
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int FindParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;

    return parent[u] = FindParent(parent[u], parent); // Path Compression
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = FindParent(u, parent);
    int pv = FindParent(v, parent);

    // rank, merge kar paaye
    if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }    
}

int spanningTree(int v, vector<vector<int>> adj[])
{
    vector<int> parent(v);  // ultimate parent will help us to determine set
    vector<int> rank(v, 0); // It will help us to merge the set

    // Starting mai har node ka parent wo khud hoga
    for (int i = 0; i < v; i++)
        parent[i] = i;

    // PQ
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            pq.push({adj[i][j][1], {i, adj[i][j][0]}});
        }
    }
    int cost = 0;
    int edges = 0;
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        // Check : same set or Different set
        if (FindParent(u, parent) != FindParent(v, parent))
        {
            cost += wt;
            UnionByRank(u, v, parent, rank);
            edges++;
        }
        if (edges == v - 1)// Optimizing :- itna edges ke baad loop nahi chalega
            break;
    }
    return cost;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj[V];

    // Standard Adjacency List for MST {neighbor, weight}
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    cout << "The Minimum Spanning Tree weight (Kruskal's) is: " << spanningTree(V, adj) << endl;

    return 0;
}
```

Time Complexity :-
v + ElogE + ElogE

So agar question ye aata hai ki hamne heap kyu use kiya koi sorting algorthum kyu nahi kiya? 
Heapify : E  time kar sakte hai , agar aapne heap ke ander aaray pass karde tab. 

