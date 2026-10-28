#include <iostream>
using namespace std;

int heapHeight(int N, int arr[])
{
    if (N == 1)
        return 1;

    int height = 0;

    while (N > 1)
    {
        height++;
        N /= 2;
    }
    return height;
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Height of Heap: " << heapHeight(n, arr) << endl;

    return 0;
}