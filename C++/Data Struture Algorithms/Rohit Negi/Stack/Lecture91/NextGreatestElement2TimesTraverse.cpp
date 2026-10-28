#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Next Greater Element 2
vector<long long> nextLargerElement(vector<long long> &arr, int n)
{
    vector<long long> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        while (!st.empty() && arr[i % n] > arr[st.top()])
        {
            ans[st.top()] = arr[i % n];
            st.pop();
        }
        if (i < n)
            st.push(i);
    }
    return ans;
}
int main()
{
    // Input array
    vector<long long> arr = {6, 8, 0, 1, 3};
    int n = arr.size();

    cout << "Array: ";
    for (long long x : arr)
        cout << x << " ";
    cout << endl;

    //  Function call
    vector<long long> result = nextLargerElement(arr, n);

    cout << "Next Greater Elements: ";
    for (long long x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}