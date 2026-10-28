#include <iostream>
#include <vector>
using namespace std;

bool checkBip(int node, vector<int> adj[], vector<int> &color)
{
    // look at each neighbour
    for (int j = 0; j < adj[node].size(); j++)
    {
        // Color is not assigned to the neighnour
        if (color[adj[node][j]] == -1)
        {
            color[adj[node][j]] = (color[node] + 1) % 2;
            if (!checkBip(adj[node][j], adj, color)) // agar 1 return karega tabhi next node ko dekhenge nahi toh return back karte jao
                return 0;
        }

        // Color already assigned hai
        else
        {
            // Color same neighbour ka
            if (color[node] == color[adj[node][j]])
                return 0;

            // agar color same nahi then wo part toh visited waha jane ki zarurat nahi hai
        }
    } // agar for loop return 0 nahi karta hai, then ye bipartite hai
    return 1;
}

bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (checkBip(i, adj, color) == 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    // Test Case 1: Bipartite Graph (0-1, 1-2, 2-3, 3-0) -> Even Cycle
    int v1 = 4;
    vector<int> adj1[v1];
    adj1[0] = {1, 3};
    adj1[1] = {0, 2};
    adj1[2] = {1, 3};
    adj1[3] = {0, 2};

    if(isBipartite(v1, adj1))
        cout << "Graph 1 is Bipartite." << endl;
    else
        cout << "Graph 1 is NOT Bipartite." << endl;

    // Test Case 2: Non-Bipartite Graph (Triangle: 0-1, 1-2, 2-0) -> Odd Cycle
    int v2 = 3;
    vector<int> adj2[v2];
    adj2[0] = {1, 2};
    adj2[1] = {0, 2};
    adj2[2] = {0, 1};

    if(isBipartite(v2, adj2))
        cout << "Graph 2 is Bipartite." << endl;
    else
        cout << "Graph 2 is NOT Bipartite." << endl;

    return 0;
}