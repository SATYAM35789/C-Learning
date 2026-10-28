#include <iostream>
#include <vector>
using namespace std;

// Adjacency matrics
// undirected- unweighted graph

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    // Creating matrix
    vector<vector<bool>> AdjMatrices(vertex, vector<bool>(vertex, 0)); // (vertex,vector<bool>(vertex,0)) :- vertex: size or row , vector<bool>(vertex,0) : col ka size vertex ke barabar aur intialize them with 0.

    int u, v;
    // Ab hamko ek ek karke batao
    for (int i = 0; i < edges; i++)
    {
        // User batayega ki kaha se kaha ke liye edges given hai hamko
        cin >> u >> v; // u : start, v : end
        AdjMatrices[u][v] = 1;
        AdjMatrices[v][u] = 1;
    }

    // Printing the matrics
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout << AdjMatrices[i][j] << " ";
    }
}