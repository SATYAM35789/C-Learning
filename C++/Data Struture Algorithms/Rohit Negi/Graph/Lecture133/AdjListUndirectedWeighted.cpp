#include <iostream>
#include <vector>
using namespace std;

// Undirected weighted graph
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<pair<int, int>> Adjlist[vertex];

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        Adjlist[u].push_back(make_pair(v, weight));
        Adjlist[v].push_back(make_pair(u, weight));
    }

    // Print the list :-
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " ->";
        for (int j = 0; j < Adjlist[1].size(); j++)
            cout << Adjlist[i][j].first << " " << Adjlist[i][j].second << " ";

        cout << endl;
    }
}
