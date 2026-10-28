#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int spanningTree(int v, vector<vector<int>> adj[])
{
    // Priority Queue :- Min Heap
    // wt , node, parent
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> IsMst(v, 0);
    vector<int> parent(v); // Not Necessary :-  Agar Spannig Tree ko DRAW karne mai use hota hai

    int cost = 0;
    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;

        // MST ka part nahi hai,
        if (!IsMst[node])
        {
            IsMst[node] = 1;
            cost += wt;
            parent[node] = par;
            pq.pop();

            // Visiting neighbour
            for (int j = 0; j < adj[node].size(); j++)
            {
                if (!IsMst[adj[node][j][0]])
                {
                    pq.push({adj[node][j][1], {adj[node][j][0], node}}); // weight , node , parent
                }
            }
        }
    }
    return cost;
}

int main()
{
    int V = 5; // Total nodes
    vector<vector<int>> adj[V];

    // Graph edges based on {neighbor, weight}
    // Edge: 0-1 (weight 2), 0-3 (weight 6)
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});

    // Edge: 1-0 (2), 1-2 (3), 1-3 (8), 1-4 (5)
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});

    // Edge: 2-1 (3), 2-4 (7)
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});

    // Edge: 3-0 (6), 3-1 (8)
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});

    // Edge: 4-1 (5), 4-2 (7)
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    // Function call
    int totalMSTWeight = spanningTree(V, adj);

    cout << "The Minimum Spanning Tree weight is: " << totalMSTWeight << endl;

    return 0;
}

