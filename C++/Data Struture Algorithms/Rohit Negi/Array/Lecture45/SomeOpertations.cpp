#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;
    cout << ptr << endl; // address of a
    // Ptr jisko point kar raha hai, uski value
    cout << *ptr << endl; // value inside a

    int b = 20;
    ptr = &b;
    cout << ptr << endl;
    cout << *ptr << endl;
    b = 30;
    cout << *ptr << endl;
}