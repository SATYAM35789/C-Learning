#include <iostream>
#include <vector>
using namespace std;

void subSequence(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> temp)
{
    // Base Case
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }

    //  Not Include
    subSequence(arr, index + 1, n, ans, temp);
    // Include
    temp.push_back(arr[index]);
    subSequence(arr, index + 1, n, ans, temp);
}

int main()
{
    int arr[] = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> temp;
    subSequence(arr, 0, 3, ans, temp);

    // Print the ans array
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }
}