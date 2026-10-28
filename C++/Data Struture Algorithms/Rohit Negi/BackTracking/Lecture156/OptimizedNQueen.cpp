#include <iostream>
#include <vector>
using namespace std;

void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column, vector<bool> &LeftDia, vector<bool> &RightDia)
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
        if (column[j] == 0 && LeftDia[n - 1 + j - row] == 0 && RightDia[row + j] == 0) //  diagonal same hai ki nahi
        {
            column[j] = 1;
            Board[row][j] = 'Q';
            LeftDia[n - 1 + j - row] = 1;
            RightDia[row + j] = 1;
            find(row + 1, n, ans, Board, column, LeftDia, RightDia);
            // Agar next row mai, queen ko nahi rakh pa rahe then , apni purani quenn ke postion ko phir se set karna hoga so
            column[j] = 0;
            Board[row][j] = '.';
            LeftDia[n - 1 + j - row] = 0;
            RightDia[row + j] = 0;
        }
    }
}

vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> Board(n);
    vector<bool> LeftDia(2 * n - 1, 0);
    vector<bool> RightDia(2 * n - 1, 0);
    // Itially board dot se  filled hoga
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Board[i].push_back('.');

    vector<bool> column(n, 0);

    find(0, n, ans, Board, column, LeftDia, RightDia);

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