#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pos = start;
    for (int i = 0; i <= end; i++)
    {
        if (arr[i] <= arr[end])
        {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
}

void quickSort(int arr[], int start, int end)
{
    //  Base Case
    if (start > end)
        return;

    int pivot = partition(arr, start, end);
    // Left side
    quickSort(arr, start, pivot - 1);
    // Right Side
    quickSort(arr, pivot + 1, end);
}

int main()
{
    int arr[] = {9, 7, 8, 6, 5, 44, 3, 2, 24, 5};
    quickSort(arr, 0, 9);

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}