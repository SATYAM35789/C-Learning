#include <iostream>
using namespace std;

void fun(int *p)
{
    *p = *p + 10;
}

int main()
{
    int n = 10;
    int *p = &n;   // Single Pointer
    int **p2 = &p; // Double Pointer

    fun(p);
    cout << n << " ";
}