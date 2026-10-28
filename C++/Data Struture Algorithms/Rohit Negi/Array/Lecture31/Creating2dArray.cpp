#include <iostream>
using namespace std;

void printCol(int arr[][3], int row, int col) // arr[][4]: need to mention the col size
{
    // Column Wise
    for (int j = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            cout << arr[i][j] << " ";
}

int main()
{
    // Creating 2D array
    // int arr[4][3];

    //  Initializing the 2d array
    int arr[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    //  Printing the all value in the array(default : rowWise)
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 3; j++)
            cout << arr[i][j];
    }

    // Print all the value in array colWise, function call
    printCol(arr, 4, 3);

    // Find element in the array
    int x = 7;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 3; j++)
            if (arr[i][j] == x)
            {
                cout << "Yes";
                return 0;
            }
    }
    cout << "No";
}