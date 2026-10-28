#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void permute(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    vector<bool> use(21, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (use[arr[i] + 10] == 0)
        {
            swap(arr[i], arr[index]);
            permute(arr, ans, index + 1);
            swap(arr[i], arr[index]);
            use[arr[i] + 10] = 1;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &arr)
{
    vector<vector<int>> ans;
    permute(arr, ans, 0);
}