#include <iostream>
#include <vector>
using namespace std;

// Adjacency matrics
// directed- weighted graph

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    // Creating matrix
    vector<vector<int>> AdjMatrices(vertex, vector<int>(vertex, 0)); // (vertex,vector<bool>(vertex,0)) :- vertex: size or row , vector<bool>(vertex,0) : col ka size vertex ke barabar aur intialize them with 0.

    int u, v, weight;
    // Ab hamko ek ek karke batao
    for (int i = 0; i < edges; i++)
    {
        // User batayega ki kaha se kaha ke liye edges given hai hamko
        cin >> u >> v >> weight; // u : start, v : end
        AdjMatrices[u][v] = weight;
    }

    // Printing the matrics
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout << AdjMatrices[i][j] << " ";
    }
}