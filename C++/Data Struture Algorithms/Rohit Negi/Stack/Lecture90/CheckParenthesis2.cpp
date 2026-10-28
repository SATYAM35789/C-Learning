#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//  Check parenthesis is valid or not
bool check(string str)
{
    int left = 0;

    for (int i = 0; i < str.size(); i++)
    {
        // Opening bracket
        if (str[i] == '(')
            left++;
        // Closing bracket
        else
        {
            if (left == 0)
                return 0;
            else
                left--;
        }
    }
    return left == 0;
}

int main()
{
    string str = "((())";
    cout << check(str) << endl;
    return 0;
}