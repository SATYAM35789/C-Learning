#include <iostream>
#include <vector>
using namespace std;

int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};
string dir = "UDLR";

bool valid(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}
void Total(vector<vector<int>> &matrix, int i, int j, int n, string &path, vector<string> &ans, vector<vector<bool>> &visited)
{
    //  Base Case :-
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[i][j] = 1;

    // up Down left right
    for (int k = 0; k < 4; k++)
    {
        if (valid(i + row[k], j + col[k], n) && matrix[i + row[k]][j + col[k]] && !visited[i + row[k]][j + col[k]])
        {
            path.push_back(dir[k]);
            Total(matrix, i + row[k], j + col[k], n, path, ans, visited);
            path.pop_back();
        }
    }
    visited[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &M, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    vector<string> ans;
    string path;

    // If initial or final block hai then
    // if (M[0][0] == 0 || M[n - 1][n - 1] = 0)
    //     return ans;

    Total(M, 0, 0, n, path, ans, visited);
}