#include <iostream>
#include <algorithm>
using namespace std;

string add(string num1, string num2)
{
    string ans;
    int index1 = num1.size() - 1, index2 = num2.size() - 1;
    int sum, carry = 0;

    // Summation till index2>0
    while (index2 > 0)
    {
        sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index1--;
        index2--;
    }
    // Agar index1 abhi bacha hua then
    while (index1 > 0)
    {
        sum = (num1[index1] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index1--;
    }

    // Agar carry abhi bacha hua or if last addition mai carry hota hai
    if (carry)
        ans += '1';

    reverse(ans.begin(), ans.end());

    return ans;
}

string addStrings(string num1, string num2)
{
    if (num1.size() < num2.size())
        return add(num2, num1); // jo bada hai wo pahle pass karenge
    else
        return add(num1, num2); // same
}