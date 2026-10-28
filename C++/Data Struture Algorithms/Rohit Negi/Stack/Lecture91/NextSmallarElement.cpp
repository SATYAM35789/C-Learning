#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Next smaller Element
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
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
    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next Smaller Elements: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
