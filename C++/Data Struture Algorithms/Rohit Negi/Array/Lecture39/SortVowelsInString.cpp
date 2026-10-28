#include <iostream>
#include <vector>
using namespace std;

string sortVowels(string s)
{
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);

    // Count of vowels in lower and upper
    for (int i = 0; i < s.size(); i++)
    {
        // lowerCase : a,e,i,o,u
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            lower[s[i] - 'a']++;
            s[i] = '#'; // Jab ham dobara traverse kare toh pata chal jaue ki yaha vowel tha
        }

        // UpperCase : A,E,I,O,U
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            upper[s[i] - 'A']++;
            s[i] = '#';
        }
    }

    // Storing the vowels in order in ans
    string ans;
    // Part1-> upper: kyuki ye chhota hota hai
    for (int i = 0; i < 26; i++)
    {
        char c = 'A' + i;
        while (upper[i])
        {
            ans += c;
            upper[i]--;
        }
    }
    // Part2: lower
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        while (lower[i])
        {
            ans += c;
            lower[i]--;
        }
    }

    // Original String ke ander, vowels ko insert karwana hai
    int first = 0, second = 0; // Second points the ans string ko
    while (second < ans.size())
    {
        if (s[first] == 'a')
        {
            s[first] = ans[second];
            second++;
        }
        first++;
    }

    return s;
}
