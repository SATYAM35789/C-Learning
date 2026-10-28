#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);
    queue<int> q;

    for (int i = 0; i < v; i++) // Disconnected Node ko bhi check karna
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;

            while (q.empty())
            {
                int node = q.front();
                q.pop();

                for (int j = 0; j < adj[node].size(); j++)
                {
                    // color not assigned to them
                    if (color[adj[node][j]] == -1)
                    {
                        color[adj[node][j]] = (color[node] + 1) % 2; // (color[node]+1)%2 :- Iski help se ham neighbour mai different color daal payenge
                        q.push(adj[node][j]);
                    }
                    // Color is already assigned
                    else
                    {
                        if (color[node] == color[adj[node][j]])
                            return 0; //   not a Bipartite Graph
                    }
                }
            }
        }
    }

    return 1; // Bipartite graph hai
}

int main()
{
    // Case 1: Bipartite Graph (Square: 0-1-2-3-0)
    int v1 = 4;
    vector<int> adj1[v1];
    adj1[0] = {1, 3};
    adj1[1] = {0, 2};
    adj1[2] = {1, 3};
    adj1[3] = {0, 2};

    if (isBipartite(v1, adj1))
        cout << "Graph 1 is Bipartite." << endl;
    else
        cout << "Graph 1 is NOT Bipartite." << endl;

    // Case 2: Non-Bipartite Graph (Triangle: 0-1-2-0)
    int v2 = 3;
    vector<int> adj2[v2];
    adj2[0] = {1, 2};
    adj2[1] = {0, 2};
    adj2[2] = {0, 1};

    if (isBipartite(v2, adj2))
        cout << "Graph 2 is Bipartite." << endl;
    else
        cout << "Graph 2 is NOT Bipartite." << endl;

    return 0;
}