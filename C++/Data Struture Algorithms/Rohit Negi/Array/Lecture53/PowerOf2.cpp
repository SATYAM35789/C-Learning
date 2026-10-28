#include <iostream>
using namespace std;

int pow(int num, int n)
{
    //  Edge Case :- agar user n= 0 daalo toh
    if (n == 0)
        return 1;
    //  Base Case :- Edge case handle karne ke baad agar Base case hata de toh bhi code perfectly kaam karega
    if (n == 1)
        return 2;

    return num * pow(num, n - 1);
}

int main()
{
    //  power of n
    int n;
    n = 5;
    cout << pow(2, n);
}