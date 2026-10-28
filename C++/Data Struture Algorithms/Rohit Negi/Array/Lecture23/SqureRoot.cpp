#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x < 2)
        return x;
    int start = 0, end = x, mid, ans;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (mid == x / mid) // equal to mid*mid==x
            return mid;

        else if (mid < x / mid) // Right side move ans mid*mid<x
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}