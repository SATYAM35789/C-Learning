#include <iostream>
#include <vector>
using namespace std;

bool find(int node, bool graph[101][101], int n, int m, vector<int> &color)
{
    //  Base condition :-
    if (node == n)
        return 1;

    // Color the node with M color
    for (int i = 0; i < m; i++)
    {
        // Check if adjecent nodes have not the same color
        bool IsPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && color[j] == i)
            {
                IsPossible = 0;
                break;
            }
        }

        // We can assign i color to this node
        if (IsPossible == 1)
        {
            color[node] = i;
            if (find(node + 1, graph, n, m, color)) // agar find 1 return karta hai then
                return 1;

            //  Agar find 1 nahi hai then
            color[node] = -1; // Check for another color
        }
    }
    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, -1);
    return find(0, graph, n, m, color);
}

int main()
{
    int n = 4; // Nodes
    int m = 3; // Colors available
    bool graph[101][101] = {0};

    // Example: Square graph (0-1, 1-2, 2-3, 3-0) aur diagonal (0-2)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;

    if (graphColoring(graph, m, n))
        cout << "Solution Exists: Graph can be colored with " << m << " colors." << endl;
    else
        cout << "Solution does not exist." << endl;

    return 0;
}