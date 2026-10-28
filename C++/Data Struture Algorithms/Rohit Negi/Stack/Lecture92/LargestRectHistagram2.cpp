#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Optimized Version :-
int largestReacangleArea(vector<int> &heights)
{
    int n = heights.size();
    int ans = 0;
    int index;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            index = st.top();
            st.pop();
            if (!st.empty())
                ans = max(ans, heights[index] * (i - st.top() - 1));
            else
                ans = max(ans, heights[index] * i);
        }
        st.push(i);
    }

    //  Ho sakta ki hamara stack ke ander value hai
    while (!st.empty())
    {
        index = st.top();
        st.pop();
        if (!st.empty())
            ans = max(ans, heights[index] * (n - st.top() - 1));
        else
            ans = max(ans, heights[index] * n);
    }
    return ans;
}
int main()
{
    //  Input histogram
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Histogram: ";
    for (int h : heights)
        cout << h << " ";
    cout << endl;

    //  Function call
    int result = largestReacangleArea(heights);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}