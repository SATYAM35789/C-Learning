#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool divide(vector<int> arr)
{
    int prefixSum = 0, totalSum = 0, n = arr.size();
    // Total Sum
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        prefixSum += arr[i];
        int ans = totalSum - prefixSum; // RightSubarray ka sum
        if (ans == totalSum)
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter the size of an array :";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the element in the array :";
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << divide(v);
}