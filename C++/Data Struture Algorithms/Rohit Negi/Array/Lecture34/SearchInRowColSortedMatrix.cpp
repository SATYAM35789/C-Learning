#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    int i = 0, j = m - 1; // i = row and j=col

    while (i < n && j >= 0)
    {
        if (matrix[i][j] == x)
            return 1;
        else if (matrix[i][j] < x)
            i++; // Nich aane ke liye row ++ karna hoga
        else
            j--;
    }
    return 0;
}