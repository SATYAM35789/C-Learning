#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> bracketNumbers(string s)
{
    int count = 0;
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < s.size(); i++)
    {
        //  Opening
        if (s[i] == '(')
        {
            count++;
            st.push(count);
            ans.push_back(count);
        }
        // Closing
        else if (s[i] == ')')
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}

int main()
{
    //  Input string
    string s = "(a+(b*c)+(d/e))";

    cout << "Input String: " << s << endl;

    //  Function call
    vector<int> result = bracketNumbers(s);

    cout << "Bracket Numbers: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}