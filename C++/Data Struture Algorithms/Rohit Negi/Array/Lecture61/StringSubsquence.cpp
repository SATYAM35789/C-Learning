#include <iostream>
#include <vector>
using namespace std;

void subSet(string s, int index, int n, vector<string> &ans, string temp)
{
    // Base Case
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }

    //  Not Include
    subSet(s, index + 1, n, ans, temp);
    // Include
    temp.push_back(s[index]);
    subSet(s, index + 1, n, ans, temp);

    //  Temp ko khali kardo return hone ke baad
    temp.pop_back();
}

int main()
{
    string s = "abc";
    vector<string> ans;
    string temp;
    subSet(s, 0, s.size(), ans, temp);

    // Print the ans array
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}