#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> st;

    // Empty the queue
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    // stack ko khali karo, array ko reverse kardo
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
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

    q = rev(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}