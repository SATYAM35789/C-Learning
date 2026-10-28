#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(int vertex, vector<int> adj[], vector<bool> &visited)
{
    queue<pair<int, int>> q;
    visited[vertex] = 1;
    q.push(make_pair(vertex, -1)); // vertex: node , -1 : parent

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (parent == adj[node][j])
                continue;
            if (visited[adj[node][j]] == 1)
                return 1;

            // Agar neighbour node visited nahi hai
            visited[adj[node][j]] = 1;
            q.push(make_pair(adj[node][j], node));
        }
    }
    return 0;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool> visited(v, 0);

    // Loop lagana zaroori hai taaki saare components cover ho sakein
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (BFS(i, adj, visited) == 1) // return 1 aata hai then cycle detected, aur yaha se 1 ko return kar denge.
                return 1;
        }
    }
    return 0;
}

int main()
{
    int v = 5;
    vector<int> adj[v];

    // Graph with a cycle (0-1-2-0)
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1};

    if (isCycle(v, adj))
    {
        cout << "Cycle detected in the graph!" << endl;
    }
    else
    {
        cout << "No cycle found." << endl;
    }

    return 0;
}