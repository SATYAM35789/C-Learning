#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Recerse Array or String
void reverseString(vector<char> &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }

    int i = 0;
    while (!st.empty())
    {
        s[i] = st.top();
        st.pop();
        i++;
    }
}

int main()
{
    //  Input string (vector form)
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "Original String: ";
    for(char c : s)
        cout << c;
    cout << endl;

    //  Reverse function call
    reverseString(s);

    cout << "Reversed String: ";
    for(char c : s)
        cout << c;
    cout << endl;

    return 0;
}