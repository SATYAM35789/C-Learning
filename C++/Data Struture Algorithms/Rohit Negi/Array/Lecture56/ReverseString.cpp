#include <iostream>
using namespace std;

void reverse(string &str, int start, int end)
{
    // Base case
    if (start >= end)
        return;

    char c = str[start];
    str[start] = str[end];
    str[end] = c;
    reverse(str, start + 1, end - 1);
}

int main()
{
    // Reverse a string
    string str = "satyam";
    reverse(str, 0, 5);
    cout << str << endl;
}