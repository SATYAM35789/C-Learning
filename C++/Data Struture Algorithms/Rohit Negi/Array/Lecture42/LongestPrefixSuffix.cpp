#include <iostream>
#include <vector>
using namespace std;

int lps(string s)
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
    return lps[s.size() - 1];
}