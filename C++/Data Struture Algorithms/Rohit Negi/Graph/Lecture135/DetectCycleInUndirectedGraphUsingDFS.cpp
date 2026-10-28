#include <iostream>
#include <vector>
using namespace std;

bool cycleDetect(int node, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;

    // Current node ke neighbour ko visit karo
    for (int j = 0; j < adj[node].size(); j++)
    {
        // Ignore the parent node
        if (parent == adj[node][j])
            continue;
        // If neighbour already visited
        if (visited[adj[node][j]] == 1)
            return 1; // Cycle mil chuka hai

        // Agar neighbour visited nahi hai than
        if (cycleDetect(adj[node][j], node, adj, visited) == 1)
            return 1;
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
            if (cycleDetect(i, -1, adj, visited) == 1) // return 1 aata hai then cycle detected, aur yaha se 1 ko return kar denge.
                return 1;
        }
    }
    return 0; // Pura visit karne ke baad loop n mile.
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