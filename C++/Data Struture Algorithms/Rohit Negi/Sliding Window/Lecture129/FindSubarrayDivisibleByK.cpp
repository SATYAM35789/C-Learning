#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    unordered_map<int, int> m; // remainder with their count
    m[0] = 1;
    int prefixSum = 0, rem, total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        rem = prefixSum % k;

        if (rem < 0) // If remainder -ve aata hai
            rem = k + rem;

        if (m.count(rem))
        {
            total += m[rem];
            m[rem]++;
        }
        else
            m[rem] = 1;
    }

    return total;
}
int main()
{
    int n, k;

    cout << "Array ka size (n) enter karein: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Array ke elements enter karein: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Divisor (k) enter karein: ";
    cin >> k;

    int result = subarraysDivByK(nums, k);
    cout << "Total subarrays divisible by " << k << " are: " << result << endl;

    return 0;
}