#include <iostream>
using namespace std;

int search(int arr[], int N, int key)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    // Test case 1: Jab element array mein maujood ho
    int arr1[] = {10, 20, 30, 40, 50};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    int key1 = 30;

    cout << "--- Test Case 1 ---" << endl;
    int result1 = search(arr1, N1, key1);
    if (result1 != -1)
    {
        cout << "Element " << key1 << " index " << result1 << " par mila." << endl;
    }
    else
    {
        cout << "Element " << key1 << " nahi mila." << endl;
    }

    cout << endl;

    // Test case 2: Jab element array mein NA ho
    int arr2[] = {5, 12, 9, 23, 77};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    int key2 = 50; // Yeh array mein nahi hai

    cout << "--- Test Case 2 ---" << endl;
    int result2 = search(arr2, N2, key2);
    if (result2 != -1)
    {
        cout << "Element " << key2 << " index " << result2 << " par mila." << endl;
    }
    else
    {
        cout << "Element " << key2 << " nahi mila (Return value: " << result2 << ")." << endl;
    }

    return 0;
}