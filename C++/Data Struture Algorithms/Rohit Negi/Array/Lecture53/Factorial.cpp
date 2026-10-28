#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;

    return n * fact(n - 1);
}

int main()
{
    //  Factorial of a number n
    int n;
    n = 5;
    if (n < 0)
    {
        cout << "Fcatorial is not possible";
        return 0;
    }
    cout << fact(n);
}