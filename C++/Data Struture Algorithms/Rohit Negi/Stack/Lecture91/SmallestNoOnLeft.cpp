#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Smallest Number on left
vector<int> leftSmaller(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    //  Input array
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    //  Function call
    vector<int> result = leftSmaller(arr, n);

    cout << "Next Smaller Elements: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
