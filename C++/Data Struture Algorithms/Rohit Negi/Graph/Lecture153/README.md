### Articulation Point :- Tarjan's Algorithum
Hamko ek graph diya hoga aur puchhega ki us graph mai kitne Articulation pont present hai. Articulation Point : Wo node jisko hatane ke baad hamara graph ek se jayda component mai bat jaayega. or Agar node ko hatane ke baad ham uske adjecent node par nahi pahuch paa rahe hai then usko ariculation point mai mil jayega. 

1. Approch :- Har node par jaye aur check karle kya is node ko hatane ke baad , iske neighbour par pahuch ja sakta hai, kya connected hai. 

2. Approch :- 
So we can note from the graph that ki koi node articulation point nahi kyuki wo node kisi cycle ka part hai. So cycle mai agar ham kisi node ko hata dete hai then hamko pata hai ham uske neighbour node par ja sakte hai. 
Note: Agar koi node cycle ka part hai, then wo Articulation point nahi ho sakta. Agar kisi graph mai cycle present hai then aur wo disconnected nahi hai then usko cycle ka first node articilation point hoga.  

So Initial node kabhi bhi Articulation point nahi ho sakta , usko hatane ke baad bhi graph do component mai nahi batega. Conditiom for articulation point :- disc[ node] <= low[neigh] . disc :- At ehat time  the node is discovered. Low :- It store the lowest discovery time reachable from current node. Itially node khude ke low aur disc  hote hai. 

So ham traverse karte ja rahe hote hai, jaha disc of node aur low of node ko same  ho rahe hote hai, jab hamko visited node milta hai, tab apne low of node ko update karenge min(low[ node], disc[ neigh]) se. 
Jab apne child se wapas aa rahe honge then, low[ node] = min(low[ node], low[ neigh]).
Edge Case :- Jiska parent -1  hoga uske liye ham articulation point wala condition apply mahi karenge. 

Conditions :- 
1. Already visited then low of node = min(low[ node], disc[ neigh])
2. If not visited then visit karlo aur wapas aate samay chack karo,
   1. Agar disc[ node] <= low[ neigh] se then articulation point hai. 
   2. update the low[node] = min(low[ node], low[ neigh]) ko

Note jiska parent -1 hoga wo kab articulation point ho sakta hai, jab root node 1 se jayda child hai then articulation point ho sakta hai. 

How come to now that ki different child hai root node ka?
root node bhi cycle mai include hoga tab ham nahi bol saklte ki root node do child hai.  So jab ek se jayda child hoga tabhi articulation point ho sakta hai, agar nahi toh nahi ho sakta. 

To add the articulation point at one time only then we need to make the array we store the particular in the aaray by marking 1, and traverse the aaray to retur the count . 

time  Complexity :- V+E
space Complexity :- V

Code Implementation :- 
```
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<bool> &artipoint, int &count)
{
    visited[node] = 1;
    disc[node] = low[node] = count;
    int child = 0;

    // visiting a node
    for (int j = 0; j < adj[node].size(); j++)
    {
        int neigh = adj[node][j];
        if (neigh == parent)
            continue;
        else if (visited[neigh])
        {
            low[node] = min(low[node], disc[neigh]);
        }
        else
        {
            child++;
            count++;
            DFS(neigh, node, adj, visited, disc, low, artipoint, count);

            // Articulation point condition, wapas aate samay check kar rahe hai agar visited mil gaya hai toh
            if (disc[node] <= low[neigh] && parent != -1)
            {
                artipoint[node] = 1;
            }
            low[node] = min(low[node], low[neigh]);
        }
    }
    // root node ke child ko check kar rahe hai
    if (child > 1 && parent == -1)
    {
        artipoint[node] = 1;
    }
}

vector<int> articulationPoint(int v, vector<int> adj[])
{
    vector<bool> artipoint(v, 0);
    vector<int> disc(v);
    vector<int> low(v);
    vector<bool> visited(v, 0);
    int count = 0; // timer
    DFS(0, -1, adj, visited, disc, low, artipoint, count);

    vector<int> ans;
    // Counting ki artipoint mai kaha kha 1 hai :-
    for (int i = 0; i < v; i++)
        if (artipoint[i])
            ans.push_back(i);

    // Agar ek bhi ArtiPoint nahi hai then
    if (ans.size() == 0)
        ans.push_back(-1);

    return ans;
}

int main()
{
    int v = 5;
    vector<int> adj[5];

    // Example graph edges
    adj[0] = {1, 2, 3};
    adj[1] = {0, 2};
    adj[2] = {0, 1};
    adj[3] = {0, 4};
    adj[4] = {3};

    vector<int> result = articulationPoint(v, adj);

    cout << "Articulation Points are: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

Bridge wale logic ko direct yaha apply kar sakte hai, so jo node bridge form kar rahe hai, wo node hamare articulation point ho jayenge. 
So hamne Is approch ko try kiya tha, hamko laga ki sayad answer sahi aayega, why wrong?
So is process mai hamne bridge edges dhoonda aur hamne , elemination process start kiya jisme jo ek node se connected hoga wo artipoint nahi ho sakta. It's fial in the example where able to understand the ki jaha bridge present nahi hai lakin articulation point present hai. When there is two cycle graph connected with same node means ek node dono cycle ka part ho, dono side cycle form ho rahi ho in that case. 

Note :- Agar koi node single cycle ka part nahi then wo articulation point articulation point hoga, ye bhi wrong hai? So ye bhi purra sahi nahi hai. point ho bhi sakta hai aur nahi bhi. So the conclusion is that ki isme cycle wala logic used nhi karna hai. So there may be different cycle present in a graph then it is possible that ki articulation point  n ho.  