#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestReacangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> Right(n);
    vector<int> Left(n);
    stack<int> st;

    // Finding next smallest Right
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            Right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // Stack ko khali karo
    while (!st.empty())
    {
        Right[st.top()] = n;
        st.pop();
    }

    //  Finding next smallest left side
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            Left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // Stack ko khali karo
    while (!st.empty())
    {
        Left[st.top()] = -1;
        st.pop();
    }

    int ans = 0;
    // Area calculating
    for (int i = 0; i < n; i++)
        ans = max(ans, heights[i] * (Right[i] - Left[i] - 1));

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