#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// String Manipulation
int removeConsecutiveSame(vector<string> v)
{
    stack<string> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            s.push(v[i]);
        else if (s.top() == v[i])
            s.pop();
        else
            s.push(v[i]);
    }
    return s.size();
}

int main()
{
    //  Input vector of strings
    vector<string> v = {"ab", "cd", "cd", "ab", "ef", "ef", "gh"};

    cout << "Original Strings: ";
    for (string s : v)
        cout << s << " ";
    cout << endl;

    //  Function call
    int result = removeConsecutiveSame(v);

    cout << "Size after removing consecutive same elements: " << result << endl;

    return 0;
}