#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void ArrayToBST(vector<int> arr, int start, int end, vector<int> &ans)
{
    if (start > end)
        return;

    int mid = start + (end - start) / 2;
    ans.push_back(arr[mid]);
    // Left Side
    ArrayToBST(arr, start, mid - 1, ans);
    // Right Side
    ArrayToBST(arr, mid + 1, end, ans);
}

vector<int> sortedArrayToBST(vector<int> &nums)
{
    // Array ko sort kar rahe hai, so ki agar user na de toh. Ha mujko pata hai question mai sorted array he diya hai.
    sort(nums.begin(), nums.end());

    vector<int> ans;
    ArrayToBST(nums, 0, nums.size() - 1, ans);
    return ans;
}

int main()
{
    // Aapka wahi array
    vector<int> nums = {6, 3, 5, 17, 11, 13, 14, 45, 15, 4};

    cout << "Converting array to Height-Balanced BST..." << endl;

    // Isse hume Pre-order sequence milega jo Balanced BST represent karta hai
    vector<int> result = sortedArrayToBST(nums);

    cout << "Pre-order traversal of the Balanced BST: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}