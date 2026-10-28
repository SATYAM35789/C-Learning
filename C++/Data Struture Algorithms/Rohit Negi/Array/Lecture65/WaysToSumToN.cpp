#include <iostream>
using namespace std;

int countWays(int arr[], int m, int sum)
{
    //  Base Case
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;

    int ans = 0;
    for (int i = 0; i < m; i++)
        ans += countWays(arr, m, sum - arr[i]);

    return ans;
}

// Is problem ko ham dp se bhi kar rahe honge, as isme time complexity bahut jayda ja rahi hai and ans ko long long type mai store karwa