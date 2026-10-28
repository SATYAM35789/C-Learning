#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string firstNonRepeatingChar(string A)
{
    string B = "";
    vector<int> repeated(26, 0);
    queue<char> q;

    for (int i = 0; i < A.size(); i++)
    {
        // Agar charater repeated hai, queue ke ander push nahi karna hai
        if (repeated[A[i] - 'a'] >= 1)
        {
            repeated[A[i] - 'a']++;
            // Repeated nahi hai so, queue mai jo front hai usko add kar do B mai
            while (!q.empty() && repeated[q.front() - 'a'] > 1)
                q.pop();

            if (q.empty())
                B += '#';
            else
                B += q.front();
        }
        // Agr character non repeated hai , toh queue ke ander push karna hai
        else
        {
            repeated[A[i] - 'a']++;
            q.push(A[i]);
            while (repeated[q.front() - 'a'] > 1)
                q.pop();

            B += q.front();
        }
    }
    return B;
}

int main()
{
    string A = "aabc";

    cout << firstNonRepeatingChar(A);

    return 0;
}