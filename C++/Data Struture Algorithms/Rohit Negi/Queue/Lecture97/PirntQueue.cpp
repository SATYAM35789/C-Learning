#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    queue<int> q;
    q.push(5);
    q.push(25);
    q.push(45);
    q.push(75);
    q.push(56);

    int n = q.size();
    while (n--)
    {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }

    // Checking that value is present in the queue or not
    q.size();
}