#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int *p = &n; // Single Pointer
    cout << p << endl;
    int **p2 = &p; // Double Pointer
    cout << p2 << endl;
    int ***p3 = &p2; // Triplet pointer
    cout << p3 << endl;

    // Modifying the value jo n mai rakhi hai
    *p = *p + 5; // 15 using single pointer
    cout << n << endl;

    **p2 = **p2 + 5; // 20 using double pointer
    cout << n << endl;

    **p3 = **p3 + 5; // 25 using triple pointer
    cout << p3 << endl;

    // So ham kisi bhi pointer ke help se apne value ko modify kar sakte hai
}