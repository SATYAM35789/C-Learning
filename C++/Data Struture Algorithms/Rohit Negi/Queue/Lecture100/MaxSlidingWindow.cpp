#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n - k; i++)
    {
        int total = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            total = max(total, nums[j]);
        }
        ans.push_back(total);
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}