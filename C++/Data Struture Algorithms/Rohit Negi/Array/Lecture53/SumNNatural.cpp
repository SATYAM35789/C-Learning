#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 1)
        return 1;

    return n + sum(n - 1);
}

int main()
{
    //  Sum of first n natural number
    int n = 6;
    cout << sum(n) << endl;
}