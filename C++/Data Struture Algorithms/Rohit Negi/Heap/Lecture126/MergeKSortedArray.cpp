#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1. Merge function: Do sorted subarrays ko merge karne ke liye
void merge(vector<int> &arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Temporary vectors banaye
    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    // Comparisons karke vapas arr mein daalo
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Jo bach gaye unhe add karo
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

// 2. MergeSort function: Recursive division
void mergeSort(vector<int> &arr, int start, int end, int portion, int k)
{
    if (portion < 2) // Agar portion 1 ho jaye toh usko return ho jao
        return;
    if (start >= end)
        return;

    int mid = start + (portion / 2) * k - 1;

    mergeSort(arr, start, mid, portion / 2, k);             // Left part sort
    mergeSort(arr, mid + 1, end, portion - portion / 2, k); // Right part sort
    merge(arr, start, mid, end);                            // Merge them
}

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    // Storing the value in the vector
    vector<int> ans;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            ans.push_back(arr[i][j]);
        }

    mergeSort(ans, 0, ans.size() - 1, k, k);
    return ans;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 5, 9},
        {2, 6, 10},
        {3, 7, 11}};

    int k = arr.size();
    vector<int> result = mergeKArrays(arr, k);

    cout << "Sorted result: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}