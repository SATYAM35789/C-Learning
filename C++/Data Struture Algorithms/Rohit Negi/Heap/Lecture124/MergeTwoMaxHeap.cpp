#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Heapify(vector<int> &arr, int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
        ans.push_back(a[i]);

    for (int i = 0; i < m; i++)
        ans.push_back(b[i]);

    // convert the vector into max Heap
    n = ans.size();
    for (int i = n / 2 - 1; i >= 0; i++)
        Heapify(ans, i, n);

    return ans;
}

int main()
{
    vector<int> a = {2, 4, 6, 8, 10};
    vector<int> b = {2, 4, 6, 8, 10};
    int n = a.size();
    int m = b.size();

    vector<int> result = mergeHeaps(a, b, n, m);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}