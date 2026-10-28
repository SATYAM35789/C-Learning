#include <iostream>
using namespace std;

void printSumDiagonal(int arr[][3], int row, int col)
{
    int firstDia = 0;
    int secondDia = 0;

    // First diagonal sum :-
    int i = 0;
    while (i < row)
    {
        firstDia += arr[i][i];
        i++;
    }
    // Second diagonal Sum
    int j=col-1;
    i=0;
    while(j>=0)
    {
        secondDia+=arr[i][j];
        i++;
        j--;
    }
    cout<<firstDia<<" "<<secondDia<<" ";
}

int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printSumDiagonal(arr, 3, 3);
}