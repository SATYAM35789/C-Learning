#include <iostream>
#include <vector>
using namespace std;

bool check(int num, vector<vector<char>> &board, int i, int j)
{
    // changing num to char
    char c = '0' + num;

    // Check at same row
    for (int col = 0; col < 9; col++)
    {
        if (board[i][col] == c)
            return 0;
    }
    //  Check at same col
    for (int row = 0; row < 9; row++)
    {
        if (board[row][j] == c)
            return 0;
    }
    // chack at same block or box
    int row = i / 3 * 3, col = j / 3 * 3;

    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
        {
            if (board[a + row][b + col] == c)
                return 0;
        }

    return 1;
}

bool find(int i, int j, vector<vector<char>> &board)
{
    // baseCondition
    if (i == 9)
        return 1;

    if (j == 9)
        return find(i + 1, 0, board);

    if (board[i][j] != '.') // . means empty so empty nahi hai then aage bad jao
        return find(i, j + 1, board);

    // if dot found then waha par 9 option ho sakte hai
    for (int num = 1; num <= 9; num++)
    {
        if (check(num, board, i, j))
        {
            board[i][j] = '0' + num;
            if (find(i, j + 1, board))
                return 1;

            board[i][j] = '.';
        }
    }

    // Jab  koi bhi num assign nahi kar pa rahe hai then return 0 kardo.
    return 0;
}
void solveSudoku(vector<vector<char>> &board)
{
    find(0, 0, board);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    // Printing the result
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < 8)
                cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < 8)
            cout << "----------------------" << endl;
    }

    return 0;
}