#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int s)
{
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);

    dist[s] = 0;
    int count = V;
    while (count--)
    {
        // Selecta a node which  is not explored yet and its distance value is minimum
        // for selecting minimum we need
        int node = -1, value = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (!Explored[i] && value > dist[i])
            {
                node = i;
                value = dist[i];
            }
        }
        Explored[node] = 1;

        // Relex the edges
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0]; // First col of 2d vertex represent the vertex.
            int weight = adj[node][j][1];    // Second col of 2d vertex represent the weight.
            // Neighbour should not be explored
            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
                dist[neighbour] = dist[node] + weight;
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

// Valid For both directed and Undirected Graph