#include <iostream>
using namespace std;

int count(string str, int index)
{
    // Base Case
    if (index == -1)
        return 0;

    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
        return 1 + count(str, index - 1);

    else
        return count(str, index - 1);
}

int main()
{
    //  Count vowels
    string str = "satyam";
    cout << count(str, 5) << endl;
}