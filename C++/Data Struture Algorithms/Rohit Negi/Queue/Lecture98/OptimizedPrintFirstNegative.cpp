#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int k)
{
    vector<long long> ans;
    queue<long long int> q;

    // k-1 elements ko push kar do, only -ve element ko
    for (long long int i = 0; i < k - 1; i++)
    {
        if (arr[i] < 0)
            q.push(i);
    }
    for (long long int i = k - 1; i < N; i++)
    {
        // push the negeative only
        if (arr[i] < 0)
            q.push(i);

        // Apne ans mai pahle window size ke first -ve ko push karwa rahe hai
        // Queue Empty
        if (q.empty())
            ans.push_back(0);
        // Queue mai koi value present hai
        else
        {
            // Check if first index of queue lies inside the window
            if (q.front() <= i - k)
                q.pop();

            if (q.empty())
                ans.push_back(0);
            else
                ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}

int main()
{
    long long arr[] = {-8, 2, 3, -6, 10};
    long long N = 5, k = 2;

    vector<long long> result = printFirstNegativeInteger(arr, N, k);

    for (auto x : result)
        cout << x << " ";

    return 0;
}