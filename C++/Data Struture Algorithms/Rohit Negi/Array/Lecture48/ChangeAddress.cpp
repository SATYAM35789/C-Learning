// Change address of the Single Pointer, using function call
#include <iostream>
using namespace std;

void fun(int **p1)
{
    *p1 = *p1 + 1;
}

int main()
{
    int n = 10;
    int *p = &n;   // Single Pointer
    int **p2 = &p; // Double Pointer

    cout << p << "Old Address" << endl;
    fun(p2);
    cout << p << "New Address" << " ";
}

//  So ham kisi bhi pointer ka data change kar sakte for that we must have the address of the that.