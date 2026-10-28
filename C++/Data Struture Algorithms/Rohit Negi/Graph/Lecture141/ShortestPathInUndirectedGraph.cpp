#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src) // M : no of edges
{
    // adjecency list create karna
    vector<int> adj[N];

    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // Array dist
    vector<int> dist(N, -1);
    vector<bool> visited(N, 0);

    queue<int> q;
    q.push(src);
    dist[src] = 0;
    visited[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // Look at all the neighbour
        for (int j = 0; j < adj[node].size(); j++)
        {
            // Agar node visited hai toh usko chod do, kuchh nahi karna hai
            if (visited[adj[node][j]])
                continue;

            visited[adj[node][j]] = 1;
            q.push(adj[node][j]);
            dist[adj[node][j]] = dist[node] + 1;
        }
    }

    return dist;
}

int main()
{
    // N = Number of nodes, M = Number of edges
    int N = 9;
    int M = 10;

    // Edges list (u, v)
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};

    int source = 0;

    // Function call
    vector<int> distances = shortestPath(edges, N, M, source);

    // Output printing
    cout << "Node Distance from Source (" << source << ")" << endl;
    cout << "-------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i << "\t";
        if (distances[i] == -1)
            cout << "Unreachable" << endl;
        else
            cout << distances[i] << endl;
    }

    return 0;
}
