#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;

    // Look at its neighbour one by one
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (visited[adj[node][j]] == 0) // also write as if(!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited, s);
    }

    // Agar sare neighbour ko push lar diya hai toh push kardo node ko stack ander
    s.push(node);
}

vector<int> topSort(int v, vector<int> adj[])
{
    // DFS find karo
    vector<bool> visited(v, 0);
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            DFS(i, adj, visited, s);
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    int v = 6; // Number of vertices
    vector<int> adj[v];

    // DAG (Directed Acyclic Graph) build kar rahe hain
    // Edges: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    // 0 aur 1 ke koi outgoing edges nahi hain

    vector<int> result = topSort(v, adj);

    cout << "Topological Sort Order: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}