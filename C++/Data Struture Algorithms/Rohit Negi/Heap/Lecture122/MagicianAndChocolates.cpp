#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MagiAndChocolate(int A, vector<int> &B)
{
    // Max Heap
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
    {
        p.push(B[i]);
    }
    long long MaxChoc = 0;
    while (A && !p.empty())
    {
        MaxChoc += p.top();

        if (p.top() / 2)
            p.push(p.top() / 2);

        p.pop();
        A--;
    }
    return MaxChoc;
}

int main()
{
    vector<int> B2 = {2, 4, 6, 8, 10};
    int A2 = 5;
    cout << " Result: " << MagiAndChocolate(A2, B2) << endl;

    return 0;
}