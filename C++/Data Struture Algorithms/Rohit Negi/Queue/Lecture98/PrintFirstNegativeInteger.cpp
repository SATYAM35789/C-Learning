#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long display(queue<long long> q)
{
    // First -ve int
    while (!q.empty())
    {
        if (q.front() < 0)
            return q.front();

        q.pop();
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int k)
{
    vector<long long> ans;
    queue<long long> q;

    // K-1 element ko push kardo
    for (long long int i = 0; i < k - 1; i++)
        q.push(arr[i]);

    for (long long int i = k - 1; i < N; i++)
    {
        q.push(arr[i]);
        ans.push_back(display(q));
        q.pop();
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