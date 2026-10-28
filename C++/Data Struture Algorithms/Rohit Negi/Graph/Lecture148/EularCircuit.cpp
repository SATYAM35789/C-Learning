#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}

int isEularCircuit(int v, vector<int> adj[])
{
    // Eular Circuit :-  then return 2
    // Calculate the degree of each node
    // All node should have even degree
    // All non-zero degree should be connected

    // Eular Path :- then return 1
    // Calculate the degree of each node
    // Zero or Two node can have odd degree and remaining have even degree
    // All non-zero degree should be connected

    // Calulating degree
    vector<int> Deg(v, 0);
    int oddDeg = 0; // No. of nodes having odd degree
    for (int i = 0; i < v; i++)
    {
        Deg[i] = adj[i].size();
        if (Deg[i] % 2 == 1)
            oddDeg++;
    }
    // Edge Case
    if (oddDeg != 2 && oddDeg != 0) // 1,3,4,5,6
        return 0;                   // Not a Euler Path and Not a Euler Circuit

    // All non-zero node should be connected.
    vector<bool> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (Deg[i]) // Agar is index par degree exist karti hai then apply DFS
        {
            DFS(i, adj, visited);
            break;
        }
    }

    //  If non zero degree is still not visited then, it is not euler path or circuit.
    // Agar Degree 0, then ignore that node, unke pass edge nahi hai
    for (int i = 0; i < v; i++)
    {
        if (Deg[i] && !visited[i])
            return 0;
    }
    // Euler ckt : 2
    //  Euler Path : 1

    if (oddDeg == 0)
        return 2;

    else
        return 1;
}

int main()
{
    int V = 5;
    vector<int> adj[V];

    // Example: A simple House shape graph (Eulerian Path exists)
    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1, 4};
    adj[3] = {1, 4};
    adj[4] = {2, 3};

    int res = isEularCircuit(V, adj);
    if (res == 0)
        cout << "Neither Euler Path nor Circuit";
    else if (res == 1)
        cout << "Eulerian Path Found";
    else
        cout << "Eulerian Circuit Found";

    return 0;
}