#include <iostream>
#include <vector>
using namespace std;

void lpsfind(vector<int> &lps, string s)
{
    vector<int> lps(s.size(), 0);
    int pre = 0, suf = 1;

    while (suf < s.size())
    {
        // Matched
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            suf++;
            pre++;
        }
        //  Not matched
        else
        {
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
}

int KMP_MATCH(string heystack, string needle)
{
    vector<int> lps(needle.size(), 0);
    lpsfind(lps, needle);

    int first = 0, second = 0;

    while (first < heystack.size() && second < needle.size())
    {
        // Dono charater match
        if (heystack[first] == needle[second])
            first++, second++;

        // Dono charater not-match
        else
        {
            if (second == 0)
                first++;
            else
                second = lps[second - 1];
        }
    }

    // Answer exist
    if (second == needle.size())
        return 1;
    else
        return 0;
}

int repeatedStringMatch(string a, string b)
{
    if (a == b)
        return 1;

    int repeat = 1;
    string temp = a;

    while (temp.size() < b.size())
    {
        temp += a;
        repeat++;
    }

    // KMP Pattern Search
    if (KMP_MATCH(temp, b) == 1)
        return repeat;

    // Temp+a , kmp search
    if (KMP_MATCH(temp + a, b) == 1)
        return repeat + 1;

    return -1;
}