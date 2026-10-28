#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &arr, int target)
{
    int start = 0, end = arr.size() - 1, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        // Found the element
        if (arr[mid] == target)
            return mid;
        // Left side sorted
        else if (arr[mid] >= arr[0])
        {
            // Checking ki target left side mai hai ki nahi
            if (arr[start] <= target && arr[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        // Right side Sorted
        else
        {
            if (arr[mid] < target && arr[end] > target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}