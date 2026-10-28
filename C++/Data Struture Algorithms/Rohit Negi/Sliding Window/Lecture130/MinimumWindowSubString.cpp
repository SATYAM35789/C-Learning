#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t)
{
    int total = t.size();
    unordered_map<char, int> m;        // strors character amd its count
    for (int i = 0; i < t.size(); i++) // charcters requiremennt in string s
        m[t[i]]++;

    int start = 0, end = 0, ans = INT_MAX, index = -1;

    while (end < s.size())
    {
        m[s[end]]--;        // decrese the count of character
        if (m[s[end]] >= 0) // agar count -ve nahi hai
            total--;        // totak ko decrese kardo

        // Can we decrese the size of window
        while (total == 0 && start <= end)
        {
            // update the length of substring
            if (ans > end - start + 1)
            {
                ans = end - start + 1;
                index = start;
            }

            m[s[start]]++;       // start ek kadam aage bhi ja rah hai means map mai jaha start hai usme 1 add kardo
            if (m[s[start]] > 0) // Agar map ka start positive hai means t ka element isko hatao aur total ko bada do
                total++;

            start++; // phir start ko ek se aage bada do
        }

        // increse the size of window
        end++;
    }

    if (index == -1)
        return "";
    string str = "";
    for (int i = index; i < index + ans; i++)
    {
        str += s[i];
    }
    return str;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Min Window Substring: " << minWindow(s, t) << endl;
    return 0;
}