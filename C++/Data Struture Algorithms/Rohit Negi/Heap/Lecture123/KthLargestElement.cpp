#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    // Max Heap
    priority_queue<int, vector<int>, greater<int>> p;
    // Inserting k element i the min heap
    for (int i = 0; i < k; i++)
        p.push(nums[i]);

    // left element of the arr ko compaire karte hai
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > p.top())
        {
            p.pop();
            p.push(nums[i]);
        }
    }

    return p.top();
}

int main()
{
    vector<int> nums = {2, 4, 6, 8, 10};
    int k;
    cout << "Enter the value of k";
    cin >> k;

    cout << " Last Stone Weight " << findKthLargest(nums, k) << endl;

    return 0;
}