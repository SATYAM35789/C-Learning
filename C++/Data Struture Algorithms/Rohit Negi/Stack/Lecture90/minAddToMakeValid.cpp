#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Minimum add to make Parenthesis valid :-
int minAddToMakeValid(string s)
{
    stack<char> st;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // Opening Bracket
        if (s[i] == '(')
            st.push(s[i]);
        //  Closing Bracket
        else
        {
            if (st.empty())
                count++;
            else
                st.pop();
        }
    }
    return count + st.size();
}

int main()
{
    //  Input string
    string s = "())(()";

    cout << "Input String: " << s << endl;

    //  Function call
    int result = minAddToMakeValid(s);

    cout << "Minimum additions required: " << result << endl;

    return 0;
}