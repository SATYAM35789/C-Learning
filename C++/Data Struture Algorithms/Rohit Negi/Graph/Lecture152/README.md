### Bridge in a Graph :-  Tarjan's Algorithm
Bridge :- Ham bridge us edges ko  bolenge jisko hatane se hamara graph do componenet mai bat jaaye. or edges do node ko connect karti hai, agar edges ko remove karne ke baad , ham ek node se dusre node par nahi pahuch pa rahe hai so usko bridge bolenge or Agar do adjecent node same cycle ka part hai then wo bridge nahi ho sakti. So hamko count karna hai ki total kitne bridge hai total,  given graph mai. 

Brute Force Approch:-  Isme ham ek ek karke check karenge ki agar node hataya toh kya dusre side pahuch sakte hai ki nahi. 
Time Complexity of this type question is quite high. E times DFS. 

So Apne example graph ko dekh rahe hai tab, ham ye conclude kar paa rahe hai ki jo bhi edges hamare loop ka part hai unko remove karne se do component mai graph divide nahi ho raha hai. So jo cycle ka part nahi hai wo as bridge kaam kar rahi hai, hamare graph ko do part mai divide kar paa rahi hai. 

So question ko is tarah se bhi puchha ja sakta hai? Given graph mai kitni edges cycle ka part hai aur kitani node cycle ka part nahi hai. 

So Agar Graph mai traversing ke waqat koi aise node hai jo visited node ko point kar raha hai then we say that this node is surely not act as bridge as it forming an cycle. 

How can we differentiate the that the node is part of the cycle or not? 
So edges se connected first node apne dusre node se sawal puchhega ki kya tum kisi aise node par pahuch sakta hai ko jo mujh par ya mujse pahle wale node par aaye ho. Agar kisi bhi aise node ko visit kar sakta hai, then edge ke toh first node par pahuch he sakte hai. 

let the first node be parent and second node be child. So modified question kya child koi aisa node visit kar sakta hai, jo parent ya us se pahle aaya ho. 

In parent child relation, Not a bridge Condition :- 
If from a child, if we can visit any node which comes to parent or the node which comes brfore parent.

So kya ab constant time mai pata kar sakte hai kya ki node parent side present hai kya. Agar ek present hua then loop exist, if not present then loop not exist. So vertex is in 0-N order. So we can conclude that : If any value is, less then or equal to parent value then it is forming loop and not a bridge. So ab agar ham check sabse chhote wale ko he store karwa ke rakhe aur check kar le lya ye chhota ya barabar hai hamare parent node se thrn not a bridge. 
minimum : Kaha se select karna hai, child to next visited mai se jo chhota hai usko. 

Conclusion :-
Jaise jaise aage badte jayenge aur naye node aate jayenge waise waise disc(discovery time) dete jayenge. If already visited then not a bridge. low : Minimum possible time to discover a node which we can visit without using parent. Low hamari minimum value hai jo ham store karte the. Starting mai same same disc naam dete jayenge. jaise he hamko visited milta hai then then u(initial) ke low update karenge min(disc[ parent],low[ child]) se. Phir ek kadam pichhe aa gye jaha hamko jaha visited mila tha. Phir same min ko update kardo and so on jab tak condition falsenahi ho jata.
Bridge:- disc[ parent] < low[ child]   
Not Bridge :- disc[ parent] >= low[ parent]  where parent= node, child = neighbour 

Condition we have :- 
1. if(neighbour==node) then ignore this case
2. if(visited[neighbour]), agar already visited hai, then low[node] = min(low[node], low[neighbour] )
3. Agar visited nahi hai then dfs call laga do
   1. Agar of node chhota hai low of high se then apply your operation. 

Time and space Complexity : V+E

Code Implementation
```
#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, int parent, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &Bridges, int &count)
{
    disc[node] = low[node] = count;
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        int neigh = adj[node][j];
        if (neigh == parent)
            continue;

        else if (visited[neigh])
        {
            low[node] = min(low[node], disc[neigh]);
        }

        else // not visited
        {
            count++;
            DFS(neigh, node, adj, disc, low, visited, Bridges, count);

            //  Bride Exist
            if (low[neigh] > disc[node])
            {
                // ek 1d vector liye hai usko 2d vector bridges ke ander daala hai.
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(neigh);
                Bridges.push_back(temp);
            }
            low[node] = min(low[node], low[neigh]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    // Creating Adjecency list :-
    vector<vector<int>> adj(n);
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0]; // col 1 mai first node
        int v = connections[i][1]; // col 2nd mai second node hai
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> Bridges;
    vector<int> disc(n);
    vector<int> low(n);

    vector<bool> visited(n, 0);

    int count = 0;
    DFS(0, -1, adj, disc, low, visited, Bridges, count);

    return Bridges;
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> bridges = criticalConnections(n, connections);

    cout << "Bridges in the graph:" << endl;
    for (auto it : bridges)
    {
        cout << it[0] << " -- " << it[1] << endl;
    }

    return 0;
}
```