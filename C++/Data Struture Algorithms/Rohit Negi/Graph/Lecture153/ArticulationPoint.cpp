#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<bool> &artipoint, int &count)
{
    visited[node] = 1;
    disc[node] = low[node] = count;
    int child = 0;

    // visiting a node
    for (int j = 0; j < adj[node].size(); j++)
    {
        int neigh = adj[node][j];
        if (neigh == parent)
            continue;
        else if (visited[neigh])
        {
            low[node] = min(low[node], disc[neigh]);
        }
        else
        {
            child++;
            count++;
            DFS(neigh, node, adj, visited, disc, low, artipoint, count);

            // Articulation point condition, wapas aate samay check kar rahe hai agar visited mil gaya hai toh
            if (disc[node] <= low[neigh] && parent != -1)
            {
                artipoint[node] = 1;
            }
            low[node] = min(low[node], low[neigh]);
        }
    }
    // root node ke child ko check kar rahe hai
    if (child > 1 && parent == -1)
    {
        artipoint[node] = 1;
    }
}

vector<int> articulationPoint(int v, vector<int> adj[])
{
    vector<bool> artipoint(v, 0);
    vector<int> disc(v);
    vector<int> low(v);
    vector<bool> visited(v, 0);
    int count = 0; // timer
    DFS(0, -1, adj, visited, disc, low, artipoint, count);

    vector<int> ans;
    // Counting ki artipoint mai kaha kha 1 hai :-
    for (int i = 0; i < v; i++)
        if (artipoint[i])
            ans.push_back(i);

    // Agar ek bhi ArtiPoint nahi hai then
    if (ans.size() == 0)
        ans.push_back(-1);

    return ans;
}

int main()
{
    int v = 5;
    vector<int> adj[5];

    // Example graph edges
    adj[0] = {1, 2, 3};
    adj[1] = {0, 2};
    adj[2] = {0, 1};
    adj[3] = {0, 4};
    adj[4] = {3};

    vector<int> result = articulationPoint(v, adj);

    cout << "Articulation Points are: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}