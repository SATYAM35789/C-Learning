#include <iostream>
#include <vector>
using namespace std;

int majorityElement(int nums[], int n)
{
    int candidate, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            candidate = nums[i];
        }
        else
        {
            if (candidate == nums[i])
                count++;
            else
                count--;
        }
    }

    //  Varifing
    count = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == candidate)
            count++;

    if (count > n / 2)
        return candidate;

    else
        return -1;
}