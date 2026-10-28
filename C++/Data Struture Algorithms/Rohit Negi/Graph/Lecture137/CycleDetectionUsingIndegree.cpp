#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclic(int v, vector<int> adj[])
{
    vector<int> Indegree(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            Indegree[adj[i][j]]++;
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (Indegree[i] == 0)
            q.push(i);

    vector<int> ans;

    while (q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            Indegree[adj[node][j]]--;
            if (Indegree[adj[node][j]] == 0)
                q.push(adj[node][j]);
        }
    }
    int count = ans.size();

    return count != v; // Agar count barabar nahi hai v ke tab 1 return katdo
}

int main()
{
    // Test Case 1: Graph with Cycle (0 -> 1 -> 2 -> 0)
    int v1 = 3;
    vector<int> adj1[v1];
    adj1[0] = {1};
    adj1[1] = {2};
    adj1[2] = {0};

    if (isCyclic(v1, adj1))
        cout << "Graph 1 mein Cycle hai!" << endl;
    else
        cout << "Graph 1 mein Cycle nahi hai." << endl;

    // Test Case 2: Graph without Cycle (0 -> 1 -> 2)
    int v2 = 3;
    vector<int> adj2[v2];
    adj2[0] = {1};
    adj2[1] = {2};
    // 2 se koi edge nahi hai

    if (isCyclic(v2, adj2))
        cout << "Graph 2 mein Cycle hai!" << endl;
    else
        cout << "Graph 2 mein Cycle nahi hai." << endl;

    return 0;
}