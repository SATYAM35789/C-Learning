#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

void DFS(int node, vector<pair<int, int>> adj[], stack<int> &s, vector<bool> &visited)
{
    visited[node] = 1;

    // Look at its all neighbour
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j].first])
            DFS(adj[node][j].first, adj, s, visited);
    }
    // After visiting all node push it in the stack
    s.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // Adjecencey list create karna
    vector<pair<int, int>> adj[N]; // first : node , vertex : weight

    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];      // intial point of edge
        int v = edges[i][1];      // final point of edge
        int weight = edges[i][2]; // uska weight kitna hai
        adj[u].push_back(make_pair(v, weight));
    }
    // Topological sort (DFS) :- we have given that ki 0 se he find karna hai
    stack<int> s;
    vector<bool> visited(N, 0);
    DFS(0, adj, s, visited);
    // stack empty
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        // look at neighbour
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;
            dist[neighbour] = min(dist[neighbour], weight + dist[node]);
        }
    }

    // Node jaha ham reack out nahi kar paye usko -1 kardo
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }

    return dist;
}
//  Disconnected graph ke liye Topo sort nikalne ki zarurat nahi hai, kyuki sourcr connected nahi hai,return -1