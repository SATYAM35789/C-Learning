#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, vector<int> &color, bool graph[101][101], int m, int n)
{
    //  Try Each Color one by one
    for (int i = 0; i < m; i++)
    {
        // No Adjecent node should have these color
        bool IsPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] == 1 && color[j] == i)
            {
                IsPossible = 0;
                break;
            }
        }

        if (IsPossible == 0)
            continue; // Ab color ko chod kar next color try karo

        color[node] = i; // Assign color to node if IsPossible is 1

        //  Go to the adjecent node, whom color is not assigned
        IsPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] == 1 && color[j] == -1) // Agar adjecnt exist karta hai aur usko color nahi mila hai then
            {
                if (!DFS(j, color, graph, m, n)) // If color not assined to neighbour, then go for next color
                {
                    IsPossible = 0;
                    break;
                }
            }
        }

        //  Agar kisi bhi neighbour ko color assign nahi hua then isPossible 0 hoga aur hamko parent ko color change karna hoga
        if (IsPossible == 1)
            return 1;

        // If not colored then ab apne parent ke pass jao uske dusre color assign karo
        color[node] = -1;
    }

    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1 && !DFS(i, color, graph, m, n))
            return 0;

        return 1;
    }
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