#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool valid(int i, int j, int n, int m)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int shortestDestination(int N, int M, vector<vector<int>> A, int X, int Y) // N : no. of rows, M: No of col , X and Y are the coordinates of destination
{
    if (X == 0 && Y == 0) // Jab source aur destination same hai.
        return 0;

    if (A[0][0] == 0)
        return -1; // Answer not possible

    // row , col
    queue<pair<int, int>> q;
    q.push({0, 0});

    A[0][0] = 0; // Marked it visited in same array so ki ham dobara visit n kare.
    int step = 0;

    while (!q.empty())
    {
        int count = q.size();

        while (count--)
        {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            // Up down left right
            for (int k = 0; k < 4; k++)
            {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (valid(new_i, new_j, N, M) && A[new_i][new_j]) // A[new_i][new_j] next node jaha ja rahe hai wo 1 hai ki nahi
                {
                    if (new_i == X && new_j == Y)
                        return step + 1; // Found answer

                    A[new_i][new_j] = 0;
                    q.push({new_i, new_j});
                }
            }
        }
        step++;
    }
    return -1; // ans not found.
}

int main()
{
    vector<vector<int>> A = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 1, 0}};

    int N = 4, M = 5;
    int X = 3, Y = 1; // Destination coordinates

    int steps = shortestDestination(N, M, A, X, Y);

    if (steps != -1)
        cout << "Shortest path is " << steps << " steps." << endl;
    else
        cout << "Destination not reachable." << endl;

    return 0;
}
