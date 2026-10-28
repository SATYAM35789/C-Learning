#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int N, int P, vector<vector<int>> &prerequisites)
{
    // Adjecency list create karna
    vector<int> adj[N];
    vector<int> inDeg(N, 0);

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]); // {1,0} :- 0->1   where adj[prerequisites[i].second] =0   and push_back(prerequisites[i].first) :- ->1
        inDeg[prerequisites[i][0]]++;
    }

    // Kahn's Algorithum :-

    // 2. Queue
    queue<int> q;
    for (int i = 0; i < N; i++)
        if (inDeg[i] == 0)
            q.push(i);

    // Storing the order
    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // uske neighbour ko ek ek se kam kardo
        for (int j = 0; j < adj[node].size(); j++)
        {
            inDeg[adj[node][j]]--;
            if (!inDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    vector<int> temp;
    return ans.size() == N ? ans : temp;
}

int main()
{
    int N = 4;
    int P = 4;

    // Test Case: 1->0, 2->0, 3->1, 3->2
    // Expected Order: 0 1 2 3 OR 0 2 1 3
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> order = findOrder(N, P, prerequisites);

    if (order.empty())
    {
        cout << "No valid order possible (Cycle detected)!" << endl;
    }
    else
    {
        cout << "Valid Course Order: ";
        for (int course : order)
        {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}