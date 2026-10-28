#include <iostream>
#include <vector>
using namespace std;

bool check(int n, vector<string> &Board, int i, int j)
{
    // Upper left Diagonal mai Q, present nahi ho
    int row = i, col = j;
    while (row > -1 && col > -1)
    {
        if (Board[row][col] == 'Q')
            return 0;

        row--, col--;
    }
    // Upper right Diagonal mai Q, present nahi ho
    row = i, col = j;
    while (row > -1 && col < n)
    {
        if (Board[row][col] == 'Q')
            return 0;
        row--, col++;
    }

    return 1;
}

void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column)
{
    // Base Case
    if (row == n)
    {
        ans.push_back(Board);
        return;
    }

    // Put queen at any n position
    for (int j = 0; j < n; j++)
    {
        if (column[j] == 0 && check(n, Board, row, j)) // check():- diagonal same hai ki nahi
        {
            column[j] = 1;
            Board[row][j] = 'Q';
            find(row + 1, n, ans, Board, column);
            // Agar next row mai, queen ko nahi rakh pa rahe then , apni purani quenn ke postion ko phir se set karna hoga so
            column[j] = 0;
            Board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> Board(n);
    // Itially board dot se  filled hoga
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Board[i].push_back('.');

    vector<bool> column(n, 0);

    find(0, n, ans, Board, column);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> solutions = solveNQueen(n);

    cout << "Total Solutions for " << n << "-Queen: " << solutions.size() << endl
         << endl;
    for (auto sol : solutions)
    {
        for (string row : sol)
        {
            cout << row << endl;
        }
        cout << "-----------------" << endl;
    }
    return 0;
}