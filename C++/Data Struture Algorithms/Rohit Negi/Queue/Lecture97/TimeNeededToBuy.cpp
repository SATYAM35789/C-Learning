#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    queue<int> q;
    int n = tickets.size();

    for (int i = 0; i < n; i++)
        q.push(i);

    int Time = 0;

    while (tickets[k] != 0)
    {
        int idx = q.front();
        q.pop();

        tickets[idx]--;
        Time++;

        if (tickets[idx] > 0)
            q.push(idx);
    }

    return Time;
}
int main()
{
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    cout << timeRequiredToBuy(tickets, k);

    return 0;
}