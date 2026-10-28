### Shortest Path in weighted Undirected Graph :- Dijkstra Algorithum
So hamko source node se destination node ke bich ka shortest path  find karke dena hai. 
So yaha ham Dijkstra's algorithm laga rahe hai so pahle Explored array jisko 0 se initialize kar denge aur dist array jisko  intmax se intilize karte the, so source node ka source node ko 0 hoga uska baad edges ko relex karte the jisme jo edges us node se neighbour kitna dur hai ye pata kar lete the phir, jo minimum dist par hota tha usko chale jate the agar wo explored nahi hota tha, phir us node ko explore karte the and so on till all are explored . 

Is procedure mai jab  destination node mil jeyega tab, So ab sawal puchhenge destination node se ki mujko shortest path ki jo value hai wo kis node ke wajah se aaya tha so on jab tak hamko Source node tak nahi pahuch jate aise karte jayenge. or Uske parent ko dekhte jao source node tak. 
So ab parent ki info ko store karwa ke rakh lenge. So ek Parent array le lenge aue sabko -1 se intialize kar lenge. Jab ham , edge ko relex kar rahe honge tab ham parent ko update kar denge.  and jab bhi hamko minimum path mile tab bhi apne parent ko update kar rahe honge. 
Jab -1 aayega tab ham ruk jeyenge aur apne ans vector ko reverse karke return kar denge. 
dest = vertex of graph let it 5
while(dest!=-1)
  path.pushback(dest)
  dest=parent[ dest]

Time Complexity :- ElogV + V
Space Complexity :- E+V

Inquestion we have 1 to n vertex so 0 based karenge. 

Code Implementation 
```
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath(int v, int m, vector<vector<int>> &edges)
{
    //  Creating adjecency list
    vector<pair<int, int>> adj[v + 1]; // 1 base graph, pair: neighbour, weight
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        // U -> V
        adj[u].push_back({v, weight});
        // V -> U
        adj[v].push_back({u, weight});
    }

    // Dijkstra Algorithum  :-
    vector<bool> Explored(v + 1, 0);
    vector<int> dist(v + 1, INT_MAX);

    vector<int> parent(v - 1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p; // pair: distance, vertex
    p.push({0, 1});
    dist[1] = 0;

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();
        if (Explored[node] == 1)
            continue;

        Explored[node] = 1;
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;
            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
                parent[neighbour] = node;
            }
        }
    }
    vector<int> path;
    // I cannot reached my destination
    if (parent[v] == -1)
    {
        path.push_back(-1);
        return path;
    }

    // I can  reached my destination
    int dest = v;
    while (dest == -1)
    {
        path.push_back(dest);
        dest = parent[dest];
    }

    // Reverse order mai answer dena hai usme first element mindist ko cover karega
    path.push_back(dist[v]);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int V = 5, E = 6;
    // {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, 2}, {2, 5, 5}, {1, 4, 1}, 
        {4, 3, 3}, {3, 2, 4}, {3, 5, 1}
    };

    vector<int> result = shortestPath(V, E, edges);

    cout << "Total Distance: " << result[0] << endl;
    cout << "Path: ";
    for(int i=1; i<result.size(); i++) cout << result[i] << " ";
    cout << endl;

    return 0;
}
```

Dijkstra's algorithum ko ham directed, undirected, cyclic and uncyclic har jagah use kar sakte hai. 
Shortest path in directed acyclic graph mai use kar sakte hai, lakin time complexity waha bad jati hai. 

Google Map :- source aur destination
So ham source aur destination dalte hai so wo dikstra algorithum , wo distance ke basis par sort aur kabhi kabhi shortest time ke basis par bhi kar deta hai. Time ke basis par wo alag alag type ke vahicle's ke average time ko calculate karke rakhe rahte hai. or ke pahle koi vehicle ko kitna time laga hai . 
Sabse  pahle region find karna so ye pahle map ko filter out karta hai, aisa thodi hota hai ki wo pure map dijkstra algo lagne lagta hai, wo region find karega waha par lagata hai. Means hamko node mil jata hai phir , weight ko introduce kar dete hai so dijkstra laga sake. 
Note:- Weight sirf distance nahi balki time ke based bhi ho sakte hai. 