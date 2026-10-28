#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int N, int M, int src, int desti) // n: no. of vertex , m:no of edges, s: sorce, t=destination
{
    // adjecency list create karna
    vector<int> adj[N];

    for (int i = 0; i < M; i++)
    {
        // O base karne ke -1 kar rahe hai
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
        adj[edges[i].second - 1].push_back(edges[i].first - 1);
    }
    // src aur distance ko bhi ek se kam karna hoga
    src--;
    desti--;

    // Array dist
    vector<bool> visited(N, 0);
    vector<int> parent(N, -1);

    queue<int> q;
    q.push(src);
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
            parent[adj[node][j]] = node;
        }
    }

    vector<int> path;
    while (desti != -1)
    {
        path.push_back(desti + 1); // 0 base Indexing ko phir se 1 base indexing mai change kar diye hai
        desti = parent[desti];
    }

    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    // Test Case: Ek simple graph
    // 1-2, 2-4, 1-3, 3-4, 4-5
    int N = 5, M = 5;
    vector<pair<int, int>> edges = {
        {1, 2}, {2, 4}, {1, 3}, {3, 4}, {4, 5}};

    int source = 1, destination = 5;

    vector<int> result = shortestPath(edges, N, M, source, destination);

    if (result.empty())
    {
        cout << "Rasta nahi mila!" << endl;
    }
    else
    {
        cout << "Shortest Path: ";
        for (int x : result)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}