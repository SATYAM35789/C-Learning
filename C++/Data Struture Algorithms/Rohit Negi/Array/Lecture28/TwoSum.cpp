#include <iostream>
#include <vector>
using namespace std;

// 1 based indexing given in the question

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans;
    int start = 0, end = numbers.size() - 1;

    while (start < end)
    {
        if (numbers[start] + numbers[end] == target)
        {
            ans.push_back(start + 1); // I baased index and initially we have taken start=0
            ans.push_back(end + 1);
            return ans;
        }
        else if (numbers[start] + numbers[end] < target)
            start++;
        else
            end--;
    }
    return ans;
}