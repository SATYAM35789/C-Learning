#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s = "Satyam";

    // Reverse String
    int start = 0, end = s.size() - 1;

    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    cout << s;

    // Calculating the length of the string
    int size = 0;
    while (s[size] == '\0')
        size++;

    cout << endl;
    cout << size << " ";

    // Checking the palindome : start aur end ko match karwayenge if matched then go and check for next, if not then return not palindrome
    string s2 = "naman";
    start = 0, end = s2.size() - 1;
    while (start < end)
    {
        if (s2[start] != s2[end])
        {
            cout << "Not a Palindrome";
            return 0;
        }
        start++, end--;
    }
    cout << "It is a palindrome";
}