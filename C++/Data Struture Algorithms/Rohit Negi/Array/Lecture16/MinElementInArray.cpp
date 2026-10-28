#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[5] = {54, 34, 55, 6, 77};
    int ans = INT_MAX;

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < ans)
            ans = arr[i];
    }
    cout << ans;
    return 0;
}