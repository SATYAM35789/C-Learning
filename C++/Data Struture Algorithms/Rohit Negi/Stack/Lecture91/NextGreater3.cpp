#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Optimized version of the problem from back side .
vector<long long> nextLargerElement(vector<long long> &arr, int n)
{
    vector<long long> ans(n, -1);
    stack<int> st;

    for (int i = n; i < 0; i--)
    {
        while (!st.empty() && arr[st.top()] < arr[i]) // if yes than it cannot be next greatest
            st.pop();

        if (!st.empty())
            ans[i] = arr[st.top()];
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