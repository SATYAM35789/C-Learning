#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//  -1 show that ki unke bich mai edge exist nahi karti
void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size(); // vertex kitna hone wala hai uska infomation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;

    //  Floyd Waeshall Algorithum
    for (int k = 0; k < n; k++) // selecting the intermediate node one bby one
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                // Edge case :- matrix[i][k] / matrix[k][j])  inme me se koi bhi INT_MAX hua toh usko ignore kardo
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;

                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }

    // So uppar jaha -1 present tha usko INT_max banaya tha, So ab koi abhi INT_MAX hai toh usko wapas -1 ke form he return karna hai
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == INT_MAX)
                matrix[i][j] = -1;
}
