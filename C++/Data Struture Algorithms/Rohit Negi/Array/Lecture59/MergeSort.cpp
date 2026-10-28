#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int left = start, right = mid + 1, index = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++, left++;
        }
        else
        {
            temp[index] = arr[right];
            right++, index++;
        }
    }
    // Left array is not empty yet
    while (left <= mid)
    {
        temp[index] = arr[right];
        index++, left++;
    }
    // Right array is not empty yet
    while (right <= end)
    {
        temp[index] = arr[right];
        right++, index++;
    }

    // Copy the temp in the original array
    index = 0;
    while (start <= end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    // Base Case
    if (start == end)
        return;

    int mid = start + (end - start) / 2;
    // left side
    mergeSort(arr, start, mid);
    // right side
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {6, 3, 7, 5, 8, 19, 4, 3, 56, 7};
    mergeSort(arr, 0, 9);

    // Printing the Sorted Array
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}