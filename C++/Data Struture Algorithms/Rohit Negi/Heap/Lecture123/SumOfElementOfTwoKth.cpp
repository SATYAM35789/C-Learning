#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long sumBetweenTwoKth(long long A[], long long N, long long k1, long long k2)
{
    // Max Heap
    priority_queue<long long> p1;
    priority_queue<long long> p2;

    // Insert k1 element into p1
    for (long long i = 0; i < k1; i++)
        p1.push(A[i]);
    // Insert k2-1 element into p1
    for (long long i = 0; i < k2 - 1; i++)
        p2.push(A[i]);

    // finding the k1 smallest element
    for (long long i = k1; i < N; i++)
    {
        if (A[i] < p1.top())
        {
            p1.pop();
            p1.push(A[i]);
        }
    }

    // finding the k2-1 smallest element
    for (long long i = k2 - 1; i < N; i++)
    {
        if (A[i] < p2.top())
        {
            p2.pop();
            p2.push(A[i]);
        }
    }
    // Sum of first max heap
    long long sum1 = 0, sum2 = 0;
    while (!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }
    // Sum of second max heap
    while (!p2.empty())
    {
        sum1 += p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}

int main()
{
    long long A[] = {23, 21, 35, 67, 8, 99, 55};
    long long n = sizeof(A) / sizeof(A[0]);
    long long k1;
    cout << "Enter the value of k1";
    cin >> k1;
    long long k2;
    cout << "Enter the value of k2";
    cin >> k2;
    cout << "Sum of element between two k1 and k2 " << sumBetweenTwoKth(A, n, k1, k2);

    return 0;
}