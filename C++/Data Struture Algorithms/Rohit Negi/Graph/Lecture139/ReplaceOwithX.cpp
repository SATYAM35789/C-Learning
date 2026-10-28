#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r;
int c;

// 4 direction mai move karna hai
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < r && j < c;
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    r = n;
    c = m;

    // Apply BFS operator from border where 0 is present and replace with T

    queue<pair<int, int>> q;
    // First Row
    for (int j = 0; j < c; j++)
    {
        if (mat[0][j] == 'O')
        {
            q.push(make_pair(0, j));
            mat[0][j] = 'T';
        }
    }
    // First Col
    for (int i = 0; i < r; i++)
    {
        if (mat[i][0] == 'O')
        {
            q.push(make_pair(i, 0));
            mat[i][0] = 'T';
        }
    }
    // last row (Corner ko chhode traverse kar rahe hai)
    for (int j = 1; j < c; j++)
    {
        if (mat[r - 1][j] == 'O')
        {
            q.push(make_pair(r - 1, j));
            mat[r - 1][j] = 'T';
        }
    }
    //  last col
    for (int i = 1; i < r - 1; i++) // upper se ek aur nichhe ek ko chhod kar traverse kar rahe hai
    {
        if (mat[i][c - 1] == 'O')
        {
            q.push(make_pair(i, c - 1));
            mat[i][c - 1] = 'T';
        }
    }

    while (q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;

        q.pop();

        // 0 ke charo taraf dekh rahe hai kon kon se element present hai
        for (int k = 0; k < 4; k++)
        {
            if (valid(i + row[k], j + col[k]) && mat[i + row[k]][j + col[k]] == 'O')
            {
                mat[i + row[k]][j + col[k]] == 'T';
                q.push(make_pair(i + row[k], j + col[k]));
            }
        }
    }

    // Replace All 'O' with 'X' and all T with 'O'
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 'O')
                mat[i][j] = 'X';
            else if (mat[i][j] == 'T')
                mat[i][j] = 'O';
        }
    return mat;
}

int main()
{
    int n = 4, m = 4;
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    vector<vector<char>> result = fill(n, m, mat);

    cout << "Resulting Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}