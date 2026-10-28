#include <iostream>
#include <vector>
using namespace std;

// Directed Unweighted graph
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<int> Adjlist[vertex];

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        Adjlist[u].push_back(v);
    }

    // Print the list :-
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " ->";
        for (int j = 0; j < Adjlist[1].size(); j++)
            cout << Adjlist[i][j] << " ";

        cout << endl;
    }
}
