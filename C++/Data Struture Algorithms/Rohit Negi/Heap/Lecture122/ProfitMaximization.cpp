#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int profitMaximization(int A, vector<int> &B)
{
    // Max Heap
    int sum = 0;
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
    {
        p.push(B[i]);
    }

    // Selling the ticket to A people
    while (A && p.empty())
    {
        sum += p.top();

        if (p.top() - 1)
            p.push(p.top() - 1);

        p.pop();
        A--;
    }
    return sum;
}

int main()
{
    vector<int> B = {2, 4, 6, 8, 10};
    int A = 5;
    cout << " Result: " << profitMaximization(A, B) << endl;

    return 0;
}