#include <iostream>
#include <climits>
using namespace std;

void printRowIndexMax(int arr[][4], int row, int col)
{
    int index = -1, sum = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        int total = 0;
        for (int j = 0; j < 4; j++)
            total += arr[i][j];

        if (total > sum)
        {
            sum = total;
            index = i; //  store the row
        }
    }
    cout << index;
}

int main()
{
    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    printRowIndexMax(arr1, 3, 4);
}