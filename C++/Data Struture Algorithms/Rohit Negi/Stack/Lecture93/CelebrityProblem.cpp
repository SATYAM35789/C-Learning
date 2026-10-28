#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = n - 1; i >= 0; i++)
    {
        st.push(i);

        int first, second;

        while (st.size() > 1)
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();

            if (M[first][second] && !M[second][first])
                st.push(second);
            else if (!M[first][second] && M[second][first])
                st.push(first);
        }
    }
    if (st.empty())
        return -1;

    int num = st.top();
    st.pop();

    // Celebrity hai yo nahi
    int row = 0, col = 0;

    for (int i = 0; i < n; i++)
    {
        row += M[num][i];
        col += M[i][num];
    }

    return row == 0 && col == n - 1 ? num : -1;
}

int main()
{
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}};

    int n = M.size();

    int result = celebrity(M, n);

    if (result == -1)
        cout << "No Celebrity\n";
    else
        cout << "Celebrity is person: " << result << endl;

    return 0;
}