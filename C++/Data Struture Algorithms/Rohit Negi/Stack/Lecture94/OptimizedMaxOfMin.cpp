#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// Function to find maximmum of minimum of every window size
vector<int> maxOfMin(int arr[], int n)
{
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        // Value kab tak pop hogi
        while (!st.empty() && arr[st.top()] > arr[i]) // next smallest right
        {
            int index = st.top();
            st.pop();
            // i= next smallest Right
            //  stack ke ander jo index hai wo nsl hai (st.top())
            if (st.empty())
            {
                int range = i; // range = window size
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            else
            {
                int range = i - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        st.push(i);

        // stack element ko khali karo
        while (!st.empty())
        {
            int index = st.top();
            st.pop();
            if (st.empty())
            {
                int range = n; // n - (-1) -1
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            else
            {
                int range = n - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }

        // ans array ki value ko update kardo
        for (n - 2; n >= 0; i--)
            ans[i] = max(ans[i], ans[i + 1]);

        return ans;
    }
}
int main()
{
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //  Function call
    vector<int> result = maxOfMin(arr, n);

    cout << "Max of Minimums for every window size:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Window size " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}