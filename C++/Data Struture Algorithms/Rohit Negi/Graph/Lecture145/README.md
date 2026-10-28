### Bellman Ford Algorithum :-  Single source shortest path algo
Ye single source shortest path Algorithum, Dijkstra's algorithum mai ham directed or undiected dono ke liye liye use kar pa rahe the lekin ek condition tha ki ham sirf +ve weight ke liye applicable. Agar -ve weight aa jata tha toh hamri algo fail ho jati thi. 

Doing Modification in the Dijkstra's algorithum so ki ye -ve weight ke liye bhi kaam karne lage. So agar ham apne example jo 3 node ho usme weight diya gaya ho jisme se ek -ve le lenge, so agar isme ham explore ko ignore maar de tab hamko hamara ans mil sakta hai means ki hamne explore wala system hata diya. 

So ab explore jab hat gaya tab ham jo bhi update ho raha hoga usko queue ke ander daal do, bahar nikalo us node explore karo means ki apne jo bhi edge us node se nikal rahi hai waha check karo keya curr[node] + weight chhota hai uske neighbour se so is process mai bar bar apne node ko explore karte jayenge har bar value update hota jayega means har bar hamko chhota distance milta chala jeyega. 
Note :-  Agar graph mai -ve cycle present hoga tab koi bhi algorithum ans nahi nikal sakta. 
Negative Cycle :- Agar us graph ke sare weight ka sum -ve aata hai then usko ham bolenge -ve cycle. So ham kabhi bhi shortest path nahi nikal sakte is type ke graph ka. 
Positive Cycle :- So agar ham given graph ka weight ka sum -ve aata hai then us case mai answer nikal sakta hai. 
Toh modification karne ke baad bhi agar dijkstra algo laga rahe hai toh infinte chalta jayega as ki isko lagega ki naya shortest path milne wala hai so time exceed limit aa jayega in case of -ve cycle. 

Disadvantages of Dijkstra algo :-(summary) 
1. -ve weight, kaam nahi kar payega. 
2. -ve cycle, mai infinite chalega. 

So we need Bellamon- Ford Algorithum. 
Ye algorithum lagta hai sirf Directed graph ke uppar. 
1. Agar -ve weight hai toh shortest path bata dega. 
2. Agar negative cycle present hai then ye detect karke bata dega ki negetive cycle present.

So dijkstra mai ek node ko pakdte hai, jaha jaha edge ja rahi hoti hai, un edges ko relex karwa dete hai, phir waha so waha se jo agale chhoti wali distance ko select karte tha , so is tarah se answer nahi nikal raha tha, So jab vertex ko select karke answer nahi mil raha then , edges selection ka method use karenge. 
Bellamon- Ford Algorithum :-
1. Relex your all edges , (v-1) time. 
    Relex edge :- U -> V
    dist[u]+weight < weight then dist[v] = dist[u]+ weight  where u =  node and v = neighbour 
2. Relex your edges one more time :- to detect the -ve cycle(cycle).
 So Agar Is baar edges ko relex karte waqt koi bhi distance ki value change hoti then cycle present hogi, if no distance then hamko shortest path mil chuka hai. 

Steps :- 
1. We are having graph having 5 vertex with 6 edges , with negative weights, we have the source node , and minimum distance from source node to source node is 0 and source node tp other distance are Infinite or intmax initiallly. 
2. Relexing all the edges
       u   v   w
    ex 2,  4,  2
       3,  4, -2
       2,  3, -3
       0,  2,  5
       1,  3,  1
       0,  1,  3

Formula :- dist[u]+w < dist[v] then dist[v] = dist[u]+w
So we have 5 vertex so v-1 times edges relex hoga 
1st time :- 
dist[2] +2 < dist[4]
dist[3] -2 < dist[4]
dist[2] -3 < dist[3]
dist[0] +5 < dist[2] and so on 

