#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> p;
    for (long long i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }

    long long cost = 0;

    while (p.size() > 1)
    {
        long long rope = p.top();
        p.pop();
        rope += p.top();
        p.pop();
        cost += rope;
        p.push(rope);
    }
    return cost;
}

int main()
{
    long long arr[] = {10, 3, 8, 9, 5, 13, 2};
    long long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum cost of " << minCost(arr, n) << endl;

    return 0;
}