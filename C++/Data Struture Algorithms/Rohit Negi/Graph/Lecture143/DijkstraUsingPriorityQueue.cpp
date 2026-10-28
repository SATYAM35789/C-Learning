#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int s)
{
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, s});

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();
        if (Explored[node] == 1)
            continue;
        Explored[node] = 1;

        // Relex the edges
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0]; // First col of 2d vertex represent the vertex.
            int weight = adj[node][j][1];    // Second col of 2d vertex represent the weight.
            // Neighbour should not be explored
            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour}); // ham make pair ke throgh kar sakte ye naya tarika hai queue mai element daalne ka
            }
        }
    }

    return dist;
}

int main()
{
    int V = 4;
    // Adjacency list: adj[u] = {{v1, w1}, {v2, w2}}
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 5});
    adj[0].push_back({2, 8});
    adj[1].push_back({2, 9});
    adj[1].push_back({3, 2});
    adj[2].push_back({3, 6});

    int source = 0;
    vector<int> distances = dijkstra(V, adj, source);

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " : " << (distances[i] == INT_MAX ? -1 : distances[i]) << endl;
    }

    return 0;
}