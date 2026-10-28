#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subArrayWithDistict(vector<int> &nums, int k) // Atlest(k) - Atlest(k+1)
{
    int total = 0; // total no of good subarray

    unordered_map<int, int> freq;

    int start = 0, end = 0, n = nums.size(), count = 0; // count: stores the count of different integer in the window

    while (end < n)
    {
        freq[nums[end]]++; // add frequency of present no

        if (freq[nums[end]] == 1) // agar subarray mai no ek se jayda bar present hai toh us no ka count nahi cahlega
            count++;

        // Decrease the window size :-
        while (count == k)
        {
            total += n - end;
            freq[nums[start]]--;
            if (freq[nums[start]] == 0) // count kab decrese hoga
                count--;
            start++;
        }
        // increse the window size till no. of different integer k ke barabar n ho jaye
        end++;
    }

    // Atleast(k+1)
    start = 0, end = 0, count = 0;
    freq.clear();
    k++;

    while (end < n)
    {
        freq[nums[end]]++; // add frequency of present no

        if (freq[nums[end]] == 1) // agar subarray mai no ek se jayda bar present hai toh us no ka count nahi cahlega
            count++;

        // Decrease the window size :-
        while (count == k)
        {
            total -= n - end;
            freq[nums[start]]--;
            if (freq[nums[start]] == 0) // count kab decrese hoga
                count--;
            start++;
        }
        // increse the window size till no. of different integer k ke barabar n ho jaye
        end++;
    }
    return total;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Subarrays with exactly " << k << " distinct integers: "
         << subArrayWithDistict(nums, k) << endl;
    return 0;
}