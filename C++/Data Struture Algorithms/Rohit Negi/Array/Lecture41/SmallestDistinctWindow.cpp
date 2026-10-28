#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findSubstring(string s)
{
    vector<int> count(256, 0);
    int first = 0, second = 0, len = s.size(), dif = 0;

    // Calculate all the unique character
    while (first < s.size())
    {
        if (count[s[first]] == 0)
            dif++;

        count[s[first]]++;
        first++;
    };

    for (int i = 0; i < 256; i++)
        count[i] = 0;

    first = 0;

    while (second < s.size())
    {
        // Increse Window : dif exist karta hai
        while (dif && second < s.size())
        {
            if (count[s[second]] == 0)
                dif--;

            count[s[second]]++;
            second++;
        }
        len = min(len, second - first); // findout ki yaha +1 kyu nahi kiya

        // decrese Window : tab tak dif=0 hai
        while (dif != 1)
        {
            len = min(len, second - first);
            count[s[first]]--;

            if (count[s[first]] == 0)
                dif++;

            first++;
        }

        return len;
    }
}