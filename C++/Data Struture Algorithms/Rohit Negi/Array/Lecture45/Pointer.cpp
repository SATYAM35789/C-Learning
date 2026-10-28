#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    // Printing the address of a
    cout << &a;

    int *ptr = &a;
    cout << ptr << endl;

    float m = 2.6;
    float *ptr1 = &m;
    cout << ptr1 << endl;

    // Jis type ka variable us type ka pointer variable banayenge, so agar ham chahte hai ki hamara pointer point kare variable
    // then uska datatype same hona chahiye

    //  Size of ptr pointer
    cout << sizeof(ptr) << endl;
    cout << sizeof(ptr1) << endl;
}
