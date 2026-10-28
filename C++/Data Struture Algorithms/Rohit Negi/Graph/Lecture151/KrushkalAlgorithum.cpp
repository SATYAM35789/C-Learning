#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int FindParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;

    return parent[u] = FindParent(parent[u], parent); // Path Compression
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = FindParent(u, parent);
    int pv = FindParent(v, parent);

    // rank, merge kar paaye
    if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int spanningTree(int v, vector<vector<int>> adj[])
{
    vector<int> parent(v);  // ultimate parent will help us to determine set
    vector<int> rank(v, 0); // It will help us to merge the set

    // Starting mai har node ka parent wo khud hoga
    for (int i = 0; i < v; i++)
        parent[i] = i;

    // PQ
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            pq.push({adj[i][j][1], {i, adj[i][j][0]}});
        }
    }
    int cost = 0;
    int edges = 0;
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        // Check : same set or Different set
        if (FindParent(u, parent) != FindParent(v, parent))
        {
            cost += wt;
            UnionByRank(u, v, parent, rank);
            edges++;
        }
        if (edges == v - 1)
            break;
    }
    return cost;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj[V];

    // Standard Adjacency List for MST {neighbor, weight}
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    cout << "The Minimum Spanning Tree weight (Kruskal's) is: " << spanningTree(V, adj) << endl;

    return 0;
}