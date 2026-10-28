#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void permut(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if (arr.size() == index)
    {
        ans.push_back(arr);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        permut(arr, ans, index + 1);
        swap(arr[i], arr[index]);
    }
}

int main()
{
    vector<int> arr(3);
    cout << "Enter the element in array";
    for (int i = 0; i < 3; i++)
        cin >> arr[i];

    vector<vector<int>> ans;

    permut(arr, ans, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}