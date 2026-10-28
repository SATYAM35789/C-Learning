#include <iostream>
#include <vector>
using namespace std;

// Brute Force approch
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}
int main()
{
    // Input array
    vector<long long> arr = {6, 8, 0, 1, 3};
    int n = arr.size();

    cout << "Array: ";
    for (long long x : arr)
        cout << x << " ";
    cout << endl;

    //  Function call
    vector<long long> result = nextLargerElement(arr, n);

    cout << "Next Greater Elements: ";
    for (long long x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}