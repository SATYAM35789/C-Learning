#include <iostream>
using namespace std;

void printEven(int N)
{
    if (N == 2)
    {
        cout << N << endl;
        return;
    }

    printEven(N - 2);
    cout << N << endl;
}

int main()
{
    // Print even number from 1to N
    int N;
    cin >> N;
    if (N % 2 == 1)
        N--;

    printEven(N);
}