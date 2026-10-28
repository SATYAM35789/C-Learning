#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellmon_ford(int v, vector<vector<int>> &edges, int s)
{
    vector<int> dist(v, 1e8); // 1e8 : 100000000
    // In edges every row represents :- u v w
    dist[s] = 0;
    int e = edges.size();

    // Relex all the edges, v-1 time
    for (int i = 0; i < v - 1; i++)
    {
        // Ek ans same aa raha relex ke baad 
        bool flag = 0;
        for (int j = 0; j < e; j++) // sari edges par jana hai
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] + wt == 1e8)
                continue;

            if (dist[u] + wt < dist[v])
            {
                flag =1; // ans mai change hua hai
                dist[v] = dist[u] + wt;
            }
        }
        if(!flag) // Agar ans mai change nahi hua then yahi se return ho jao. 
        return dist;
    }

    //  To detect the cycle
    for (int j = 0; j < e; j++) // sari edges par jana hai
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] + wt == 1e8)
            continue;

        if (dist[u] + wt < dist[v])
        {
            // Cycle detected : So agar koi bhi change hota hai last time chalane ke baad then
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }
    return dist;
}

int main()
{
    int V = 4;
    // Edges: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 1},
        {2, 1, -2}, // Negative edge
        {1, 3, 3}
    };

    int source = 0;
    vector<int> result = bellmon_ford(V, edges, source);

    if (result.size() == 1 && result[0] == -1)
    {
        cout << "Negative Cycle Detected!" << endl;
    }
    else
    {
        cout << "Shortest distances from source " << source << ":" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i << " : " << result[i] << endl;
        }
    }

    return 0;
}