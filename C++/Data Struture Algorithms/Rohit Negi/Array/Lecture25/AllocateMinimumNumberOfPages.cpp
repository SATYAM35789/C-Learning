#include <iostream>
using namespace std;

int findPages(int arr[], int N, int M)
{
    if (M > N)
        return -1;

    int start = 0, end = 0, mid, ans;
    for (int i = 0; i < N; i++)
    {
        start = max(start, arr[i]);
        end += arr[i];
    }

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        int pages = 0, count = 1;
        for (int i = 0; i < N; i++) // Page Allocating
        {
            pages += arr[i];
            if (pages > mid)
            {
                count++;
                pages = arr[i];
            }
        }

        if (count <= M)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
}