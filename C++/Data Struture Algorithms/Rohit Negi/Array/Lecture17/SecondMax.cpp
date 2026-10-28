#include <iostream>
#include <climits>
using namespace std;

int print2Largest(int arr[], int n)
{
    int ans = INT_MIN;
    //  largest element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans)
            ans = arr[i];
    }

    // Second Largest element
    int secondMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != ans)
        {
            secondMax = max(ans, arr[i]);
        }
    }

    // Agar secondMax update hi nahi hua (yaani koi second largest nahi mila)
    if (secondMax == INT_MIN)
        return -1;
    return secondMax;
}

int main()
{
    // Test Case 1: Normal Array
    int arr1[] = {12, 35, 1, 10, 34, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "--- Test Case 1 ---" << endl;
    cout << "Array: {12, 35, 1, 10, 34, 1}" << endl;
    cout << "Second Largest: " << print2Largest(arr1, n1) << endl; // Expected: 34
    cout << endl;

    // Test Case 2: Saare elements same ho
    int arr2[] = {10, 10, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "--- Test Case 2 ---" << endl;
    cout << "Array: {10, 10, 10}" << endl;
    cout << "Second Largest: " << print2Largest(arr2, n2) << endl; // Expected: -1
    cout << endl;

    // Test Case 3: Negative numbers ke saath
    int arr3[] = {-5, -2, -9, -1, -3};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "--- Test Case 3 ---" << endl;
    cout << "Array: {-5, -2, -9, -1, -3}" << endl;
    cout << "Second Largest: " << print2Largest(arr3, n3) << endl; // Expected: -2

    return 0;
}