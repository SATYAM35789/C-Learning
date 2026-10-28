#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to Calculate the span of stock price
vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && price[i] >= price[st.top()])
        {
            ans[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = st.top() + 1;
        st.pop();
    }
    return ans;
}
int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Stock Prices: ";
    for (int i = 0; i < n; i++)
        cout << price[i] << " ";
    cout << endl;

    vector<int> result = calculateSpan(price, n);

    cout << "Stock Span: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}