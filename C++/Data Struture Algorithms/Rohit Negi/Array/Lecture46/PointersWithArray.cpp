#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    // Print the address of first element or oth index
    cout << arr << endl;     // 1st method
    cout << arr + 0 << endl; // 2nd method
    cout << &arr[0] << endl; // 3rd method

    int *ptr = arr;
    cout << ptr << endl; // 4th method

    // Print the address of 2nd element or 1st index
    cout << arr + 1 << endl;
    cout << &arr[1] << endl;

    // Print the value of 0th index
    cout << arr[0] << endl;
    cout << *arr << endl;
    cout << *(arr + 0) << endl;
    cout << *ptr << endl;

    // Printing the all address of the array
    for (int i = 0; i < 5; i++)
        cout << arr + i << endl;

    // Saare value ko print kara do
    for (int i = 0; i < 5; i++)
        cout << *(arr + i) << endl;

    // Arithmatic Operation ptr++; ptr--, ptr = ptr+1

    int *ptr1 = arr;
    //     // Printing all the value with the help of pointer
    // for(int i=0;i<5;i++)
    // {
    //     cout<<*ptr1<<" ";
    //     ptr++;
    // }

    // Addition with pointer
    ptr1 = ptr1 + 3;
    cout << *ptr1;

    // Substraction
    ptr1 = ptr1 - 2;
    cout << *ptr1 << endl;
}