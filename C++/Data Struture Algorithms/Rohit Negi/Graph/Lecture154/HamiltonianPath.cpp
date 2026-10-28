#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, int &count, int N)
{
    visited[node] = 1;
    count++;

    if (count == N)
        return 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]] && DFS(adj[node][j], adj, visited, count, N))
            return 1;
    }

    // Jab sare neighbour ko visit karne ke baad bhi ans nahi mil raha hai then
    visited[node] = 0;
    count--;
    return 0;
}

bool check(int N, int M, vector<vector<int>> Edges)
{
    // Creating Adjecency List
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++)
    {
        adj[Edges[i][0] - 1].push_back(Edges[i][1] - 1);
        adj[Edges[i][1] - 1].push_back(Edges[i][0] - 1);
    }

    vector<bool> visited(N, 0);
    int count = 0; // Kitne node visited ho chuke hai graph mai

    // Hamara starting node koi bhi ho sakta hai, Sayad 0 node se ans na mile so
    for (int i = 0; i < N; i++)
    {
        if (DFS(i, adj, visited, count, N))
            return 1;
    }
    return 0;
}

int main()
{
    int N = 4, M = 4;
    // Example: 1-2, 2-3, 3-4, 2-4
    vector<vector<int>> Edges = {{1, 2}, {2, 3}, {3, 4}, {2, 4}};

    if (check(N, M, Edges))
        cout << "Hamiltonian Path exists!" << endl;
    else
        cout << "Hamiltonian Path does not exist." << endl;

    return 0;
}