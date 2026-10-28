#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topSort(int v, vector<int> adj[])
{
    vector<int> ans;
    vector<int> indegree(v, 0); // Store the indegree of every node

    // Step 1: Indegree calculate karo
    for (int i = 0; i < v; i++)
        for (int j = 0; j < adj[i].size(); j++)
            indegree[adj[i][j]]++;

    // Step 2: Queue mein woh nodes push karo jinpar koi dependency nahi hai (indegree 0)
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (indegree[i] == 0)
            q.push(i);

    // Step 3: BFS process
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // node ke neighbour mai jis bhi node par edge ja rahi usko ek kam kardo
        for (int j = 0; j < adj[node].size(); j++)
        {
            indegree[adj[node][j]]--;
            if (indegree[adj[node][j]] == 0)
                q.push(adj[node][j]);
        }
    }
    return ans;
}

int main()
{
    int v = 6;
    vector<int> adj[v];

    // Example DAG: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> result = topSort(v, adj);

    cout << "Topological Sort Order: ";
    for (int node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}