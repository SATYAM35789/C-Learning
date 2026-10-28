#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int start, int end, int x)
{
    // Base case
    if (start > end)
        return 0;

    int mid = start + (end - start) / 2;
    if (arr[mid] == x)
        return 1;
    else if (arr[mid] < x)
        return BinarySearch(arr, mid + 1, end, x);
    else
        return BinarySearch(arr, start, mid - 1, x);
}

int main()
{
    int arr[] = {22, 32, 34, 56, 78, 88};
    int x = 56;
    cout << BinarySearch(arr, 0, 5, x);
}