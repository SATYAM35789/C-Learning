#include <iostream>
#include <vector>
using namespace std;

long long countSubarrays(vector<int> &nums, int k)
{
    int maxElement = 0, n = nums.size();
    for (int i = 0; i < n; i++)
        maxElement = max(maxElement, nums[i]); // max element ko store kar raha hai

    long long total = 0;
    int count = 0, start = 0, end = 0;

    while (end < n)
    {
        // increse the window length until , maxElement is equal to k
        if (nums[end] == maxElement)
            count++;
        // Agar count barabar ho gaya k ke tab tak
        while (count == k)
        {
            // window ko kam karna hai
            total += n - end;
            if (nums[start] == maxElement)
                count--;

            start++;
        }
        end++;
    }
    return total;
}
int main()
{
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;

    cout << "Count of subarrays: " << countSubarrays(nums, k) << endl;
    // Example: {1,3,2,3,3} ke liye result 3 aayega ({1,3,2,3}, {1,3,2,3,3}, {3,2,3,3})

    return 0;
}