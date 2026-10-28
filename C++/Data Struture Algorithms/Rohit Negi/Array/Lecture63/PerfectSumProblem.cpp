#include <iostream>
using namespace std;

int subSet(int arr[], int index, int n, int sum)
{
    if (index == n)
        return sum == 0;

    return subSet(arr, index + 1, n, sum) + subSet(arr, index + 1, n, sum + arr[index]);
}

int main()
{
    int arr[] = {2, 5, 6, 1};
    int sum = 8;
    cout << subSet(arr, 0, 4, sum) << endl;
}