#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Valid Parentheses
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        // Opening
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        // Closing
        else
        {
            // empty hai ya nahi
            if (st.empty())
                return 0;
            // Check for this )
            else if (s[i] == ')')
            {
                if (st.top() != '(')
                    return 0;
                else
                    st.pop();
            }
            // Check for this }
            else if (s[i] == '}')
            {
                if (st.top() != '{')
                    return 0;
                else
                    st.pop();
            }
            // Check for this ]
            else
            {
                if (st.top() != '[')
                    return 0;
                else
                    st.pop();
            }
        }
    }
    return st.empty();
}

int main()
{
    //  Test cases
    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "({[]})";

    cout << "Input: " << s1 << " -> ";
    cout << (isValid(s1) ? "Valid" : "Invalid") << endl;

    cout << "Input: " << s2 << " -> ";
    cout << (isValid(s2) ? "Valid" : "Invalid") << endl;

    cout << "Input: " << s3 << " -> ";
    cout << (isValid(s3) ? "Valid" : "Invalid") << endl;

    return 0;
}
