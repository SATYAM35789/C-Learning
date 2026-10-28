#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    // Intialize the map when no element present, then sum =0
    m[0] = 1;
    int prefixSum = 0;
    int total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        if (m.count(prefixSum) - k)
        {
            total += m[prefixSum - k]; // Agar prifix  Sum -k exist karta hai then  difference kitni baar aaya hai ysko add kardo total mai
            m[prefixSum]++;
        }
        else
            m[prefixSum]++;
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

    cout << "Target sum (k) enter karein: ";
    cin >> k;

    int result = subarraySum(nums, k);
    cout << "Total subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
