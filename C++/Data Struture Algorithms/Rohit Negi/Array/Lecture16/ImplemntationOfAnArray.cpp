#include <iostream>
using namespace std;

int main()
{
    // int arr[5];  // Array declaration

    // initialization in array ways
    // int arr[5] = {1, 2, 4, 5, 5};
    // int arr[5] = {1, 2};
    // int arr[5] = {0};  // initialize with Zero

    int arr[5];

    // Taking input from the user
    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    // print the value :-
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}

//  When the array is defined it is suggested that, the size of an array should not be the variable means ki
//  size ko user ke according daale, it should be constant. So good habit is that ki ham apne array ko ek specific or ek badi value se define karde
// and user uske bich ki value daale the utna ham stor kar lenge.

// Errror :- out of index :-  When want to access the index which is not in the range of assigned array size. ex arr[5], arr[6] etc ko access karna
// the above example.

// sizeof(variableName) :-  variable ka size kitna hoga.
// sizeof(arr) :- Overall array ka size kitna hoga wo print karega like int arr[5]; then 4*5 = 20.
// Finding the no, of element in the array = sizeof(arr)/sizeof(arr[0]) ,  sizeof(arr[0]) = arr ke zero index hai uska size kitna hai. 4 if int   -> 20/4 = 5
