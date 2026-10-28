#include <iostream>
using namespace std;

int main()
{
    int L, B, H;
    cin >> L >> B >> H;

    // Creating the 3d array jaha 2d array ka address store karenge
    int ***ptr = new int **[L];

    // Creating the 2d array, and storing it int array we created
    for (int i = 0; i < L; i++)
    {
        ptr[i] = new int *[B];
        // Creating 1d array, and storing it in the 2d array
        for (int j = 0; j < B; j++)
        {
            ptr[i][j] = new int[H];
        }
    }

    // Inserting value in the 3d array
    for (int i = 0; i < L; i++)
        for (int j = 0; i < B; j++)
            for (int k = 0; i < H; k++)
                ptr[i][j][k] = i + j + k;

    // Printing value in the 3d array
    for (int i = 0; i < L; i++)
        for (int j = 0; i < B; j++)
            for (int k = 0; i < H; k++)
                cout << ptr[i][j][k] << " ";
}