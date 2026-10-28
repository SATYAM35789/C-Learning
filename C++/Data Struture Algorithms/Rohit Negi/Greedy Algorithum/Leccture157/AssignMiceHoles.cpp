#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int assignMiceHoles(int n, int M[], int H[])
{
    sort(M, M + n);
    sort(H, H + n);

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, abs(M[i] - H[i]));
    }

    return;
}

int main()
{
    int M[] = {4, -4, 2};
    int H[] = {4, 0, 5};
    int n = sizeof(M) / sizeof(M[0]);

    cout << "Minimum time to assign all mice: " << assignMiceHoles(n, M, H) << endl;

    return 0;
}