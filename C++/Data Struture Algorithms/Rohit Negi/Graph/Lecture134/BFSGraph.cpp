#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfsGraph(int v, vector<int> adj[])
{
    queue<int> q;
    q.push(0);
    vector<bool> visited(v, 0);
    visited[0] = 1;

    int node;
    vector<int> ans;

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        ans.push_back(node);

        // 0 ke bagal wale node ko dekhna hai
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (visited[adj[node][j]] == 0)
            {
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}

int main()
{
    int v = 5; // Number of vertices
    vector<int> adj[5];

    // Graph edges build kar rahe hain
    adj[0] = {1, 2, 3};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    vector<int> result = bfsGraph(v, adj);

    cout << "BFS Traversal starting from node 0: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}