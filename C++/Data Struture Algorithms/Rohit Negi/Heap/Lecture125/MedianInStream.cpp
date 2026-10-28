#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> RightMinHeap;
    // Function to insert heap
    void insertHeap(int &x)
    {
        // Base Case
        if (leftMaxHeap.empty())
        {
            leftMaxHeap.push(x);
            return;
        }

        if (x > leftMaxHeap.top())
            RightMinHeap.push(x);
        else
            leftMaxHeap.push(x);

        balanceHeaps(); // question ki demand hai
    }

    // Function to balance heaps
    void balanceHeaps()
    {
        // MinHeap size (right side) should not be greater than maxHeap(left Side)
        if (RightMinHeap.size() > leftMaxHeap.size())
        {
            leftMaxHeap.push(RightMinHeap.top());
            RightMinHeap.pop();
        }

        else
        {
            // Difference blw heaps should not be greater then 1
            if (RightMinHeap.size() < leftMaxHeap.size() - 1)
            {
                RightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            }
        }
    }

    // Function to return median
    double getMedian()
    {
        // left > right
        if (leftMaxHeap.size() > RightMinHeap.size())
            return leftMaxHeap.top();
        else
        {
            double ans = leftMaxHeap.top() + RightMinHeap.top();
            ans /= 2;
            return ans;
        }
    }
};

int main()
{
    // Aapki Solution class ka object banaya
    Solution sol;

    // Test cases: Data stream
    vector<int> stream = {5, 15, 1, 3, 2};

    cout << "Data Stream Processing:" << endl;
    for (int i = 0; i < stream.size(); i++)
    {
        sol.insertHeap(stream[i]);
        cout << "Inserted: " << stream[i] << " | Current Median: " << sol.getMedian() << endl;
    }

    return 0;
}
