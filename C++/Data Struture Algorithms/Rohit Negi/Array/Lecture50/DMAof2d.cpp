#include <iostream>
using namespace std;

int main()
{
    // Array create karna hai, jo store karega ek address ko
    int n, m; // n=rows and m=col
    cin >> n >> m;

    int **ptr = new int *[n];
    // creating 1d array and unki address ko is array mai store karna hai
    for (int i = 0; i < n; i++)
    {
        ptr[i] = new int[m];
    }

    // Inserting value in the 2d array we created
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ptr[i][j];

    //  Print the inserted value
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ptr[i][j] << " ";
        cout << endl;
    }

    // Release the memory , heap main
    for (int i = 0; i < n; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
}