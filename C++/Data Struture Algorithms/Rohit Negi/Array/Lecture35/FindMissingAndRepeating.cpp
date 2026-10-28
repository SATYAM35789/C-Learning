#include <iostream>
#include <vector>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n)
{
    //  Array ki value ko decrese karo by one
    for (int i = 0; i < n; i++)
        arr[i]--;

    // Occarance
    for (int i = 0; i < n; i++)
    {
        // Original no niklo and waha N ko add kardo
        arr[arr[i] % n] += n;
    }

    // Returning ans : Missing and Repwating number
    vector<int> ans(2);

    for (int i = 0; i < n; i++)
    {
        // repeating
        if (arr[i] / n == 2)
            ans[0] = i + 1;
        else if (arr[i] / n == 0) // Missing No
            ans[1] = i + 1;
    }
    return ans;
}