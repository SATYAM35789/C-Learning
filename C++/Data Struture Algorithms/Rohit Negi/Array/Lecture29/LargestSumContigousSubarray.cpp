#include <iostream>
#include <climits>
using namespace std;

long long maxSubarray(int arr[], int n)
{
    long long maxi = INT_MIN, prefixSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        maxi = max(prefixSum, maxi);
        if (prefixSum < 0)
            prefixSum = 0;
    }
    return maxi;
}