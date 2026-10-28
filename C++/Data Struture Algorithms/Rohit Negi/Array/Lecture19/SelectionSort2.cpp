#include <iostream>
using namespace std;

int main()
{
    int arr[1000];
    int n;
    cout << " Enter the size of an array ";
    cin >> n;

    cout << "Enter the element in the array";
    //  Taking input from the user
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) // No. of round
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
                index = j;
        }
        swap(arr[i], arr[index]);
    }

    // Print the element to verify the answer
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}