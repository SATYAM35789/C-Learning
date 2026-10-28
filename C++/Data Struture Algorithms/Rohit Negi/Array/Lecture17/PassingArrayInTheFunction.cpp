#include <iostream>
using namespace std;

void fun(int a[], int n)
{
    cout << sizeof(a) << endl;
    for (int i = 0; i <= n; i++)
        cout << a[i] << " ";
}

int main()
{
    int arr[] = {
        22,
        223,
        4,
        33,
        444,
    };
    fun(arr, 5);
    cout << sizeof(arr) << endl;
}