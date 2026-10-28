#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minBitKFlips(vector<int> &nums, int k)
{

    queue<int> q;
    int flip = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (!q.empty() && q.front() < i)
            q.pop();

        // flip condition
        if (q.size() % 2 == nums[i])
        {
            if (i + k - 1 > n)
                return -1;

            q.push(i + k - 1);
            flip++;
        }
    }
    return flip;
}
int main()
{
    vector<int> nums1 = {0, 1, 0};
    int k1 = 1;
    cout << "Test 1: " << minBitKFlips(nums1, k1) << " (Expected: 2)" << endl;

    vector<int> nums2 = {1, 1, 0};
    int k2 = 2;
    cout << "Test 2: " << minBitKFlips(nums2, k2) << " (Expected: -1)" << endl;

    vector<int> nums3 = {0, 0, 0, 1, 0, 1, 1, 0};
    int k3 = 3;
    cout << "Test 3: " << minBitKFlips(nums3, k3) << " (Expected: 3)" << endl;

    return 0;
}