#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//  Check parenthesis is valid or not
bool check(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        // Opening bracket
        if (str[i] == '(')
            s.push(str[i]);
        // Closing bracket
        else
        {
            //  Kahi stack khali toh nahi hai
            if (s.empty())
                return 0;
            else
                s.pop();
        }
    }
    return s.empty();
}

int main()
{
    string str = "((())";
    cout << check(str) << endl;
    return 0;
}