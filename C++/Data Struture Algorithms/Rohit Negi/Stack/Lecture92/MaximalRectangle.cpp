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

int maximalRectangle(vector<vector<char>> &matrix)
{
    int ans = 0;
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> heights(col, 0);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '0')
                heights[j] = 0;
            else
                heights[j]++;
        }
        ans = max(ans, largestReacangleArea(heights));
    }
    return ans;
}
int main()
{
    //  Binary matrix
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << "Matrix:\n";
    for (auto row : matrix)
    {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }

    //  Function call
    int result = maximalRectangle(matrix);

    cout << "\nMaximum Rectangle Area: " << result << endl;

    return 0;
}