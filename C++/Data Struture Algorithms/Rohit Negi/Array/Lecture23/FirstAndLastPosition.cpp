#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1, first = -1, last = -1, mid;

    //  Find First
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            end = mid - 1; // left mai aur kahi toh target hai ki nahi
        }
        else if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    // Find Last
    start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            start = mid + 1; // mid ke Right mai aur kahi toh target hai ki nahi
        }
        else if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    // Ab Hamko vector ke form mai, start aur last , jindex kp wapas karna hai.
    vector<int> a(2); // syntex vector<datatype> name(sizeofvector)
    a[0] = first;
    a[1] = last;

    return a;
}