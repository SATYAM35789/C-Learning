#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> d;
    vector<int> ans;
    int n = nums.size();

    // k-1 element ko traverse karo
    for (int i = 0; i < k - 1; i++)
    {
        if (d.empty())
            d.push_back(i);
        else
        {
            while (!d.empty() && nums[i] > nums[d.back()])
                d.pop_back();

            d.push_back(i);
        }
    }
    //  k-1 se laker n-1 tak traverse karo
    for (int i = k - 1; i < n; i++)
    {
        // Remove the smaller element from the last
        while (!d.empty() && nums[i] > nums[d.back()])
            d.pop_back();

        d.push_back(i);
        // if front element is outside the window than pop it.
        if (d.front() <= i - k)
            d.pop_front();
        //  Find ans
        ans.push_back(nums[d.front()]);
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