#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxSubarrayLength(vector<int> &nums, int k)
{
    int len = 0;
    unordered_map<int, int> count;

    int start = 0, end = 0, n = nums.size();

    while (end < n)
    {
        count[nums[end]]++;
        while (count[nums[end]] > k) // yaha nums of  end par ruke hue hai check kar rahe hai ki kya count mai nums of end wo abhi bada hai k se, jab tak bada tab tak window decrease hota jayenge
        {
            count[nums[start]]--;
            start++;
        }
        len = max(len, end - start + 1);
        end++;
    }
    return len;
}

int main()
{
    // Example: {1, 2, 3, 1, 2, 3, 1, 2}, k = 2
    // Expected output: 6 (Subarray: {1, 2, 3, 1, 2, 3} where freq <= 2)
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    cout << "Maximum length of subarray is: " << maxSubarrayLength(nums, k) << endl;

    return 0;
}
