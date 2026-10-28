#include <iostream>
#include <vector>
using namespace std;

bool DetectCycle(int node, vector<int> adj[], vector<bool> &path, vector<bool> &visited)
{
    visited[node] = 1;
    path[node] = 1;

    // visiting neighbour one by one
    for (int j = 0; j < adj[node].size(); j++)
    {
        // if Already present in the path then retun means cycle detected
        if (path[adj[node][j]] == 1)
            return 1;

        else
        {
            // Agar node ke neighbour already visited hai means kisi aur path ka part rahe chuka hai so skip kardo
            if (visited[adj[node][j]] == 1)
                continue;

            // so if unvisited hai then call detectCycle and agar ye 1 deta hai then return kardo 1
            if (DetectCycle(adj[node][j], adj, path, visited) == 1)
                return 1;
        }
    }
    path[node] = 0;
    return 0; // cycle not present in graph
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool> path(v, 0);
    vector<bool> visited(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && DetectCycle(i, adj, path, visited))
            return 1;
    }

    return 0;
}

int main()
{
    int v = 4;
    vector<int> adj[v];

    // Directed Graph with a cycle: 0 -> 1 -> 2 -> 0
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0, 3}; // Cycle yahan hai 0->1->2->0

    if (isCycle(v, adj))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}