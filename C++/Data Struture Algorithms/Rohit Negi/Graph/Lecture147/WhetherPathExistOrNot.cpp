#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Charon directions (Up, Down, Left, Right)
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

bool isValid(int r, int c, int N, int M)
{
    return (r >= 0 && r < N && c >= 0 && c < M);
}

bool isPathPossible(vector<vector<int>> &grid)
{
    int N = grid.size();
    int M = grid[0].size();

    queue<pair<int, int>> q;

    // 1. Pehle Source (1) aur Destination (2) ki position dhoondhte hain
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 1)
            { // Source mil gaya
                q.push({i, j});
                grid[i][j] = 0; // Mark visited by making it a wall
            }
        }
    }

    // 2. BFS Start
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Charon taraf check karo
        for (int i = 0; i < 4; i++)
        {
            int nr = r + rowDir[i];
            int nc = c + colDir[i];

            if (isValid(nr, nc, N, M))
            {
                // Agar Destination (2) mil gaya
                if (grid[nr][nc] == 2)
                    return true;

                // Agar Blank path (3) hai, toh wahan jao
                if (grid[nr][nc] == 3)
                {
                    grid[nr][nc] = 0; // Mark visited (make it wall)
                    q.push({nr, nc});
                }
            }
        }
    }

    return false; // Sab explore kar liya par 2 nahi mila
}

int main()
{
    // 1: Source, 2: Destination, 3: Path, 0: Wall
    vector<vector<int>> matrix = {
        {3, 3, 0, 2},
        {1, 3, 0, 3},
        {0, 3, 3, 3},
        {0, 0, 0, 0}};

    if (isPathPossible(matrix))
        cout << "Path Exists (Yes)" << endl;
    else
        cout << "Path Does Not Exist (No)" << endl;

    return 0;
}