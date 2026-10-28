#include <iostream>
using namespace std;

bool linearSearch(int arr[], int x, int index, int n)
{
    // Base case
    if (index == n)
        return 0;

    if (arr[index] == x)
        return 1;

    return linearSearch(arr, x, index + 1, n);
}

int main()
{
    int arr[] = {2, 4, 5, 7, 43, 56};
    int x = 7;
    cout << linearSearch(arr, x, 0, 6);
}