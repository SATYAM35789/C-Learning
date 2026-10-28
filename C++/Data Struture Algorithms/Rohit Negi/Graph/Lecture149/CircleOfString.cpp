#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}

int isCircle(int n, vector<string> A)
{
    // Edges create karna
    // Adjecency list
    vector<int> adj[26]; // 26 : small letter ke string hai and a=0,b=1,... z=25. So itne he combination ban sakte hai.
    vector<int> InDeg(26, 0);
    vector<int> OutDeg(26, 0);
    for (int i = 0; i < n; i++)
    {
        string temp = A[i];
        int u = temp[0] - 'a';               // temp ke first charcter  store kar rahe hai ,
        int v = temp[temp.size() - 1] - 'a'; // last string char ko stored kar rahe hai
        adj[temp[u]].push_back(v);

        // Find Indegree and OutDegree
        OutDeg[u]++;
        InDeg[v]++;
    }

    // Eluerian Ckr exist or not
    // Find Indegree and OutDegree

    for (int i = 0; i < 26; i++)
    {
        if (InDeg[i] != OutDeg[i])
            return 0; // Not Eluerian ckt
    }

    //  ALL the edges are part of one component
    vector<bool> visited(26, 0);
    int node = A[0][0] - 'a';
    DFS(node, adj, visited); // A[0][0] :- A[0] means iske first string A[0][0] A ka first string, and string first character

    // Indegree exist but not visited
    for (int i = 0; i < 26; i++)
    {
        if (InDeg[i] && !visited[i]) // InDeg or OutDeg kuchh bhi le sakte hai
            return 0;
    }

    return 1;
}

int main() {
    vector<string> A = {"abc", "bcd", "cda"};
    if (isCircle(3, A))
        cout << "Yes, it forms a circle!" << endl;
    else
        cout << "No circle possible." << endl;
    return 0;
}