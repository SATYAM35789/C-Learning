#include <iostream>
using namespace std;

int main()
{
    int arr[1000];
    int n;
    cout << "Enter the value n";
    cin >> n;

    cout << "Enter the element of the array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Bubble sort
    for (int i = n - 2; i >= 0; i--)
    {
        bool swapped = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == 0)
            break;
    }

    //  Print the value after bubble sort to verify that sorting is done or not
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}