#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    print(n - 1);
}

int main()
{
    // Print n to 1
    int n;
    cin >> n;

    //  Iterative approch :-
    for (int i = n; i > 0; i--)
        cout << i << endl;

    //  Recursive Approch
    print(n);
}