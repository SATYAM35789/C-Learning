#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r;
int c;

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < r && j < c;
}

int numIslands(vector<vector<char>> &grid)
{
    r = grid.size();
    c = grid[0].size();

    queue<pair<int, int>> q;
    int count = 0;

    // check the character 1 in the grid
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                // Make 1 to 0 after visiting
                q.push(make_pair(i, j));
                grid[i][j] = 0;

                while (!q.empty())
                {
                    // row aur colume ko bahar nikalte hai, taki uski neighbour ko visit kar paye
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();
                    // 8 Direction: 3 uppar, 3 niche aur 2 bagal mai check karna hai 1 hai ki nahi
                    int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
                    int col[8] = {-1, 0, +1, -1, 0, +1, -1. + 1};

                    // Moving in the direction
                    for (int k = 0; k < 8; k++)
                    {
                        // Valid :- Ensure ki ham 2d array ke , to segmentation fault.
                        if (valid(new_i + row[k], new_j + col[k]) && grid[new_i + row[k]][new_j + col[k]] == '1')
                        {
                            grid[new_i + row[k]][new_j + col[k]] = '0';
                            q.push(make_pair(new_i + row[k], new_j + col[k]));
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    // Test Case: Grid with 2 Islands (8-direction logic)
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '1'}};

    int result = numIslands(grid);
    cout << "Total Number of Islands: " << result << endl;

    return 0;
}
