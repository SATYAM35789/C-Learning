#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> KthLargestInStream(vector<int> &nums, int k)
{
    // Max Heap
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> p;
    // Inserting k element i the min heap
    for (int i = 0; i < k - 1; i++)
    {
        p.push(nums[i]);
        ans.push_back(-1);
    }

    // left element of the arr ko compaire karte hai
    for (int i = k - 1; i < nums.size(); i++)
    {
        if (nums[i] > p.top())
        {
            p.push(nums[i]);
            ans.push_back(nums[i]);
        }
        else
            ans.push_back(-1);
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 4, 6, 8, 10};
    int k;
    cout << "Enter the value of k";
    cin >> k;

    cout << " Kth Largest in the stream :" << endl;
    vector<int> result = KthLargestInStream(nums, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}