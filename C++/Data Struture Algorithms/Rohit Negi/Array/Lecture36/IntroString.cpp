#include <iostream>
using namespace std;

int main()
{
    //  Simple string Name in the array
    // char arr[] = {'a','p','p','l','e'};
    // // cout<<arr;
    // for(int i=0;i<5;i++)
    // cout<<arr[i];

    // Definied the maximum size ki user se input n lena pade
    char arr[20];
    cin >> arr;
    cout << arr;
    // Yaha ham verify kar sakte hai ki last character null character hota as 20 letter daal ke dekh lo
    // end of string/character array

    // Verifying ki null character ke baad ke element access nahi kar sakte as
    arr[2] = '\0';
}