#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int col[8] = {1, -1, 1, -1, 2, 2, -2, -2};

bool valid(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

int minStepToReachTarget(vector<int> &knightPos, vector<int> &TargetPos, int N)
{

    // Questtion mai 1 based indexing hai, so
    knightPos[0]--;
    knightPos[1]--;
    TargetPos[0]--;
    TargetPos[1]--;

    // Agar source node he target node ho toh
    if (TargetPos[0] == knightPos[0] && TargetPos[1] == knightPos[1])
        return 0;

    queue<pair<int, int>> q;
    // Chessboard
    vector<vector<bool>> chess(N, vector<bool>(N, 0));
    q.push({knightPos[0], knightPos[1]}); // Jaha hai uski position
    chess[knightPos[0]][knightPos[1]] = 1;

    int step = 0;

    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 8; k++)
            {
                int New_i = i + row[k];
                int New_j = j + col[k];

                if (valid(New_i, New_j, N) && !chess[New_i][New_j])
                {
                    if (New_i == TargetPos[0] && New_j == TargetPos[1])
                        return step + 1;
                    chess[New_i][New_j] = 1;
                    q.push({New_i, New_j});
                }
            }
        }
        step++;
    }
    return -1; // answer not found
}

int main()
{
    int N = 30;
    vector<int> knightPos = {1, 1};
    vector<int> targetPos = {30, 30};

    cout << "Minimum steps: " << minStepToReachTarget(knightPos, targetPos, N) << endl;
    return 0;
}