#include <iostream>
using namespace std;

int main()
{
    //  Variable ke heap memory
    int *ptr = new int;
    *ptr = 5; // value assign : just like we assign value normal pointer
    cout << ptr << endl;

    float *ptr2 = new float;
    *ptr2 = 5.6;
    cout << ptr2 << endl;

    int n;
    cout << "Enter the size of an array :";
    cin >> n;
    int *p = new int[n];

    //  value in the array
    for (int i = 0; i < n; i++)
        p[i] = i + 1;

    //  Print the element
    for (int i = 0; i < n; i++)
        cout << p[i] << endl;

    //  Use delete key
    delete ptr;
    delete ptr2;
    delete[] p;
}