#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> moodifyQueue(queue<int> q, int k)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    int n = q.size();
    // Ab stack ke element ko Queue mai daal do
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // Pahle ke element ko , phir se pichhe daalo do
    while (n--)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;

    q = moodifyQueue(q, k);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}