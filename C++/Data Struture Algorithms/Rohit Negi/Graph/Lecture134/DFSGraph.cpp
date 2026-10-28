#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (visited[adj[node][j]] == 0)
            DFS(adj[node][j], adj, visited, ans);
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]) // v = no. of vertex
{
    vector<bool> visited(v, 0);
    vector<int> ans;
    DFS(0, adj, visited, ans);

    return ans;
}

int main()
{
    int v = 5; // Total vertices (0 to 4)
    vector<int> adj[v];

    // Edges add kar rahe hain (Example Graph)
    // 0 -> 1, 0 -> 2
    // 1 -> 3
    // 2 -> 4
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // DFS call karna
    vector<int> result = dfsOfGraph(v, adj);

    // Output print karna
    cout << "DFS Traversal: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}