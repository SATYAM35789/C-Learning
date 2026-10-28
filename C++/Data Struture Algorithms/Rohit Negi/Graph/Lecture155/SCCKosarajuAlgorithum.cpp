#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  Topological Sort
void Topological(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;

    // look ar its all neighbour
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            Topological(adj[node][j], adj, visited, s);
    }
    // After visit, push it in the stack
    s.push(node);
}

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}

int kosaraju(int v, vector<vector<int>> &adj)
{
    stack<int> s;
    vector<bool> visited(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            Topological(i, adj, visited, s);
    }

    // Reverse the edges
    vector<vector<int>> adj2(v);

    for (int i = 0; i < v; i++)
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i;
            int v = adj[i][j]; // i mai jitne bhi element hai unme edge bhej rahe hai
            adj2[v].push_back(u);
        }

    // Abhi sara visited hai, so unvisited mark karenge pahle
    for (int i = 0; i < v; i++)
        visited[i] = 0;
    // popped element from the stack
    int scc = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!visited[node])
        {
            scc++;
            DFS(node, adj2, visited);
        }
    }

    return scc;

    // Topological Sort
    //  Reverse the edges
    //  Popped the element from stack
    //   If  the popped node is not visiyed yet
    // scc++ DFS Apply
}

int main()
{
    int v = 5;
    vector<vector<int>> adj(v);

    // Building a Directed Graph
    // 0 -> 2, 2 -> 1, 1 -> 0 (Component 1)
    // 0 -> 3, 3 -> 4 (Other edges)
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    int sccCount = kosaraju(v, adj);

    cout << "Total Strongly Connected Components: " << sccCount << endl;

    return 0;
}