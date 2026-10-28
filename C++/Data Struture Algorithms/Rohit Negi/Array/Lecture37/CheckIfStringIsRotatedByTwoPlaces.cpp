#include <iostream>
using namespace std;

void rotateClockWise(string &s)
{
    char c = s.size() - 1;
    int index = s.size() - 2;

    while (index >= 0)
    {
        s[index + 1] = s[index];
        index--;
    }
    s[0] += c;
}

void rotateAntiClockWise(string &s)
{
    char c = s[0];
    int index = 1;

    while (index < s.size())
    {
        s[index - 1] = s[index];
        index++;
    }
    s[s.size() - 1] += c;
}

bool isRotate(string str1, string str2)
{
    if (str1.size() != str2.size())
        return 0;

    string clockWise, antiClockWise;

    clockWise = str1;
    rotateClockWise(clockWise);
    rotateClockWise(clockWise);

    if (clockWise == str2)
        return 1;

    antiClockWise = str1;
    rotateAntiClockWise(antiClockWise);
    rotateAntiClockWise(antiClockWise);

    if (antiClockWise == str2)
        return 1;

    return 0;
}