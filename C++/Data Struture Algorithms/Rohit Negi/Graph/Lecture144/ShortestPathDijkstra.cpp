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

int main()
{
    int V = 5, E = 6;
    // {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, 2}, {2, 5, 5}, {1, 4, 1}, {4, 3, 3}, {3, 2, 4}, {3, 5, 1}};

    vector<int> result = shortestPath(V, E, edges);

    cout << "Total Distance: " << result[0] << endl;
    cout << "Path: ";
    for (int i = 1; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}

//  Single source shortest path algo