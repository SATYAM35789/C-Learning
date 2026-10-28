#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool serachMatrix(vector<vector<int>> &matrix, int target)
{
    int N = matrix.size(), M = matrix[0].size();
    int row_Index, col_Index, start = 0, end = N * M - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        row_Index = mid / M;
        col_Index = mid % M;

        if (matrix[row_Index][col_Index] == target)
            return 1;

        else if (matrix[row_Index][col_Index] < target)
            start = mid + 1;

        else
            mid - 1;
    }
    return 0;
}
