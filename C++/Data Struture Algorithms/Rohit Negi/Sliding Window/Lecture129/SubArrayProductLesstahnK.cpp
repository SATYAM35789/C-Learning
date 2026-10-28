#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int product = 0, start = 0, end = 0, n = nums.size(), count;

    while (end < n)
    {
        product *= nums[end];

        // Product chota hona chahiye mere k se
        while (product >= k && start <= end)
        {
            product /= nums[start];
            start++;
        }
        count += 1 + (end - start);
    }
    return count;
}

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    cout << "Total subarrays: " << numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}