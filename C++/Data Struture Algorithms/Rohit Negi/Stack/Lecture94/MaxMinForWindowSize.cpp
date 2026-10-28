#include <iostream>
#include <vector>
#include <stack>
#include <climits> 
using namespace std;

// Function to find maximmum of minimum of every window size
vector<int> maxOfMin(int arr[], int n)
{
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int num = INT_MAX;
            for (int k = j; k < j + i + 1; k++)
            {
                num = min(num, arr[k]);
            }
            ans[i] = max(ans[i], num);
        }
    }
    return ans;
}
int main()
{
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //  Function call
    vector<int> result = maxOfMin(arr, n);

    cout << "Max of Minimums for every window size:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Window size " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}