Similarly v-1 times karenge
Note:-
1. Ek baar sabhi edges ko relex karne mai, kisi ek node ka shortest distance mil ja raha hai, source node se, isiliye v-1 time edges ko relex karte hai. Kyuki starting hamko sirf source node ka distance pata hota jo aur sab to infinite hote hai so Source node wala he Edge relex condition ko satisfied karta hai. 
2. Dijkstra algo vertex ko pakad je edges ko relex karwata hai aur Bellmon ford Edges ko pakad ke. Edges ko isilye kyuki jo hamara dijkstra tha wo infinte time chalte ja raha tha , so edges ke through infinite time nahi chalata hai.

Note:- Agar ham apne edges ko reverse karde tab, So if you have relexed all the edges, if there is no changes in dist, then yahi hamara ans hai. 
Conclusion :-  So if source node ka last mai relex kar rahe hai tab , answer hamko (v-1) time edges ko relex karne par mil sakta hai(which is worst scenario), if source start mai he hai while edges relexing so toh hamko answer jaldi mil sakta hai. 

Code Implementation :-
```
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellmon_ford(int v, vector<vector<int>> &edges, int s)
{
    vector<int> dist(v, 1e8); // 1e8 : 100000000
    // In edges every row represents :- u v w
    dist[s] = 0;
    int e = edges.size();

    // Relex all the edges, v-1 time
    for (int i = 0; i < v - 1; i++)
    {
        // Ek ans same aa raha relex ke baad 
        bool flag = 0;
        for (int j = 0; j < e; j++) // sari edges par jana hai
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] + wt == 1e8)
                continue;

            if (dist[u] + wt < dist[v])
            {
                flag =1; // ans mai change hua hai
                dist[v] = dist[u] + wt;
            }
        }
        if(!flag) // Agar ans mai change nahi hua then yahi se return ho jao. 
        return dist;
    }

    //  To detect the cycle
    for (int j = 0; j < e; j++) // sari edges par jana hai
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] + wt == 1e8)
            continue;

        if (dist[u] + wt < dist[v])
        {
            // Cycle detected : So agar koi bhi change hota hai last time chalane ke baad then
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }
    return dist;
}

int main()
{
    int V = 4;
    // Edges: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 1},
        {2, 1, -2}, // Negative edge
        {1, 3, 3}
    };

    int source = 0;
    vector<int> result = bellmon_ford(V, edges, source);

    if (result.size() == 1 && result[0] == -1)
    {
        cout << "Negative Cycle Detected!" << endl;
    }
    else
    {
        cout << "Shortest distances from source " << source << ":" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i << " : " << result[i] << endl;
        }
    }

    return 0;
}
```
Edge Case :
So hamne code mai Intmax ki jagah 1e8 liya hai so jab wt =ve hai then ye kaam tph kar raha hai, lakin agar wt -ve  us case mai edge relex wali condition true ho ja rahi so value update ho ja rahi hai. So intmax -wt ko hamko as intmax he treat karna hai . 

Time Complexity :- (V-1)*e + e = O(Ve) Best case e
Space Complexity :- V

Best Case Possibilty :- jab source node he disconnected ho hamare graph se. 

Bellmon algorithum ko undirected graph ke liye apply kar sakte hai? 
Laga sakte hai lakin lagna nahi chahiye, So ham Edges ko introduced kar denge , agar undirected hai then ham edges toh bana he sakte hai 0 to 1 and 1 to 0 bhi bana sakte hai. 
Undirected Graph ko Directed ke liye use karna chahiye, So if positive edge hai then Bellmon mai hamko ev time lagta dijkstra se elogv lagta hai. 
Undirected mai agar -ve edge hua toh ham dono algo se ans nahi nikal payenge. Kyuki undirected ke case mai agar dhyan se dekhe toh agar koi -wt se u to v and vto u ho rha then ye cycle nahi form kar raha. and -ve hai weight hai toh dijkstra toh laga he nahi sakte. 
