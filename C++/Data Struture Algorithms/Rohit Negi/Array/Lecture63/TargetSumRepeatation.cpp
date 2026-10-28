#include <iostream>
using namespace std;

int subSum(int arr[], int index, int n, int sum)
{
    if (sum == 0)
        return 1;

    if (index == n || sum < 0)
        return 0;

    return subSum(arr, index + 1, n, sum) + subSum(arr, index, n, sum - arr[index]);
}

int main()
{
    int arr[] = {2, 3, 4};
    int sum = 6;
    cout << subSum(arr, 0, 3, sum);
}