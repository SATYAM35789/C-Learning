#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

vector<int> smallestRange(vector<vector<int>> &nums)
{
    // min heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;

    int minimum, maximum = INT_MIN;
    // Insert first element of each roe int heap
    for (int i = 0; i < nums.size(); i++)
    {
        p.push(make_pair(nums[i][0], make_pair(i, 0)));
        maximum = max(maximum, nums[i][0]); // compairing present element with the max
    }

    minimum = p.top().first;
    vector<int> ans(2);
    ans[0] = minimum;
    ans[1] = maximum;

    pair<int, pair<int, int>> temp;
    int row, col, element;

    while (p.size() == nums.size())
    {
        temp = p.top();
        p.pop();

        element = temp.first;
        row = temp.second.first;
        col = temp.second.second;

        // next element ko daal if exist
        if (col + 1 < nums[row].size()) // ek list mai kitne col hone wale hai, no of col = nums[row].size()
        {
            col++;
            p.push(make_pair(nums[row][col], make_pair(row, col)));
            maximum = max(maximum, nums[row][col]);
            minimum = p.top().first;

            // Checking ki differnce pahle wale range difference se kam hai.
            if (maximum - minimum < ans[1] - ans[0])
            {
                ans[0] = minimum;
                ans[1] = maximum;
            }
        }
    }
    return ans;
}
int main()
{
    // Example Input: 3 sorted lists
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}};

    vector<int> result = smallestRange(nums);

    cout << "Smallest Range is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}