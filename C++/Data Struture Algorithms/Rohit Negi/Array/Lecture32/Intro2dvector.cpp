#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n, m;
    cout << "Enter the rows and cols" << endl;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 1));

    //  Taking input from the user
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    //  Print the value of the 2d vector
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}