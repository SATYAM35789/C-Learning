#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minChar(string str)
{
    // String Reverse
    string rev = str;
    reverse(rev.begin(), rev.end());

    int size = str.size();
    str += '$';
    str += rev;

    // LPS
    int n = str.size();
    vector<int> lps(n, 0);

    int pre = 0, suf = 1;

    while (suf < str.size())
    {
        // Matched
        if (str[pre] == str[suf])
        {
            lps[suf] = pre + 1;
            pre++, suf++;
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
    return size - lps[n - 1];
}