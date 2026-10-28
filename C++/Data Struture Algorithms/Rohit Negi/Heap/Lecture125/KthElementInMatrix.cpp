#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define MAX 100
using namespace std;

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(make_pair(mat[i][0], make_pair(i, 0)));
    }
    // Create Min Heap priority_queue<int , vector<int> , greater<int>>p(temp.begin(),temp.end());
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

    int ans;
    pair<int, pair<int, int>> Element;
    int i, j;

    while (k--)
    {
        Element = p.top();
        p.pop();
        ans = Element.first;       // value
        i = Element.second.first;  // row
        j = Element.second.second; // col num

        if (j + 1 < n)
            p.push(make_pair(mat[i][j + 1], make_pair(i, j + 1)));
    }

    return ans;
}

int main()
{
    int n = 4;
    int k = 8;

    // Sample matrix
    int mat[MAX][MAX] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}};

    cout << "Matrix ka " << k << "-th smallest element hai: "
         << kthSmallest(mat, n, k) << endl;

    return 0;
}