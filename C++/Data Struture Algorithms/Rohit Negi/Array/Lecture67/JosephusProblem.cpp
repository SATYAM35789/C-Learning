#include <iostream>
#include <vector>
using namespace std;

int winner(vector<bool> &person, int n, int index, int personLeft, int k)
{
    if (personLeft == 1)
        for (int i = 0; i < n; i++)
            if (person[i] == 0)
                return i;

    // Find the position of kill
    int kill = (k - 1) % personLeft;

    while (kill--)
    {
        index = (index + 1) % n;
        // If found the Already killed person, then unse aage chalo
        while (person[index] == 1)
            index = (index + 1) % n;
    }

    // Found the kth position
    person[index] = 1;

    // find, Next alive person
    while (person[index] == 1)
        index = (index + 1) % n;

    return winner(person, n, index, personLeft - 1, k);
}

int findTheWinner(int n, int k)
{
    vector<bool> person(n, 0);
    return winner(person, n, 0, n, k) + 1;
}
