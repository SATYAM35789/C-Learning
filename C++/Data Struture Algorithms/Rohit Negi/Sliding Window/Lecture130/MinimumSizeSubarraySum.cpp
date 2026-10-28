#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int total = INT_MAX, start = 0, end = 0;
    int sum = 0, n = nums.size();

    while (end < n)
    {
        sum += nums[end];

        // Window ki length ko decrese karna
        while (sum >= target)
        {
            total = min(total, end - start + 1);
            // Removing the start value or decresing window
            sum -= nums[start];
            start++;
        }

        // window ki length ko increse karna
        end++;
    }

    return total == INT_MAX ? 0 : total;
}

int main()
{
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    int result = minSubArrayLen(target, nums);

    cout << "Minimum length of subarray with sum >= " << target << " is: " << result << endl;

    return 0;
}