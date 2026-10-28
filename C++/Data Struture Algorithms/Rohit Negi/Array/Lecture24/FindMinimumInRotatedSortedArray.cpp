#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1, ans = arr[0], mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        // Left side sorted Array
        if (arr[mid] >= arr[0])
            start = mid + 1;

        //  Right Side Sorted Array
        else
        {
            ans = arr[mid];
            end = mid - 1;
        }
    }
    return ans;
}