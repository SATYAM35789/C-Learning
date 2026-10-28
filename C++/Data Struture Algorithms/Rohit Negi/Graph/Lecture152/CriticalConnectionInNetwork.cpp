#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, int parent, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &Bridges, int &count)
{
    disc[node] = low[node] = count;
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        int neigh = adj[node][j];
        if (neigh == parent)
            continue;

        else if (visited[neigh])
        {
            low[node] = min(low[node], disc[neigh]);
        }

        else // not visited
        {
            count++;
            DFS(neigh, node, adj, disc, low, visited, Bridges, count);

            //  Bride Exist
            if (low[neigh] > disc[node])
            {
                // ek 1d vector liye hai usko 2d vector bridges ke ander daala hai.
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(neigh);
                Bridges.push_back(temp);
            }
            low[node] = min(low[node], low[neigh]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    // Creating Adjecency list :-
    vector<vector<int>> adj(n);
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0]; // col 1 mai first node
        int v = connections[i][1]; // col 2nd mai second node hai
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> Bridges;
    vector<int> disc(n);
    vector<int> low(n);

    vector<bool> visited(n, 0);

    int count = 0;
    DFS(0, -1, adj, disc, low, visited, Bridges, count);

    return Bridges;
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> bridges = criticalConnections(n, connections);

    cout << "Bridges in the graph:" << endl;
    for (auto it : bridges)
    {
        cout << it[0] << " -- " << it[1] << endl;
    }

    return 0;
}