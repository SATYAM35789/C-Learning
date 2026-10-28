#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int start = 0, end = 1, n = arr.size();

    // Edge case :
    if (target < 0)
        target = target + -1;
    while (end < n)
    {
        // substraction equal to target
        if (arr[end] - arr[start] == target)
            return 1;

        // Substraction is lessthan target
        else if (arr[end] - arr[start] < target)
            end++;
        else
            start++;

        // Edge case
        if (start == end)
            end++;
    }
    return 0;
}